#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <QObject>
#include <QSqlDatabase>

    class Database_Connection : public QObject
{
    Q_OBJECT

public:
    explicit Database_Connection(const QString& connectionName = "mainConnection", QObject *parent = nullptr);
    ~Database_Connection();


    bool connectToDB(const QString &hostname, const QString &databasename, const int &port, const QString &username, const QString &password);
    QSqlDatabase getDatabaseConnection() const;
    void close();

private:
    QString m_connectionName;
};

#endif // DATABASE_CONNECTION_H
