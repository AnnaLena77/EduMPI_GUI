#ifndef CLUSTER_ARCHITECTURE_H
#define CLUSTER_ARCHITECTURE_H

#include "cluster_node.h"
#include "database_thread.h"
#include "qstandarditemmodel.h"
#include "qthread.h"
#include <QJSValue>
#include <QtConcurrent/QtConcurrent>
#include <bash_process_manager.h>

#include <database_connection.h>
#include <QtQml/qqmlregistration.h>

class Cluster_Architecture;

class Cluster_Architecture : public QObject
{

    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(int count READ count CONSTANT)
    Q_PROPERTY(long p2p_send_max READ p2p_send_max WRITE set_p2p_send_max NOTIFY p2p_send_max_changed)
    Q_PROPERTY(long coll_send_max READ coll_send_max WRITE set_coll_send_max NOTIFY coll_send_max_changed)

    Q_PROPERTY(long p2p_recv_max READ p2p_recv_max WRITE set_p2p_recv_max NOTIFY p2p_recv_max_changed)
    Q_PROPERTY(long coll_recv_max READ coll_recv_max WRITE set_coll_recv_max NOTIFY coll_recv_max_changed)

    Q_PROPERTY(int slurm_id READ slurm_id WRITE set_slurm_id NOTIFY slurm_id_changed)
    Q_PROPERTY(int proc_num READ proc_num WRITE set_proc_num NOTIFY proc_num_changed)

    Q_PROPERTY(int end_time READ end_time WRITE set_end_time NOTIFY end_timeChanged)

    QThread database_thread;

public:

    explicit Cluster_Architecture(QObject *parent = nullptr);
    ~Cluster_Architecture();

    int count() const;
    long p2p_send_max();
    long coll_send_max();
    long p2p_recv_max();
    long coll_recv_max();
    int slurm_id();
    int proc_num();
    int end_time();

    void set_p2p_send_max(long max);
    void set_coll_send_max(long max);
    void set_p2p_recv_max(long max);
    void set_coll_recv_max(long max);
    //void set_slurm_id(int id);

    //Initialization
    Q_INVOKABLE void initialize(QString db_connection, bool live);
    Q_INVOKABLE void startThread();
    Q_INVOKABLE void set_slurm_id(int id);
    Q_INVOKABLE void set_proc_num(int proc);
    Q_INVOKABLE void setOption(int opt);

    //Invokables for Timeline
    Q_INVOKABLE void showConditionAt(int timeSecondsA, int timeSecondsB);
    Q_INVOKABLE void startAndStop(bool start);

    Q_INVOKABLE Cluster_Node* nodeAt(int index);

    Q_INVOKABLE void set_end_time(int time);

    //void buildClusterComponents();
    void updateDatasize();
    int timerId;
    QVector<Cluster_Node*> get_nodeList();

signals:
    void p2p_send_max_changed();
    void coll_send_max_changed();
    void p2p_recv_max_changed();
    void coll_recv_max_changed();
    void slurm_id_changed();
    void proc_num_changed();
    void end_timeChanged(QDateTime time);

    //Signals for Thread
    void signalToConnect(const QString &, const QString &, const int &, const QString &, const QString &);
    void signalToUpdateData(const int &);
    void signalToClearDB();
    void signalToShowTimestampData(const QDateTime timestampA, const QDateTime timestampB);
    void startDatabaseThread();
    void signalToDBConnection();
    void waitForEnd();

    //Signals for QML
    void componentsBuilt();
    void connectionSignal(bool success);
    //set bool = 1 for start-timestamp and bool = 0 for end-timestamp
    void dataIn(int timestamp, QTime qTimestamp, bool start);
    void signalSlurmStatusChanged(QString status);
    void copiedOutputFile(QString output);


public slots:
    void buildClusterComponents(const QMap<QString, QVector<int>> &);
    void updateDataToUI(const QList<DataColumn> &);
    void removeClusterComponents();
    //set bool = 1 for start-timestamp and bool = 0 for end-timestamp
    void handleTimestamp(QDateTime timestamp, bool start);

private:

    //database-connection
    QString m_connectionName;
    Database_Thread *m_dbThread;

    bool m_componentsBuilt = false;
    QVector<Cluster_Node*> m_nodes;
    long m_p2p_send_max = 0;
    long m_coll_send_max = 0;
    long m_p2p_recv_max = 0;
    long m_coll_recv_max = 0;
    bool m_connection_ready = false;
    bool m_cluster_connection_ready = false;
    int m_time_display = 0;

    QDateTime m_start_timestamp;

    //cluster identifications
    QString m_cluster_address;
    QString m_cluster_ident;
    QString m_cluster_eduMPI_path;
    QString m_remote_bash_path;
    QString m_remote_dir_bash;

    std::string m_envFilePath;
    int m_slurm_id;
    int m_proc_num;
    int m_option;
    bool m_status_running=false;
    bool m_live_run;
    int m_end_time;

protected:
    void timerEvent(QTimerEvent *event);

};

#endif // CLUSTER_ARCHITECTURE_H
