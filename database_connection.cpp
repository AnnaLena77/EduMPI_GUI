#include "database_connection.h"
#include "ranks_instances.h"
#include "cluster_node.h"
#include <QSqlDatabase>
#include <iostream>
#include <qsqlquery.h>
#include <fstream>
#include <iostream>
#include <QProcess>

#include <unistd.h>

QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

Database_Connection::Database_Connection(QObject *parent) : QObject(parent)
{
    //buildClusterComponents();
}

void Database_Connection::connect(QString hostname, QString databasename, int port, QString username, QString password){
    db.setHostName(hostname);
    db.setPort(port);
    db.setDatabaseName(databasename);
    db.setUserName(username);
    db.setPassword(password);
    bool ok = db.open();
    m_connection_ready = true;

    std::cout << "New Connection" << std::endl;
}

void Database_Connection::buildClusterComponents(int proc_num){
    std::cout << "New Cluster Components" << std::endl;
    QSqlQuery query;
    QString name = "";
    Cluster_Node* node;
    query.exec("SELECT * FROM cluster_information ORDER BY processorname, rank");
    while(query.size()<proc_num){
        query.exec("SELECT * FROM cluster_information ORDER BY processorname, rank");
    }
    while(query.next()) {
        QString actual_name = query.value("processorname").toString();
        if(actual_name!=name){
            std::cout << "Name:" << actual_name.toStdString() << std::endl;
            name = actual_name;
            node = new Cluster_Node(this, name.toUtf8().constData());
            m_nodes << node;
        }
        int actual_rank = query.value("rank").toInt();
        Cluster_Rank *rank = new Cluster_Rank(node, actual_rank);
        node->addRank(rank);
    }
    timerId = startTimer(1000);
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

long Database_Connection::coll_send_max(){
    return m_coll_send_max;
}
long Database_Connection::p2p_send_max(){
    return m_p2p_send_max;
}

long Database_Connection::coll_recv_max(){
    return m_coll_recv_max;
}
long Database_Connection::p2p_recv_max(){
    return m_p2p_recv_max;
}

void Database_Connection::set_coll_send_max(long max){
    m_coll_send_max = max;
}
void Database_Connection::set_p2p_send_max(long max){
    m_p2p_send_max = max;
}

void Database_Connection::set_coll_recv_max(long max){
    m_coll_recv_max = max;
}
void Database_Connection::set_p2p_recv_max(long max){
    m_p2p_recv_max = max;
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

    QString name = m_nodes[0]->getName();
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
                set_p2p_send_max(send_datasize);
            }
            if(recv_datasize>m_p2p_recv_max){
                set_p2p_recv_max(recv_datasize);
            }
            this->m_nodes[index]->rankAt(proc_rank-this->m_nodes[index]->getSmalestRankId())->set_p2p_sendDatasize(send_datasize);
            this->m_nodes[index]->rankAt(proc_rank-this->m_nodes[index]->getSmalestRankId())->set_p2p_recvDatasize(recv_datasize);
        } else if(comm_type=="collective"){
            if(send_datasize>m_coll_send_max){
                set_coll_send_max(send_datasize);
            }
            if(recv_datasize>m_coll_recv_max){
                set_coll_recv_max(recv_datasize);
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

void Database_Connection::createBashSkript(QString host, QString username, QString edumpi_path, QString local_path, QString local_name, bool file){
    const char *homeDir = getenv("HOME");
    std::string filePath = std::string(homeDir) + "/skript.sh";

    if(local_name.endsWith(".c")){
        local_name.chop(2);
    }
    if(local_path.startsWith("file:///")){
        local_path.remove(0,7);
    }
    std::ofstream scriptFile(filePath);
    if(scriptFile.is_open()){
        scriptFile << "#!/bin/bash\n";
        scriptFile << "REMOTE_HOST=\"" + host.toStdString() + "\"\n";
        scriptFile << "REMOTE_USER=\"" + username.toStdString() + "\"\n";
        scriptFile << "REMOTE_DIR=\"/home/$REMOTE_USER\"\n";
        scriptFile << "EDUMPI_PATH=\"" + edumpi_path.toStdString() + "\"\n";
        scriptFile << "LOCAL_PATH=\"" + local_path.toStdString() + "\"\n";
        scriptFile << "LOCAL_NAME=\"" + local_name.toStdString() + "\"\n";
        scriptFile << "PROCESSOR_COUNT=\"$1\"\n";
        if(file){
            scriptFile << "scp \"$LOCAL_PATH\" \"$REMOTE_USER@$REMOTE_HOST:$REMOTE_DIR/eduMPI_files/\"\n";
        } else {
            scriptFile << "scp -r \"$LOCAL_PATH\" \"$REMOTE_USER@$REMOTE_HOST:$REMOTE_DIR/eduMPI_files/\"\n";
        }
        scriptFile << "SSH_COMMAND=\"cd eduMPI_files; $'$REMOTE_DIR''$EDUMPI_PATH'/bin/mpicc -o $LOCAL_NAME $LOCAL_NAME.c; time '$REMOTE_DIR''$EDUMPI_PATH'/bin/mpirun -np $PROCESSOR_COUNT --map-by :PE=2 --hostfile /etc/mpi/hosts ./$LOCAL_NAME\"\n";

        scriptFile << "ssh \"$REMOTE_USER@$REMOTE_HOST\" \"$SSH_COMMAND\"";

        scriptFile << "\nexec bash";

        scriptFile.close();
    }
}

void Database_Connection::startBash(int proc_num){
    std::cout << "StartBash" << std::endl;
    QString homedir = getenv("HOME");
    QString dir = homedir + "/skript.sh";
    QProcess process;

    process.setProgram("gnome-terminal");
    process.setArguments(QStringList() << "--" << dir << QString::number(proc_num));

    process.startDetached();
}

void Database_Connection::closeApp(){
    std::cout << db.isOpen() << std::endl;
    if(m_connection_ready){
        QSqlQuery query;
        query.exec("DELETE FROM cluster_information;");
        query.exec("DELETE FROM mpi_information;");
    }
    db.close();
}
