#include "database_connection.h"
#include "bash_process_manager.h"
#include "database_thread.h"
#include "qevent.h"
#include "qsqlquery.h"
#include "ranks_instances.h"
#include "cluster_node.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <QProcess>
#include <QFile>
#include <qdatetime.h>
#include <QMetaObject>

#include <unistd.h>
#include <csignal>
#include <sys/stat.h>


Database_Connection::Database_Connection(QObject *parent) : QObject(parent)
{
    Database_Thread *dbt = new Database_Thread;
    slurm_process = new Bash_Process_Manager;

    dbt->moveToThread(&database_thread);

    QObject::connect(slurm_process, &Bash_Process_Manager::slurmIdReady, dbt, &Database_Thread::getSlurmId);
    QObject::connect(slurm_process, &Bash_Process_Manager::slurmIdReady, this, &Database_Connection::getSlurmID);
    QObject::connect(slurm_process, &Bash_Process_Manager::slurm_status_changed, this, &Database_Connection::slurm_status_changed);

    Database_Thread::connect(&database_thread, &QThread::finished, dbt, &QObject::deleteLater);
    Database_Thread::connect(this, &Database_Connection::signalToConnect, dbt, &Database_Thread::connectToDB);
    Database_Thread::connect(dbt, &Database_Thread::connectedToDB, this, &Database_Connection::dbConnectionSuccessful);

    Database_Thread::connect(this, &Database_Connection::setProcNum, dbt, &Database_Thread::getProcNum);
    Database_Thread::connect(dbt, &Database_Thread::clusterComponentsReady, this, &Database_Connection::buildClusterComponents);

    Database_Thread::connect(this, &Database_Connection::signalToUpdateData, dbt, &Database_Thread::updateData);
    Database_Thread::connect(dbt, &Database_Thread::updateDataReady, this, &Database_Connection::updateDataToUI);

    Database_Thread::connect(this, &Database_Connection::signalToClearDB, dbt, &Database_Thread::clearDatabase);
    Database_Thread::connect(dbt, &Database_Thread::dbCleared, this, &Database_Connection::removeClusterComponents);

    Database_Thread::connect(this, &Database_Connection::signalToShowTimestampData, dbt, &Database_Thread::showDataFromTimePeriod);

    Database_Thread::connect(dbt, &Database_Thread::setTimestamp, this, &Database_Connection::handleTimestamp);

    database_thread.start();
}

void Database_Connection::dbConnectionSuccessful(const bool &success){
    std::cout << "Hello from dbConnectionSuccessful Signal : " << success << std::endl;
    m_connection_ready = true;
    emit connectionSignal(success);

}

void Database_Connection::connect(QString hostname, QString databasename, int port, QString username, QString password){
    char tempFileTemplate[] = "/tmp/XXXXXX.env";
    std::cout << "Temp file template: " << tempFileTemplate << std::endl;
    int fd = mkstemps(tempFileTemplate, 4);
    m_envFilePath = tempFileTemplate;
    if (fd == -1) {
        std::cerr << "Failed to create temporary file: " << strerror(errno) << std::endl;
        return;
    }
    close(fd);

    std::cout << "Temporary file created: " << m_envFilePath << std::endl;

    std::ofstream tempFile(m_envFilePath,  std::ofstream::trunc);
    if (!tempFile.is_open()) {
        std::cerr << "Failed to open temporary file for writing: " << strerror(errno) << std::endl;
        return;
    }

    tempFile << "DB_HOST=" << hostname.toStdString() << "\n";
    tempFile << "DB_NAME=" << databasename.toStdString() << "\n";
    tempFile << "DB_PORT=" << port << "\n";
    tempFile << "DB_USER=" << username.toStdString() << "\n";
    tempFile << "DB_PW=" << password.toStdString() << "\n";

    emit signalToConnect(hostname, databasename, port, username, password);
}

