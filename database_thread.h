#ifndef DATABASE_THREAD_H
#define DATABASE_THREAD_H

#include <QObject>
#include <QThread>
#include <iostream>

class Database_Thread : public QThread
{
    Q_OBJECT
    void run() override {
        std::cout << "Hello from thread" << std::endl;
    }

signals:

};

#endif // DATABASE_THREAD_H
