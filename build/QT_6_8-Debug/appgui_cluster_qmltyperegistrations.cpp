/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#include <cluster_node.h>
#include <cluster_rank.h>
#include <controller.h>
#include <nodes_instances.h>
#include <ranks_instances.h>


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_GUI_Cluster()
{
    qmlRegisterTypesAndRevisions<Cluster_Node>("GUI_Cluster", 1);
    qmlRegisterTypesAndRevisions<Cluster_Rank>("GUI_Cluster", 1);
    qmlRegisterTypesAndRevisions<Controller>("GUI_Cluster", 1);
    qmlRegisterTypesAndRevisions<Nodes_Instances>("GUI_Cluster", 1);
    qmlRegisterAnonymousType<QQuick3DInstancing, 254>("GUI_Cluster", 1);
    qmlRegisterTypesAndRevisions<Ranks_Instances>("GUI_Cluster", 1);
    qmlRegisterModule("GUI_Cluster", 1, 0);
}

static const QQmlModuleRegistration registration("GUI_Cluster", qml_register_types_GUI_Cluster);
