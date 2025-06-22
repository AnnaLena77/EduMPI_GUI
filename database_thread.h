#ifndef DATABASE_THREAD_H
#define DATABASE_THREAD_H

#include "qdatetime.h"
#include <QObject>
#include <QThread>
#include <iostream>
#include <QSqlDatabase>
#include <QStandardItemModel>
#include <database_connection.h>

struct DataColumn
{
    QString proc_name;
    QString comm_type;
    int proc_rank;
    long recv_datasize;
    long send_datasize;
    float late_sender;
    float late_receiver;
    float time_diff;
};


class Database_Thread : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool thread_running READ thread_running WRITE set_thread_running NOTIFY thread_runningChanged)




public:
    explicit Database_Thread(QString dbConnectionName, int slurm_id, int proc_num, bool live_run, QObject *parent = nullptr);
    ~Database_Thread();

    // Getter und Setter für die Property
    bool thread_running() const;
    void set_thread_running(bool running);

    void detailed_p2p_Query(const QDateTime timestampA, const QDateTime timestampB);

    //detailed matrices
    void initialize_detailed_matrices();
    void reset_detailed_matrices();

public slots:
    void connectToDB();
    void threadbuildClusterComponents();
    void updateData(const int &time_display);
    void showDataFromTimePeriod(const QDateTime timestampA, const QDateTime timestampB);
    void clearDatabase();

    void getProcNum(const int proc_num);
    void fetchEduMPIJobs(const QString &userId);
    void selectEndTimestamp();

    void set_end_timestamp_db(QDateTime timestamp);
    void reset_actual_timestamp(); 
    //Q_INVOKABLE void set_thread_running(bool running);


signals:
    void connectedToDB(const bool &success);
    void clusterComponentsReady(const QMap<QString, QVector<int>> &map);
    void updateDataReady(const QList<DataColumn> &list);
    void updateDetailedP2P(QList<QVariantList>);
    void updateDetailedColl(QList<QVariantList>);
    void dbCleared();
    //set bool = 1 for start-timestamp and bool = 0 for end-timestamp
    void setTimestamp(QDateTime timestamp, bool start);
    void eduMPIJobsFetched(const QVariantList &jobIds);
    void thread_runningChanged();

    void setFunctionsString(QString string);
    void setCommMatrixP2PSend(QVector<QVector<long>>);
    void setCommMatrixP2PRecv(QVector<QVector<long>>);
    void setCommMatrixCollSend(QVector<QVector<long>>);
    void setCommMatrixCollRecv(QVector<QVector<long>>);
    void setCommMatrixTotalSend(QVector<QVector<long>>);

private:

    //database_connection
    Database_Connection *m_dbConnection;
    QString m_connectionName;

    bool m_clearingProc = false;
    QDateTime m_actualDBEntryTime;
    QDateTime m_firstDBEntryDate;
    bool m_thread_running;
    QTime m_firstDBEntryTime;
    int m_slurm_id;
    int m_proc_num;
    bool m_live_run;

    //Detailed Communication Matrices
    QVector<QVector<long>> m_p2p_send_volume_matrix;
    QVector<QVector<long>> m_p2p_recv_volume_matrix;
    QVector<QVector<long>> m_coll_send_volume_matrix;
    QVector<QVector<long>> m_coll_recv_volume_matrix;
    QVector<QVector<long>> m_total_send_volume_matrix;

    QVector<QVector<float>> m_p2p_time_matrix;
    QVector<QVector<float>> m_coll_time_matrix;
};

#endif // DATABASE_THREAD_H
