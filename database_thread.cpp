#include "database_thread.h"
#include "QSql"
#include <QSqlQuery>
#include <QSqlRecord>
#include <unistd.h>
#include <QDateTime>
#include <QStandardItemModel>
#include <QSqlError>
#include <QTimeZone>
#include <QCoreApplication>

Database_Thread::Database_Thread(QString dbConnectionName, int slurm_id, int proc_num, bool live_run, QObject *parent)
    : QObject(parent) {

    m_connectionName = dbConnectionName;
    m_proc_num = proc_num;
    m_slurm_id = slurm_id;
    m_live_run = live_run;
    m_thread_running = true;
}

Database_Thread::~Database_Thread(){
}

void Database_Thread::clearDatabase(){
    {
        QSqlDatabase db = QSqlDatabase::database(m_connectionName);
        if (!db.isOpen()) {
            qDebug() << "Databaseconnection " << m_connectionName << " is not open";
            return;
        }
        db.close();
    }
    QSqlDatabase::removeDatabase(m_connectionName);
}

void Database_Thread::connectToDB(){
    QSqlDatabase db = QSqlDatabase::cloneDatabase("mainConnection", m_connectionName);
    //std::cout << "Slurm_ID ANGEKOMMEN" << std::endl;
    db = QSqlDatabase::database(m_connectionName);
    if (!db.isOpen()) {
        db.open();
    }
}

void Database_Thread::threadbuildClusterComponents(){
    //qDebug() << "Current thread:" << QThread::currentThread();
    QSqlDatabase db = QSqlDatabase::database(m_connectionName);
    if (!db.isOpen()) {
        qDebug() << "Databaseconnection " << m_connectionName << " is not open";
        return;
    }

    m_firstDBEntryTime = QTime();
    QSqlQuery query(db);
    QString name = "";

    QMap<QString, QVector<int>> map;

    query.prepare("SELECT * FROM edumpi_cluster_info WHERE edumpi_run_id = :slurm_id ORDER BY processorname, processrank");
    query.bindValue(":slurm_id", m_slurm_id);
    query.exec();

    while((query.size()<m_proc_num || m_proc_num<=0) && m_thread_running){
        query.exec();
        if(m_proc_num == -1234){
            break;
        }
        QThread::msleep(1000);
    }
    if(!m_thread_running){
        return;
    }
    //std::cout << "Size passt!!!!!" << std::endl;

    while(query.next()) {
        QString actual_name = query.value("processorname").toString();
        int actual_rank = query.value("processrank").toInt();

        if(map.isEmpty()){
            map.insert(actual_name, {actual_rank});
        }else if(!map.contains(actual_name)){
            map.insert(actual_name, {actual_rank});
        } else {
            map[actual_name].append(actual_rank);
        }
    }
    emit clusterComponentsReady(map);
}

