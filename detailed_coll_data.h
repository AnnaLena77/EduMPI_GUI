#ifndef DETAILED_COLL_DATA_H
#define DETAILED_COLL_DATA_H

#include <QtCore/qglobal.h>
#include <QAbstractListModel>
#include <QStringList>
#include <QVariantList>
#include <QSqlDatabase>


class Detailed_coll_data: public QAbstractTableModel
{
    Q_OBJECT
    //Q_PROPERTY(QString uniqueFunctions READ uniqueFunctions WRITE set_uniqueFunctions NOTIFY uniqueFunctions_Changed)

public:
    explicit Detailed_coll_data(QObject *parent = nullptr);
    ~Detailed_coll_data() override;

    enum Roles {
        function = Qt::UserRole + 1,
        processrank = Qt::UserRole + 2,
        coll_algorithm = Qt::UserRole +3,
        coll_partnerranks = Qt::UserRole +4

    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE QVariant simple_data(int row, const QString &role) const;
    Q_INVOKABLE QString uniqueFunctions() const;
    QHash<int, QByteArray> roleNames() const override;

    void set_uniqueFunctions();


public slots:
    void queryData(QList<QVariantList> query);
signals:
    void newDataInsertion();
    void uniqueFunctions_Changed();

private:
    QList<QVariantList> m_coll_data;
    QString m_uniqueFunctions;

};

#endif // DETAILED_COLL_DATA_H
