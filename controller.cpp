#include "controller.h"
#include "bash_process_manager.h"
#include "table_userid.h"
#include "qevent.h"
#include <iostream>
#include <fstream>
#include <QProcess>
#include <QFile>
#include <qdatetime.h>
#include <QMetaObject>

#include <unistd.h>
#include <csignal>
#include <sys/stat.h>


Controller::Controller(QObject *parent) : QObject(parent)
{
    slurm_process = new Bash_Process_Manager;

    QObject::connect(slurm_process, &Bash_Process_Manager::slurmIdReady, this, &Controller::getSlurmID);
    QObject::connect(slurm_process, &Bash_Process_Manager::slurm_status_changed, this, &Controller::slurm_status_changed);
    QObject::connect(slurm_process, &Bash_Process_Manager::slotEndTime, this, &Controller::slotEndTime);

    m_connectionName = "mainConnection";
}

void Controller::connect(QString hostname, QString databasename, int port, QString username, QString password){
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

    bool connect = connectToDB(hostname, databasename, port, username, password);
    //Hier stand vorher nur True, kann sein, dass das gebraucht wird!
    m_connection_ready = connect;
    m_job_table = new Table_UserID();
    if(!m_cluster_ident.isEmpty()){
        m_job_table->loadJobs(m_cluster_ident);
    }
    //m_job_table->setDatabaseConnection(m_dbConnection);
    emit connectionSignal(connect);
}


Controller::~Controller()
{

}

bool Controller::copyEnvFile(){
    char tempFileTemplate[] = "/tmp/XXXXXX.env";
    int fd = mkstemps(tempFileTemplate, 4);
    std::string temp_string = tempFileTemplate;
    if (fd == -1) {
        std::cerr << "Failed to create temporary file: " << strerror(errno) << std::endl;
        return false;
    }
    close(fd);

    QFile sourceFile(QString::fromStdString(m_envFilePath));
    QFile destFile(QString::fromStdString(temp_string));

    if (!destFile.open(QIODevice::WriteOnly)) {
        qWarning() << "Failed to open destination file:" << temp_string;
        return false;
    }
    if (!sourceFile.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open source file:" << m_envFilePath;
        return false;
    }

    QByteArray fileData = sourceFile.readAll();
    destFile.write(fileData);

    if (!m_envFilePath.empty()) {
        if (unlink(m_envFilePath.c_str()) != 0) {
            std::cerr << "Failed to delete temporary file" << std::endl;
        } else {
            std::cout << "Temporary .env file deleted" << std::endl;
        }
    }

    m_envFilePath = temp_string;
    return true;
}

void Controller::copyOutputFile(){
    QtConcurrent::run([this]() {
        QProcess proc;
        const char *homeDir = getenv("HOME");
        QString filePath = QString(homeDir);

        QString sshCommand = QString("scp %1@%2:%3/slurm-%4.out %5").arg(m_cluster_ident, m_cluster_address, m_remote_dir_bash, QString::number(m_slurm_id), filePath);
        std::cout << sshCommand.toStdString() << std::endl;

        proc.start("bash", QStringList() << "-c" << sshCommand);

        // Warten, bis der Prozess gestartet ist
        if (!proc.waitForStarted()) {
            proc.kill();
        }

        // Warten, bis der Prozess beendet ist
        if (!proc.waitForFinished()) {
            proc.kill();
        }
        QString outputPath = filePath + "/slurm-" + QString::number(m_slurm_id) + ".out";
        emit copiedOutputFile(outputPath);
    });
}

