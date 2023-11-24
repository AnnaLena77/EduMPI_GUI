#ifndef NODE_H
#define NODE_H

#include <QObject>
#include <QQmlEngine>

class Node : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    Node();
};

#endif // NODE_H
