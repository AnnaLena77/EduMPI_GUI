/****************************************************************************
** Meta object code from reading C++ file 'cluster_architecture.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cluster_architecture.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cluster_architecture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.6. It"
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
struct qt_meta_stringdata_CLASSCluster_ArchitectureENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSCluster_ArchitectureENDCLASS = QtMocHelpers::stringData(
    "Cluster_Architecture",
    "p2p_send_max_changed",
    "",
    "coll_send_max_changed",
    "p2p_recv_max_changed",
    "coll_recv_max_changed",
    "slurm_id_changed",
    "proc_num_changed",
    "signalToConnect",
    "signalToUpdateData",
    "signalToClearDB",
    "signalToShowTimestampData",
    "timestampA",
    "timestampB",
    "startDatabaseThread",
    "signalToDBConnection",
    "componentsBuilt",
    "connectionSignal",
    "success",
    "dataIn",
    "timestamp",
    "qTimestamp",
    "signalSlurmStatusChanged",
    "status",
    "copiedOutputFile",
    "output",
    "buildClusterComponents",
    "QMap<QString,QList<int>>",
    "updateDataToUI",
    "QList<DataColumn>",
    "removeClusterComponents",
    "handleTimestamp",
    "initialize",
    "db_connection",
    "live",
    "startThread",
    "set_slurm_id",
    "id",
    "set_proc_num",
    "proc",
    "setOption",
    "opt",
    "showConditionAt",
    "timeSecondsA",
    "timeSecondsB",
    "startAndStop",
    "start",
    "nodeAt",
    "Cluster_Node*",
    "index",
    "count",
    "p2p_send_max",
    "coll_send_max",
    "p2p_recv_max",
    "coll_recv_max",
    "slurm_id",
    "proc_num"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCluster_ArchitectureENDCLASS_t {
    uint offsetsAndSizes[114];
    char stringdata0[21];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[21];
    char stringdata5[22];
    char stringdata6[17];
    char stringdata7[17];
    char stringdata8[16];
    char stringdata9[19];
    char stringdata10[16];
    char stringdata11[26];
    char stringdata12[11];
    char stringdata13[11];
    char stringdata14[20];
    char stringdata15[21];
    char stringdata16[16];
    char stringdata17[17];
    char stringdata18[8];
    char stringdata19[7];
    char stringdata20[10];
    char stringdata21[11];
    char stringdata22[25];
    char stringdata23[7];
    char stringdata24[17];
    char stringdata25[7];
    char stringdata26[23];
    char stringdata27[25];
    char stringdata28[15];
    char stringdata29[18];
    char stringdata30[24];
    char stringdata31[16];
    char stringdata32[11];
    char stringdata33[14];
    char stringdata34[5];
    char stringdata35[12];
    char stringdata36[13];
    char stringdata37[3];
    char stringdata38[13];
    char stringdata39[5];
    char stringdata40[10];
    char stringdata41[4];
    char stringdata42[16];
    char stringdata43[13];
    char stringdata44[13];
    char stringdata45[13];
    char stringdata46[6];
    char stringdata47[7];
    char stringdata48[14];
    char stringdata49[6];
    char stringdata50[6];
    char stringdata51[13];
    char stringdata52[14];
    char stringdata53[13];
    char stringdata54[14];
    char stringdata55[9];
    char stringdata56[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCluster_ArchitectureENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCluster_ArchitectureENDCLASS_t qt_meta_stringdata_CLASSCluster_ArchitectureENDCLASS = {
    {
        QT_MOC_LITERAL(0, 20),  // "Cluster_Architecture"
        QT_MOC_LITERAL(21, 20),  // "p2p_send_max_changed"
        QT_MOC_LITERAL(42, 0),  // ""
        QT_MOC_LITERAL(43, 21),  // "coll_send_max_changed"
        QT_MOC_LITERAL(65, 20),  // "p2p_recv_max_changed"
        QT_MOC_LITERAL(86, 21),  // "coll_recv_max_changed"
        QT_MOC_LITERAL(108, 16),  // "slurm_id_changed"
        QT_MOC_LITERAL(125, 16),  // "proc_num_changed"
        QT_MOC_LITERAL(142, 15),  // "signalToConnect"
        QT_MOC_LITERAL(158, 18),  // "signalToUpdateData"
        QT_MOC_LITERAL(177, 15),  // "signalToClearDB"
        QT_MOC_LITERAL(193, 25),  // "signalToShowTimestampData"
        QT_MOC_LITERAL(219, 10),  // "timestampA"
        QT_MOC_LITERAL(230, 10),  // "timestampB"
        QT_MOC_LITERAL(241, 19),  // "startDatabaseThread"
        QT_MOC_LITERAL(261, 20),  // "signalToDBConnection"
        QT_MOC_LITERAL(282, 15),  // "componentsBuilt"
        QT_MOC_LITERAL(298, 16),  // "connectionSignal"
        QT_MOC_LITERAL(315, 7),  // "success"
        QT_MOC_LITERAL(323, 6),  // "dataIn"
        QT_MOC_LITERAL(330, 9),  // "timestamp"
        QT_MOC_LITERAL(340, 10),  // "qTimestamp"
        QT_MOC_LITERAL(351, 24),  // "signalSlurmStatusChanged"
        QT_MOC_LITERAL(376, 6),  // "status"
        QT_MOC_LITERAL(383, 16),  // "copiedOutputFile"
        QT_MOC_LITERAL(400, 6),  // "output"
        QT_MOC_LITERAL(407, 22),  // "buildClusterComponents"
        QT_MOC_LITERAL(430, 24),  // "QMap<QString,QList<int>>"
        QT_MOC_LITERAL(455, 14),  // "updateDataToUI"
        QT_MOC_LITERAL(470, 17),  // "QList<DataColumn>"
        QT_MOC_LITERAL(488, 23),  // "removeClusterComponents"
        QT_MOC_LITERAL(512, 15),  // "handleTimestamp"
        QT_MOC_LITERAL(528, 10),  // "initialize"
        QT_MOC_LITERAL(539, 13),  // "db_connection"
        QT_MOC_LITERAL(553, 4),  // "live"
        QT_MOC_LITERAL(558, 11),  // "startThread"
        QT_MOC_LITERAL(570, 12),  // "set_slurm_id"
        QT_MOC_LITERAL(583, 2),  // "id"
        QT_MOC_LITERAL(586, 12),  // "set_proc_num"
        QT_MOC_LITERAL(599, 4),  // "proc"
        QT_MOC_LITERAL(604, 9),  // "setOption"
        QT_MOC_LITERAL(614, 3),  // "opt"
        QT_MOC_LITERAL(618, 15),  // "showConditionAt"
        QT_MOC_LITERAL(634, 12),  // "timeSecondsA"
        QT_MOC_LITERAL(647, 12),  // "timeSecondsB"
        QT_MOC_LITERAL(660, 12),  // "startAndStop"
        QT_MOC_LITERAL(673, 5),  // "start"
        QT_MOC_LITERAL(679, 6),  // "nodeAt"
        QT_MOC_LITERAL(686, 13),  // "Cluster_Node*"
        QT_MOC_LITERAL(700, 5),  // "index"
        QT_MOC_LITERAL(706, 5),  // "count"
        QT_MOC_LITERAL(712, 12),  // "p2p_send_max"
        QT_MOC_LITERAL(725, 13),  // "coll_send_max"
        QT_MOC_LITERAL(739, 12),  // "p2p_recv_max"
        QT_MOC_LITERAL(752, 13),  // "coll_recv_max"
        QT_MOC_LITERAL(766, 8),  // "slurm_id"
        QT_MOC_LITERAL(775, 8)   // "proc_num"
    },
    "Cluster_Architecture",
    "p2p_send_max_changed",
    "",
    "coll_send_max_changed",
    "p2p_recv_max_changed",
    "coll_recv_max_changed",
    "slurm_id_changed",
    "proc_num_changed",
    "signalToConnect",
    "signalToUpdateData",
    "signalToClearDB",
    "signalToShowTimestampData",
    "timestampA",
    "timestampB",
    "startDatabaseThread",
    "signalToDBConnection",
    "componentsBuilt",
    "connectionSignal",
    "success",
    "dataIn",
    "timestamp",
    "qTimestamp",
    "signalSlurmStatusChanged",
    "status",
    "copiedOutputFile",
    "output",
    "buildClusterComponents",
    "QMap<QString,QList<int>>",
    "updateDataToUI",
    "QList<DataColumn>",
    "removeClusterComponents",
    "handleTimestamp",
    "initialize",
    "db_connection",
    "live",
    "startThread",
    "set_slurm_id",
    "id",
    "set_proc_num",
    "proc",
    "setOption",
    "opt",
    "showConditionAt",
    "timeSecondsA",
    "timeSecondsB",
    "startAndStop",
    "start",
    "nodeAt",
    "Cluster_Node*",
    "index",
    "count",
    "p2p_send_max",
    "coll_send_max",
    "p2p_recv_max",
    "coll_recv_max",
    "slurm_id",
    "proc_num"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCluster_ArchitectureENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       7,  267, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      17,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  188,    2, 0x06,    8 /* Public */,
       3,    0,  189,    2, 0x06,    9 /* Public */,
       4,    0,  190,    2, 0x06,   10 /* Public */,
       5,    0,  191,    2, 0x06,   11 /* Public */,
       6,    0,  192,    2, 0x06,   12 /* Public */,
       7,    0,  193,    2, 0x06,   13 /* Public */,
       8,    5,  194,    2, 0x06,   14 /* Public */,
       9,    1,  205,    2, 0x06,   20 /* Public */,
      10,    0,  208,    2, 0x06,   22 /* Public */,
      11,    2,  209,    2, 0x06,   23 /* Public */,
      14,    0,  214,    2, 0x06,   26 /* Public */,
      15,    0,  215,    2, 0x06,   27 /* Public */,
      16,    0,  216,    2, 0x06,   28 /* Public */,
      17,    1,  217,    2, 0x06,   29 /* Public */,
      19,    2,  220,    2, 0x06,   31 /* Public */,
      22,    1,  225,    2, 0x06,   34 /* Public */,
      24,    1,  228,    2, 0x06,   36 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      26,    1,  231,    2, 0x0a,   38 /* Public */,
      28,    1,  234,    2, 0x0a,   40 /* Public */,
      30,    0,  237,    2, 0x0a,   42 /* Public */,
      31,    1,  238,    2, 0x0a,   43 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      32,    2,  241,    2, 0x02,   45 /* Public */,
      35,    0,  246,    2, 0x02,   48 /* Public */,
      36,    1,  247,    2, 0x02,   49 /* Public */,
      38,    1,  250,    2, 0x02,   51 /* Public */,
      40,    1,  253,    2, 0x02,   53 /* Public */,
      42,    2,  256,    2, 0x02,   55 /* Public */,
      45,    1,  261,    2, 0x02,   58 /* Public */,
      47,    1,  264,    2, 0x02,   60 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::QTime,   20,   21,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   25,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 27,    2,
    QMetaType::Void, 0x80000000 | 29,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,   20,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   33,   34,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Int,   41,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   43,   44,
    QMetaType::Void, QMetaType::Bool,   46,
    0x80000000 | 48, QMetaType::Int,   49,

 // properties: name, type, flags
      50, QMetaType::Int, 0x00015401, uint(-1), 0,
      51, QMetaType::Long, 0x00015003, uint(0), 0,
      52, QMetaType::Long, 0x00015003, uint(1), 0,
      53, QMetaType::Long, 0x00015003, uint(2), 0,
      54, QMetaType::Long, 0x00015003, uint(3), 0,
      55, QMetaType::Int, 0x00015003, uint(4), 0,
      56, QMetaType::Int, 0x00015003, uint(5), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Cluster_Architecture::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSCluster_ArchitectureENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCluster_ArchitectureENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCluster_ArchitectureENDCLASS_t,
        // property 'count'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'p2p_send_max'
        QtPrivate::TypeAndForceComplete<long, std::true_type>,
        // property 'coll_send_max'
        QtPrivate::TypeAndForceComplete<long, std::true_type>,
        // property 'p2p_recv_max'
        QtPrivate::TypeAndForceComplete<long, std::true_type>,
        // property 'coll_recv_max'
        QtPrivate::TypeAndForceComplete<long, std::true_type>,
        // property 'slurm_id'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'proc_num'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Cluster_Architecture, std::true_type>,
        // method 'p2p_send_max_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'coll_send_max_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'p2p_recv_max_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'coll_recv_max_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slurm_id_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'proc_num_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalToConnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'signalToUpdateData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'signalToClearDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalToShowTimestampData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime, std::false_type>,
        // method 'startDatabaseThread'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalToDBConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'componentsBuilt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connectionSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'dataIn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTime, std::false_type>,
        // method 'signalSlurmStatusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'copiedOutputFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'buildClusterComponents'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QMap<QString,QVector<int>> &, std::false_type>,
        // method 'updateDataToUI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<DataColumn> &, std::false_type>,
        // method 'removeClusterComponents'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleTimestamp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDateTime, std::false_type>,
        // method 'initialize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'startThread'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'set_slurm_id'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'set_proc_num'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setOption'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'showConditionAt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'startAndStop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'nodeAt'
        QtPrivate::TypeAndForceComplete<Cluster_Node *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void Cluster_Architecture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Cluster_Architecture *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->p2p_send_max_changed(); break;
        case 1: _t->coll_send_max_changed(); break;
        case 2: _t->p2p_recv_max_changed(); break;
        case 3: _t->coll_recv_max_changed(); break;
        case 4: _t->slurm_id_changed(); break;
        case 5: _t->proc_num_changed(); break;
        case 6: _t->signalToConnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 7: _t->signalToUpdateData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->signalToClearDB(); break;
        case 9: _t->signalToShowTimestampData((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[2]))); break;
        case 10: _t->startDatabaseThread(); break;
        case 11: _t->signalToDBConnection(); break;
        case 12: _t->componentsBuilt(); break;
        case 13: _t->connectionSignal((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->dataIn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[2]))); break;
        case 15: _t->signalSlurmStatusChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->copiedOutputFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->buildClusterComponents((*reinterpret_cast< std::add_pointer_t<QMap<QString,QList<int>>>>(_a[1]))); break;
        case 18: _t->updateDataToUI((*reinterpret_cast< std::add_pointer_t<QList<DataColumn>>>(_a[1]))); break;
        case 19: _t->removeClusterComponents(); break;
        case 20: _t->handleTimestamp((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1]))); break;
        case 21: _t->initialize((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 22: _t->startThread(); break;
        case 23: _t->set_slurm_id((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->set_proc_num((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: _t->setOption((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 26: _t->showConditionAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 27: _t->startAndStop((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 28: { Cluster_Node* _r = _t->nodeAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< Cluster_Node**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Cluster_Architecture::*)();
            if (_t _q_method = &Cluster_Architecture::p2p_send_max_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)();
            if (_t _q_method = &Cluster_Architecture::coll_send_max_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)();
            if (_t _q_method = &Cluster_Architecture::p2p_recv_max_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)();
            if (_t _q_method = &Cluster_Architecture::coll_recv_max_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)();
            if (_t _q_method = &Cluster_Architecture::slurm_id_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)();
            if (_t _q_method = &Cluster_Architecture::proc_num_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)(const QString & , const QString & , const int & , const QString & , const QString & );
            if (_t _q_method = &Cluster_Architecture::signalToConnect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)(const int & );
            if (_t _q_method = &Cluster_Architecture::signalToUpdateData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)();
            if (_t _q_method = &Cluster_Architecture::signalToClearDB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)(const QDateTime , const QDateTime );
            if (_t _q_method = &Cluster_Architecture::signalToShowTimestampData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)();
            if (_t _q_method = &Cluster_Architecture::startDatabaseThread; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)();
            if (_t _q_method = &Cluster_Architecture::signalToDBConnection; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)();
            if (_t _q_method = &Cluster_Architecture::componentsBuilt; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)(bool );
            if (_t _q_method = &Cluster_Architecture::connectionSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)(int , QTime );
            if (_t _q_method = &Cluster_Architecture::dataIn; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)(QString );
            if (_t _q_method = &Cluster_Architecture::signalSlurmStatusChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)(QString );
            if (_t _q_method = &Cluster_Architecture::copiedOutputFile; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Cluster_Architecture *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->count(); break;
        case 1: *reinterpret_cast< long*>(_v) = _t->p2p_send_max(); break;
        case 2: *reinterpret_cast< long*>(_v) = _t->coll_send_max(); break;
        case 3: *reinterpret_cast< long*>(_v) = _t->p2p_recv_max(); break;
        case 4: *reinterpret_cast< long*>(_v) = _t->coll_recv_max(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->slurm_id(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->proc_num(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Cluster_Architecture *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->set_p2p_send_max(*reinterpret_cast< long*>(_v)); break;
        case 2: _t->set_coll_send_max(*reinterpret_cast< long*>(_v)); break;
        case 3: _t->set_p2p_recv_max(*reinterpret_cast< long*>(_v)); break;
        case 4: _t->set_coll_recv_max(*reinterpret_cast< long*>(_v)); break;
        case 5: _t->set_slurm_id(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->set_proc_num(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Cluster_Architecture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cluster_Architecture::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCluster_ArchitectureENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Cluster_Architecture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 29;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Cluster_Architecture::p2p_send_max_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Cluster_Architecture::coll_send_max_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Cluster_Architecture::p2p_recv_max_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Cluster_Architecture::coll_recv_max_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Cluster_Architecture::slurm_id_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Cluster_Architecture::proc_num_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Cluster_Architecture::signalToConnect(const QString & _t1, const QString & _t2, const int & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Cluster_Architecture::signalToUpdateData(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Cluster_Architecture::signalToClearDB()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Cluster_Architecture::signalToShowTimestampData(const QDateTime _t1, const QDateTime _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Cluster_Architecture::startDatabaseThread()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void Cluster_Architecture::signalToDBConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void Cluster_Architecture::componentsBuilt()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void Cluster_Architecture::connectionSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Cluster_Architecture::dataIn(int _t1, QTime _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Cluster_Architecture::signalSlurmStatusChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Cluster_Architecture::copiedOutputFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}
QT_WARNING_POP
