#ifndef BASH_PROCESS_MANAGER_H
#define BASH_PROCESS_MANAGER_H

#include <QObject>
#include <QProcess>

class Bash_Process_Manager : public QObject
{
    Q_OBJECT
public:
    //explicit Bash_Process_Manager(QObject *parent = nullptr);
    explicit Bash_Process_Manager(QObject *parent = nullptr);
    void startProcess(const QStringList &arguments);
    void sendSignal(int signal);

private slots:
    void handleOutput();
    void handleError();
    void handleProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);
    //void handleError();
    //void handleProcessFinished();

private:
    QProcess *process;
};



#endif // BASH_PROCESS_MANAGER_H
