#ifndef CLUSTER_NODE_H
#define CLUSTER_NODE_H

#include "cluster_core.h"
#include "qqmlintegration.h"
#include <QObject>
#include <QQmlListProperty>

class Cluster_Node;

class Cluster_Node : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int count READ count CONSTANT)
    //Q_PROPERTY(type name READ name WRITE setname NOTIFY nameChanged)
    Q_PROPERTY(QVector<Cluster_Core *> cores READ cores WRITE setCores NOTIFY coresChanged)
    QML_ELEMENT

public:
    using QObject::QObject;
    //Konstruktoren
    explicit Cluster_Node(QObject *parent = nullptr);
    Cluster_Node(QObject *parent, std::string name);
    //Destruktor
    ~Cluster_Node();

    QVector<Cluster_Core *> cores();

    int count() const;
    void addCore(Cluster_Core* core);
    void setCores(QVector<Cluster_Core *> list);

    void updateCores();

    Q_INVOKABLE QObject* coreAt(int index);
    Q_INVOKABLE QString getName()const;

private:
    QVector<Cluster_Core *> m_cores;
    std::string m_name;
    int timerId;
    int m_start_id = 0;

signals:
    void coresChanged();

protected:
    void timerEvent(QTimerEvent *event);
};

#endif
