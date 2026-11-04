#include "login_store.h"

#include <QSettings>
#include <QEventLoop>
#include <QDebug>

#ifdef EDUMPI_HAVE_KEYCHAIN
#include <qt6keychain/keychain.h>
#endif

namespace {

const char *kService = "EduMPI GUI";

// Native format by default; tests switch QSettings::setDefaultFormat() to a temporary folder.
QSettings settings(){
    return QSettings(QSettings::defaultFormat(), QSettings::UserScope, "EduMPI", "EduMPI GUI");
}

// One keychain entry per login: user@host:port/database
QString passwordKey(const QString &host, int port, const QString &name, const QString &user){
    return QString("%1@%2:%3/%4").arg(user, host).arg(port).arg(name);
}

#ifdef EDUMPI_HAVE_KEYCHAIN
// The jobs of QtKeychain run asynchronously; the login form needs the result at once.
QString readPassword(const QString &key){
    QKeychain::ReadPasswordJob job(kService);
    job.setAutoDelete(false);
    job.setKey(key);
    QEventLoop loop;
    QObject::connect(&job, &QKeychain::Job::finished, &loop, &QEventLoop::quit);
    job.start();
    loop.exec();
    if(job.error() != QKeychain::NoError){
        if(job.error() != QKeychain::EntryNotFound){
            qDebug() << "Keychain: password not read:" << job.errorString();
        }
        return QString();
    }
    return job.textData();
}

void writePassword(const QString &key, const QString &password){
    QKeychain::WritePasswordJob job(kService);
    job.setAutoDelete(false);
    job.setKey(key);
    job.setTextData(password);
    QEventLoop loop;
    QObject::connect(&job, &QKeychain::Job::finished, &loop, &QEventLoop::quit);
    job.start();
    loop.exec();
    if(job.error() != QKeychain::NoError){
        qDebug() << "Keychain: password not stored:" << job.errorString();
    }
}
#endif

} // namespace

QVariantMap Login_Store::loadDb(){
    QSettings s = settings();
    QVariantMap m;
    if(!s.contains("db/host")){
        return m;
    }
    const QString host = s.value("db/host").toString();
    const QString name = s.value("db/name").toString();
    const int port = s.value("db/port", 5432).toInt();
    const QString user = s.value("db/user").toString();
    m["host"] = host;
    m["name"] = name;
    m["port"] = port;
    m["user"] = user;
#ifdef EDUMPI_HAVE_KEYCHAIN
    m["password"] = readPassword(passwordKey(host, port, name, user));
#else
    m["password"] = QString();
#endif
    return m;
}

void Login_Store::saveDb(const QString &host, const QString &name, int port, const QString &user, const QString &password){
    QSettings s = settings();
    s.setValue("db/host", host);
    s.setValue("db/name", name);
    s.setValue("db/port", port);
    s.setValue("db/user", user);
#ifdef EDUMPI_HAVE_KEYCHAIN
    if(!password.isEmpty()){
        writePassword(passwordKey(host, port, name, user), password);
    }
#else
    Q_UNUSED(password);
#endif
}

QVariantMap Login_Store::loadCluster(){
    QSettings s = settings();
    QVariantMap m;
    if(!s.contains("cluster/ident")){
        return m;
    }
    m["address"] = s.value("cluster/address").toString();
    m["ident"] = s.value("cluster/ident").toString();
    m["path"] = s.value("cluster/path").toString();
    return m;
}

void Login_Store::saveCluster(const QString &address, const QString &ident, const QString &path){
    QSettings s = settings();
    s.setValue("cluster/address", address);
    s.setValue("cluster/ident", ident);
    s.setValue("cluster/path", path);
}
