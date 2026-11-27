#include "app_mode.h"

#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QOperatingSystemVersion>
#include <QRegularExpression>
#include <QStandardPaths>

namespace {

// KEY=value-Datei lesen; gesetzte Umgebungsvariablen haben Vorrang (wie bei dev/compose.sh)
QMap<QString, QString> readEnvFile(const QString &path)
{
    QMap<QString, QString> values;
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return values;
    while (!file.atEnd()) {
        const QString line = QString::fromUtf8(file.readLine()).trimmed();
        const qsizetype eq = line.indexOf('=');
        if (line.startsWith('#') || eq <= 0)
            continue;
        const QString key = line.left(eq);
        values[key] = qEnvironmentVariable(key.toUtf8().constData(), line.mid(eq + 1));
    }
    return values;
}

// Pfad für die Git-for-Windows-Bash (C:/x -> /c/x); auf anderen Systemen unverändert
QString bashPath(QString path)
{
    path.replace('\\', '/');
    if (QOperatingSystemVersion::currentType() == QOperatingSystemVersion::Windows) {
        const QRegularExpressionMatch drive = QRegularExpression("^([A-Za-z]):/").match(path);
        if (drive.hasMatch())
            path = "/" + drive.captured(1).toLower() + "/" + path.mid(3);
    }
    return path;
}

QString shellQuote(const QString &s)
{
    QString q = s;
    q.replace('\\', "\\\\").replace('"', "\\\"").replace('$', "\\$").replace('`', "\\`");
    return "\"" + q + "\"";
}

struct Loaded {
    QVariantMap config;
    QString sshOptions;   // ohne Port-Flag
    QString sshPort;
};

#ifdef EDUMPI_DEV_MODE
Loaded loadDev()
{
    Loaded l;
    l.config["enabled"] = false;
    const QString path = qEnvironmentVariable("EDUMPI_DEV_ENV");
    const auto v = readEnvFile(path);
    if (path.isEmpty() || v.isEmpty()) {
        qWarning() << "[DEV] EDUMPI_DEV_ENV nicht gesetzt oder nicht lesbar - Dev-Modus aus"
                   << "(vorher 'source EduMPI/dev/ssh/activate')";
        return l;
    }
    l.config["mode"] = "dev";
    l.config["name"] = "Dev-Cluster";
    l.config["dbHost"] = v.value("EDUMPI_DEV_DB_HOST");
    l.config["dbPort"] = v.value("EDUMPI_DB_PORT", "5432");
    l.config["dbName"] = v.value("EDUMPI_DEV_DB_NAME");
    l.config["dbUser"] = v.value("EDUMPI_DEV_DB_USER");
    l.config["dbPassword"] = v.value("EDUMPI_DEV_DB_PW");
    l.config["clusterHost"] = v.value("EDUMPI_DEV_CLUSTER_HOST");
    l.config["clusterUser"] = v.value("EDUMPI_DEV_CLUSTER_USER");
    l.config["edumpiPath"] = v.value("EDUMPI_DEV_EDUMPI_PATH", "/opt/edumpi");
    l.config["maxRanks"] = 0;
    // Die GUI ruft ssh ohne Port-Option auf; nur der Wrapper leitet auf den Dev-Cluster um
    const QString ssh = QStandardPaths::findExecutable("ssh");
    l.config["sshWrapper"] = ssh.contains("/dev/ssh/bin/");
    if (!l.config["sshWrapper"].toBool())
        qWarning() << "[DEV] ssh ist nicht der Wrapper aus EduMPI/dev/ssh/bin:" << ssh;
    l.config["enabled"] = true;
    return l;
}
#endif

#ifdef EDUMPI_DEMO_MODE
Loaded loadDemo()
{
    Loaded l;
    l.config["enabled"] = false;
    const QString path = qEnvironmentVariable("EDUMPI_DEMO_ENV");
    const auto v = readEnvFile(path);
    if (path.isEmpty() || v.isEmpty()) {
        qWarning() << "[DEMO] EDUMPI_DEMO_ENV nicht gesetzt oder nicht lesbar - Demo-Modus aus"
                   << "(die GUI über start.sh bzw. start.cmd des Demo-Repos starten)";
        return l;
    }
    const QString key = v.value("EDUMPI_DEMO_SSH_KEY");
    const QString knownHosts = v.value("EDUMPI_DEMO_SSH_KNOWN_HOSTS");
    for (const QString &f : {key, knownHosts}) {
        if (!QFileInfo::exists(f))
            qWarning() << "[DEMO] Datei fehlt:" << f;
    }
    l.config["mode"] = "demo";
    l.config["name"] = v.value("EDUMPI_DEMO_NAME", "Demo");
    l.config["dbHost"] = v.value("EDUMPI_DEMO_DB_HOST", "127.0.0.1");
    l.config["dbPort"] = v.value("EDUMPI_DEMO_DB_PORT", "5432");
    l.config["dbName"] = v.value("EDUMPI_DEMO_DB_NAME", "edumpi");
    l.config["dbUser"] = v.value("EDUMPI_DEMO_DB_USER", "edumpi");
    l.config["dbPassword"] = v.value("EDUMPI_DEMO_DB_PW", "edumpi");
    l.config["clusterHost"] = v.value("EDUMPI_DEMO_CLUSTER_HOST", "127.0.0.1");
    l.config["clusterUser"] = v.value("EDUMPI_DEMO_CLUSTER_USER", "dev");
    l.config["edumpiPath"] = v.value("EDUMPI_DEMO_EDUMPI_PATH", "/opt/edumpi");
    l.config["maxRanks"] = v.value("EDUMPI_DEMO_MAX_RANKS", "0").toInt();
    l.config["sshPort"] = v.value("EDUMPI_DEMO_SSH_PORT", "22");
    l.config["sshWrapper"] = true;
    l.sshPort = l.config["sshPort"].toString();
    // BatchMode: nie nach einem Passwort fragen (würde die GUI blockieren); nur der Demo-Key,
    // nur der bekannte Host-Key des Demo-Clusters, unabhängig von ~/.ssh des Testers
    l.sshOptions = "-o BatchMode=yes -o ConnectTimeout=10 -o IdentitiesOnly=yes"
                   " -o StrictHostKeyChecking=yes -i " + shellQuote(bashPath(key))
                   + " -o " + shellQuote("UserKnownHostsFile=" + bashPath(knownHosts));
    l.config["enabled"] = true;
    return l;
}
#endif

const Loaded &loaded()
{
    static const Loaded l = [] {
#if defined(EDUMPI_DEMO_MODE)
        return loadDemo();
#elif defined(EDUMPI_DEV_MODE)
        return loadDev();
#else
        Loaded none;
        none.config["enabled"] = false;
        none.config["mode"] = "";
        return none;
#endif
    }();
    return l;
}

} // namespace

namespace AppMode {

const QVariantMap &config() { return loaded().config; }

bool demo() { return loaded().config.value("mode").toString() == "demo"; }

QString sshOptions()
{
    if (!demo())
        return QString();
    return "-p " + loaded().sshPort + " " + loaded().sshOptions;
}

QString scpOptions()
{
    if (!demo())
        return QString();
    return "-P " + loaded().sshPort + " " + loaded().sshOptions;
}

} // namespace AppMode
