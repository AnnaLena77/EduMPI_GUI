#include "database_thread.h"
#include "QSql"
#include <QSqlQuery>
#include <QSqlRecord>
#include <unistd.h>
#include <QDateTime>
#include <QStandardItemModel>
#include <QSqlError>

QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

void Database_Thread::connectToDB(const QString &hostname, const QString &databasename, const int &port, const QString &username, const QString &password){
    db.setHostName(hostname);
    db.setPort(port);
    db.setDatabaseName(databasename);
    db.setUserName(username);
    db.setPassword(password);
    bool ok = db.open();

    emit connectedToDB(ok);

    std::cout << "New Connection" << std::endl;
    m_slurm_id = 0;
    m_proc_num = 0;
}

void Database_Thread::clearDatabase(){
    /*m_clearingProc = true;
    if(db.isOpen()){
        QSqlQuery query(db);
        query.exec("DELETE FROM cluster_information;");
        query.exec("DELETE FROM mpi_information;");
        sleep(1);
        query.exec("CALL refresh_continuous_aggregate('mpi_ds_secondly', NULL, NULL);");
        //db.close();
        std::cout << "Database gecleard" << std::endl;
    }
    m_clearingProc = false;*/
}

void Database_Thread::threadbuildClusterComponents(){
    if(!db.isOpen()){
        return;
    }
    std::cout << "Test from threadbuildClusterComponents" << std::endl;
    /*while(m_clearingProc){

    }*/

    std::cout << "New Cluster Components" << std::endl;
    QSqlQuery query(db);
    QString name = "";

    QMap<QString, QVector<int>> map;

    query.prepare("SELECT * FROM edumpi_cluster_info WHERE edumpi_run_id = :slurm_id ORDER BY processorname, processrank");
    query.bindValue(":slurm_id", m_slurm_id);
    query.exec();

    while(query.size()<m_proc_num){
        query.exec();
        sleep(1);
    }
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

    QSqlQuery queryy(db);
    QDateTime timestamp;

    if(m_firstDBEntryTime.isNull()){
        queryy.prepare("SELECT time_second FROM edumpi_data_secondly WHERE edumpi_run_id=:slurm_id order by time_second DESC LIMIT 1");
        queryy.bindValue(":slurm_id", m_slurm_id);
        queryy.exec();
        if(queryy.next()){
            timestamp = queryy.value(0).toDateTime();
            m_firstDBEntryTime = timestamp.time();
            m_actualDBEntryTime = timestamp.addSecs(-3);
            emit setTimestamp(m_firstDBEntryTime);
        } else {
            return;
        }
    } else{
        m_actualDBEntryTime = m_actualDBEntryTime.addSecs(1);
    }

    QSqlQuery query(db);
    QString queryString;

    if(time_display == 0){
        queryString = QString("SELECT * FROM edumpi_data_secondly WHERE time_second = '%1' AND edumpi_run_id = %2;").arg(m_actualDBEntryTime.toString("yyyy-MM-dd HH:mm:ss")).arg(m_slurm_id);
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
            list.append(dc);
        }while(query.next());
    } else{
        //std::cout << "Keine Daten \n" << std::endl;
        query.prepare("SELECT MAX(time_end) FROM edumpi_running_data WHERE edumpi_run_id = :slurm_id");
        query.bindValue(":slurm_id", m_slurm_id);
        query.exec();
        if(query.next()){
            QString max = query.value("max").toString();
            //std::cout << "In der edumpi_running_data stehen Daten bis Timestamp: "  << max.toStdString() << "\n" << std::endl;
        }
    }

    emit updateDataReady(list);

}

void Database_Thread::showDataFromTimePeriod(const QTime timestampA, const QTime timestampB){
    QDateTime a = QDateTime::currentDateTime();
    QDateTime b = QDateTime::currentDateTime();
    a.setTime(timestampA);
    b.setTime(timestampB);

    QString queryString = "SELECT * FROM edumpi_data_secondly WHERE time_second BETWEEN :starttime AND :endtime AND edumpi_run_id = :slurm_id;";
    QSqlQuery query(db);
    query.prepare(queryString);
    query.bindValue(":starttime", a.toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":endtime", b.toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":slurm_id", m_slurm_id);

    //std::cout << queryString.toStdString() << std::endl;

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
                list.append(dc);
            }while(query.next());
        }else{
        }

        emit updateDataReady(list);

    } else {
        QSqlError fehler = query.lastError();
        qDebug() << "Fehler beim Ausführen der Abfrage:" << fehler.text();
    }


}

void Database_Thread::getSlurmId(const int id){
    std::cout << "Slurm_ID ANGEKOMMEN" << std::endl;
    m_slurm_id = id;
    threadbuildClusterComponents();
}

void Database_Thread::getProcNum(const int proc_num){
    m_proc_num = proc_num;
}