//Continuous update of the data in the database for the live view
void Database_Thread::updateData(const int &time_display){

    QSqlDatabase db = QSqlDatabase::database(m_connectionName);
    if (!db.isOpen()) {
        qDebug() << "Databaseconnection " << m_connectionName << " is not open";
        return;
    }

    QSqlQuery queryy(db);
    QDateTime timestamp_runtime;
    QDateTime timestamp;

    if(m_firstDBEntryTime.isNull()){
        queryy.prepare("SELECT start_time FROM edumpi_runs WHERE edumpi_run_id = :run_id");
        queryy.bindValue(":run_id", m_slurm_id);
        while(m_thread_running){
            QCoreApplication::processEvents();
            QThread::msleep(1000);
            queryy.exec();
            if(queryy.next()){
                timestamp_runtime = queryy.value(0).toDateTime();
                timestamp_runtime = timestamp_runtime.toLocalTime();
                //qDebug() << "Timestamp_runtime: " << timestamp_runtime;
                break;
            }
        }
        queryy.prepare("SELECT time_start, time_end FROM edumpi_secondly_data WHERE edumpi_run_id=:slurm_id order by time_start ASC LIMIT 1");
        queryy.bindValue(":slurm_id", m_slurm_id);
        while(m_thread_running){
            queryy.exec();
            if(queryy.next()){
                timestamp = queryy.value(0).toDateTime();
                QDateTime timestamp_end = queryy.value(1).toDateTime();
                timestamp_runtime = timestamp_runtime.toLocalTime();


                int diff = timestamp_runtime.msecsTo(timestamp);
                int diff2 = timestamp.msecsTo(timestamp_end);
                if(m_live_run){
                    if(diff < 3000 && diff2 < 3000){
                        qDebug() << "Timediff < 3000: " << diff << " " << timestamp_runtime.toString() << ", " <<  timestamp.toString();
                        sleep(3);
                    } else {
                        qDebug() << "Timediff > 300: " << diff << " " << timestamp_runtime.toString() << ", " << timestamp.toString();
                    }
                }

                m_firstDBEntryTime = timestamp_runtime.time();
                m_firstDBEntryDate = timestamp_runtime;
                m_actualDBEntryTime = timestamp_runtime;
                emit setTimestamp(timestamp_runtime, 1);
                break;
            }
            else {
                QThread::msleep(1000);
            }
        }
        queryy.finish();
    } else{
        m_actualDBEntryTime = m_actualDBEntryTime.addSecs(1);
    }

    QSqlQuery query(db);
    QString queryString;

    if(time_display == 0){
        QDateTime ts_toUTC = m_actualDBEntryTime.toUTC();
        queryString = QString("SELECT processorname, processrank, communicationtype, SUM(send_ds) AS send_ds, SUM(recv_ds) AS recv_ds, SUM(time_diff) AS time_diff, SUM(latesendertime) AS latesendertime, SUM(laterecvrtime) AS laterecvrtime FROM edumpi_secondly_data WHERE edumpi_run_id = %1 AND time_end >= '%2' AND time_start <= '%2' GROUP BY processorname, processrank, communicationtype;").arg(m_slurm_id).arg(ts_toUTC.toString("yyyy-MM-dd HH:mm:ss"));
    }
    else if(time_display == 1){
         QDateTime ts_toUTC = m_actualDBEntryTime.toUTC();
        queryString = QString("SELECT processorname, processrank, communicationtype, SUM(send_ds) AS send_ds, SUM(recv_ds) AS recv_ds, SUM(time_diff) AS time_diff, SUM(latesendertime) AS latesendertime, SUM(laterecvrtime) AS laterecvrtime FROM edumpi_secondly_data WHERE edumpi_run_id = %1 AND (time_end <= '%2' OR time_start <= '%2') GROUP BY processorname, processrank, communicationtype;").arg(m_slurm_id).arg(ts_toUTC.toString("yyyy-MM-dd HH:mm:ss"));
    }

    //std::cout << queryString.toStdString() << std::endl;


    query.exec(queryString);
    QList<DataColumn> list;


    if(query.next()){
        do {
            DataColumn dc;
            dc.proc_name = query.value("processorname").toString();
            dc.comm_type = query.value("communicationtype").toString();
            dc.proc_rank = query.value("processrank").toInt();
            dc.recv_datasize = query.value("recv_ds").toLongLong();
            dc.send_datasize = query.value("send_ds").toLongLong();

            dc.late_sender = query.value("latesendertime").toFloat();
            dc.late_receiver = query.value("laterecvrtime").toFloat();
            dc.time_diff = query.value("time_diff").toFloat();
            list.append(dc);
        }while(query.next());
    } else{
        //std::cout << "Keine Daten \n" << std::endl;
        /*query.prepare("SELECT MAX(time_end) FROM edumpi_running_data WHERE edumpi_run_id = :slurm_id");
        query.bindValue(":slurm_id", m_slurm_id);
        query.exec();
        if(query.next()){
            QString max = query.value("max").toString();
            //std::cout << "In der edumpi_running_data stehen Daten bis Timestamp: "  << max.toStdString() << "\n" << std::endl;
        }*/
    }
    query.finish();
    emit updateDataReady(list);
    detailed_p2p_Query(m_actualDBEntryTime.toUTC(), m_actualDBEntryTime.toUTC());

}

void Database_Thread::detailed_p2p_Query(const QDateTime timestampA, const QDateTime timestampB){
    QList<QVariantList> p2p_list;
    QList<QVariantList> coll_list;

    QSqlDatabase db = QSqlDatabase::database(m_connectionName);
    if (!db.isOpen()) {
        qDebug() << "Databaseconnection " << m_connectionName << " is not open";
        return;
    }

    QString queryString = "SELECT function, communicationtype, processrank, partnerrank, coll_algorithm, coll_partnerranks FROM edumpi_detailed_data WHERE edumpi_run_id = :slurm_id AND ((time_end >= :endtime AND time_start <= :starttime) OR (time_end BETWEEN :starttime AND :endtime)) GROUP BY function, communicationtype, processrank, partnerrank, coll_algorithm, coll_partnerranks;";

    QDateTime a = timestampA.toUTC();
    QDateTime b = timestampB.toUTC();

    QSqlQuery query(db);
    query.prepare(queryString);
    query.bindValue(":starttime", a.toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":endtime", b.toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":slurm_id", m_slurm_id);

    //std::cout << "Test Starttime" << a.toString("yyyy-MM-d HH:mm:ss").toStdString() << std::endl;

    if (query.exec()) {
        while(query.next()){
            if(query.value(1) == "p2p"){
                QVariantList list;
                list << query.value(0)  // function
                     << query.value(2) // processrank
                     << query.value(3) ;// partnerrank
                p2p_list.append(list);
            } else if(query.value(1) == "collective"){
                QVariantList list;
                list << query.value(0) // function
                     << query.value(2) // processrank
                     << query.value(4) // coll algorithm
                     << query.value(5); //coll_partnerranks
                coll_list.append(list);
            }
        }

    } else {
        QSqlError fehler = query.lastError();
        qDebug() << "Query Error:" << fehler.text();
    }
    query.finish();
    emit updateDetailedP2P(p2p_list);
    emit updateDetailedColl(coll_list);
}

