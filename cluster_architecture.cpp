#include "cluster_architecture.h"
#include "database_thread.h"

Cluster_Architecture::Cluster_Architecture(QObject *parent) : QObject(parent) {

}

Cluster_Architecture::~Cluster_Architecture()
{
    if (database_thread.isRunning()) {
        if (database_thread.isRunning()) {
            // Signal zum Beenden des Threads senden
            m_dbThread->set_thread_running(false);
            emit signalToClearDB();
            database_thread.quit();  // Veranlasst den Thread, die Ereignisschleife zu verlassen
            database_thread.wait();  // Wartet, bis der Thread beendet ist
            delete m_dbThread;
        }
        //delete database_thread;  // Löscht den Thread, nachdem er beendet wurde
        //database_thread = nullptr;
    }
}

void Cluster_Architecture::initialize(QString db_connection, bool live){

    m_connectionName = db_connection;
    m_live_run = live;
}

void Cluster_Architecture::resetCluster_Architecture(){

    if (database_thread.isRunning()) {
        if (database_thread.isRunning()) {
            // Signal zum Beenden des Threads senden
            emit signalToClearDB();
            database_thread.quit();  // Veranlasst den Thread, die Ereignisschleife zu verlassen
            database_thread.wait();  // Wartet, bis der Thread beendet ist
            delete m_dbThread;
        }
        //delete database_thread;  // Löscht den Thread, nachdem er beendet wurde
        //database_thread = nullptr;
    }

    m_componentsBuilt = false;
    m_nodes.clear();
    m_p2p_send_max = 0;
    m_coll_send_max = 0;
    m_p2p_recv_max = 0;
    m_coll_recv_max = 0;
    m_time_display = 0;

    m_start_timestamp = QDateTime();

    m_slurm_id = 0;
    m_proc_num = 0;
    m_status_running=false;
    m_end_time = 0;
}

void Cluster_Architecture::setOption(int opt){
    //std::cout << "setOption" << std::endl;
    m_option = opt;
}

void Cluster_Architecture::startThread(){
    if(!QSqlDatabase::contains(m_connectionName)) {
        qDebug() << "Connection " << m_connectionName << " does not exist.";
        return;
    }
    QString name_helper = "Thread_%1";
    QSqlDatabase db = QSqlDatabase::database(m_connectionName);
    if (!db.isOpen()) {
        qDebug() << "Databaseconnection " << m_connectionName << " is not open";
        return;
    }
    QString thread_connection_name = name_helper.arg(m_slurm_id);

    m_dbThread = new Database_Thread(thread_connection_name, m_slurm_id, m_proc_num, m_live_run);
    m_dbThread->moveToThread(&database_thread);

    qDebug() << "m_proc_num: " << m_proc_num;
    //clone_db.moveToThread(&database_thread);

    //m_dbThread->moveToThread(dbThread);
    Database_Thread::connect(m_dbThread, &Database_Thread::clusterComponentsReady, this, &Cluster_Architecture::buildClusterComponents);
    Database_Thread::connect(this, &Cluster_Architecture::signalToDBConnection, m_dbThread, &Database_Thread::connectToDB);
    Database_Thread::connect(this, &Cluster_Architecture::startDatabaseThread, m_dbThread, &Database_Thread::threadbuildClusterComponents);

    Database_Thread::connect(this, &Cluster_Architecture::signalToUpdateData, m_dbThread, &Database_Thread::updateData);
    Database_Thread::connect(m_dbThread, &Database_Thread::updateDataReady, this, &Cluster_Architecture::updateDataToUI);

    Database_Thread::connect(this, &Cluster_Architecture::signalToClearDB, m_dbThread, &Database_Thread::clearDatabase);
    Database_Thread::connect(m_dbThread, &Database_Thread::dbCleared, this, &Cluster_Architecture::removeClusterComponents);

    Database_Thread::connect(this, &Cluster_Architecture::signalToShowTimestampData, m_dbThread, &Database_Thread::showDataFromTimePeriod);
    Database_Thread::connect(m_dbThread, &Database_Thread::setTimestamp, this, &Cluster_Architecture::handleTimestamp);

    Database_Thread::connect(this, &Cluster_Architecture::waitForEnd, m_dbThread, &Database_Thread::selectEndTimestamp);
    Database_Thread::connect(this, &Cluster_Architecture::end_timeChanged, m_dbThread, &Database_Thread::set_end_timestamp_db);

    Database_Thread::connect(this, &Cluster_Architecture::reset_bottom_bar, m_dbThread, &Database_Thread::reset_actual_timestamp);
    Database_Thread::connect(m_dbThread, &Database_Thread::updateDetailedP2P, &m_detailed_p2p, &Detailed_p2p_data::queryData);
    Database_Thread::connect(m_dbThread, &Database_Thread::updateDetailedColl, &m_detailed_coll, &Detailed_coll_data::queryData);

    Database_Thread::connect(m_dbThread, &Database_Thread::setFunctionsString, this, &Cluster_Architecture::set_mpi_functions);
    Database_Thread::connect(m_dbThread, &Database_Thread::setCommMatrixP2PSend, this, &Cluster_Architecture::set_p2p_send_volume_matrix);
    Database_Thread::connect(m_dbThread, &Database_Thread::setCommMatrixP2PRecv, this, &Cluster_Architecture::set_p2p_recv_volume_matrix);
    Database_Thread::connect(m_dbThread, &Database_Thread::setCommMatrixCollSend, this, &Cluster_Architecture::set_coll_send_volume_matrix);
    Database_Thread::connect(m_dbThread, &Database_Thread::setCommMatrixCollRecv, this, &Cluster_Architecture::set_coll_recv_volume_matrix);

    Database_Thread::connect(m_dbThread, &Database_Thread::setCommMatrixTotalSend, this, &Cluster_Architecture::set_total_send_volume_matrix);


    //database_thread.start();
    database_thread.start();

}

