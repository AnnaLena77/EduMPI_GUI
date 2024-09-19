#include "table_userid.h"
#include "database_connection.h"

Table_UserID::Table_UserID(QObject *parent)
    : QAbstractTableModel(parent)
{
}

Table_UserID::~Table_UserID()
{

}

void Table_UserID::loadJobs(const QString &userId){
}

int Table_UserID::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_edumpi_runs.size();
}

QVariant Table_UserID::data(const QModelIndex &index, int role) const {
    if(!index.isValid() || index.row() >= m_edumpi_runs.size()){
        return QVariant();
    }
    if(role == JobIdRole){
        return m_edumpi_runs.at(index.row());
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

/*void Table_UserID::eduMPIJobsFetched(const QVariantList &jobIds){

}*/
