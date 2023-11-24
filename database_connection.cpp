#include "database_connection.h"
#include "ranks_instances.h"
#include "cluster_node.h"
#include <QSqlDatabase>
#include <iostream>
#include <qsqlquery.h>

#include <unistd.h>

QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

Database_Connection::Database_Connection(QObject *parent) : QObject(parent)
{
    db.setHostName("10.35.8.10");
    db.setDatabaseName("tsdb");
    db.setUserName("postgres");
    db.setPassword("postgres");
    bool ok = db.open();

    timerId = startTimer(1000);
    std::cout << "New Connection" << std::endl;
    buildClusterComponents();
}

void Database_Connection::buildClusterComponents(){
    std::cout << "New Cluster Components" << std::endl;
    QSqlQuery query;
    QString name = "";
    Cluster_Node* node;
    query.exec("SELECT * FROM cluster_information ORDER BY processorname, rank");
    /*while(query.next()==false){
        usleep(200);
        query.exec("SELECT * FROM cluster_information ORDER BY processorname, rank");
    }*/
    while(query.next()) {
        QString actual_name = query.value("processorname").toString();
        if(actual_name!=name){
            name = actual_name;
            node = new Cluster_Node(this, name.toUtf8().constData());
            m_nodes << node;
        }
        int actual_rank = query.value("rank").toInt();
        Cluster_Rank *rank = new Cluster_Rank(node, actual_rank);
        node->addRank(rank);
    }

    m_componentsBuilt = true;
}

Database_Connection::~Database_Connection()
{
    //qDebug() << "Hier wird die Database gelöscht!";
    //qDeleteAll(m_nodes);
    //m_nodes.clear();
}

int Database_Connection::count() const{
    return this->m_nodes.count();
}

Cluster_Node* Database_Connection::nodeAt(int index){
    if(index<0 || index>=m_nodes.count()){
        return 0;
    }
    return this->m_nodes[index];
}

QVector<Cluster_Node*> Database_Connection::get_nodeList(){
    return m_nodes;
}


void Database_Connection::updateDatasize(){
    if(!m_componentsBuilt){
        return;
    }
    QSqlQuery query;
    query.exec("SELECT processrank, processorname, communicationtype, SUM(sendDatasize) AS sum_send_ds, SUM(recvDatasize) AS sum_recv_ds FROM mpi_information GROUP BY processorname, processrank, communicationtype ORDER BY processrank ASC");
    QString name = this->m_nodes[0]->getName();
    int index = 0;

    while(query.next()) {
        QString proc_name = query.value("processorname").toString();
        QString comm_type = query.value("communicationtype").toString();
        int proc_rank = query.value("processrank").toInt();
        long recv_datasize = query.value("sum_recv_ds").toLongLong();
        long send_datasize = query.value("sum_send_ds").toLongLong();

        if(name != proc_name){
            //std::cout << "test" << std::endl;
            for(int i=0; i<this->m_nodes.count(); i++){
                if (this->m_nodes[i]->getName()==proc_name){
                    name = proc_name;
                    index = i;
                    break;
                }
            }
        }
        //std::cout << "Index: " << index << " Datasize: " << datasize <<" Position " << proc_rank-this->m_nodes[index]->getSmalestRankId() << std::endl;
        if(comm_type=="p2p"){
            if(send_datasize>m_p2p_send_max){
                m_p2p_send_max = send_datasize;
            }
            this->m_nodes[index]->rankAt(proc_rank-this->m_nodes[index]->getSmalestRankId())->set_p2p_sendDatasize(send_datasize);
            this->m_nodes[index]->rankAt(proc_rank-this->m_nodes[index]->getSmalestRankId())->set_p2p_recvDatasize(recv_datasize);
        } else if(comm_type=="collective"){
            if(send_datasize>m_coll_send_max){
                m_coll_send_max = send_datasize;
            }
            this->m_nodes[index]->rankAt(proc_rank-this->m_nodes[index]->getSmalestRankId())->set_coll_sendDatasize(send_datasize);
            this->m_nodes[index]->rankAt(proc_rank-this->m_nodes[index]->getSmalestRankId())->set_coll_recvDatasize(recv_datasize);
        } else{
        std::cerr << "The communication_type " << comm_type.toStdString() << " is unknown!" << std::endl;
        }
    }
    return;
}

void Database_Connection::timerEvent(QTimerEvent* event){
    updateDatasize();
    //emit r
    //std::cout << "Name: " << m_nodes[0]->getName().toStdString() << std::endl;
}
