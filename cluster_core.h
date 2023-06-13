#ifndef CLUSTER_CORE_H
#define CLUSTER_CORE_H

#include <QObject>

class Cluster_Core;

class Cluster_Core : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(int processrank const)
    Q_PROPERTY(int datasize READ datasize WRITE setDatasize NOTIFY datasizeChanged)
    //Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)

public:
    explicit Cluster_Core(QObject *parent = nullptr);

    Cluster_Core(QObject *parent, int id);
    //Destruktor
    ~Cluster_Core();

    int datasize();
    void updateDatasize();
    void setDatasize(int datasize);

    Q_INVOKABLE int getId() const;

signals:
    void datasizeChanged();

private:
    int m_datasize;
    int m_id;
    int m_processrank;
    int timerId;

protected:
    void timerEvent(QTimerEvent *event);
};

#endif // CLUSTER_CORE_H
