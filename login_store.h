#ifndef LOGIN_STORE_H
#define LOGIN_STORE_H

#include <QString>
#include <QVariantMap>

// Remembers the last successful logins. Host, database, port, user and the cluster details go into
// QSettings (plain text, nothing secret). The database password goes into the keychain of the
// operating system (QtKeychain: macOS Keychain, Windows Credential Manager, Secret Service on Linux).
// Without QtKeychain (EDUMPI_HAVE_KEYCHAIN not defined) or without a running keychain service the
// password is simply not remembered; it is never written to a file.
class Login_Store
{
public:
    static QVariantMap loadDb();        // host, name, port, user, password (empty if unknown)
    static void saveDb(const QString &host, const QString &name, int port, const QString &user, const QString &password);
    static QVariantMap loadCluster();   // address, ident, path
    static void saveCluster(const QString &address, const QString &ident, const QString &path);
};

#endif // LOGIN_STORE_H
