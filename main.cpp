#include "controller.h"
#include "cluster_architecture.h"
#include "table_userid.h"
#include "ranks_instances.h"
#include "customlinegeometry.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>
#include <QQuickWindow>

#include <QQuickView>

#include <QtQuick3D/qquick3d.h>


int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray());
    qputenv("QT_WAYLAND_DISABLE_TEXT_INPUT", "1");
    qputenv("QT_LOGGING_RULES", "qt.qpa.wayland.textinput=false");

    //QScopedPointer<Database_Connection> db(new Database_Connection);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    //engine.addImportPath("qrc:/");
    //engine.addImportPath("qrc:/Sidebar/"); // Speziell für Sidebar

    const char *homeDir = getenv("HOME");
    if (homeDir == nullptr) {
        homeDir = ""; // Fallback, falls HOME nicht definiert ist
    }

    // Übergabe des Home-Verzeichnisses an QML
    engine.rootContext()->setContextProperty("homeDirectory", QString(homeDir));

    // Set default pictures path for screenshots
    engine.rootContext()->setContextProperty("picturesDirectory",
                                             QStandardPaths::writableLocation(QStandardPaths::PicturesLocation));

    //qmlRegisterType<CustomLineGeometry>("CustomGeometry", 1, 0, "CustomLineGeometry");


    //qmlRegisterType<Controller>("appGui_Cluster.Controller", 1, 0, "Controller");
    //qmlRegisterType<Cluster_Architecture>("appGui_Cluster.Nodes", 1, 0, "Nodes_List");
    //qmlRegisterType<Table_UserID>("Qt.db.models", 1, 0, "TableUserID");

    //const QUrl url(u"qrc:/GUI_Cluster/main.qml"_qs);

    const QUrl url(QStringLiteral("qrc:/GUI_Cluster/main.qml"));

    /*QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);*/
    engine.load(url);
    //qmlRegisterSingletonInstance("Qt.db.qobjectSingleton", 1, 0, "NodesList", db.get());

    //Database_Connection dbi;

    //QQmlContext* context = engine.rootContext();

    //context->setContextProperty("NodesList", &dbi);
    //qDebug() << "Current thread Main Main:" << QThread::currentThread();

    return app.exec();
}
