#ifndef APP_MODE_H
#define APP_MODE_H

#include <QString>
#include <QVariantMap>

// Auto-Connect-Modi der GUI, beide nur per CMake-Option einkompiliert und erst aktiv, wenn die
// zugehörige Umgebungsvariable auf eine lesbare KEY=value-Datei zeigt:
//   Dev-Modus  (EDUMPI_DEV_MODE,  EDUMPI_DEV_ENV):  lokaler Dev-Cluster aus EduMPI/dev, gui.env
//   Demo-Modus (EDUMPI_DEMO_MODE, EDUMPI_DEMO_ENV): Demo-Repo tool-edumpi-docker, .run/demo.env
// Ohne Option oder Datei verhält sich die GUI wie bisher (config().enabled == false).
namespace AppMode {

// Für QML (Kontext-Eigenschaft "appMode"): mode ("", "dev" oder "demo"), enabled, name,
// dbHost, dbPort, dbName, dbUser, dbPassword, clusterHost, clusterUser, edumpiPath,
// maxRanks (nur demo, 0 = unbegrenzt), sshWrapper (nur dev).
const QVariantMap &config();

bool demo();

// Zusätzliche Optionen für ssh bzw. scp im Demo-Modus (Port, Key, known_hosts, BatchMode),
// fertig für die Shell gequotet; sonst leer. scp braucht -P statt -p für den Port.
QString sshOptions();
QString scpOptions();

} // namespace AppMode

#endif // APP_MODE_H
