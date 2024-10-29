#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <QObject>
#include <QSqlDatabase>


class Database_Connection;

class Database_Connection : public QObject
{
    Q_OBJECT

public:
    explicit Database_Connection(QObject *parent = nullptr);

    bool connectToDB(const QString &hostname, const QString &databasename, const int &port, const QString &username, const QString &password);
    QSqlDatabase getDatabaseConnection() const;
    void close();

private:
    QSqlDatabase m_database;
};


#endif // DATABASE_CONNECTION_H