void Cluster_Architecture::buildClusterComponents(const QMap<QString, QVector<int>> &map){
    //std::cout << "componentsBuilt 1!" << std::endl;
    if(m_option!=0){
        std::cout << "m_option NULL Fehler, " << m_option << std::endl;
        return;
    }
    Cluster_Node *node;

    if(map.isEmpty()){
        std::cout << "Build Cluster Compoenents failed!" << std::endl;
    } else{
        QMapIterator<QString, QVector<int>> iter(map);
        while(iter.hasNext()){
            iter.next();
            //std::cout << "Iter-Key: " << iter.key().toStdString() << std::endl;
            node = new Cluster_Node(this, iter.key().toUtf8().constData());
            m_nodes << node;
            for(int i = 0; i<iter.value().length(); i++){
                Cluster_Rank *rank = new Cluster_Rank(node, iter.value()[i]);
                node->addRank(rank);
                //std::cout << rank->getId() << std::endl;
            }
        }
    }
    //if(m_live_run){
        //timerId = startTimer(1000);
    emit signalToUpdateData(m_time_display);
    //}
    emit componentsBuilt();
    //std::cout << "componentsBuilt 2!" << std::endl;
    m_componentsBuilt = true;
}

void Cluster_Architecture::removeClusterComponents(){
    m_nodes.clear();
    timerId = -1;
    std::cout << "Removed Cluster-Components" << std::endl;
}

int Cluster_Architecture::count() const{
    return this->m_nodes.count();
}

long Cluster_Architecture::coll_send_max(){
    return m_coll_send_max;
}
long Cluster_Architecture::p2p_send_max(){
    return m_p2p_send_max;
}

long Cluster_Architecture::coll_recv_max(){
    return m_coll_recv_max;
}
long Cluster_Architecture::p2p_recv_max(){
    return m_p2p_recv_max;
}

long Cluster_Architecture::detailed_p2p_max(){
    return m_detailed_p2p_max;
}

long Cluster_Architecture::detailed_coll_max(){
    return m_detailed_coll_max;
}

long Cluster_Architecture::detailed_total_max(){
    return m_detailed_total_max;
}

