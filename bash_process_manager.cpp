#include "bash_process_manager.h"

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <QDebug>

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
}

void Bash_Process_Manager::sendSignal(int signal)
{
    if (process->state() == QProcess::Running) {
        ::kill(process->processId(), signal); // Sendet das angegebene Signal an den Prozess
    }
}

void Bash_Process_Manager::handleOutput()
{
    QString output = process->readAllStandardOutput();

    if(slurm_job_id==0){
         if(output.contains("JOB_ID=")){
            QString jobId = output.mid(output.indexOf('=') + 1).trimmed();
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
    else {
        if(m_status != "completed"){
            m_status = "completed";
            emit slurm_status_changed(m_status);
        }
    }
    //qDebug() << "Output:" << output;
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
    process->kill();
}
