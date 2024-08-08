#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include "cluster_node.h"
#include "database_thread.h"
#include "qstandarditemmodel.h"
#include "qthread.h"
#include <QJSValue>
#include <QtConcurrent/QtConcurrent>
#include <bash_process_manager.h>


class Database_Connection;

class Database_Connection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int count READ count CONSTANT)
    Q_PROPERTY(long p2p_send_max READ p2p_send_max WRITE set_p2p_send_max NOTIFY p2p_send_max_changed)
    Q_PROPERTY(long coll_send_max READ coll_send_max WRITE set_coll_send_max NOTIFY coll_send_max_changed)

    Q_PROPERTY(long p2p_recv_max READ p2p_recv_max WRITE set_p2p_recv_max NOTIFY p2p_recv_max_changed)
    Q_PROPERTY(long coll_recv_max READ coll_recv_max WRITE set_coll_recv_max NOTIFY coll_recv_max_changed)

    Q_PROPERTY(bool db_connection  MEMBER m_connection_ready NOTIFY connectionChanged)
    Q_PROPERTY(bool cluster_connection MEMBER m_cluster_connection_ready NOTIFY clusterConnectionChanged)
    Q_PROPERTY(int time_display MEMBER m_time_display NOTIFY time_display_changed)
    QML_ELEMENT

    QThread database_thread;

public:
    explicit Database_Connection(QObject *parent = nullptr);
    ~Database_Connection();

    int count() const;
    long p2p_send_max();
    long coll_send_max();
    long p2p_recv_max();
    long coll_recv_max();

    void set_p2p_send_max(long max);
    void set_coll_send_max(long max);
    void set_p2p_recv_max(long max);
    void set_coll_recv_max(long max);

    void copyOutputFile();

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
    Q_INVOKABLE void showConditionAt(int timeSecondsA, int timeSecondsB);
    Q_INVOKABLE void startAndStop(bool start);

    //Asynchronous Callback for Cluster-Connection Check:
    Q_INVOKABLE QString connectCluster(const QString &address, const QString &ident, const QString &path);
    Q_INVOKABLE void connectClusterAsync(const QString &address, const QString &ident, const QString &path, QJSValue callback);

    //Q_INVOKABLE QString getOutputFile();


    Q_INVOKABLE Cluster_Node* nodeAt(int index);

    //void buildClusterComponents();
    void updateDatasize();
    int timerId;
    QVector<Cluster_Node*> get_nodeList();

    Bash_Process_Manager *slurm_process;

signals:
    void p2p_send_max_changed();
    void coll_send_max_changed();
    void p2p_recv_max_changed();
    void coll_recv_max_changed();
    void connectionChanged();
    void clusterConnectionChanged();
    void time_display_changed();

    //Signals for QML
    void componentsBuilt();
    void connectionSignal(bool success);
    void dataIn(int timestamp);
    void signalSlurmStatusChanged(QString status);
    void copiedOutputFile(QString output);

    //Signals for Thread
    void signalToConnect(const QString &, const QString &, const int &, const QString &, const QString &);
    void setProcNum(const int proc_num);
    void signalToUpdateData(const int &);
    void signalToClearDB();
    void signalToShowTimestampData(const QTime timestampA, const QTime timestampB);

//Slots for Thread
public slots:
    void dbConnectionSuccessful(const bool &);
    void buildClusterComponents(const QMap<QString, QVector<int>> &);
    void updateDataToUI(const QList<DataColumn> &);
    void removeClusterComponents();
    void handleTimestamp(QTime timestamp);
    void slurm_status_changed(QString status);
    void getSlurmID(const int id);

private:
    bool m_componentsBuilt = false;
    QVector<Cluster_Node*> m_nodes;
    long m_p2p_send_max = 0;
    long m_coll_send_max = 0;
    long m_p2p_recv_max = 0;
    long m_coll_recv_max = 0;
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
    int m_slurm_id;
    int m_option;
    bool m_status_running=false;

protected:
    void timerEvent(QTimerEvent *event);
};

#endif // DATABASE_CONNECTION_H
