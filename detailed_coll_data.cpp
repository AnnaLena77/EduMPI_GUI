#include "detailed_coll_data.h"

Detailed_coll_data::Detailed_coll_data(QObject *parent)
    : QAbstractTableModel(parent) {

}

Detailed_coll_data::~Detailed_coll_data()
{

}

void Detailed_coll_data::queryData(QList<QVariantList> query){

    beginResetModel();
    m_coll_data.clear();

        for (const QVariantList& entry : query) {
            if (entry.size() < 4) continue;  // Stelle sicher, dass die 4. Position existiert

            QVariantList list = entry;  // Kopiere die bestehende Liste

            if (!entry[3].toString().isEmpty()) {  // Sicherstellen, dass entry[3] nicht leer ist
                QByteArray bitmask = entry[3].toByteArray();
                QList<QVariant> numbers;
                int bitIndex = 0;

                // Jedes Byte der Bitmaske durchgehen
                for (char byte : bitmask) {
                    for (int i = 0; i < 8; i++) {  // 8 Bits pro Byte
                        if (byte & (1 << i)) {  // Prüfen, ob das Bit gesetzt ist
                            int value = bitIndex + i;  // Position berechnen
                            if (value <= 400) {  // Wertebereich beachten
                                numbers.append(value);
                            }
                        }
                    }
                    bitIndex += 8;  // Zum nächsten Byte springen
                }

                list[3] = QVariant(numbers);  // Die extrahierten Zahlen in Position 4 setzen
            }
            m_coll_data.append(list);
        }

    endResetModel();
    emit newDataInsertion();
    //set_uniqueFunctions();

}
int Detailed_coll_data::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return m_coll_data.size();
}
int Detailed_coll_data::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 5;  // Beispiel: Anzahl der Spalten (z.B. für Job-ID, Startzeit, Endzeit)
}

QVariant Detailed_coll_data::data(const QModelIndex &index, int role) const {
    if(!index.isValid() || index.row() >= m_coll_data.size()){
        return QVariant();
    }
    QVariantList rowindex = m_coll_data.at(index.row());
    if(role == function){
        return rowindex.at(0);
    } else if (role == processrank){
        return rowindex.at(1);
    } else if (role == coll_algorithm){
        return rowindex.at(2);
    } else if (role == coll_partnerranks){
        return rowindex.at(3);
    }
    return QVariant();
}

QVariant Detailed_coll_data::simple_data(int row, const QString &role) const {
    if(row >= 0 && m_coll_data.size()) {
        QVariantList rowindex = m_coll_data.at(row);
        if(role == "function"){
            return rowindex.at(0);
        } else if (role == "processrank"){
            return rowindex.at(1);
        } else if (role == "coll_algorithm"){
            return rowindex.at(2);
        } else if(role == "coll_partnerranks"){
            return rowindex.at(3);
        }
    }
    return QVariant();
}

QHash<int, QByteArray> Detailed_coll_data::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[function] = "function";
    roles[processrank] = "processrank";
    roles[coll_algorithm] = "coll_algorithm";
    roles[coll_partnerranks] = "coll_partnerranks";
    return roles;
}
void Detailed_coll_data::set_uniqueFunctions() {
    QSet<QString> uniqueSet;
    for (const QVariantList &row : m_coll_data) {
        uniqueSet.insert(row.at(0).toString());  // Annahme: Funktion ist in Spalte 0
    }
    m_uniqueFunctions = uniqueSet.values().join(", ");
    emit uniqueFunctions_Changed();
}

QString Detailed_coll_data::uniqueFunctions() const{
    return m_uniqueFunctions;
}
