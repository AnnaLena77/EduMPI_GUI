/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<cluster_node.h>)
#  include <cluster_node.h>
#endif
#if __has_include(<cluster_rank.h>)
#  include <cluster_rank.h>
#endif
#if __has_include(<controller.h>)
#  include <controller.h>
#endif
#if __has_include(<nodes_instances.h>)
#  include <nodes_instances.h>
#endif
#if __has_include(<ranks_instances.h>)
#  include <ranks_instances.h>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_GUI_Cluster()
{
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<Cluster_Node>("GUI_Cluster", 1);
    qmlRegisterTypesAndRevisions<Cluster_Rank>("GUI_Cluster", 1);
    qmlRegisterTypesAndRevisions<Controller>("GUI_Cluster", 1);
    qmlRegisterTypesAndRevisions<Nodes_Instances>("GUI_Cluster", 1);
    qmlRegisterAnonymousType<QQuick3DInstancing, 254>("GUI_Cluster", 1);
    qmlRegisterTypesAndRevisions<Ranks_Instances>("GUI_Cluster", 1);
    QT_WARNING_POP
    qmlRegisterModule("GUI_Cluster", 1, 0);
}

static const QQmlModuleRegistration gUIClusterRegistration("GUI_Cluster", qml_register_types_GUI_Cluster);
