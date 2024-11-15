#include "database_connection.h"
#include "QSql"
#include <QSqlQuery>
#include <QSqlRecord>
#include <unistd.h>
#include <QDateTime>
#include <QStandardItemModel>
#include <QSqlError>
#include <iostream>

Database_Connection::Database_Connection(const QString& connectionName, QObject *parent)
    : QObject(parent), m_connectionName(connectionName)
{

}

Database_Connection::~Database_Connection()
{
    qDebug() << "Close Database_Connection::close";
    close();
}


bool Database_Connection::connectToDB(const QString &hostname, const QString &databasename, const int &port, const QString &username, const QString &password){
    if (QSqlDatabase::contains(m_connectionName)) {
        auto db = QSqlDatabase::database(m_connectionName);
        if (db.isOpen()) {
            qDebug() << "Database Connection " << m_connectionName << "i already open.";
            return true;
        }
    }
    auto db = QSqlDatabase::addDatabase("QPSQL", m_connectionName);
    db.setHostName(hostname);
    db.setPort(port);
    db.setDatabaseName(databasename);
    db.setUserName(username);
    db.setPassword(password);
    bool ok = db.open();

    std::cout << "New Connection" << std::endl;
    return ok;
}

void Database_Connection::close(){
    if (QSqlDatabase::contains(m_connectionName)) {
        auto db = QSqlDatabase::database(m_connectionName);
        db.close();
        QSqlDatabase::removeDatabase(m_connectionName);
    }
}

QSqlDatabase Database_Connection::getDatabaseConnection() const{
    if(QSqlDatabase::contains(m_connectionName)) {
        return QSqlDatabase::database(m_connectionName);
    } else {
        qDebug() << "Verbindungsname" << m_connectionName << "existiert nicht.";
        return QSqlDatabase();
    };
}