QString Controller::connectCluster(const QString &address, const QString &ident, const QString &path){
//QString Controller::connectCluster(QString &address, QString &ident, QString &path){
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

void Controller::connectClusterAsync(const QString &address, const QString &ident, const QString &path, QJSValue callback){
    QtConcurrent::run([=]() {
        QString result = connectCluster(address, ident, path);

        // Ensure the callback is invoked in the main thread
        QMetaObject::invokeMethod(this, [=]() {
                callback.call(QJSValueList() << result);
            }, Qt::QueuedConnection);
    });
    if(m_connection_ready){
        m_job_table->loadJobs(m_cluster_ident);
    }
}

void Controller::writeLocalBashFile(QString local_path, bool file, int proc_num){
    //m_visualization = visualization;
    m_start_timestamp = QTime();
    if(m_componentsBuilt){
        //removeClusterComponents();
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

    QString tempFilePath = QDir::temp().absoluteFilePath("temp_bash_script_"+ m_cluster_ident +".sh");
    std::cout << "TempFile: " << tempFilePath.toStdString() << std::endl;
    QFile tempFile(tempFilePath);

    if (!tempFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Fehler beim Versuch, die temporäre Datei zu schreiben." << tempFile.errorString();
        if(!tempFile.open(QIODevice::WriteOnly | QIODevice::Text)){
            sleep(1);
            return;
        }
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
                if(m_option != 3){
                    out << "scp \"" + QString::fromStdString(m_envFilePath) + "\" \"$REMOTE_USER@$REMOTE_HOST:$REMOTE_DIR/tmp/\"\n";
                    //m_remote_dir_bash = "/home/" + m_cluster_ident + "/eduMPI_files";
                }
                out << "scp \"" + local_path + "\" \"$REMOTE_USER@$REMOTE_HOST:$REMOTE_DIR/\"\n";
                out << "scp \"" + m_remote_bash_path + "\" \"$REMOTE_USER@$REMOTE_HOST:$REMOTE_DIR/\"\n";
                m_remote_dir_bash = "/home/" + m_cluster_ident + "/eduMPI_files";
            } else{
                out << "mkdir " + local_path  + "/tmp\n";
                out << "scp -r \"" + local_path + "\" \"$REMOTE_USER@$REMOTE_HOST:$REMOTE_DIR/\"\n";
                int lastSlashIndex = local_path.lastIndexOf("/");
                QString dir_name = local_path.mid(lastSlashIndex + 1);
                out << "scp \"" + QString::fromStdString(m_envFilePath) + "\" \"$REMOTE_USER@$REMOTE_HOST:$REMOTE_DIR/tmp/\"\n";
                out << "scp \"" + m_remote_bash_path + "\" \"$REMOTE_USER@$REMOTE_HOST:$REMOTE_DIR/" + "\"\n";
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

bool Controller::checkFile(QString source, QString program, bool file){
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

QString Controller::readBash(){
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

void Controller::writeBash(QString content){
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

void Controller::startBash(int proc_num){
    if(m_componentsBuilt){
        //removeClusterComponents();
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

void Controller::writeRemoteBashFile(QString program_name, int proc_num, int option){
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
        if(option == 3){
            scriptFile << "#SBATCH --ntasks=1\n";
            scriptFile << "#SBATCH --job-name=eduMPI_OpenMP\n";
            scriptFile << "#SBATCH --nodes=1\n";
            scriptFile << "#SBATCH --exclusive\n";
        } else {
            scriptFile << "#SBATCH --ntasks=" << proc_num << "\n";
            scriptFile << "#SBATCH --job-name=eduMPI\n";
        }

        if(option == 0){
            scriptFile << "#SBATCH --cpus-per-task=2\n\n";
        } else if (option == 3){
            scriptFile << "#SBATCH --cpus-per-task=" << proc_num <<"\n\n";
        } else {
            scriptFile << "#SBATCH --cpus-per-task=1\n\n";
        }

        if(option == 0){
            scriptFile << "for i in {1..5}; do\n";
            scriptFile << "    if source ." << m_envFilePath << " 2>/dev/null; then\n";
            scriptFile << "        export $(cut -d= -f1 ." << m_envFilePath << ")\n";
            scriptFile << "        rm ." << m_envFilePath << "\n";
            scriptFile << "        break\n";
            scriptFile << "    else\n";
            scriptFile << "        sleep 1\n";
            scriptFile << "    fi\n";
            scriptFile << "done\n";
            scriptFile << "export OMPI_MCA_coll_han_priority=0\n";
        } else if(option == 2){
            scriptFile << "export PATH=\"$PATH:/opt/scalasca/bin\"\n";
            scriptFile << "export PATH=\"$PATH:/opt/scorep/bin\"\n";
        } else if(option == 3){
            scriptFile << "export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK\n";
        }

        if(option == 0){
            scriptFile << "export EDUMPI_PROGRAM=" << program_name.toStdString() << ".c\n";
            scriptFile << m_cluster_eduMPI_path.toStdString() << "/bin/mpicc " << program_name.toStdString() << ".c -o " << program_name.toStdString() << " -lm" << "\n";
            scriptFile << m_cluster_eduMPI_path.toStdString() << "/bin/mpirun -n " << proc_num << " --map-by :PE=2 --mca pml ob1 ./"+program_name.toStdString();
        } else if(option == 1) {
            scriptFile << "mpicc " << program_name.toStdString() << ".c -o " << program_name.toStdString() << " -lm" << "\n";
            scriptFile << "mpirun -n " << proc_num << " ./"+program_name.toStdString();
        } else if(option == 2) {
            scriptFile << "scorep mpicc " << program_name.toStdString() << ".c -o " << program_name.toStdString() << " -lm" << "\n";
            scriptFile << "scalasca -analyze -e scorep_" << program_name.toStdString() << "_" << proc_num << "_$SLURM_JOB_ID mpiexec -n " << proc_num << " ./"+program_name.toStdString();
        } else if(option == 3){
            scriptFile << "gcc " << program_name.toStdString() << ".c -o " << program_name.toStdString() << " -lm -fopenmp" << "\n";
            scriptFile << "./" << program_name.toStdString();
        }
        scriptFile.close();

    }
}


void Controller::slurm_status_changed(QString status){
    qDebug() << "Call Slurm_Status_Changed " << status;
    if(status.contains("running")||status.contains("pending")){
        m_status_running = true;
    }
    //std::cout << "slurm_status_changed Methode, m_option " << m_option << std::endl;
    if(m_option == 0){
        if((status == "completed" || status == "cancelled")){
                copyOutputFile();
            /*} else {
                std::cout << "m_start_timestamp same" << std::endl;
                m_status_running = false;
                return;
            }*/
        } else {
            //std::cout << "slurm_status_changed, status: " << status.toStdString() << " m_componentsBuild" << m_componentsBuilt << std::endl;
        }
    } else {
        if((status == "completed" || status == "cancelled")&& m_status_running){
            qDebug() << "Call CopyOutputFile\n";
            copyOutputFile();
            //slurm_process->killProcess();
        }
    }
    emit signalSlurmStatusChanged(status);
}

void Controller::slotEndTime(QDateTime time){
    QTime qtimeTimestamp;
    int seconds;
    qtimeTimestamp = time.time();
    QTime midnight;
    midnight.setHMS(0,0,0);
    seconds = midnight.secsTo(qtimeTimestamp);
    emit signalEndTime(seconds);
}

void Controller::getSlurmID(const int id){
    m_slurm_id = id;
    emit liveSlurmID(m_slurm_id);
}

void Controller::cancelRunningJob(){
    std::cout << "Signal: cancelRunningJob" << std::endl;
    int signal = SIGTERM;
    slurm_process->sendSignal(signal);
    slurm_process->killProcess();
}

void Controller::closeApp(){
    qDebug() << "CLOSE APP";
    //removeClusterComponents();
    if (!m_envFilePath.empty()) {
        if (unlink(m_envFilePath.c_str()) != 0) {
            std::cerr << "Failed to delete temporary file" << std::endl;
        } else {
            std::cout << "Temporary .env file deleted" << std::endl;
        }
    }
    if(slurm_process){
        int signal = SIGTERM;
        slurm_process->sendSignal(signal);
        slurm_process->killProcess();
    } else {
        qDebug() << "slurm_process is already removed";
    }
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

//Slots and Signals for Table_UserID
void Controller::slotFetchEduMPIJobs(){

}



bool Controller::connectToDB(const QString &hostname, const QString &databasename, const int &port, const QString &username, const QString &password){
    if (QSqlDatabase::contains(m_connectionName)) {
        auto db = QSqlDatabase::database(m_connectionName);
        if (db.isOpen()) {
            qDebug() << "Database Connection " << m_connectionName << " is already open.";
            return true;
        }
    }
    auto db = QSqlDatabase::addDatabase("QPSQL", m_connectionName);
    db.setHostName(hostname);
    db.setPort(port);
    db.setDatabaseName(databasename);
    db.setUserName(username);
    db.setPassword(password);
    bool ok = db.open();

    std::cout << "New Connection" << std::endl;
    return ok;
}

QString Controller::getDatabaseConnection(){
    return m_connectionName;
}

QString Controller::getClusterIdent(){
    return m_cluster_ident;
}

void Controller::setComponentsBuild(bool b){
    m_componentsBuilt = b;
}

void Controller::setTimestamp(QTime timestamp){
    m_start_timestamp = timestamp;
}

Table_UserID* Controller::getJobTable(){
    return m_job_table;
}

/*int Controller::count() const{
    return 42;
}*/
