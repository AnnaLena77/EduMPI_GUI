#ifndef CLUSTER_RANK_H
#define CLUSTER_RANK_H

#include "qdebug.h"
#include "qqmlintegration.h"
#include <QObject>

class Cluster_Rank;

class Cluster_Rank : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(int processrank const)
    Q_PROPERTY(long p2p_send_datasize READ p2p_send_datasize WRITE set_p2p_sendDatasize NOTIFY send_p2p_datasizeChanged)
    Q_PROPERTY(long p2p_recv_datasize READ p2p_recv_datasize WRITE set_p2p_recvDatasize NOTIFY recv_p2p_datasizeChanged)
    Q_PROPERTY(long coll_send_datasize READ coll_send_datasize WRITE set_coll_sendDatasize NOTIFY send_coll_datasizeChanged)
    Q_PROPERTY(long coll_recv_datasize READ coll_recv_datasize WRITE set_coll_recvDatasize NOTIFY recv_coll_datasizeChanged)
    //Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    QML_ELEMENT

public:
    explicit Cluster_Rank(QObject *parent = nullptr);

    Cluster_Rank(QObject *parent, int id);
    //Destruktor
    ~Cluster_Rank();

    long p2p_send_datasize();
    long p2p_recv_datasize();
    long coll_send_datasize();
    long coll_recv_datasize();
    void set_p2p_sendDatasize(long datasize);
    void set_p2p_recvDatasize(long datasize);
    void set_coll_sendDatasize(long datasize);
    void set_coll_recvDatasize(long datasize);

    Q_INVOKABLE int getId() const;

signals:
    void send_p2p_datasizeChanged();
    void recv_p2p_datasizeChanged();
    void send_coll_datasizeChanged();
    void recv_coll_datasizeChanged();
private:
    long m_p2p_send_datasize;
    long m_p2p_recv_datasize;
    long m_coll_send_datasize;
    long m_coll_recv_datasize;
    int m_id;
    int m_processrank;
    int timerId;

/*protected:
    void timerEvent(QTimerEvent *event);*/
};

#endif // CLUSTER_RANK_H
