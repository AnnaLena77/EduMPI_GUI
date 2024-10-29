/****************************************************************************
** Meta object code from reading C++ file 'cluster_architecture.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../cluster_architecture.h"
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
struct qt_meta_stringdata_CLASSCluster_ArchitectureENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCluster_ArchitectureENDCLASS = QtMocHelpers::stringData(
    "Cluster_Architecture",
    "p2p_send_max_changed",
    "",
    "coll_send_max_changed",
    "p2p_recv_max_changed",
    "coll_recv_max_changed",
    "signalToConnect",
    "setProcNum",
    "proc_num",
    "setSlurmID",
    "slurm_id",
    "signalToUpdateData",
    "signalToClearDB",
    "signalToShowTimestampData",
    "timestampA",
    "timestampB",
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
    "Database_Connection*",
    "dbConnection",
    "live",
    "startThread",
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
    "coll_recv_max"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCluster_ArchitectureENDCLASS_t {
    uint offsetsAndSizes[104];
    char stringdata0[21];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[21];
    char stringdata5[22];
    char stringdata6[16];
    char stringdata7[11];
    char stringdata8[9];
    char stringdata9[11];
    char stringdata10[9];
    char stringdata11[19];
    char stringdata12[16];
    char stringdata13[26];
    char stringdata14[11];
    char stringdata15[11];
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
    char stringdata33[21];
    char stringdata34[13];
    char stringdata35[5];
    char stringdata36[12];
    char stringdata37[10];
    char stringdata38[4];
    char stringdata39[16];
    char stringdata40[13];
    char stringdata41[13];
    char stringdata42[13];
    char stringdata43[6];
    char stringdata44[7];
    char stringdata45[14];
    char stringdata46[6];
    char stringdata47[6];
    char stringdata48[13];
    char stringdata49[14];
    char stringdata50[13];
    char stringdata51[14];
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
        QT_MOC_LITERAL(108, 15),  // "signalToConnect"
        QT_MOC_LITERAL(124, 10),  // "setProcNum"
        QT_MOC_LITERAL(135, 8),  // "proc_num"
        QT_MOC_LITERAL(144, 10),  // "setSlurmID"
        QT_MOC_LITERAL(155, 8),  // "slurm_id"
        QT_MOC_LITERAL(164, 18),  // "signalToUpdateData"
        QT_MOC_LITERAL(183, 15),  // "signalToClearDB"
        QT_MOC_LITERAL(199, 25),  // "signalToShowTimestampData"
        QT_MOC_LITERAL(225, 10),  // "timestampA"
        QT_MOC_LITERAL(236, 10),  // "timestampB"
        QT_MOC_LITERAL(247, 15),  // "componentsBuilt"
        QT_MOC_LITERAL(263, 16),  // "connectionSignal"
        QT_MOC_LITERAL(280, 7),  // "success"
        QT_MOC_LITERAL(288, 6),  // "dataIn"
        QT_MOC_LITERAL(295, 9),  // "timestamp"
        QT_MOC_LITERAL(305, 10),  // "qTimestamp"
        QT_MOC_LITERAL(316, 24),  // "signalSlurmStatusChanged"
        QT_MOC_LITERAL(341, 6),  // "status"
        QT_MOC_LITERAL(348, 16),  // "copiedOutputFile"
        QT_MOC_LITERAL(365, 6),  // "output"
        QT_MOC_LITERAL(372, 22),  // "buildClusterComponents"
        QT_MOC_LITERAL(395, 24),  // "QMap<QString,QList<int>>"
        QT_MOC_LITERAL(420, 14),  // "updateDataToUI"
        QT_MOC_LITERAL(435, 17),  // "QList<DataColumn>"
        QT_MOC_LITERAL(453, 23),  // "removeClusterComponents"
        QT_MOC_LITERAL(477, 15),  // "handleTimestamp"
        QT_MOC_LITERAL(493, 10),  // "initialize"
        QT_MOC_LITERAL(504, 20),  // "Database_Connection*"
        QT_MOC_LITERAL(525, 12),  // "dbConnection"
        QT_MOC_LITERAL(538, 4),  // "live"
        QT_MOC_LITERAL(543, 11),  // "startThread"
        QT_MOC_LITERAL(555, 9),  // "setOption"
        QT_MOC_LITERAL(565, 3),  // "opt"
        QT_MOC_LITERAL(569, 15),  // "showConditionAt"
        QT_MOC_LITERAL(585, 12),  // "timeSecondsA"
        QT_MOC_LITERAL(598, 12),  // "timeSecondsB"
        QT_MOC_LITERAL(611, 12),  // "startAndStop"
        QT_MOC_LITERAL(624, 5),  // "start"
        QT_MOC_LITERAL(630, 6),  // "nodeAt"
        QT_MOC_LITERAL(637, 13),  // "Cluster_Node*"
        QT_MOC_LITERAL(651, 5),  // "index"
        QT_MOC_LITERAL(657, 5),  // "count"
        QT_MOC_LITERAL(663, 12),  // "p2p_send_max"
        QT_MOC_LITERAL(676, 13),  // "coll_send_max"
        QT_MOC_LITERAL(690, 12),  // "p2p_recv_max"
        QT_MOC_LITERAL(703, 13)   // "coll_recv_max"
    },
    "Cluster_Architecture",
    "p2p_send_max_changed",
    "",
    "coll_send_max_changed",
    "p2p_recv_max_changed",
    "coll_recv_max_changed",
    "signalToConnect",
    "setProcNum",
    "proc_num",
    "setSlurmID",
    "slurm_id",
    "signalToUpdateData",
    "signalToClearDB",
    "signalToShowTimestampData",
    "timestampA",
    "timestampB",
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
    "Database_Connection*",
    "dbConnection",
    "live",
    "startThread",
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
    "coll_recv_max"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCluster_ArchitectureENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       5,  239, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  164,    2, 0x06,    6 /* Public */,
       3,    0,  165,    2, 0x06,    7 /* Public */,
       4,    0,  166,    2, 0x06,    8 /* Public */,
       5,    0,  167,    2, 0x06,    9 /* Public */,
       6,    5,  168,    2, 0x06,   10 /* Public */,
       7,    1,  179,    2, 0x06,   16 /* Public */,
       9,    1,  182,    2, 0x06,   18 /* Public */,
      11,    1,  185,    2, 0x06,   20 /* Public */,
      12,    0,  188,    2, 0x06,   22 /* Public */,
      13,    2,  189,    2, 0x06,   23 /* Public */,
      16,    0,  194,    2, 0x06,   26 /* Public */,
      17,    1,  195,    2, 0x06,   27 /* Public */,
      19,    2,  198,    2, 0x06,   29 /* Public */,
      22,    1,  203,    2, 0x06,   32 /* Public */,
      24,    1,  206,    2, 0x06,   34 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      26,    1,  209,    2, 0x0a,   36 /* Public */,
      28,    1,  212,    2, 0x0a,   38 /* Public */,
      30,    0,  215,    2, 0x0a,   40 /* Public */,
      31,    1,  216,    2, 0x0a,   41 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      32,    2,  219,    2, 0x02,   43 /* Public */,
      36,    0,  224,    2, 0x02,   46 /* Public */,
      37,    1,  225,    2, 0x02,   47 /* Public */,
      39,    2,  228,    2, 0x02,   49 /* Public */,
      42,    1,  233,    2, 0x02,   52 /* Public */,
      44,    1,  236,    2, 0x02,   54 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime,   14,   15,
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
    QMetaType::Void, 0x80000000 | 33, QMetaType::Bool,   34,   35,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   40,   41,
    QMetaType::Void, QMetaType::Bool,   43,
    0x80000000 | 45, QMetaType::Int,   46,

 // properties: name, type, flags
      47, QMetaType::Int, 0x00015401, uint(-1), 0,
      48, QMetaType::Long, 0x00015003, uint(0), 0,
      49, QMetaType::Long, 0x00015003, uint(1), 0,
      50, QMetaType::Long, 0x00015003, uint(2), 0,
      51, QMetaType::Long, 0x00015003, uint(3), 0,

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
        // method 'signalToConnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setProcNum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'setSlurmID'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'signalToUpdateData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'signalToClearDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalToShowTimestampData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<Database_Connection *, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'startThread'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        case 4: _t->signalToConnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 5: _t->setProcNum((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->setSlurmID((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->signalToUpdateData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->signalToClearDB(); break;
        case 9: _t->signalToShowTimestampData((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[2]))); break;
        case 10: _t->componentsBuilt(); break;
        case 11: _t->connectionSignal((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->dataIn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[2]))); break;
        case 13: _t->signalSlurmStatusChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->copiedOutputFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->buildClusterComponents((*reinterpret_cast< std::add_pointer_t<QMap<QString,QList<int>>>>(_a[1]))); break;
        case 16: _t->updateDataToUI((*reinterpret_cast< std::add_pointer_t<QList<DataColumn>>>(_a[1]))); break;
        case 17: _t->removeClusterComponents(); break;
        case 18: _t->handleTimestamp((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1]))); break;
        case 19: _t->initialize((*reinterpret_cast< std::add_pointer_t<Database_Connection*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 20: _t->startThread(); break;
        case 21: _t->setOption((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->showConditionAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 23: _t->startAndStop((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 24: { Cluster_Node* _r = _t->nodeAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< Cluster_Node**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Database_Connection* >(); break;
            }
            break;
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
            using _t = void (Cluster_Architecture::*)(const QString & , const QString & , const int & , const QString & , const QString & );
            if (_t _q_method = &Cluster_Architecture::signalToConnect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)(const int );
            if (_t _q_method = &Cluster_Architecture::setProcNum; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)(const int );
            if (_t _q_method = &Cluster_Architecture::setSlurmID; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
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
            if (_t _q_method = &Cluster_Architecture::componentsBuilt; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)(bool );
            if (_t _q_method = &Cluster_Architecture::connectionSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)(int , QTime );
            if (_t _q_method = &Cluster_Architecture::dataIn; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)(QString );
            if (_t _q_method = &Cluster_Architecture::signalSlurmStatusChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Cluster_Architecture::*)(QString );
            if (_t _q_method = &Cluster_Architecture::copiedOutputFile; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
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
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
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
void Cluster_Architecture::signalToConnect(const QString & _t1, const QString & _t2, const int & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Cluster_Architecture::setProcNum(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Cluster_Architecture::setSlurmID(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
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
void Cluster_Architecture::componentsBuilt()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void Cluster_Architecture::connectionSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Cluster_Architecture::dataIn(int _t1, QTime _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Cluster_Architecture::signalSlurmStatusChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Cluster_Architecture::copiedOutputFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}
QT_WARNING_POP
