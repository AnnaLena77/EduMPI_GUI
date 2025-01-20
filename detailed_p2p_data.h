#include <QtCore/qglobal.h>
#include <QAbstractListModel>
#include <QStringList>
#include <QVariantList>
#include <QSqlDatabase>

#ifndef DETAILED_P2P_DATA_H
#define DETAILED_P2P_DATA_H


class Detailed_p2p_data: public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit Detailed_p2p_data(QObject *parent = nullptr);
    ~Detailed_p2p_data() override;

    enum Roles {
        function = Qt::UserRole + 1,
        processrank = Qt::UserRole + 2,
        partnerrank = Qt::UserRole +3,
        send_ds = Qt::UserRole + 4,
        recv_ds = Qt:: UserRole + 5

    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void queryData(QList<QVariantList> query);



private:
    QList<QVariantList> m_p2p_data;


};


#endif // DETAILED_P2P_DATA_H
