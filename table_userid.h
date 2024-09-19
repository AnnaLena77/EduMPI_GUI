#include <QAbstractListModel>
#include <QStringList>
#include <QVariantList>
#include "qqmlintegration.h"

#ifndef TABLE_USERID_H
#define TABLE_USERID_H

class Table_UserID: public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit Table_UserID(QObject *parent = nullptr);
    ~Table_UserID() override;

    Q_INVOKABLE void loadJobs(const QString &userId);

    enum Roles {
        JobIdRole = Qt::UserRole + 1
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void fetchEduMPIJobsForUser();

signals:
    void eduMPIJobsFetchedForUser(const QVariantList &jobIds);

private:
        QVariantList m_edumpi_runs;


};

#endif // TABLE_USERID_H