int Cluster_Architecture::slurm_id(){
    return m_slurm_id;
}
int Cluster_Architecture::proc_num(){
    return m_proc_num;
}

int Cluster_Architecture::end_time(){
    return m_end_time;
}

int Cluster_Architecture::time_display(){
    return m_time_display;
}

void Cluster_Architecture::set_time_display(int dis){
    m_time_display = dis;
    emit time_displayChanged();
}

void Cluster_Architecture::set_coll_send_max(long max){
    m_coll_send_max = max;
    emit coll_send_max_changed();
}
void Cluster_Architecture::set_p2p_send_max(long max){
    m_p2p_send_max = max;
    emit p2p_send_max_changed();
}

void Cluster_Architecture::set_coll_recv_max(long max){
    m_coll_recv_max = max;
    emit coll_recv_max_changed();
}
void Cluster_Architecture::set_p2p_recv_max(long max){
    m_p2p_recv_max = max;
    emit p2p_recv_max_changed();
}

void Cluster_Architecture::set_detailed_coll_max(long max){
    m_detailed_coll_max = max;
    emit detailed_coll_max_changed();
}


void Cluster_Architecture::set_detailed_p2p_max(long max){
    m_detailed_p2p_max = max;
    emit detailed_p2p_max_changed();
}

void Cluster_Architecture::set_detailed_total_max(long max){
    m_detailed_total_max = max;
    emit detailed_total_max_changed();
}

void Cluster_Architecture::set_slurm_id(int id){
    m_slurm_id = id;
    //qDebug() << "set_slurm_id";
    startThread();
    emit signalToDBConnection();
    emit startDatabaseThread();
}
void Cluster_Architecture::set_proc_num(int proc){
    m_proc_num = proc;
    emit proc_num_changed();
}

void Cluster_Architecture::set_end_time(int time){
    if(time == -1){
        QThread::msleep(2000);
        m_dbThread->set_thread_running(false);
    } else {
        m_end_time = time;
        QDateTime timestamp = m_start_timestamp.addSecs(time);
        emit end_timeChanged(timestamp);
    }
}

void Cluster_Architecture::set_mpi_functions(QString string){
    m_mpi_functions = string;
    emit mpi_functions_changed();
}

QString Cluster_Architecture::mpi_functions(){
    return m_mpi_functions;
}

Cluster_Node* Cluster_Architecture::nodeAt(int index){
    if(index<0 || index>=m_nodes.count()){
        return 0;
    }
    return this->m_nodes[index];
}

QVector<Cluster_Node*> Cluster_Architecture::get_nodeList(){
    return m_nodes;
}

void Cluster_Architecture::updateDataToUI(const QList<DataColumn> &list){

    if(!m_componentsBuilt){
        return;
    }

    for (Cluster_Node *n : m_nodes){
        for(Cluster_Rank *r : n->ranks()){
            r->set_coll_recvDatasize(0);
            r->set_coll_sendDatasize(0);
            r->set_p2p_recvDatasize(0);
            r->set_p2p_sendDatasize(0);

            r->set_p2p_late_sender(0);
            r->set_p2p_late_recvr(0);
            r->set_coll_late_sender(0);
            r->set_coll_late_recvr(0);

            r->set_p2p_timediff(0);
            r->set_coll_timediff(0);
        }
    }
    set_p2p_recv_max(0);
    set_p2p_send_max(0);
    set_coll_send_max(0);
    set_coll_recv_max(0);

    set_detailed_coll_max(0);
    set_detailed_p2p_max(0);

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
            this->m_nodes[index]->rankAt(dc.proc_rank-this->m_nodes[index]->getSmalestRankId())->set_p2p_late_sender(dc.late_sender);
            this->m_nodes[index]->rankAt(dc.proc_rank-this->m_nodes[index]->getSmalestRankId())->set_p2p_late_recvr(dc.late_receiver);
            this->m_nodes[index]->rankAt(dc.proc_rank-this->m_nodes[index]->getSmalestRankId())->set_p2p_timediff(dc.time_diff);
        } else if(dc.comm_type=="collective"){
            if(dc.send_datasize>m_coll_send_max){
                set_coll_send_max(dc.send_datasize);
            }
            if(dc.recv_datasize>m_coll_recv_max){
                set_coll_recv_max(dc.recv_datasize);
            }
            this->m_nodes[index]->rankAt(dc.proc_rank-this->m_nodes[index]->getSmalestRankId())->set_coll_sendDatasize(dc.send_datasize);
            this->m_nodes[index]->rankAt(dc.proc_rank-this->m_nodes[index]->getSmalestRankId())->set_coll_recvDatasize(dc.recv_datasize);
            this->m_nodes[index]->rankAt(dc.proc_rank-this->m_nodes[index]->getSmalestRankId())->set_coll_late_sender(dc.late_sender);
            this->m_nodes[index]->rankAt(dc.proc_rank-this->m_nodes[index]->getSmalestRankId())->set_coll_late_recvr(dc.late_receiver);
            this->m_nodes[index]->rankAt(dc.proc_rank-this->m_nodes[index]->getSmalestRankId())->set_coll_timediff(dc.time_diff);
        } else{
            std::cerr << "The communication_type " << dc.comm_type.toStdString() << " is unknown!" << std::endl;
        }
    }
    return;
}

