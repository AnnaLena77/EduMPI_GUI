#ifndef DATABASE_THREAD_H
#define DATABASE_THREAD_H

#include <QObject>
#include <QThread>
#include <iostream>
#include <QSqlDatabase>
#include <QStandardItemModel>

struct DataColumn
{
    QString proc_name;
    QString comm_type;
    int proc_rank;
    long recv_datasize;
    long send_datasize;
};


class Database_Thread : public QObject
{
    Q_OBJECT


/*public:
    explicit Database_Thread(QObject *parent = nullptr);*/

public slots:
    void connectToDB(const QString &hostname, const QString &databasename, const int &port, const QString &username, const QString &password);
    void threadbuildClusterComponents(const int &proc_num);
    void updateData(const int &time_display);
    void clearDatabase();

signals:
    void connectedToDB(const bool &success);
    void clusterComponentsReady(const QMap<QString, QVector<int>> &map);
    void updateDataReady(const QList<DataColumn> &list);
    void dbCleared();

private:
    bool m_clearingProc = false;
};

#endif // DATABASE_THREAD_H
