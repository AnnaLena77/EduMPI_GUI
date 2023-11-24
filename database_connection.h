#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <QSqlDatabase>
#include "cluster_node.h"


class Database_Connection;

class Database_Connection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int count READ count CONSTANT)
    Q_PROPERTY(long p2p_send_max MEMBER m_p2p_send_max NOTIFY p2p_send_max_changed)
    Q_PROPERTY(long coll_send_max MEMBER m_coll_send_max NOTIFY coll_send_max_changed)

public:
    explicit Database_Connection(QObject *parent = nullptr);
    ~Database_Connection();

    int count() const;
    Q_INVOKABLE Cluster_Node* nodeAt(int index);

    //void buildClusterComponents();
    void updateDatasize();
    int timerId;
    QVector<Cluster_Node*> get_nodeList();

public slots:
    void buildClusterComponents();

signals:
    void p2p_send_max_changed();
    void coll_send_max_changed();



private:
    bool m_componentsBuilt = false;
    QSqlDatabase m_db;
    QVector<Cluster_Node*> m_nodes;
    long m_p2p_send_max;
    long m_coll_send_max;

protected:
    void timerEvent(QTimerEvent *event);
};

#endif // DATABASE_CONNECTION_H
