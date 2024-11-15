#include <QAbstractListModel>
#include <QStringList>
#include <QVariantList>
#include "database_connection.h"

#ifndef TABLE_USERID_H
#define TABLE_USERID_H

class Table_UserID: public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit Table_UserID(QObject *parent = nullptr);
    ~Table_UserID() override;

    Q_INVOKABLE void loadJobs(const QString &userId);
    //Q_INVOKABLE void setDatabaseConnection(Database_Connection *dbConnection);

    enum Roles {
        JobIdRole = Qt::UserRole + 1,
        StartTime = Qt::UserRole + 2,
        EndTime = Qt::UserRole +3
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void fetchEduMPIJobsForUser();

signals:
    void eduMPIJobsFetchedForUser(const QVariantList &jobIds);

private:
    //database-connection
    QString m_connectionName = "mainConnection";
    QList<QVariantList> m_edumpi_runs;


};

#endif // TABLE_USERID_H
