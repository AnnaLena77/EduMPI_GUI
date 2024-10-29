#include "database_connection.h"
#include "QSql"
#include <QSqlQuery>
#include <QSqlRecord>
#include <unistd.h>
#include <QDateTime>
#include <QStandardItemModel>
#include <QSqlError>
#include <iostream>

Database_Connection::Database_Connection(QObject *parent) : QObject(parent) {

}

bool Database_Connection::connectToDB(const QString &hostname, const QString &databasename, const int &port, const QString &username, const QString &password){
    m_database = QSqlDatabase::addDatabase("QPSQL");
    m_database.setHostName(hostname);
    m_database.setPort(port);
    m_database.setDatabaseName(databasename);
    m_database.setUserName(username);
    m_database.setPassword(password);
    bool ok = m_database.open();

    std::cout << "New Connection" << std::endl;
    return ok;
}

void Database_Connection::close(){
    m_database.close();
}

QSqlDatabase Database_Connection::getDatabaseConnection() const{
    return m_database;
}
