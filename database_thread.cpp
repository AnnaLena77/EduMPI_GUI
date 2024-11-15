#include "database_thread.h"
#include "QSql"
#include <QSqlQuery>
#include <QSqlRecord>
#include <unistd.h>
#include <QDateTime>
#include <QStandardItemModel>
#include <QSqlError>

Database_Thread::Database_Thread(QString dbConnectionName, int slurm_id, int proc_num, bool live_run, QObject *parent)
    : QObject(parent) {

    m_connectionName = dbConnectionName;
    m_proc_num = proc_num;
    m_slurm_id = slurm_id;
    m_live_run = live_run;
}

Database_Thread::~Database_Thread(){
    QSqlDatabase db = QSqlDatabase::database(m_connectionName);
    if (!db.isOpen()) {
        qDebug() << "Databaseconnection " << m_connectionName << " is not open";
        return;
    }
    db.close();
    QSqlDatabase::removeDatabase(m_connectionName);
}

void Database_Thread::clearDatabase(){

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

    while(query.size()<m_proc_num || m_proc_num<=0){
        query.exec();
        if(m_proc_num == -1234){
            break;
        }
        sleep(1);
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
    QDateTime timestamp;

    if(m_firstDBEntryTime.isNull()){
        //queryy.prepare("SELECT time_second FROM edumpi_data_secondly WHERE edumpi_run_id=:slurm_id order by time_second DESC LIMIT 1");
        while(true){
            queryy.prepare("SELECT time_start, time_end FROM edumpi_secondly_data WHERE edumpi_run_id=:slurm_id order by time_start ASC LIMIT 1");
            queryy.bindValue(":slurm_id", m_slurm_id);
            queryy.exec();
            if(queryy.next()){
                timestamp = queryy.value(0).toDateTime();
                QDateTime timestamp_end = queryy.value(1).toDateTime();

                int diff = timestamp.msecsTo(timestamp_end);
                if(m_live_run){
                    if(diff < 3000){
                        qDebug() << "Timediff < 3000: " << diff << " " << timestamp.toString() << ", " <<  timestamp_end.toString();
                        sleep(3);
                    } else {
                        qDebug() << "Timediff > 3000: " << diff << " " << timestamp.toString() << ", " << timestamp_end.toString();
                    }
                }

                m_firstDBEntryTime = timestamp.time();
                m_actualDBEntryTime = timestamp;
                emit setTimestamp(timestamp);
            break;
            }
        }
    } else{
        m_actualDBEntryTime = m_actualDBEntryTime.addSecs(1);
    }

    QSqlQuery query(db);
    QString queryString;

    if(time_display == 0){
        //queryString = QString("SELECT * FROM edumpi_data_secondly WHERE time_second = '%1' AND edumpi_run_id = %2;").arg(m_actualDBEntryTime.toString("yyyy-MM-dd HH:mm:ss")).arg(m_slurm_id);
        queryString = QString("SELECT processorname, processrank, communicationtype, SUM(send_ds) AS send_ds, SUM(recv_ds) AS recv_ds, SUM(time_diff) AS time_diff, SUM(latesendertime) AS latesendertime, SUM(laterecvrtime) AS laterecvrtime FROM edumpi_secondly_data WHERE edumpi_run_id = %1 AND time_end >= '%2' AND time_start <= '%2' GROUP BY processorname, processrank, communicationtype;").arg(m_slurm_id).arg(m_actualDBEntryTime.toString("yyyy-MM-dd HH:mm:ss"));
    }
    else if(time_display == 1){
        queryString = QString("SELECT processrank, processorname, communicationtype, SUM(sendDatasize) AS send_ds, SUM(recvDatasize) AS recv_ds FROM edumpi_running_data WHERE edumpi_run_id=%1 GROUP BY processorname, processrank, communicationtype ORDER BY processrank ASC").arg(m_slurm_id);
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

    emit updateDataReady(list);

}

void Database_Thread::showDataFromTimePeriod(const QDateTime timestampA, const QDateTime timestampB){
    QSqlDatabase db = QSqlDatabase::database(m_connectionName);
    if (!db.isOpen()) {
        qDebug() << "Databaseconnection " << m_connectionName << " is not open";
        return;
    }

    QString queryString = "SELECT processorname, processrank, communicationtype, SUM(send_ds) AS send_ds, SUM(recv_ds) AS recv_ds, SUM(time_diff) AS time_diff, SUM(latesendertime) AS latesendertime, SUM(laterecvrtime) AS laterecvrtime FROM edumpi_secondly_data WHERE edumpi_run_id = :slurm_id AND ((time_end >= :endtime AND time_start <= :starttime) OR (time_end BETWEEN :starttime AND :endtime)) GROUP BY processorname, processrank, communicationtype;";

    QSqlQuery query(db);
    query.prepare(queryString);
    query.bindValue(":starttime", timestampA.toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":endtime", timestampB.toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":slurm_id", m_slurm_id);

    //std::cout << "Starttime" << a.toString("yyyy-MM-d HH:mm:ss").toStdString() << std::endl;

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


}

/*void Database_Thread::getSlurmId(const int id){
    std::cout << "Slurm_ID ANGEKOMMEN" << std::endl;
    m_slurm_id = id;
    QString name_helper = "Thread %1";
    QSqlDatabase db = QSqlDatabase::database(m_connectionName);
    if (!db.isOpen()) {
        qDebug() << "Databaseconnection " << m_connectionName << " is not open";
        return;
    }
    m_connectionName = name_helper.arg(m_slurm_id);
    QSqlDatabase clone_db = QSqlDatabase::cloneDatabase(db, m_connectionName);
    clone_db.open();
    threadbuildClusterComponents();
}*/

void Database_Thread::getProcNum(const int proc_num){
    m_proc_num = proc_num;
}

void Database_Thread::fetchEduMPIJobs(const QString &userId){

}