void Cluster_Architecture::timerEvent(QTimerEvent* event){
    if(m_componentsBuilt){
        //std::cout << "timer:Event, TRUE!" << std::endl;
        emit signalToUpdateData(m_time_display);
    }
    //updateDatasize();
    //emit r
    //std::cout << "Name: " << m_nodes[0]->getName().toStdString() << std::endl;
}

//Functionality for timeline

void Cluster_Architecture::startAndStop(bool start){
    if(!m_componentsBuilt){
        return;
    }
    if(start == true){
        if(timerId != -1){
            std::cout << "Kill Timer" << std::endl;
            killTimer(timerId);
        }
    } else{
        timerId = startTimer(1000);
    }
}

void Cluster_Architecture::handleTimestamp(QDateTime timestamp, bool start){
    QTime qtimeTimestamp;
    int seconds;
    if(start){
        std::cout << "Start-Timestamp: " << timestamp.toString("yyyy-MM-d HH:mm:ss").toStdString() << std::endl;
        m_start_timestamp = timestamp;
    } else {
        std::cout << "End-Timestamp: " << timestamp.toString("yyyy-MM-d HH:mm:ss").toStdString() << std::endl;
    }
    qtimeTimestamp = timestamp.time();
    QTime midnight;
    midnight.setHMS(0,0,0);
    seconds = midnight.secsTo(qtimeTimestamp);
    emit dataIn(seconds, qtimeTimestamp, start);
}

void Cluster_Architecture::showConditionAt(int timeSecondsA, int timeSecondsB){
    QDateTime timestampA, timestampB;
    if(m_time_display == 0){
        timestampA = m_start_timestamp.addSecs(timeSecondsA);
        timestampB = m_start_timestamp.addSecs(timeSecondsB);
    } else if (m_time_display == 1) {
        timestampA = m_start_timestamp;
        timestampB = m_start_timestamp.addSecs(timeSecondsB);
    }
    //std::cout << "Timestamp A: " << timestampA.toString("hh:mm:ss").toStdString() << std::endl;
    //std::cout << "Timestamp B: " << timestampB.toString("hh:mm:ss").toStdString() << std::endl;
    emit signalToShowTimestampData(timestampA, timestampB);
}

Detailed_p2p_data* Cluster_Architecture::detailedP2P() {
    return &m_detailed_p2p;
}

Detailed_coll_data* Cluster_Architecture::detailedColl() {
    return &m_detailed_coll;
}

//Methods for detailed matrices

QVector<QVector<long>> Cluster_Architecture::p2p_send_volume_matrix() const{
    return m_p2p_send_volume_matrix;
}

void Cluster_Architecture::set_p2p_send_volume_matrix(QVector<QVector<long>> matrix){
    m_p2p_send_volume_matrix = matrix;
    emit p2p_send_volume_matrix_changed();
}

