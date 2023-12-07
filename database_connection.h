#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <QSqlDatabase>
#include "cluster_node.h"


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
    QML_ELEMENT

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
    Q_INVOKABLE void buildClusterComponents(int proc_num);
    Q_INVOKABLE void createBashSkript(QString host, QString username, QString edumpi_path, QString local_path, QString local_name, bool file);
    Q_INVOKABLE void closeApp();
    Q_INVOKABLE void startBash(int proc_num);

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


private:
    bool m_componentsBuilt = false;
    QSqlDatabase m_db;
    QVector<Cluster_Node*> m_nodes;
    long m_p2p_send_max = 0;
    long m_coll_send_max = 0;
    long m_p2p_recv_max = 0;
    long m_coll_recv_max = 0;
    bool m_connection_ready = false;

protected:
    void timerEvent(QTimerEvent *event);
};

#endif // DATABASE_CONNECTION_H
