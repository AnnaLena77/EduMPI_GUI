#include "database_connection.h"
#include "database_thread.h"
#include "qevent.h"
#include "ranks_instances.h"
#include "cluster_node.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <QProcess>
#include <QFile>
#include <qdatetime.h>

#include <unistd.h>


Database_Connection::Database_Connection(QObject *parent) : QObject(parent)
{
    Database_Thread *dbt = new Database_Thread;
    dbt->moveToThread(&database_thread);
    Database_Thread::connect(&database_thread, &QThread::finished, dbt, &QObject::deleteLater);
    Database_Thread::connect(this, &Database_Connection::signalToConnect, dbt, &Database_Thread::connectToDB);
    Database_Thread::connect(dbt, &Database_Thread::connectedToDB, this, &Database_Connection::dbConnectionSuccessful);

    Database_Thread::connect(this, &Database_Connection::signalToBuildComponents, dbt, &Database_Thread::threadbuildClusterComponents);
    Database_Thread::connect(dbt, &Database_Thread::clusterComponentsReady, this, &Database_Connection::buildClusterComponents);

    Database_Thread::connect(this, &Database_Connection::signalToUpdateData, dbt, &Database_Thread::updateData);
    Database_Thread::connect(dbt, &Database_Thread::updateDataReady, this, &Database_Connection::updateDataToUI);

    database_thread.start();
}

void Database_Connection::dbConnectionSuccessful(const bool &success){
    std::cout << "Hello from dbConnectionSuccessful Signal : " << success << std::endl;
    m_connection_ready = true;

}

void Database_Connection::connect(QString hostname, QString databasename, int port, QString username, QString password){
    signalToConnect(hostname, databasename, port, username, password);
}

void Database_Connection::buildClusterComponents(const QMap<QString, QVector<int>> &map){
    Cluster_Node *node;

    if(map.isEmpty()){
        std::cout << "FAILED!" << std::endl;
    } else{
        QMapIterator<QString, QVector<int>> iter(map);
        while(iter.hasNext()){
            iter.next();
            //std::cout << iter.key().toStdString() << std::endl;
            node = new Cluster_Node(this, iter.key().toUtf8().constData());
            m_nodes << node;
            for(int i = 0; i<iter.value().length(); i++){
                Cluster_Rank *rank = new Cluster_Rank(node, iter.value()[i]);
                node->addRank(rank);
                //std::cout << rank->getId() << std::endl;
            }
        }
    }
    timerId = startTimer(1000);
    m_componentsBuilt = true;
}

Database_Connection::~Database_Connection()
{
    database_thread.quit();
    database_thread.wait();
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


void Database_Connection::updateDataToUI(const QList<DataColumn> &list){


    for (Cluster_Node *n : m_nodes){
            for(Cluster_Rank *r : n->ranks()){
                r->set_coll_recvDatasize(0);
                r->set_coll_sendDatasize(0);
                r->set_p2p_recvDatasize(0);
                r->set_p2p_sendDatasize(0);
            }
    }
    set_p2p_recv_max(0);
    set_p2p_send_max(0);
    set_coll_send_max(0);
    set_coll_recv_max(0);

    QString name = m_nodes[0]->getName();
    int index = 0;

    for(int i = 0; i<list.count(); i++){
        DataColumn dc = list[i];
        if(name != dc.proc_name){
                //std::cout << "test" << std::endl;
            for(int i=0; i<this->m_nodes.count(); i++){
                if (this->m_nodes[i]->getName()==dc.proc_name){
                    name = dc.proc_name;
                    index = i;
                    break;
                }
            }
        }
        if(dc.comm_type=="p2p"){
            if(dc.send_datasize>m_p2p_send_max){
                set_p2p_send_max(dc.send_datasize);
            }
            if(dc.recv_datasize>m_p2p_recv_max){
                set_p2p_recv_max(dc.recv_datasize);
            }
            this->m_nodes[index]->rankAt(dc.proc_rank-this->m_nodes[index]->getSmalestRankId())->set_p2p_sendDatasize(dc.send_datasize);
            this->m_nodes[index]->rankAt(dc.proc_rank-this->m_nodes[index]->getSmalestRankId())->set_p2p_recvDatasize(dc.recv_datasize);
        } else if(dc.comm_type=="collective"){
            if(dc.send_datasize>m_coll_send_max){
                set_coll_send_max(dc.send_datasize);
            }
            if(dc.recv_datasize>m_coll_recv_max){
                set_coll_recv_max(dc.recv_datasize);
            }
            this->m_nodes[index]->rankAt(dc.proc_rank-this->m_nodes[index]->getSmalestRankId())->set_coll_sendDatasize(dc.send_datasize);
            this->m_nodes[index]->rankAt(dc.proc_rank-this->m_nodes[index]->getSmalestRankId())->set_coll_recvDatasize(dc.recv_datasize);
        } else{
        std::cerr << "The communication_type " << dc.comm_type.toStdString() << " is unknown!" << std::endl;
        }
    }
    return;
}

void Database_Connection::timerEvent(QTimerEvent* event){
    signalToUpdateData(m_time_display);
    //updateDatasize();
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
        scriptFile << "SSH_COMMAND=\"cd eduMPI_files; $'$EDUMPI_PATH'/bin/mpicc -o $LOCAL_NAME $LOCAL_NAME.c; time '$EDUMPI_PATH'/bin/mpirun -np $PROCESSOR_COUNT --map-by :PE=2 --hostfile /etc/mpi/hosts ./$LOCAL_NAME\"\n";

        scriptFile << "ssh \"$REMOTE_USER@$REMOTE_HOST\" \"$SSH_COMMAND\"";

        scriptFile << "\nexec bash";

        scriptFile.close();
    }
}

QString Database_Connection::readBash(){
    const char *homeDir = getenv("HOME");
    QString filePath = QString(homeDir) + "/skript.sh";

    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Fehler beim Öffnen der Datei";
        //return "0";
    }
    QTextStream in(&file);
    QString fileContent = in.readAll();
    file.close();
    return fileContent;
}

void Database_Connection::writeBash(QString content){
    const char *homeDir = getenv("HOME");
    QString filePath = QString(homeDir) + "/skript.sh";

    QFile file(filePath);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "Fehler beim Öffnen der Datei";
        //return "0";
    }
    else {
        QTextStream stream(&file);
        stream<<content;
        file.close();
    }
}

void Database_Connection::startBash(int proc_num){
    signalToBuildComponents(proc_num);
    std::cout << "StartBash" << std::endl;
    QString homedir = getenv("HOME");
    QString dir = homedir + "/skript.sh";
    QProcess process;

    process.setProgram("gnome-terminal");
    process.setArguments(QStringList() << "--" << dir << QString::number(proc_num));

    process.startDetached();
}

void Database_Connection::closeApp(){
    /*std::cout << db.isOpen() << std::endl;
    if(m_connection_ready){
        QSqlQuery query;
        query.exec("DELETE FROM cluster_information;");
        sleep(1);
        query.exec("CALL refresh_continuous_aggregate('mpi_ds_secondly', NULL, NULL);");
        query.exec("DELETE FROM mpi_information;");
    }
    db.close();*/
}