QVector<QVector<long>> Cluster_Architecture::p2p_recv_volume_matrix() const{
    return m_p2p_recv_volume_matrix;
}

void Cluster_Architecture::set_p2p_recv_volume_matrix(QVector<QVector<long>> matrix){
    m_p2p_recv_volume_matrix = matrix;
    emit p2p_recv_volume_matrix_changed();
}

QVector<QVector<long>> Cluster_Architecture::coll_send_volume_matrix() const{
    return m_coll_send_volume_matrix;
}

void Cluster_Architecture::set_coll_send_volume_matrix(QVector<QVector<long>> matrix){
    m_coll_send_volume_matrix = matrix;
    emit coll_send_volume_matrix_changed();


}

QVector<QVector<long>> Cluster_Architecture::coll_recv_volume_matrix() const{
    return m_coll_recv_volume_matrix;
}

void Cluster_Architecture::set_coll_recv_volume_matrix(QVector<QVector<long>> matrix){
    m_coll_recv_volume_matrix = matrix;
    emit coll_recv_volume_matrix_changed();
}

QVector<QVector<long>> Cluster_Architecture::total_send_volume_matrix() const{
    return m_total_send_volume_matrix;
}

void Cluster_Architecture::set_total_send_volume_matrix(QVector<QVector<long>> matrix){
    m_total_send_volume_matrix = matrix;
    calculateDetailedMatricesMaxAndAvg();
    emit total_send_volume_matrix_changed();
}

QVector<QVector<long>> addMatrices(const QVector<QVector<long>>& matrixA,
                                   const QVector<QVector<long>>& matrixB)
{
    if (matrixA.size() != matrixB.size())
        throw std::invalid_argument("Matrix dimensions do not match (rows).");

    QVector<QVector<long>> result;
    result.reserve(matrixA.size());

    for (int i = 0; i < matrixA.size(); ++i) {
        if (matrixA[i].size() != matrixB[i].size())
            throw std::invalid_argument("Matrix dimensions do not match (columns).");

        QVector<long> row;
        row.reserve(matrixA[i].size());

        for (int j = 0; j < matrixA[i].size(); ++j) {
            row.append(matrixA[i][j] + matrixB[i][j]);
        }
        result.append(std::move(row));
    }

    return result;
}

//Calculate Maximum and Average of detailed matrices
void Cluster_Architecture::calculateDetailedMatricesMaxAndAvg() {
    m_detailed_p2p_max = 0;
    m_detailed_coll_max = 0;
    m_detailed_total_max = 0;

    m_detailed_p2p_avg = 0;
    m_detailed_coll_avg = 0;
    m_detailed_total_avg = 0;

    for (const auto& row : m_p2p_send_volume_matrix) {
        for (const auto& value : row) {
            if (value > m_detailed_p2p_max) {
                m_detailed_p2p_max = value;
            }
            m_detailed_p2p_avg += value;
        }
    }

    for (const auto& row : m_coll_send_volume_matrix) {
        for (const auto& value : row) {
            if (value > m_detailed_coll_max) {
                m_detailed_coll_max = value;
            }
            m_detailed_coll_avg += value;
        }
    }

    for (const auto& row : m_total_send_volume_matrix) {
        for (const auto& value : row) {
            if (value > m_detailed_total_max) {
                m_detailed_total_max = value;
            }
            m_detailed_total_avg += value;
        }
    }

    int totalElementsP2P = m_proc_num * m_proc_num;
    int totalElementsColl = m_proc_num * m_proc_num;
    int totalElementsTotal = m_proc_num * m_proc_num;

    if (totalElementsP2P > 0)
        m_detailed_p2p_avg /= totalElementsP2P;

    if (totalElementsColl > 0)
        m_detailed_coll_avg /= totalElementsColl;

    if (totalElementsTotal > 0)
        m_detailed_total_avg /= totalElementsTotal;

    emit detailed_p2p_max_changed();
    emit detailed_coll_max_changed();
    emit detailed_total_max_changed();
}



