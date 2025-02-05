#include "detailed_p2p_data.h"

#include <QSqlQuery>

Detailed_p2p_data::Detailed_p2p_data(QObject *parent)
    : QAbstractTableModel(parent)
{

}

Detailed_p2p_data::~Detailed_p2p_data()
{

}

void Detailed_p2p_data::queryData(QList<QVariantList> query){

    beginResetModel();
    m_p2p_data.clear();

    m_p2p_data = query;

    endResetModel();

    if (!m_p2p_data.isEmpty()) { // Nur ausgeben, wenn tatsächlich Daten vorhanden sind
        //qDebug() << "Table Data (only printed once):";
        for (int i = 0; i < m_p2p_data.size(); ++i) {
            const QVariantList& row = m_p2p_data.at(i);
            QStringList rowStrings;
            for (const QVariant& value : row) {
                rowStrings << value.toString();
            }
            //qDebug() << "Row" << i << ":" << rowStrings.join(", ");
        }
        emit newDataInsertion();
    } else {
        emit newDataInsertion();
        //qDebug() << "No data to display.";
    }
}

int Detailed_p2p_data::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_p2p_data.size();
}
int Detailed_p2p_data::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 5;  // Beispiel: Anzahl der Spalten (z.B. für Job-ID, Startzeit, Endzeit)
}

QVariant Detailed_p2p_data::data(const QModelIndex &index, int role) const {
    if(!index.isValid() || index.row() >= m_p2p_data.size()){
        return QVariant();
    }
    QVariantList rowindex = m_p2p_data.at(index.row());
    if(role == function){
        return rowindex.at(0);
    } else if (role == processrank){
        return rowindex.at(1);
    } else if (role == partnerrank){
        return rowindex.at(2);
    }
    return QVariant();
}

QVariant Detailed_p2p_data::simple_data(int row, const QString &role) const {
    if(row >= 0 && m_p2p_data.size()) {
        QVariantList rowindex = m_p2p_data.at(row);
        if(role == "function"){
            return rowindex.at(0);
        } else if (role == "processrank"){
            return rowindex.at(1);
        } else if (role == "partnerrank"){
            return rowindex.at(2);
        }
    }
    return QVariant();
}

QHash<int, QByteArray> Detailed_p2p_data::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[function] = "function";
    roles[processrank] = "processrank";
    roles[partnerrank] = "partnerrank";
    return roles;
}