void Database_Connection::buildClusterComponents(const QMap<QString, QVector<int>> &map){
    if(m_option!=0){
        return;
    }
    Cluster_Node *node;

    if(map.isEmpty()){
        std::cout << "FAILED!" << std::endl;
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
    timerId = startTimer(1000);
    emit componentsBuilt();
    m_componentsBuilt = true;
}

void Database_Connection::removeClusterComponents(){
    m_nodes.clear();
    timerId = -1;
    std::cout << "Removed Cluster-Components" << std::endl;
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

     //std::cout << "Update Database" << std::endl;

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

void Database_Connection::timerEvent(QTimerEvent* event){
    if(m_componentsBuilt){
        //std::cout << "timer:Event, TRUE!" << std::endl;
        emit signalToUpdateData(m_time_display);
    }
    //updateDatasize();
    //emit r
    //std::cout << "Name: " << m_nodes[0]->getName().toStdString() << std::endl;
}

void Database_Connection::copyOutputFile(){
    QProcess proc;
    const char *homeDir = getenv("HOME");
    QString filePath = QString(homeDir);

    QString sshCommand = QString("scp %1@%2:%3/slurm-%4.out %5").arg(m_cluster_ident, m_cluster_address, m_remote_dir_bash, QString::number(m_slurm_id), filePath);
    std::cout << sshCommand.toStdString() << std::endl;

    proc.start("bash", QStringList() << "-c" << sshCommand);

    // Warten, bis der Prozess gestartet ist
    if (!proc.waitForStarted()) {
        proc.kill();
        //return "Error! The SSH process could not be started. Please check all details and your network connection. A VPN connection may be necessary. Restart the application.";
    }

    // Warten, bis der Prozess beendet ist
    if (!proc.waitForFinished()) {
        proc.kill();
        //return "Error! The SSH process could not be started. Please check all details and your network connection. A VPN connection may be necessary. Restart the application.! ";
    }
    QString outputPath = filePath + "/slurm-" + QString::number(m_slurm_id) + ".out";
    emit copiedOutputFile(outputPath);
}

QString Database_Connection::connectCluster(const QString &address, const QString &ident, const QString &path){

//QString Database_Connection::connectCluster(QString &address, QString &ident, QString &path){
    m_cluster_address = address;
    m_cluster_ident = ident;
    m_cluster_eduMPI_path = path;

    QString filePath = "/home/" + ident + "/eduMPI_files/tmp/";

    QProcess process;

    QString sshCommand = QString("ssh %1@%2 '[ -d \"%3\" ] && echo \"exists\" || echo \"not exist\"; [ -d \"%4\" ] || mkdir -p \"%4\"'").arg(ident, address, path, filePath);

    // Starten des SSH-Befehls
    process.start("bash", QStringList() << "-c" << sshCommand);

    // Warten, bis der Prozess gestartet ist
    if (!process.waitForStarted()) {
        process.kill();
        return "Error! The SSH process could not be started. Please check all details and your network connection. A VPN connection may be necessary. Restart the application.";
    }

    // Warten, bis der Prozess beendet ist
    if (!process.waitForFinished()) {
        process.kill();
        //return "Error! The SSH process could not be started. Please check all details and your network connection. A VPN connection may be necessary. Restart the application.! ";
    }

    // Ausgabe des Prozesses lesen
    QString output = process.readAllStandardOutput().trimmed();
    QString errorOutput = process.readAllStandardError().trimmed();

    // Überprüfen, ob der Pfad existiert
    if (output == "exists") {
        process.kill();
        m_cluster_connection_ready = true;
        return "Success! An SSH connection could be established and an EduMPI version exists under the specified path.";
    } else if (output == "not exist") {
        process.kill();
        m_cluster_connection_ready = false;
        return "Error! No EduMPI version could be found under the specified path.";
    } else {
        if (!errorOutput.isEmpty()) {
            qDebug() << "Fehlerausgabe:" << errorOutput;
            process.kill();
            if(errorOutput.startsWith("ssh: connect to host")){
                m_cluster_connection_ready = false;
                return "Error! The specified host cannot be reached. Check your network connection. It may be necessary to establish a VPN connection.";
            } else if(errorOutput.startsWith("ssh: Could not resolve hostname")){
                m_cluster_connection_ready = false;
                return "Error! There seems to be something wrong with your host information. Please check the name or IP address.";
            }
            m_cluster_connection_ready = false;
            return "Error! There seems to be a problem with your ID. Before you can start an MPI application, you must generate an SSH key once for passwordless communication. Follow the instructions under: \nHelp > SSH-Key-Gen Guide.";
        }
        process.kill();
        m_cluster_connection_ready = false;
        return "Error! An error has occurred. Please check all details and your network connection. A VPN connection may be necessary.";
    }

    // Überprüfen auf Fehler
}

void Database_Connection::connectClusterAsync(const QString &address, const QString &ident, const QString &path, QJSValue callback){
    QtConcurrent::run([=]() {
        QString result = connectCluster(address, ident, path);

        // Ensure the callback is invoked in the main thread
        QMetaObject::invokeMethod(this, [=]() {
                callback.call(QJSValueList() << result);
            }, Qt::QueuedConnection);
    });
}

void Database_Connection::writeLocalBashFile(QString local_path, bool file, int proc_num){
    //m_visualization = visualization;

    if(m_componentsBuilt){
        removeClusterComponents();
        m_componentsBuilt = false;
        std::cout << "Nach Start der Bash: False!" << std::endl;
        emit signalToClearDB();
    }
    emit setProcNum(proc_num);

    if(local_path.startsWith("file:///")){
        local_path.remove(0,7);
    }

    QProcess bash_proc;
    QString resourcePath;
    if(m_option != 2){
        resourcePath = ":/bash_files/local_bash_skript.sh";
    } else {
        resourcePath = ":/bash_files/local_bash_skript_scorep.sh";
    }

    // Temporäre Datei erstellen
    QFile f(resourcePath);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Fehler beim Öffnen der Ressource.";
        return;
    }

    QString tempFilePath = QDir::temp().absoluteFilePath("temp_bash_script.sh");
    std::cout << "TempFile: " << tempFilePath.toStdString() << std::endl;
    QFile tempFile(tempFilePath);

    if (!tempFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Fehler beim Erstellen der temporären Datei.";
        return;
    }

    int lineNumber = 0;

    QTextStream in(&f);
    QTextStream out(&tempFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        lineNumber++;
        out << line << "\n";
        if(lineNumber == 9) {
            if(file){
                out << "scp " + local_path + " \"$REMOTE_USER@$REMOTE_HOST:$REMOTE_DIR/\"\n";
                out << "scp " + m_remote_bash_path + " \"$REMOTE_USER@$REMOTE_HOST:$REMOTE_DIR/\"\n";
                out << "scp " + QString::fromStdString(m_envFilePath) + " \"$REMOTE_USER@$REMOTE_HOST:$REMOTE_DIR/tmp/\"\n";
                m_remote_dir_bash = "/home/" + m_cluster_ident + "/eduMPI_files";
            } else{
                out << "mkdir " + local_path  + "/tmp\n";
                out << "scp -r " + local_path + " \"$REMOTE_USER@$REMOTE_HOST:$REMOTE_DIR/\"\n";
                int lastSlashIndex = local_path.lastIndexOf("/");
                QString dir_name = local_path.mid(lastSlashIndex + 1);
                out << "scp " + m_remote_bash_path + " \"$REMOTE_USER@$REMOTE_HOST:$REMOTE_DIR/" + "\"\n";
                out << "scp " + QString::fromStdString(m_envFilePath) + " \"$REMOTE_USER@$REMOTE_HOST:$REMOTE_DIR/tmp/\"\n";
                m_remote_dir_bash = "/home/" + m_cluster_ident + "/eduMPI_files/" + dir_name;
            }
        }
    }

    f.close();
    tempFile.close();

    // Ausführungsrechte für die temporäre Datei setzen
    tempFile.setPermissions(tempFile.permissions() | QFile::ExeUser);

    slurm_process->startProcess(QStringList() << "--" << tempFilePath << m_cluster_ident << m_cluster_address << m_remote_dir_bash << "remote_bash_eduMPI.sh" );
}

bool Database_Connection::checkFile(QString source, QString program, bool file){
    if(source.startsWith("file:///")){
        source.remove(0,7);
    }
    if(file){
        if(source.endsWith(".c")){
            QFile fileA(source);
            if(!fileA.exists()){
                return false;
            }
            int slashIndex = source.lastIndexOf('/');
            QString trimmedSource = source.left(slashIndex);

            if(!program.endsWith(".c")){
                program += ".c";
            }

            trimmedSource = trimmedSource + "/" + program;
            QFile fileB(trimmedSource);
            if(!fileB.exists()){
                return false;
            }
        } else {
            return false;
        }
    } else {
        if(!source.endsWith("/")){
            source += "/";
        }
        if(!program.endsWith(".c")){
            program += ".c";
        }
        source += program;
        QFile fileA(source);
        if(!fileA.exists()){
            return false;
        }
    }
    return true;
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
    if(m_componentsBuilt){
        removeClusterComponents();
        m_componentsBuilt = false;
        std::cout << "Nach Start der Bash: False!" << std::endl;
        emit signalToClearDB();
    }
    //emit signalToBuildComponents(proc_num);
    std::cout << "StartBash" << std::endl;
    QString homedir = getenv("HOME");
    QString dir = homedir + "/skript.sh";
    chmod(dir.toStdString().c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
    QProcess process;

    process.setProgram("gnome-terminal");
    process.setArguments(QStringList() << "--" << dir << QString::number(proc_num));

    process.startDetached();
}

void Database_Connection::writeRemoteBashFile(QString program_name, int proc_num, int option){
    m_option = option;

    const char *homeDir = getenv("HOME");
    QString filePath = QString::fromUtf8(homeDir)  + "/remote_bash_eduMPI.sh";
    m_remote_bash_path = filePath;


    if(program_name.endsWith(".c")){
        program_name.chop(2);
    }

    std::ofstream scriptFile(filePath.toStdString());
    if(scriptFile.is_open()){
        scriptFile << "#!/usr/bin/env bash\n";
        scriptFile << "#SBATCH --partition=all\n";
        scriptFile << "#SBATCH --ntasks=" << proc_num << "\n";
        scriptFile << "#SBATCH --job-name=eduMPI\n";
        if(option == 0){
            scriptFile << "#SBATCH --cpus-per-task=2\n\n";
        } else {
            scriptFile << "#SBATCH --cpus-per-task=1\n\n";
        }

        if(option == 0){
            scriptFile << "source ." << m_envFilePath << "\n";
            scriptFile << "export $(cut -d= -f1 ." << m_envFilePath << ")\n";
            scriptFile << "rm ." << m_envFilePath << "\n";
            scriptFile << "export OMPI_MCA_coll_han_priority=0\n";
        } else if(option == 2){
            scriptFile << "export PATH=\"$PATH:/opt/scalasca/bin\"\n";
            scriptFile << "export PATH=\"$PATH:/opt/scorep/bin\"\n";
        }

        if(option == 0){
            scriptFile << m_cluster_eduMPI_path.toStdString() << "/bin/mpicc " << program_name.toStdString() << ".c -o " << program_name.toStdString() << " -lm" << "\n";
            scriptFile << m_cluster_eduMPI_path.toStdString() << "/bin/mpirun -n " << proc_num << " --map-by :PE=2 --mca pml ob1 ./"+program_name.toStdString();
        } else if(option == 1) {
            scriptFile << "mpicc " << program_name.toStdString() << ".c -o " << program_name.toStdString() << " -lm" << "\n";
            scriptFile << "mpirun -n " << proc_num << " ./"+program_name.toStdString();
        } else if(option == 2) {
            scriptFile << "scorep mpicc " << program_name.toStdString() << ".c -o " << program_name.toStdString() << " -lm" << "\n";
            scriptFile << "scalasca -analyze -e scorep_" << program_name.toStdString() << "_" << proc_num << "_$SLURM_JOB_ID mpiexec -n " << proc_num << " ./"+program_name.toStdString();
        }
        scriptFile.close();

    }
}


//Functionality for timeline

void Database_Connection::startAndStop(bool start){
    std::cout << "startAndStop " << start << std::endl;
    if(!m_componentsBuilt){
        return;
        std::cout << "startAndStop Return" << start << std::endl;
    }
    if(start == true){
        if(timerId != -1){
            killTimer(timerId);
        }
    } else{
        timerId = startTimer(1000);
    }
}

void Database_Connection::handleTimestamp(QTime timestamp){
    m_start_timestamp = timestamp;
    QTime midnight;
    midnight.setHMS(0,0,0);
    int seconds = midnight.secsTo(timestamp);
    emit dataIn(seconds);
    //std::cout << "Seconds: " << seconds << std::endl;
}

void Database_Connection::showConditionAt(int timeSecondsA, int timeSecondsB){
    QTime timestampA = m_start_timestamp.addSecs(timeSecondsA);
    QTime timestampB = m_start_timestamp.addSecs(timeSecondsB);

    emit signalToShowTimestampData(timestampA, timestampB);

}

void Database_Connection::slurm_status_changed(QString status){
    emit signalSlurmStatusChanged(status);
    if(status == "running"){
        m_status_running = true;
    }
    if(m_option == 0){
        if(status == "completed" && m_componentsBuilt){
            startAndStop(true);
            copyOutputFile();
        }
    } else {
        if(status == "completed" && m_status_running){
            copyOutputFile();
            //slurm_process->killProcess();
        }
    }
}
void Database_Connection::getSlurmID(const int id){
    m_slurm_id = id;
}

void Database_Connection::cancelRunningJob(){
    std::cout << "Signal: cancelRunningJob" << std::endl;
    int signal = SIGTERM;
    slurm_process->sendSignal(signal);
    slurm_process->killProcess();
}

void Database_Connection::closeApp(){
    removeClusterComponents();
    if (!m_envFilePath.empty()) {
        if (unlink(m_envFilePath.c_str()) != 0) {
            std::cerr << "Failed to delete temporary file" << std::endl;
        } else {
            std::cout << "Temporary .env file deleted" << std::endl;
        }
    }

    int signal = SIGTERM;
    slurm_process->sendSignal(signal);
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
