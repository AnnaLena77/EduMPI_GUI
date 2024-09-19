/****************************************************************************
** Meta object code from reading C++ file 'database_connection.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../database_connection.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'database_connection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDatabase_ConnectionENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDatabase_ConnectionENDCLASS = QtMocHelpers::stringData(
    "Database_Connection",
    "QML.Element",
    "auto",
    "p2p_send_max_changed",
    "",
    "coll_send_max_changed",
    "p2p_recv_max_changed",
    "coll_recv_max_changed",
    "connectionChanged",
    "clusterConnectionChanged",
    "time_display_changed",
    "componentsBuilt",
    "connectionSignal",
    "success",
    "dataIn",
    "timestamp",
    "signalSlurmStatusChanged",
    "status",
    "copiedOutputFile",
    "output",
    "signalToConnect",
    "setProcNum",
    "proc_num",
    "signalToUpdateData",
    "signalToClearDB",
    "signalToShowTimestampData",
    "timestampA",
    "timestampB",
    "fetchEduMPIJobsForUser",
    "userId",
    "dbConnectionSuccessful",
    "buildClusterComponents",
    "QMap<QString,QList<int>>",
    "updateDataToUI",
    "QList<DataColumn>",
    "removeClusterComponents",
    "handleTimestamp",
    "slurm_status_changed",
    "getSlurmID",
    "id",
    "slotFetchEduMPIJobs",
    "connect",
    "hostname",
    "databasename",
    "port",
    "UserName",
    "password",
    "writeLocalBashFile",
    "local_path",
    "file",
    "closeApp",
    "cancelRunningJob",
    "startBash",
    "readBash",
    "writeBash",
    "content",
    "checkFile",
    "source",
    "program",
    "writeRemoteBashFile",
    "program_name",
    "option",
    "showConditionAt",
    "timeSecondsA",
    "timeSecondsB",
    "startAndStop",
    "start",
    "connectCluster",
    "address",
    "ident",
    "path",
    "connectClusterAsync",
    "QJSValue",
    "callback",
    "nodeAt",
    "Cluster_Node*",
    "index",
    "count",
    "p2p_send_max",
    "coll_send_max",
    "p2p_recv_max",
    "coll_recv_max",
    "db_connection",
    "cluster_connection",
    "time_display"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDatabase_ConnectionENDCLASS_t {
    uint offsetsAndSizes[170];
    char stringdata0[20];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[21];
    char stringdata4[1];
    char stringdata5[22];
    char stringdata6[21];
    char stringdata7[22];
    char stringdata8[18];
    char stringdata9[25];
    char stringdata10[21];
    char stringdata11[16];
    char stringdata12[17];
    char stringdata13[8];
    char stringdata14[7];
    char stringdata15[10];
    char stringdata16[25];
    char stringdata17[7];
    char stringdata18[17];
    char stringdata19[7];
    char stringdata20[16];
    char stringdata21[11];
    char stringdata22[9];
    char stringdata23[19];
    char stringdata24[16];
    char stringdata25[26];
    char stringdata26[11];
    char stringdata27[11];
    char stringdata28[23];
    char stringdata29[7];
    char stringdata30[23];
    char stringdata31[23];
    char stringdata32[25];
    char stringdata33[15];
    char stringdata34[18];
    char stringdata35[24];
    char stringdata36[16];
    char stringdata37[21];
    char stringdata38[11];
    char stringdata39[3];
    char stringdata40[20];
    char stringdata41[8];
    char stringdata42[9];
    char stringdata43[13];
    char stringdata44[5];
    char stringdata45[9];
    char stringdata46[9];
    char stringdata47[19];
    char stringdata48[11];
    char stringdata49[5];
    char stringdata50[9];
    char stringdata51[17];
    char stringdata52[10];
    char stringdata53[9];
    char stringdata54[10];
    char stringdata55[8];
    char stringdata56[10];
    char stringdata57[7];
    char stringdata58[8];
    char stringdata59[20];
    char stringdata60[13];
    char stringdata61[7];
    char stringdata62[16];
    char stringdata63[13];
    char stringdata64[13];
    char stringdata65[13];
    char stringdata66[6];
    char stringdata67[15];
    char stringdata68[8];
    char stringdata69[6];
    char stringdata70[5];
    char stringdata71[20];
    char stringdata72[9];
    char stringdata73[9];
    char stringdata74[7];
    char stringdata75[14];
    char stringdata76[6];
    char stringdata77[6];
    char stringdata78[13];
    char stringdata79[14];
    char stringdata80[13];
    char stringdata81[14];
    char stringdata82[14];
    char stringdata83[19];
    char stringdata84[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDatabase_ConnectionENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDatabase_ConnectionENDCLASS_t qt_meta_stringdata_CLASSDatabase_ConnectionENDCLASS = {
    {
        QT_MOC_LITERAL(0, 19),  // "Database_Connection"
        QT_MOC_LITERAL(20, 11),  // "QML.Element"
        QT_MOC_LITERAL(32, 4),  // "auto"
        QT_MOC_LITERAL(37, 20),  // "p2p_send_max_changed"
        QT_MOC_LITERAL(58, 0),  // ""
        QT_MOC_LITERAL(59, 21),  // "coll_send_max_changed"
        QT_MOC_LITERAL(81, 20),  // "p2p_recv_max_changed"
        QT_MOC_LITERAL(102, 21),  // "coll_recv_max_changed"
        QT_MOC_LITERAL(124, 17),  // "connectionChanged"
        QT_MOC_LITERAL(142, 24),  // "clusterConnectionChanged"
        QT_MOC_LITERAL(167, 20),  // "time_display_changed"
        QT_MOC_LITERAL(188, 15),  // "componentsBuilt"
        QT_MOC_LITERAL(204, 16),  // "connectionSignal"
        QT_MOC_LITERAL(221, 7),  // "success"
        QT_MOC_LITERAL(229, 6),  // "dataIn"
        QT_MOC_LITERAL(236, 9),  // "timestamp"
        QT_MOC_LITERAL(246, 24),  // "signalSlurmStatusChanged"
        QT_MOC_LITERAL(271, 6),  // "status"
        QT_MOC_LITERAL(278, 16),  // "copiedOutputFile"
        QT_MOC_LITERAL(295, 6),  // "output"
        QT_MOC_LITERAL(302, 15),  // "signalToConnect"
        QT_MOC_LITERAL(318, 10),  // "setProcNum"
        QT_MOC_LITERAL(329, 8),  // "proc_num"
        QT_MOC_LITERAL(338, 18),  // "signalToUpdateData"
        QT_MOC_LITERAL(357, 15),  // "signalToClearDB"
        QT_MOC_LITERAL(373, 25),  // "signalToShowTimestampData"
        QT_MOC_LITERAL(399, 10),  // "timestampA"
        QT_MOC_LITERAL(410, 10),  // "timestampB"
        QT_MOC_LITERAL(421, 22),  // "fetchEduMPIJobsForUser"
        QT_MOC_LITERAL(444, 6),  // "userId"
        QT_MOC_LITERAL(451, 22),  // "dbConnectionSuccessful"
        QT_MOC_LITERAL(474, 22),  // "buildClusterComponents"
        QT_MOC_LITERAL(497, 24),  // "QMap<QString,QList<int>>"
        QT_MOC_LITERAL(522, 14),  // "updateDataToUI"
        QT_MOC_LITERAL(537, 17),  // "QList<DataColumn>"
        QT_MOC_LITERAL(555, 23),  // "removeClusterComponents"
        QT_MOC_LITERAL(579, 15),  // "handleTimestamp"
        QT_MOC_LITERAL(595, 20),  // "slurm_status_changed"
        QT_MOC_LITERAL(616, 10),  // "getSlurmID"
        QT_MOC_LITERAL(627, 2),  // "id"
        QT_MOC_LITERAL(630, 19),  // "slotFetchEduMPIJobs"
        QT_MOC_LITERAL(650, 7),  // "connect"
        QT_MOC_LITERAL(658, 8),  // "hostname"
        QT_MOC_LITERAL(667, 12),  // "databasename"
        QT_MOC_LITERAL(680, 4),  // "port"
        QT_MOC_LITERAL(685, 8),  // "UserName"
        QT_MOC_LITERAL(694, 8),  // "password"
        QT_MOC_LITERAL(703, 18),  // "writeLocalBashFile"
        QT_MOC_LITERAL(722, 10),  // "local_path"
        QT_MOC_LITERAL(733, 4),  // "file"
        QT_MOC_LITERAL(738, 8),  // "closeApp"
        QT_MOC_LITERAL(747, 16),  // "cancelRunningJob"
        QT_MOC_LITERAL(764, 9),  // "startBash"
        QT_MOC_LITERAL(774, 8),  // "readBash"
        QT_MOC_LITERAL(783, 9),  // "writeBash"
        QT_MOC_LITERAL(793, 7),  // "content"
        QT_MOC_LITERAL(801, 9),  // "checkFile"
        QT_MOC_LITERAL(811, 6),  // "source"
        QT_MOC_LITERAL(818, 7),  // "program"
        QT_MOC_LITERAL(826, 19),  // "writeRemoteBashFile"
        QT_MOC_LITERAL(846, 12),  // "program_name"
        QT_MOC_LITERAL(859, 6),  // "option"
        QT_MOC_LITERAL(866, 15),  // "showConditionAt"
        QT_MOC_LITERAL(882, 12),  // "timeSecondsA"
        QT_MOC_LITERAL(895, 12),  // "timeSecondsB"
        QT_MOC_LITERAL(908, 12),  // "startAndStop"
        QT_MOC_LITERAL(921, 5),  // "start"
        QT_MOC_LITERAL(927, 14),  // "connectCluster"
        QT_MOC_LITERAL(942, 7),  // "address"
        QT_MOC_LITERAL(950, 5),  // "ident"
        QT_MOC_LITERAL(956, 4),  // "path"
        QT_MOC_LITERAL(961, 19),  // "connectClusterAsync"
        QT_MOC_LITERAL(981, 8),  // "QJSValue"
        QT_MOC_LITERAL(990, 8),  // "callback"
        QT_MOC_LITERAL(999, 6),  // "nodeAt"
        QT_MOC_LITERAL(1006, 13),  // "Cluster_Node*"
        QT_MOC_LITERAL(1020, 5),  // "index"
        QT_MOC_LITERAL(1026, 5),  // "count"
        QT_MOC_LITERAL(1032, 12),  // "p2p_send_max"
        QT_MOC_LITERAL(1045, 13),  // "coll_send_max"
        QT_MOC_LITERAL(1059, 12),  // "p2p_recv_max"
        QT_MOC_LITERAL(1072, 13),  // "coll_recv_max"
        QT_MOC_LITERAL(1086, 13),  // "db_connection"
        QT_MOC_LITERAL(1100, 18),  // "cluster_connection"
        QT_MOC_LITERAL(1119, 12)   // "time_display"
    },
    "Database_Connection",
    "QML.Element",
    "auto",
    "p2p_send_max_changed",
    "",
    "coll_send_max_changed",
    "p2p_recv_max_changed",
    "coll_recv_max_changed",
    "connectionChanged",
    "clusterConnectionChanged",
    "time_display_changed",
    "componentsBuilt",
    "connectionSignal",
    "success",
    "dataIn",
    "timestamp",
    "signalSlurmStatusChanged",
    "status",
    "copiedOutputFile",
    "output",
    "signalToConnect",
    "setProcNum",
    "proc_num",
    "signalToUpdateData",
    "signalToClearDB",
    "signalToShowTimestampData",
    "timestampA",
    "timestampB",
    "fetchEduMPIJobsForUser",
    "userId",
    "dbConnectionSuccessful",
    "buildClusterComponents",
    "QMap<QString,QList<int>>",
    "updateDataToUI",
    "QList<DataColumn>",
    "removeClusterComponents",
    "handleTimestamp",
    "slurm_status_changed",
    "getSlurmID",
    "id",
    "slotFetchEduMPIJobs",
    "connect",
    "hostname",
    "databasename",
    "port",
    "UserName",
    "password",
    "writeLocalBashFile",
    "local_path",
    "file",
    "closeApp",
    "cancelRunningJob",
    "startBash",
    "readBash",
    "writeBash",
    "content",
    "checkFile",
    "source",
    "program",
    "writeRemoteBashFile",
    "program_name",
    "option",
    "showConditionAt",
    "timeSecondsA",
    "timeSecondsB",
    "startAndStop",
    "start",
    "connectCluster",
    "address",
    "ident",
    "path",
    "connectClusterAsync",
    "QJSValue",
    "callback",
    "nodeAt",
    "Cluster_Node*",
    "index",
    "count",
    "p2p_send_max",
    "coll_send_max",
    "p2p_recv_max",
    "coll_recv_max",
    "db_connection",
    "cluster_connection",
    "time_display"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDatabase_ConnectionENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       1,   14, // classinfo
      40,   16, // methods
       8,  390, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      18,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  256,    4, 0x06,    9 /* Public */,
       5,    0,  257,    4, 0x06,   10 /* Public */,
       6,    0,  258,    4, 0x06,   11 /* Public */,
       7,    0,  259,    4, 0x06,   12 /* Public */,
       8,    0,  260,    4, 0x06,   13 /* Public */,
       9,    0,  261,    4, 0x06,   14 /* Public */,
      10,    0,  262,    4, 0x06,   15 /* Public */,
      11,    0,  263,    4, 0x06,   16 /* Public */,
      12,    1,  264,    4, 0x06,   17 /* Public */,
      14,    1,  267,    4, 0x06,   19 /* Public */,
      16,    1,  270,    4, 0x06,   21 /* Public */,
      18,    1,  273,    4, 0x06,   23 /* Public */,
      20,    5,  276,    4, 0x06,   25 /* Public */,
      21,    1,  287,    4, 0x06,   31 /* Public */,
      23,    1,  290,    4, 0x06,   33 /* Public */,
      24,    0,  293,    4, 0x06,   35 /* Public */,
      25,    2,  294,    4, 0x06,   36 /* Public */,
      28,    1,  299,    4, 0x06,   39 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      30,    1,  302,    4, 0x0a,   41 /* Public */,
      31,    1,  305,    4, 0x0a,   43 /* Public */,
      33,    1,  308,    4, 0x0a,   45 /* Public */,
      35,    0,  311,    4, 0x0a,   47 /* Public */,
      36,    1,  312,    4, 0x0a,   48 /* Public */,
      37,    1,  315,    4, 0x0a,   50 /* Public */,
      38,    1,  318,    4, 0x0a,   52 /* Public */,
      40,    0,  321,    4, 0x0a,   54 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      41,    5,  322,    4, 0x02,   55 /* Public */,
      47,    3,  333,    4, 0x02,   61 /* Public */,
      50,    0,  340,    4, 0x02,   65 /* Public */,
      51,    0,  341,    4, 0x02,   66 /* Public */,
      52,    1,  342,    4, 0x02,   67 /* Public */,
      53,    0,  345,    4, 0x02,   69 /* Public */,
      54,    1,  346,    4, 0x02,   70 /* Public */,
      56,    3,  349,    4, 0x02,   72 /* Public */,
      59,    3,  356,    4, 0x02,   76 /* Public */,
      62,    2,  363,    4, 0x02,   80 /* Public */,
      65,    1,  368,    4, 0x02,   83 /* Public */,
      67,    3,  371,    4, 0x02,   85 /* Public */,
      71,    4,  378,    4, 0x02,   89 /* Public */,
      74,    1,  387,    4, 0x02,   94 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    4,    4,    4,    4,    4,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime, QMetaType::QTime,   26,   27,
    QMetaType::Void, QMetaType::QString,   29,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, 0x80000000 | 32,    4,
    QMetaType::Void, 0x80000000 | 34,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,   42,   43,   44,   45,   46,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Int,   48,   49,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   55,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   57,   58,   49,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   60,   22,   61,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   63,   64,
    QMetaType::Void, QMetaType::Bool,   66,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   68,   69,   70,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 72,   68,   69,   70,   73,
    0x80000000 | 75, QMetaType::Int,   76,

 // properties: name, type, flags
      77, QMetaType::Int, 0x00015401, uint(-1), 0,
      78, QMetaType::Long, 0x00015003, uint(0), 0,
      79, QMetaType::Long, 0x00015003, uint(1), 0,
      80, QMetaType::Long, 0x00015003, uint(2), 0,
      81, QMetaType::Long, 0x00015003, uint(3), 0,
      82, QMetaType::Bool, 0x00015003, uint(4), 0,
      83, QMetaType::Bool, 0x00015003, uint(5), 0,
      84, QMetaType::Int, 0x00015003, uint(6), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Database_Connection::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSDatabase_ConnectionENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDatabase_ConnectionENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'count'
        int,
        // property 'p2p_send_max'
        long,
        // property 'coll_send_max'
        long,
        // property 'p2p_recv_max'
        long,
        // property 'coll_recv_max'
        long,
        // property 'db_connection'
        bool,
        // property 'cluster_connection'
        bool,
        // property 'time_display'
        int,
        // Q_OBJECT / Q_GADGET
        Database_Connection,
        // method 'p2p_send_max_changed'
        void,
        // method 'coll_send_max_changed'
        void,
        // method 'p2p_recv_max_changed'
        void,
        // method 'coll_recv_max_changed'
        void,
        // method 'connectionChanged'
        void,
        // method 'clusterConnectionChanged'
        void,
        // method 'time_display_changed'
        void,
        // method 'componentsBuilt'
        void,
        // method 'connectionSignal'
        void,
        bool,
        // method 'dataIn'
        void,
        int,
        // method 'signalSlurmStatusChanged'
        void,
        QString,
        // method 'copiedOutputFile'
        void,
        QString,
        // method 'signalToConnect'
        void,
        const QString &,
        const QString &,
        const int &,
        const QString &,
        const QString &,
        // method 'setProcNum'
        void,
        const int,
        // method 'signalToUpdateData'
        void,
        const int &,
        // method 'signalToClearDB'
        void,
        // method 'signalToShowTimestampData'
        void,
        const QTime,
        const QTime,
        // method 'fetchEduMPIJobsForUser'
        void,
        const QString &,
        // method 'dbConnectionSuccessful'
        void,
        const bool &,
        // method 'buildClusterComponents'
        void,
        const QMap<QString,QVector<int>> &,
        // method 'updateDataToUI'
        void,
        const QList<DataColumn> &,
        // method 'removeClusterComponents'
        void,
        // method 'handleTimestamp'
        void,
        QTime,
        // method 'slurm_status_changed'
        void,
        QString,
        // method 'getSlurmID'
        void,
        const int,
        // method 'slotFetchEduMPIJobs'
        void,
        // method 'connect'
        void,
        QString,
        QString,
        int,
        QString,
        QString,
        // method 'writeLocalBashFile'
        void,
        QString,
        bool,
        int,
        // method 'closeApp'
        void,
        // method 'cancelRunningJob'
        void,
        // method 'startBash'
        void,
        int,
        // method 'readBash'
        QString,
        // method 'writeBash'
        void,
        QString,
        // method 'checkFile'
        bool,
        QString,
        QString,
        bool,
        // method 'writeRemoteBashFile'
        void,
        QString,
        int,
        int,
        // method 'showConditionAt'
        void,
        int,
        int,
        // method 'startAndStop'
        void,
        bool,
        // method 'connectCluster'
        QString,
        const QString &,
        const QString &,
        const QString &,
        // method 'connectClusterAsync'
        void,
        const QString &,
        const QString &,
        const QString &,
        QJSValue,
        // method 'nodeAt'
        Cluster_Node *,
        int
    >,
    nullptr
} };

