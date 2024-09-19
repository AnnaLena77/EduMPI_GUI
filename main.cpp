#include "database_connection.h"
#include "table_userid.h"

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

    //QScopedPointer<Database_Connection> db(new Database_Connection);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<Database_Connection>("Qt.db.models", 1, 0, "NodesList");
    qmlRegisterType<Table_UserID>("Qt.db.models", 1, 0, "Table_UserID");

    const QUrl url(u"qrc:/GUI_Cluster/main.qml"_qs);
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


    return app.exec();
}
