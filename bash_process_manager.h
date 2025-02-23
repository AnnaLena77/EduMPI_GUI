#ifndef BASH_PROCESS_MANAGER_H
#define BASH_PROCESS_MANAGER_H

#include <QObject>
#include <QProcess>
#include <QDateTime>

class Bash_Process_Manager : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(long status NOTIFY slurm_status_changed)

public:
    //explicit Bash_Process_Manager(QObject *parent = nullptr);
    explicit Bash_Process_Manager(QObject *parent = nullptr);
    void startProcess(const QStringList &arguments);
    void sendSignal(int signal);
    void killProcess();
    static QString getBashPath();

    int slurm_job_id=0;

signals:
    void slurmIdReady(const int);
    void slurm_status_changed(QString status);
    void slotEndTime(QDateTime(time));

private slots:
    void handleOutput();
    void handleError();
    void handleProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);
    //void handleError();
    //void handleProcessFinished();


private:
    QProcess *process;
    QString m_status;
    bool m_kill_signal = false;

};



#endif // BASH_PROCESS_MANAGER_H
