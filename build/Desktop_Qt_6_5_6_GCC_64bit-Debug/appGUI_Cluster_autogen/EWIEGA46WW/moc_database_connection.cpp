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
    "signalToConnect",
    "setProcNum",
    "proc_num",
    "signalToUpdateData",
    "signalToClearDB",
    "signalToShowTimestampData",
    "timestampA",
    "timestampB",
    "signalSlurmStatusChanged",
    "status",
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
    "startBash",
    "readBash",
    "writeBash",
    "content",
    "checkFile",
    "source",
    "program",
    "writeRemoteBashFile",
    "program_name",
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
    "getOutputFile",
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
    uint offsetsAndSizes[158];
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
    char stringdata16[16];
    char stringdata17[11];
    char stringdata18[9];
    char stringdata19[19];
    char stringdata20[16];
    char stringdata21[26];
    char stringdata22[11];
    char stringdata23[11];
    char stringdata24[25];
    char stringdata25[7];
    char stringdata26[23];
    char stringdata27[23];
    char stringdata28[25];
    char stringdata29[15];
    char stringdata30[18];
    char stringdata31[24];
    char stringdata32[16];
    char stringdata33[21];
    char stringdata34[11];
    char stringdata35[3];
    char stringdata36[8];
    char stringdata37[9];
    char stringdata38[13];
    char stringdata39[5];
    char stringdata40[9];
    char stringdata41[9];
    char stringdata42[19];
    char stringdata43[11];
    char stringdata44[5];
    char stringdata45[9];
    char stringdata46[10];
    char stringdata47[9];
    char stringdata48[10];
    char stringdata49[8];
    char stringdata50[10];
    char stringdata51[7];
    char stringdata52[8];
    char stringdata53[20];
    char stringdata54[13];
    char stringdata55[16];
    char stringdata56[13];
    char stringdata57[13];
    char stringdata58[13];
    char stringdata59[6];
    char stringdata60[15];
    char stringdata61[8];
    char stringdata62[6];
    char stringdata63[5];
    char stringdata64[20];
    char stringdata65[9];
    char stringdata66[9];
    char stringdata67[14];
    char stringdata68[7];
    char stringdata69[14];
    char stringdata70[6];
    char stringdata71[6];
    char stringdata72[13];
    char stringdata73[14];
    char stringdata74[13];
    char stringdata75[14];
    char stringdata76[14];
    char stringdata77[19];
    char stringdata78[13];
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
        QT_MOC_LITERAL(246, 15),  // "signalToConnect"
        QT_MOC_LITERAL(262, 10),  // "setProcNum"
        QT_MOC_LITERAL(273, 8),  // "proc_num"
        QT_MOC_LITERAL(282, 18),  // "signalToUpdateData"
        QT_MOC_LITERAL(301, 15),  // "signalToClearDB"
        QT_MOC_LITERAL(317, 25),  // "signalToShowTimestampData"
        QT_MOC_LITERAL(343, 10),  // "timestampA"
        QT_MOC_LITERAL(354, 10),  // "timestampB"
        QT_MOC_LITERAL(365, 24),  // "signalSlurmStatusChanged"
        QT_MOC_LITERAL(390, 6),  // "status"
        QT_MOC_LITERAL(397, 22),  // "dbConnectionSuccessful"
        QT_MOC_LITERAL(420, 22),  // "buildClusterComponents"
        QT_MOC_LITERAL(443, 24),  // "QMap<QString,QList<int>>"
        QT_MOC_LITERAL(468, 14),  // "updateDataToUI"
        QT_MOC_LITERAL(483, 17),  // "QList<DataColumn>"
        QT_MOC_LITERAL(501, 23),  // "removeClusterComponents"
        QT_MOC_LITERAL(525, 15),  // "handleTimestamp"
        QT_MOC_LITERAL(541, 20),  // "slurm_status_changed"
        QT_MOC_LITERAL(562, 10),  // "getSlurmID"
        QT_MOC_LITERAL(573, 2),  // "id"
        QT_MOC_LITERAL(576, 7),  // "connect"
        QT_MOC_LITERAL(584, 8),  // "hostname"
        QT_MOC_LITERAL(593, 12),  // "databasename"
        QT_MOC_LITERAL(606, 4),  // "port"
        QT_MOC_LITERAL(611, 8),  // "UserName"
        QT_MOC_LITERAL(620, 8),  // "password"
        QT_MOC_LITERAL(629, 18),  // "writeLocalBashFile"
        QT_MOC_LITERAL(648, 10),  // "local_path"
        QT_MOC_LITERAL(659, 4),  // "file"
        QT_MOC_LITERAL(664, 8),  // "closeApp"
        QT_MOC_LITERAL(673, 9),  // "startBash"
        QT_MOC_LITERAL(683, 8),  // "readBash"
        QT_MOC_LITERAL(692, 9),  // "writeBash"
        QT_MOC_LITERAL(702, 7),  // "content"
        QT_MOC_LITERAL(710, 9),  // "checkFile"
        QT_MOC_LITERAL(720, 6),  // "source"
        QT_MOC_LITERAL(727, 7),  // "program"
        QT_MOC_LITERAL(735, 19),  // "writeRemoteBashFile"
        QT_MOC_LITERAL(755, 12),  // "program_name"
        QT_MOC_LITERAL(768, 15),  // "showConditionAt"
        QT_MOC_LITERAL(784, 12),  // "timeSecondsA"
        QT_MOC_LITERAL(797, 12),  // "timeSecondsB"
        QT_MOC_LITERAL(810, 12),  // "startAndStop"
        QT_MOC_LITERAL(823, 5),  // "start"
        QT_MOC_LITERAL(829, 14),  // "connectCluster"
        QT_MOC_LITERAL(844, 7),  // "address"
        QT_MOC_LITERAL(852, 5),  // "ident"
        QT_MOC_LITERAL(858, 4),  // "path"
        QT_MOC_LITERAL(863, 19),  // "connectClusterAsync"
        QT_MOC_LITERAL(883, 8),  // "QJSValue"
        QT_MOC_LITERAL(892, 8),  // "callback"
        QT_MOC_LITERAL(901, 13),  // "getOutputFile"
        QT_MOC_LITERAL(915, 6),  // "nodeAt"
        QT_MOC_LITERAL(922, 13),  // "Cluster_Node*"
        QT_MOC_LITERAL(936, 5),  // "index"
        QT_MOC_LITERAL(942, 5),  // "count"
        QT_MOC_LITERAL(948, 12),  // "p2p_send_max"
        QT_MOC_LITERAL(961, 13),  // "coll_send_max"
        QT_MOC_LITERAL(975, 12),  // "p2p_recv_max"
        QT_MOC_LITERAL(988, 13),  // "coll_recv_max"
        QT_MOC_LITERAL(1002, 13),  // "db_connection"
        QT_MOC_LITERAL(1016, 18),  // "cluster_connection"
        QT_MOC_LITERAL(1035, 12)   // "time_display"
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
    "signalToConnect",
    "setProcNum",
    "proc_num",
    "signalToUpdateData",
    "signalToClearDB",
    "signalToShowTimestampData",
    "timestampA",
    "timestampB",
    "signalSlurmStatusChanged",
    "status",
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
    "startBash",
    "readBash",
    "writeBash",
    "content",
    "checkFile",
    "source",
    "program",
    "writeRemoteBashFile",
    "program_name",
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
    "getOutputFile",
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
      37,   16, // methods
       8,  363, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  238,    4, 0x06,    9 /* Public */,
       5,    0,  239,    4, 0x06,   10 /* Public */,
       6,    0,  240,    4, 0x06,   11 /* Public */,
       7,    0,  241,    4, 0x06,   12 /* Public */,
       8,    0,  242,    4, 0x06,   13 /* Public */,
       9,    0,  243,    4, 0x06,   14 /* Public */,
      10,    0,  244,    4, 0x06,   15 /* Public */,
      11,    0,  245,    4, 0x06,   16 /* Public */,
      12,    1,  246,    4, 0x06,   17 /* Public */,
      14,    1,  249,    4, 0x06,   19 /* Public */,
      16,    5,  252,    4, 0x06,   21 /* Public */,
      17,    1,  263,    4, 0x06,   27 /* Public */,
      19,    1,  266,    4, 0x06,   29 /* Public */,
      20,    0,  269,    4, 0x06,   31 /* Public */,
      21,    2,  270,    4, 0x06,   32 /* Public */,
      24,    1,  275,    4, 0x06,   35 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      26,    1,  278,    4, 0x0a,   37 /* Public */,
      27,    1,  281,    4, 0x0a,   39 /* Public */,
      29,    1,  284,    4, 0x0a,   41 /* Public */,
      31,    0,  287,    4, 0x0a,   43 /* Public */,
      32,    1,  288,    4, 0x0a,   44 /* Public */,
      33,    1,  291,    4, 0x0a,   46 /* Public */,
      34,    1,  294,    4, 0x0a,   48 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      36,    5,  297,    4, 0x02,   50 /* Public */,
      42,    3,  308,    4, 0x02,   56 /* Public */,
      45,    0,  315,    4, 0x02,   60 /* Public */,
      46,    1,  316,    4, 0x02,   61 /* Public */,
      47,    0,  319,    4, 0x02,   63 /* Public */,
      48,    1,  320,    4, 0x02,   64 /* Public */,
      50,    3,  323,    4, 0x02,   66 /* Public */,
      53,    2,  330,    4, 0x02,   70 /* Public */,
      55,    2,  335,    4, 0x02,   73 /* Public */,
      58,    1,  340,    4, 0x02,   76 /* Public */,
      60,    3,  343,    4, 0x02,   78 /* Public */,
      64,    4,  350,    4, 0x02,   82 /* Public */,
      67,    0,  359,    4, 0x02,   87 /* Public */,
      68,    1,  360,    4, 0x02,   88 /* Public */,

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
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    4,    4,    4,    4,    4,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime, QMetaType::QTime,   22,   23,
    QMetaType::Void, QMetaType::QString,   25,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, 0x80000000 | 28,    4,
    QMetaType::Void, 0x80000000 | 30,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime,   15,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::Int,   35,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,   37,   38,   39,   40,   41,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Int,   43,   44,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   51,   52,   44,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   54,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   56,   57,
    QMetaType::Void, QMetaType::Bool,   59,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   61,   62,   63,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 65,   61,   62,   63,   66,
    QMetaType::QString,
    0x80000000 | 69, QMetaType::Int,   70,

 // properties: name, type, flags
      71, QMetaType::Int, 0x00015401, uint(-1), 0,
      72, QMetaType::Long, 0x00015003, uint(0), 0,
      73, QMetaType::Long, 0x00015003, uint(1), 0,
      74, QMetaType::Long, 0x00015003, uint(2), 0,
      75, QMetaType::Long, 0x00015003, uint(3), 0,
      76, QMetaType::Bool, 0x00015003, uint(4), 0,
      77, QMetaType::Bool, 0x00015003, uint(5), 0,
      78, QMetaType::Int, 0x00015003, uint(6), 0,

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
        // method 'signalSlurmStatusChanged'
        void,
        QString,
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
        // method 'getOutputFile'
        QString,
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
        case 10: _t->signalToConnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 11: _t->setProcNum((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->signalToUpdateData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->signalToClearDB(); break;
        case 14: _t->signalToShowTimestampData((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[2]))); break;
        case 15: _t->signalSlurmStatusChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->dbConnectionSuccessful((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->buildClusterComponents((*reinterpret_cast< std::add_pointer_t<QMap<QString,QList<int>>>>(_a[1]))); break;
        case 18: _t->updateDataToUI((*reinterpret_cast< std::add_pointer_t<QList<DataColumn>>>(_a[1]))); break;
        case 19: _t->removeClusterComponents(); break;
        case 20: _t->handleTimestamp((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1]))); break;
        case 21: _t->slurm_status_changed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 22: _t->getSlurmID((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->connect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 24: _t->writeLocalBashFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 25: _t->closeApp(); break;
        case 26: _t->startBash((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 27: { QString _r = _t->readBash();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 28: _t->writeBash((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 29: { bool _r = _t->checkFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 30: _t->writeRemoteBashFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 31: _t->showConditionAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 32: _t->startAndStop((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 33: { QString _r = _t->connectCluster((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 34: _t->connectClusterAsync((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QJSValue>>(_a[4]))); break;
        case 35: { QString _r = _t->getOutputFile();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 36: { Cluster_Node* _r = _t->nodeAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< Cluster_Node**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 34:
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
            using _t = void (Database_Connection::*)(const QString & , const QString & , const int & , const QString & , const QString & );
            if (_t _q_method = &Database_Connection::signalToConnect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)(const int );
            if (_t _q_method = &Database_Connection::setProcNum; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)(const int & );
            if (_t _q_method = &Database_Connection::signalToUpdateData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)();
            if (_t _q_method = &Database_Connection::signalToClearDB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)(const QTime , const QTime );
            if (_t _q_method = &Database_Connection::signalToShowTimestampData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (Database_Connection::*)(QString );
            if (_t _q_method = &Database_Connection::signalSlurmStatusChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
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
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
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
void Database_Connection::signalToConnect(const QString & _t1, const QString & _t2, const int & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Database_Connection::setProcNum(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Database_Connection::signalToUpdateData(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Database_Connection::signalToClearDB()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void Database_Connection::signalToShowTimestampData(const QTime _t1, const QTime _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Database_Connection::signalSlurmStatusChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}
QT_WARNING_POP