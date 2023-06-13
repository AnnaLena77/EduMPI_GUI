#ifndef MONGODATA_H
#define MONGODATA_H

#include "cluster_node.h"

class MongoData;

class MongoData : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int count READ count CONSTANT)

public:
    explicit MongoData(QObject *parent = nullptr);
    //Destruktor
    ~MongoData();

    int count() const;
    void buildClusterComponents();

    Q_INVOKABLE QObject* nodeAt(int index);

private:

    QVector<Cluster_Node*> m_nodes;
};

#endif // MONGODATA_H
