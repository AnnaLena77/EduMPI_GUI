#ifndef CLUSTER_NODE_H
#define CLUSTER_NODE_H

#include "cluster_rank.h"
#include "qqmlintegration.h"
#include <QObject>
#include <QQmlListProperty>

class Cluster_Node;

class Cluster_Node : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int count READ count CONSTANT)
    //Q_PROPERTY(type name READ name WRITE setname NOTIFY nameChanged)
    //Q_PROPERTY(QVector<Cluster_Rank *> ranks READ ranks WRITE setRanks NOTIFY ranksChanged)
    QML_ELEMENT

public:
    //using QObject::QObject;
    //Konstruktoren
    explicit Cluster_Node(QObject *parent = nullptr);
    Cluster_Node(QObject *parent, std::string name);
    //Destruktor
    ~Cluster_Node();

    QVector<Cluster_Rank *> ranks();

    int count() const;


    void addRank(Cluster_Rank* rank);
    void setRanks(QVector<Cluster_Rank *> list);

    void updateRanks();
    int getSmalestRankId();

    Q_INVOKABLE Cluster_Rank* rankAt(int index);
    Q_INVOKABLE QString getName()const;

private:
    QVector<Cluster_Rank *> m_ranks;
    std::string m_name = "";
    int timerId;
    int m_start_id = 0;
    int m_smalest_rank = 0;
    int m_biggest_rank = 0;

signals:
    void ranksChanged();

/*protected:
    void timerEvent(QTimerEvent *event);
*/
};

#endif
