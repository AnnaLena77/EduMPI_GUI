#include "bash_process_manager.h"

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <QDebug>
#include <iostream>
#include <QDateTime>

/*Bash_Process_Manager::Bash_Process_Manager(QObject *parent) : QObject(parent)
{

}*/
Bash_Process_Manager::Bash_Process_Manager (QObject *parent)
    : QObject(parent), process(new QProcess(this))
{
    connect(process, &QProcess::readyReadStandardOutput, this, &Bash_Process_Manager::handleOutput);
    connect(process, &QProcess::readyReadStandardError, this, &Bash_Process_Manager::handleError);
    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, &Bash_Process_Manager::handleProcessFinished);


}

void Bash_Process_Manager::startProcess(const QStringList &arguments)
{
    process->setProgram("bash");
    process->setArguments(arguments);
    process->start();
    m_status = "";

    //qDebug() << "Start Process";
}

void Bash_Process_Manager::sendSignal(int signal)
{
    if (process->state() == QProcess::Running) {
        qDebug() << "Kill Signal";
        ::kill(process->processId(), signal); // Sendet das angegebene Signal an den Prozess
    }
}

void Bash_Process_Manager::handleOutput()
{
    QString output = process->readAllStandardOutput();

    //if(slurm_job_id==0){
    if(output.contains("JOB_ID=")){
        QString jobId = output.mid(output.indexOf('=') + 1).trimmed();
        std::cout << "JOB-ID: " << jobId.toInt() << std::endl;
        if(slurm_job_id != jobId.toInt()){
            slurm_job_id = jobId.toInt();
            emit slurmIdReady(slurm_job_id);
        }
    }
    if (output.contains("PENDING")){
        if(m_status != "pending"){
            m_status = "pending";
            emit slurm_status_changed(m_status);
        }
    }
    else if(output.contains("RUNNING")){
        if(m_status != "running"){
            m_status = "running";
            emit slurm_status_changed(m_status);
        }
    }
    else if(output.contains("CANCELLED")){
        if(m_status != "cancelled"){
            m_status = "cancelled";
            emit slurm_status_changed(m_status);
            if(m_kill_signal){
                if(process->state() == QProcess::Running){
                    process->kill();
                }
            }
        }
    }
    else if(output.contains("COMPLETED") || output.contains("FAILED") || output.contains("Status: \n")){
        if(m_status != "completed"){
            m_status = "completed";
            emit slurm_status_changed(m_status);
            if(m_kill_signal){
                if(process->state() == QProcess::Running){
                    process->kill();
                }
            }
        }
    }
    else if(output.contains("EndTime")){
        output = output.trimmed();
        QString timestamp = output.section(' ', 0, 0);
        QDateTime endTime = QDateTime::fromString(timestamp, Qt::ISODate);

        // Überprüfung und Ausgabe
        if (endTime.isValid()) {
            emit slotEndTime(endTime);
            std::cout << "QDateTime: " << endTime.toString(Qt::ISODate).toStdString() << std::endl;
        } else {
            std::cerr << "Invalid QDateTime!" << std::endl;
        }

    }
    else{
            qDebug() << "Output:" << output;

    }
}

void Bash_Process_Manager::handleError()
{
    QString error = process->readAllStandardError();
    qDebug() << "Error:" << error;
}

void Bash_Process_Manager::handleProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    Q_UNUSED(exitStatus);
    qDebug() << "Process finished with exit code" << exitCode;
}

void Bash_Process_Manager::killProcess(){
    m_kill_signal = true;
}