void Database_Connection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Database_Connection *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->p2p_send_max_changed(); break;
        case 1: _t->coll_send_max_changed(); break;
        case 2: _t->p2p_recv_max_changed(); break;
        case 3: _t->coll_recv_max_changed(); break;
        case 4: _t->connectionChanged(); break;
        case 5: _t->clusterConnectionChanged(); break;
        case 6: _t->time_display_changed(); break;
        case 7: _t->componentsBuilt(); break;
        case 8: _t->connectionSignal((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->dataIn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->signalSlurmStatusChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->copiedOutputFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->signalToConnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 13: _t->setProcNum((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->signalToUpdateData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->signalToClearDB(); break;
        case 16: _t->signalToShowTimestampData((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[2]))); break;
        case 17: _t->fetchEduMPIJobsForUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->dbConnectionSuccessful((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 19: _t->buildClusterComponents((*reinterpret_cast< std::add_pointer_t<QMap<QString,QList<int>>>>(_a[1]))); break;
        case 20: _t->updateDataToUI((*reinterpret_cast< std::add_pointer_t<QList<DataColumn>>>(_a[1]))); break;
        case 21: _t->removeClusterComponents(); break;
        case 22: _t->handleTimestamp((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1]))); break;
        case 23: _t->slurm_status_changed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 24: _t->getSlurmID((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: _t->slotFetchEduMPIJobs(); break;
        case 26: _t->connect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 27: _t->writeLocalBashFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 28: _t->closeApp(); break;
        case 29: _t->cancelRunningJob(); break;
        case 30: _t->startBash((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 31: { QString _r = _t->readBash();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 32: _t->writeBash((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 33: { bool _r = _t->checkFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 34: _t->writeRemoteBashFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 35: _t->showConditionAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 36: _t->startAndStop((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 37: { QString _r = _t->connectCluster((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 38: _t->connectClusterAsync((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QJSValue>>(_a[4]))); break;
        case 39: { Cluster_Node* _r = _t->nodeAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< Cluster_Node**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 38:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 3:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QJSValue >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Database_Connection::*)();
            if (_t _q_method = &Database_Connection::p2p_send_max_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)();
            if (_t _q_method = &Database_Connection::coll_send_max_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)();
            if (_t _q_method = &Database_Connection::p2p_recv_max_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)();
            if (_t _q_method = &Database_Connection::coll_recv_max_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)();
            if (_t _q_method = &Database_Connection::connectionChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)();
            if (_t _q_method = &Database_Connection::clusterConnectionChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)();
            if (_t _q_method = &Database_Connection::time_display_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)();
            if (_t _q_method = &Database_Connection::componentsBuilt; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)(bool );
            if (_t _q_method = &Database_Connection::connectionSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)(int );
            if (_t _q_method = &Database_Connection::dataIn; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)(QString );
            if (_t _q_method = &Database_Connection::signalSlurmStatusChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)(QString );
            if (_t _q_method = &Database_Connection::copiedOutputFile; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)(const QString & , const QString & , const int & , const QString & , const QString & );
            if (_t _q_method = &Database_Connection::signalToConnect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)(const int );
            if (_t _q_method = &Database_Connection::setProcNum; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)(const int & );
            if (_t _q_method = &Database_Connection::signalToUpdateData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)();
            if (_t _q_method = &Database_Connection::signalToClearDB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)(const QTime , const QTime );
            if (_t _q_method = &Database_Connection::signalToShowTimestampData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)(const QString & );
            if (_t _q_method = &Database_Connection::fetchEduMPIJobsForUser; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Database_Connection *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->count(); break;
        case 1: *reinterpret_cast< long*>(_v) = _t->p2p_send_max(); break;
        case 2: *reinterpret_cast< long*>(_v) = _t->coll_send_max(); break;
        case 3: *reinterpret_cast< long*>(_v) = _t->p2p_recv_max(); break;
        case 4: *reinterpret_cast< long*>(_v) = _t->coll_recv_max(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->m_connection_ready; break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->m_cluster_connection_ready; break;
        case 7: *reinterpret_cast< int*>(_v) = _t->m_time_display; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Database_Connection *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->set_p2p_send_max(*reinterpret_cast< long*>(_v)); break;
        case 2: _t->set_coll_send_max(*reinterpret_cast< long*>(_v)); break;
        case 3: _t->set_p2p_recv_max(*reinterpret_cast< long*>(_v)); break;
        case 4: _t->set_coll_recv_max(*reinterpret_cast< long*>(_v)); break;
        case 5:
            if (_t->m_connection_ready != *reinterpret_cast< bool*>(_v)) {
                _t->m_connection_ready = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->connectionChanged();
            }
            break;
        case 6:
            if (_t->m_cluster_connection_ready != *reinterpret_cast< bool*>(_v)) {
                _t->m_cluster_connection_ready = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->clusterConnectionChanged();
            }
            break;
        case 7:
            if (_t->m_time_display != *reinterpret_cast< int*>(_v)) {
                _t->m_time_display = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->time_display_changed();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Database_Connection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Database_Connection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDatabase_ConnectionENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Database_Connection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Database_Connection::p2p_send_max_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Database_Connection::coll_send_max_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Database_Connection::p2p_recv_max_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Database_Connection::coll_recv_max_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Database_Connection::connectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Database_Connection::clusterConnectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Database_Connection::time_display_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Database_Connection::componentsBuilt()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Database_Connection::connectionSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Database_Connection::dataIn(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Database_Connection::signalSlurmStatusChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Database_Connection::copiedOutputFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Database_Connection::signalToConnect(const QString & _t1, const QString & _t2, const int & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Database_Connection::setProcNum(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Database_Connection::signalToUpdateData(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Database_Connection::signalToClearDB()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void Database_Connection::signalToShowTimestampData(const QTime _t1, const QTime _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Database_Connection::fetchEduMPIJobsForUser(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}
QT_WARNING_POP
