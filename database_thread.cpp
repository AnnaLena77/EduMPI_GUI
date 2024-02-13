#include "database_thread.h"
#include "QSql"
#include <QSqlQuery>
#include <QSqlRecord>
#include <unistd.h>
#include <QDateTime>
#include <QStandardItemModel>

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
}

void Database_Thread::threadbuildClusterComponents(const int &proc_num){
    if(!db.isOpen()){
        return;
    }

    std::cout << "New Cluster Components" << std::endl;
    QSqlQuery query(db);
    QString name = "";

    QMap<QString, QVector<int>> map;

    query.exec("SELECT * FROM cluster_information ORDER BY processorname, rank");
    while(query.size()<proc_num){
        query.exec("SELECT * FROM cluster_information ORDER BY processorname, rank");
        sleep(1);
    }
    while(query.next()) {
        QString actual_name = query.value("processorname").toString();
        int actual_rank = query.value("rank").toInt();

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

void Database_Thread::updateData(const int &time_display){

    QSqlQuery query(db);
    QSqlQuery queryy(db);
    QSqlQuery queryyy(db);

    QString queryString;

    if(time_display == 0){
        //query.exec("SELECT processrank, processorname, communicationtype, SUM(sendDatasize) AS sum_send_ds, SUM(recvDatasize) AS sum_recv_ds FROM mpi_information GROUP BY processorname, processrank, communicationtype ORDER BY processrank ASC");
        //1970-01-01 01:00:00.000 +0100
        QDateTime timestamp;
        //auto first_query_start = std::chrono::high_resolution_clock::now();
        queryy.exec("SELECT time_second FROM mpi_ds_secondly order by time_second DESC LIMIT 1");
        //auto first_query_end = std::chrono::high_resolution_clock::now();
        //auto duration = std::chrono::duration_cast<std::chrono::seconds>(first_query_end - first_query_start);
        //std::cout << "Zeitdifferenz erster Query: " << duration.count() << " Sekunden." << std::endl;
        if(queryy.next()){
            timestamp = queryy.value(0).toDateTime();
            //std::cout << "Hypertable Max: " << timestamp.toString("yyyy-MM-dd HH:mm:ss").toStdString() << std::endl;
            timestamp = timestamp.addSecs(-1);
        }
        else{
            return;
        }
        //query.exec("SELECT processrank, processorname, communicationtype, SUM(sendDatasize) AS sum_send_ds, SUM(recvDatasize) AS sum_recv_ds FROM mpi_information GROUP BY processorname, processrank, communicationtype ORDER BY processrank ASC");
        //1970-01-01 01:00:00.000 +0100
        /*queryyy.exec("SELECT MAX(time_end) FROM mpi_information");
        if(queryyy.next()){
            QDateTime timestamp = queryyy.value(0).toDateTime();
            std::cout << "Real Table Max: " << timestamp.toString("yyyy-MM-dd HH:mm:ss").toStdString() << std::endl;

        }*/

        QDateTime current_time = QDateTime::currentDateTime();
        //std::cout << "Frontend-Time: " << current_time.toString("yyyy-MM-dd HH:mm:ss").toStdString() << std::endl;

    //auto second_query_start = std::chrono::high_resolution_clock::now();
        queryString = QString("SELECT * FROM mpi_ds_secondly WHERE time_second = '%1';").arg(timestamp.toString("yyyy-MM-dd HH:mm:ss"));
        //auto second_query_end = std::chrono::high_resolution_clock::now();
        //auto second_duration = std::chrono::duration_cast<std::chrono::seconds>(second_query_end - second_query_start);
        //std::cout << "Zeitdifferenz zweiter Query: " << second_duration.count() << " Sekunden." << std::endl;
        //query.exec("SELECT * FROM mpi_ds_secondly WHERE time_second = (SELECT MAX(time_second) - interval '1 second' FROM mpi_ds_secondly);");*/

    }
    else if(time_display == 1){
        queryString = "SELECT processrank, processorname, communicationtype, SUM(sendDatasize) AS send_ds, SUM(recvDatasize) AS recv_ds FROM mpi_information GROUP BY processorname, processrank, communicationtype ORDER BY processrank ASC";
    }

    query.exec(queryString);
    QList<DataColumn> list;

    while(query.next()) {
        DataColumn dc;
        dc.proc_name = query.value("processorname").toString();
        dc.comm_type = query.value("communicationtype").toString();
        dc.proc_rank = query.value("processrank").toInt();
        dc.recv_datasize = query.value("recv_ds").toLongLong();
        dc.send_datasize = query.value("send_ds").toLongLong();
        list.append(dc);
    }

    emit updateDataReady(list);
        /*QString proc_name = query.value("processorname").toString();
        QStandardItem *processor_item = new QStandardItem(proc_name);
        model->setItem(row, 0, processor_item);

        QString comm_type = query.value("communicationtype").toString();
        QStandardItem *comm_type_item = new QStandardItem(comm_type);
        model->setItem(row, 1, comm_type_item);

        int proc_rank = query.value("processrank").toInt();
        QStandardItem *proc_rank_item = new QStandardItem(proc_rank);
        model->setItem(row, 0, processor_item);

        long recv_datasize = query.value("recv_ds").toLongLong();
        long send_datasize = query.value("send_ds").toLongLong();*/
}
