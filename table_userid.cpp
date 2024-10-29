#include "table_userid.h"

#include "QSql"
#include <QSqlQuery>
#include <QSqlError>
#include <iostream>>

Table_UserID::Table_UserID(QObject *parent)
    : QAbstractTableModel(parent)
{

}

Table_UserID::~Table_UserID()
{

}

void Table_UserID::loadJobs(const QString &userId){
    if(!m_db.isOpen()){
        return;
    }
    QSqlQuery query(m_db);
    query.prepare("SELECT edumpi_run_id, start_time, end_time FROM edumpi_runs WHERE user_id = :user_id ORDER BY edumpi_run_id");
    query.bindValue(":user_id", userId);
    query.exec();

    if (!query.exec()) {
        qWarning() << "Query failed: " << query.lastError();
        return;
    }

    beginResetModel();
    m_edumpi_runs.clear();

    // Speichern der Abfrageergebnisse in m_edumpi_runs
    while (query.next()) {
        QVariantList rowData;
        rowData << query.value(0)  // edumpi_run_id
                << query.value(1)  // start_time
                << query.value(2); // end_time
        m_edumpi_runs.append(rowData);
    }

    endResetModel();
}

int Table_UserID::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_edumpi_runs.size();
}
int Table_UserID::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 3;  // Beispiel: Anzahl der Spalten (z.B. für Job-ID, Startzeit, Endzeit)
}

QVariant Table_UserID::data(const QModelIndex &index, int role) const {
    if(!index.isValid() || index.row() >= m_edumpi_runs.size()){
        return QVariant();
    }
    QVariantList rowindex = m_edumpi_runs.at(index.row());
    if(role == JobIdRole){
        //std::cout << "Test: " << m_edumpi_runs.at(index.row()) << std::endl;
        return rowindex.at(0);
    }
    return QVariant();
}

QHash<int, QByteArray> Table_UserID::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[JobIdRole] = "jobID";
    return roles;
}

void Table_UserID::fetchEduMPIJobsForUser(){

}

void Table_UserID::setDatabaseConnection(Database_Connection *dbConnection) {
    m_dbConnection = dbConnection;
    m_db = dbConnection->getDatabaseConnection();  // Stelle sicher, dass die Verbindung hergestellt ist
}


/*void Table_UserID::eduMPIJobsFetched(const QVariantList &jobIds){

}*/
