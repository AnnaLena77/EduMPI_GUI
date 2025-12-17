#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "cluster_node.h"
#include <QJSValue>
#include <QtConcurrent/QtConcurrent>
#include <bash_process_manager.h>
#include "table_userid.h"
//#include <QVariantList>

#include <QtQml/qqmlregistration.h>


class Controller;

class Controller : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(int count READ count CONSTANT)

    Q_PROPERTY(bool db_connection  MEMBER m_connection_ready NOTIFY connectionChanged)
    Q_PROPERTY(bool cluster_connection MEMBER m_cluster_connection_ready NOTIFY clusterConnectionChanged)
    Q_PROPERTY(QVariantList open_job_windows MEMBER m_open_job_windows READ open_job_windows NOTIFY open_job_windowsChanged)
    //Q_PROPERTY(int time_display MEMBER m_time_display NOTIFY time_display_changed)

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

    void copyOutputFile();

    bool connectToDB(const QString &hostname, const QString &databasename, const int &port, const QString &username, const QString &password);

    QVariantList open_job_windows();

    Q_INVOKABLE void connect(QString hostname, QString databasename, int port, QString UserName, QString password);
    //Q_INVOKABLE void buildClusterComponents(int proc_num);
    Q_INVOKABLE void writeLocalBashFile(QString local_path, bool file, int proc_num);//QString local_path, QString local_name, bool file);
    Q_INVOKABLE void closeApp();
    Q_INVOKABLE void cancelRunningJob();
    Q_INVOKABLE void startBash(int proc_num);
    Q_INVOKABLE QString readBash();
    Q_INVOKABLE void writeBash(QString content);

    Q_INVOKABLE bool checkFile(QString source, QString program, bool file);
    Q_INVOKABLE void writeRemoteBashFile(QString program_name, int proc_num, int option);

    //Invokables for Timeline
    //Q_INVOKABLE void showConditionAt(int timeSecondsA, int timeSecondsB);
    //Q_INVOKABLE void startAndStop(bool start);

    //Asynchronous Callback for Cluster-Connection Check:
    Q_INVOKABLE QString connectCluster(const QString &address, const QString &ident, const QString &path);
    Q_INVOKABLE void connectClusterAsync(const QString &address, const QString &ident, const QString &path, QJSValue callback);

    //Invokable for getting all Run-IDs of open windows
    Q_INVOKABLE bool check_open_window(int slurm_id);
    Q_INVOKABLE void append_open_window(int slurm_id);
    Q_INVOKABLE void remove_open_window(int slurm_id);

    //Q_INVOKABLE QString getOutputFile();

    //void buildClusterComponents();
    void updateDatasize();
    int timerId;
    QVector<Cluster_Node*> get_nodeList();

    Bash_Process_Manager *slurm_process;

    Q_INVOKABLE QString getDatabaseConnection();
    Q_INVOKABLE void setComponentsBuild(bool b);
    Q_INVOKABLE void setTimestamp(QTime timestamp);
    Q_INVOKABLE Table_UserID *getJobTable();
    Q_INVOKABLE QString getClusterIdent();

    Q_INVOKABLE bool copyEnvFile();

signals:

    //Signals for QML
    int count() const;
    void liveSlurmID(int slurm_id);
    void connectionSignal(bool success);
    void dataIn(int timestamp);
    void signalSlurmStatusChanged(QString status);
    void copiedOutputFile(QString output);

    void signalEndTime(int time);

    //Signals for Thread
    void signalToConnect(const QString &, const QString &, const int &, const QString &, const QString &);
    void setProcNum(const int proc_num);
    void signalToClearDB();

    //Signal for Table_UserID
    void fetchEduMPIJobsForUser(const QString &userId);

    void connectionChanged();
    void clusterConnectionChanged();

    void open_job_windowsChanged();

//Slots for Thread
public slots:
    //void dbConnectionSuccessful(const bool &);
    //void buildClusterComponents(const QMap<QString, QVector<int>> &);
    //void updateDataToUI(const QList<DataColumn> &);
    //void removeClusterComponents();
    //void handleTimestamp(QTime timestamp);
    void slotEndTime(QDateTime time);
    void slurm_status_changed(QString status);
    void getSlurmID(const int id);

    //Table_UserID
    void slotFetchEduMPIJobs();

private:

    QString m_connectionName;

    bool m_componentsBuilt = false;
    bool m_connection_ready = false;
    bool m_cluster_connection_ready = false;
    int m_time_display = 0;

    QTime m_start_timestamp;

    //cluster identifications
    QString m_cluster_address;
    QString m_cluster_ident;
    QString m_cluster_eduMPI_path;
    QString m_remote_bash_path;
    QString m_remote_dir_bash;

    std::string m_envFilePath;
    // Program id (slurm)
    int m_slurm_id;
    // Program name (for Score-P functionlality
    QString m_program_name;
    // Program number of processes
    int m_proc_num = 0;

    int m_option;
    bool m_status_running=false;

    Table_UserID *m_job_table;
    QVariantList m_open_job_windows;

protected:
    //void timerEvent(QTimerEvent *event);
};

#endif // CONTROLLER_H
