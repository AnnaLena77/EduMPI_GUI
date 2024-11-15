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
    qDebug() << "Table User ID Destructor call";
}

void Table_UserID::loadJobs(const QString &userId){

    QSqlDatabase db = QSqlDatabase::database(m_connectionName);
    if (!db.isOpen()) {
        qDebug() << "Databaseconnection " << m_connectionName << " is not open";
        return;
    }
    QSqlQuery query(db);
    query.prepare("SELECT edumpi_run_id, start_time, end_time FROM edumpi_runs WHERE user_id = :user_id ORDER BY edumpi_run_id");
    query.bindValue(":user_id", userId);
    query.exec();

    if (!query.exec()) {
        qWarning() << "Query failed: " << query.lastError();
        return;
    }

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
        return rowindex.at(0);
    } else if (role == StartTime){
        return rowindex.at(1);
    } else if (role == EndTime){
        return rowindex.at(2);
    }
    return QVariant();
}

QHash<int, QByteArray> Table_UserID::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[JobIdRole] = "jobID";
    roles[StartTime] = "startTime";
    roles[EndTime] = "endTime";
    return roles;
}

void Table_UserID::fetchEduMPIJobsForUser(){

}