void Database_Thread::selectEndTimestamp(){
    QSqlDatabase db = QSqlDatabase::database(m_connectionName);
    if (!db.isOpen()) {
        qDebug() << "Databaseconnection " << m_connectionName << " is not open";
        return;
    }
    QSqlQuery queryy(db);
    QDateTime timestamp_runtime;
    QDateTime timestamp_end;

    queryy.prepare("SELECT end_time FROM edumpi_runs WHERE edumpi_run_id = :run_id");
    queryy.bindValue(":run_id", m_slurm_id);
    for(int i=0; i<5; i++){
        queryy.exec();
        if(queryy.next()){
            timestamp_end = queryy.value(0).toDateTime();
            timestamp_runtime = timestamp_runtime.toLocalTime();
            emit setTimestamp(timestamp_end, 0);
            break;
        }
        sleep(1);
    }
    queryy.finish();

}

void Database_Thread::showDataFromTimePeriod(const QDateTime timestampA, const QDateTime timestampB){
    QSqlDatabase db = QSqlDatabase::database(m_connectionName);
    if (!db.isOpen()) {
        qDebug() << "Databaseconnection " << m_connectionName << " is not open";
        return;
    }

    QString queryString = "SELECT processorname, processrank, communicationtype, SUM(send_ds) AS send_ds, SUM(recv_ds) AS recv_ds, SUM(time_diff) AS time_diff, SUM(latesendertime) AS latesendertime, SUM(laterecvrtime) AS laterecvrtime FROM edumpi_secondly_data WHERE edumpi_run_id = :slurm_id AND ((time_end >= :endtime AND time_start <= :starttime) OR (time_end BETWEEN :starttime AND :endtime)) GROUP BY processorname, processrank, communicationtype;";

    QDateTime a = timestampA.toUTC();
    QDateTime b = timestampB.toUTC();

    QSqlQuery query(db);
    query.prepare(queryString);
    query.bindValue(":starttime", a.toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":endtime", b.toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":slurm_id", m_slurm_id);

    //std::cout << "Test Starttime" << a.toString("yyyy-MM-d HH:mm:ss").toStdString() << std::endl;

    if (query.exec()) {
        QList<DataColumn> list;

        if(query.next()){
            do {

                DataColumn dc;
                dc.proc_name = query.value("processorname").toString();
                dc.comm_type = query.value("communicationtype").toString();
                dc.proc_rank = query.value("processrank").toInt();
                dc.recv_datasize = query.value("recv_ds").toLongLong();
                dc.send_datasize = query.value("send_ds").toLongLong();

                dc.late_sender = query.value("latesendertime").toFloat();
                dc.late_receiver = query.value("laterecvrtime").toFloat();
                dc.time_diff = query.value("time_diff").toFloat();

                //std::cout << dc.proc_name.toStdString() << " " << dc.comm_type.toStdString() << " " << dc.proc_rank << std::endl;

                list.append(dc);
            }while(query.next());
        }else{
        }

        emit updateDataReady(list);

    } else {
        QSqlError fehler = query.lastError();
        qDebug() << "Query Error:" << fehler.text();
    }
    query.finish();
    detailed_p2p_Query(timestampA, timestampB);

}

void Database_Thread::getProcNum(const int proc_num){
    m_proc_num = proc_num;
}

void Database_Thread::fetchEduMPIJobs(const QString &userId){

}

void Database_Thread::set_end_timestamp_db(QDateTime timestamp){
    QSqlDatabase db = QSqlDatabase::database(m_connectionName);
    if (!db.isOpen()) {
        qDebug() << "Databaseconnection " << m_connectionName << " is not open";
        return;
    }

    QString queryString = "UPDATE edumpi_runs SET end_time = :endtime WHERE edumpi_run_id = :slurm_id";

    QDateTime end = timestamp.toUTC();

    QSqlQuery query(db);
    query.prepare(queryString);
    query.bindValue(":endtime", end.toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":slurm_id", m_slurm_id);

    if(!query.exec()){
        QSqlError fehler = query.lastError();
        qDebug() << "Query Update Error:" << fehler.text();
    }
    query.finish();
}

void Database_Thread::reset_actual_timestamp(){
    m_actualDBEntryTime = m_firstDBEntryDate.addMSecs(-1);
}

void Database_Thread::set_thread_running(bool running){
    m_thread_running = running;
    emit thread_runningChanged();
}

bool Database_Thread::thread_running() const{
    return m_thread_running;
}
