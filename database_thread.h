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


public:
    explicit Database_Thread(QString dbConnectionName, int slurm_id, int proc_num, bool live_run, QObject *parent = nullptr);
    ~Database_Thread();

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


signals:
    void connectedToDB(const bool &success);
    void clusterComponentsReady(const QMap<QString, QVector<int>> &map);
    void updateDataReady(const QList<DataColumn> &list);
    void dbCleared();
    //set bool = 1 for start-timestamp and bool = 0 for end-timestamp
    void setTimestamp(QDateTime timestamp, bool start);
    void eduMPIJobsFetched(const QVariantList &jobIds);

private:

    //database_connection
    Database_Connection *m_dbConnection;
    QString m_connectionName;

    bool m_clearingProc = false;
    QDateTime m_actualDBEntryTime;
    QTime m_firstDBEntryTime;
    int m_slurm_id;
    int m_proc_num;
    bool m_live_run;
};

#endif // DATABASE_THREAD_H
