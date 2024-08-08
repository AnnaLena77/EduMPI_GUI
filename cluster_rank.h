#ifndef CLUSTER_RANK_H
#define CLUSTER_RANK_H

#include "qdebug.h"
#include "qqmlintegration.h"
#include <QObject>
#include <QVector3D>

class Cluster_Rank;

class Cluster_Rank : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(int processrank const)
    Q_PROPERTY(long p2p_send_datasize READ p2p_send_datasize WRITE set_p2p_sendDatasize NOTIFY send_p2p_datasizeChanged)
    Q_PROPERTY(long p2p_recv_datasize READ p2p_recv_datasize WRITE set_p2p_recvDatasize NOTIFY recv_p2p_datasizeChanged)
    Q_PROPERTY(float p2p_late_sender READ p2p_late_sender WRITE set_p2p_late_sender NOTIFY p2p_late_senderChanged)
    Q_PROPERTY(float p2p_late_recvr READ p2p_late_recvr WRITE set_p2p_late_recvr NOTIFY p2p_late_recvrChanged)
    Q_PROPERTY(long coll_send_datasize READ coll_send_datasize WRITE set_coll_sendDatasize NOTIFY send_coll_datasizeChanged)
    Q_PROPERTY(long coll_recv_datasize READ coll_recv_datasize WRITE set_coll_recvDatasize NOTIFY recv_coll_datasizeChanged)
    Q_PROPERTY(float coll_late_sender READ coll_late_sender WRITE set_coll_late_sender NOTIFY coll_late_senderChanged)
    Q_PROPERTY(float coll_late_recvr READ coll_late_recvr WRITE set_coll_late_recvr NOTIFY coll_late_recvrChanged)
    Q_PROPERTY(float coll_timediff READ coll_timediff WRITE set_coll_timediff NOTIFY coll_timediffChanged)
    Q_PROPERTY(float p2p_timediff READ p2p_timediff WRITE set_p2p_timediff NOTIFY p2p_timediffChanged)

    Q_PROPERTY(QVector3D position READ position WRITE set_position NOTIFY positionChanged)

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
    float p2p_late_sender();
    float p2p_late_recvr();
    float p2p_timediff();
    float coll_late_sender();
    float coll_late_recvr();
    float coll_timediff();
    QVector3D position();
    void set_p2p_sendDatasize(long datasize);
    void set_p2p_recvDatasize(long datasize);
    void set_coll_sendDatasize(long datasize);
    void set_coll_recvDatasize(long datasize);
    void set_p2p_late_sender(float time);
    void set_p2p_late_recvr(float time);
    void set_p2p_timediff(float time);
    void set_coll_late_sender(float time);
    void set_coll_late_recvr(float time);
    void set_coll_timediff(float time);
    void set_position(QVector3D vec);

    Q_INVOKABLE int getId() const;

signals:
    void send_p2p_datasizeChanged();
    void recv_p2p_datasizeChanged();
    void send_coll_datasizeChanged();
    void recv_coll_datasizeChanged();
    void p2p_late_senderChanged();
    void p2p_late_recvrChanged();
    void p2p_timediffChanged();
    void coll_late_senderChanged();
    void coll_late_recvrChanged();
    void coll_timediffChanged();
    void positionChanged();
private:
    long m_p2p_send_datasize;
    long m_p2p_recv_datasize;
    long m_coll_send_datasize;
    long m_coll_recv_datasize;
    float m_p2p_late_sender;
    float m_p2p_late_recvr;
    float m_p2p_timediff;
    float m_coll_late_sender;
    float m_coll_late_recvr;
    float m_coll_timediff;
    int m_id;
    int m_processrank;
    int timerId;
    QVector3D m_position;

/*protected:
    void timerEvent(QTimerEvent *event);*/
};

#endif // CLUSTER_RANK_H
