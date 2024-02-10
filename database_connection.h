#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include "cluster_node.h"
#include "database_thread.h"
#include "qstandarditemmodel.h"
#include "qthread.h"


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

    Q_INVOKABLE void connect(QString hostname, QString databasename, int port, QString UserName, QString password);
    //Q_INVOKABLE void buildClusterComponents(int proc_num);
    Q_INVOKABLE void createBashSkript(QString host, QString username, QString edumpi_path, QString local_path, QString local_name, bool file);
    Q_INVOKABLE void closeApp();
    Q_INVOKABLE void startBash(int proc_num);
    Q_INVOKABLE QString readBash();
    Q_INVOKABLE void writeBash(QString content);

    Q_INVOKABLE Cluster_Node* nodeAt(int index);

    //void buildClusterComponents();
    void updateDatasize();
    int timerId;
    QVector<Cluster_Node*> get_nodeList();

signals:
    void p2p_send_max_changed();
    void coll_send_max_changed();
    void p2p_recv_max_changed();
    void coll_recv_max_changed();
    void connectionChanged();
    void time_display_changed();

    void componentsBuilt();

    //Signals for Thread
    void signalToConnect(const QString &, const QString &, const int &, const QString &, const QString &);
    void signalToBuildComponents(const int &);
    void signalToUpdateData(const int &);

//Slots for Thread
public slots:
    void dbConnectionSuccessful(const bool &);
    void buildClusterComponents(const QMap<QString, QVector<int>> &);
    void updateDataToUI(const QList<DataColumn> &);

private:
    bool m_componentsBuilt = false;
    QVector<Cluster_Node*> m_nodes;
    long m_p2p_send_max = 0;
    long m_coll_send_max = 0;
    long m_p2p_recv_max = 0;
    long m_coll_recv_max = 0;
    bool m_connection_ready = false;
    int m_time_display = 0;

protected:
    void timerEvent(QTimerEvent *event);
};

#endif // DATABASE_CONNECTION_H
