/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../controller.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSControllerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSControllerENDCLASS = QtMocHelpers::stringData(
    "Controller",
    "QML.Element",
    "auto",
    "count",
    "",
    "liveSlurmID",
    "slurm_id",
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
    "connectionChanged",
    "clusterConnectionChanged",
    "time_display_changed",
    "buildClusterComponents",
    "QMap<QString,QList<int>>",
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
    "getDatabaseConnection",
    "Database_Connection*",
    "setComponentsBuild",
    "b",
    "setTimestamp",
    "getJobTable",
    "Table_UserID*",
    "getClusterIdent",
    "db_connection",
    "cluster_connection",
    "time_display"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSControllerENDCLASS_t {
    uint offsetsAndSizes[158];
    char stringdata0[11];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[6];
    char stringdata4[1];
    char stringdata5[12];
    char stringdata6[9];
    char stringdata7[17];
    char stringdata8[8];
    char stringdata9[7];
    char stringdata10[10];
    char stringdata11[25];
    char stringdata12[7];
    char stringdata13[17];
    char stringdata14[7];
    char stringdata15[16];
    char stringdata16[11];
    char stringdata17[9];
    char stringdata18[19];
    char stringdata19[16];
    char stringdata20[26];
    char stringdata21[11];
    char stringdata22[11];
    char stringdata23[23];
    char stringdata24[7];
    char stringdata25[18];
    char stringdata26[25];
    char stringdata27[21];
    char stringdata28[23];
    char stringdata29[25];
    char stringdata30[16];
    char stringdata31[21];
    char stringdata32[11];
    char stringdata33[3];
    char stringdata34[20];
    char stringdata35[8];
    char stringdata36[9];
    char stringdata37[13];
    char stringdata38[5];
    char stringdata39[9];
    char stringdata40[9];
    char stringdata41[19];
    char stringdata42[11];
    char stringdata43[5];
    char stringdata44[9];
    char stringdata45[17];
    char stringdata46[10];
    char stringdata47[9];
    char stringdata48[10];
    char stringdata49[8];
    char stringdata50[10];
    char stringdata51[7];
    char stringdata52[8];
    char stringdata53[20];
    char stringdata54[13];
    char stringdata55[7];
    char stringdata56[16];
    char stringdata57[13];
    char stringdata58[13];
    char stringdata59[13];
    char stringdata60[6];
    char stringdata61[15];
    char stringdata62[8];
    char stringdata63[6];
    char stringdata64[5];
    char stringdata65[20];
    char stringdata66[9];
    char stringdata67[9];
    char stringdata68[22];
    char stringdata69[21];
    char stringdata70[19];
    char stringdata71[2];
    char stringdata72[13];
    char stringdata73[12];
    char stringdata74[14];
    char stringdata75[16];
    char stringdata76[14];
    char stringdata77[19];
    char stringdata78[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSControllerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSControllerENDCLASS_t qt_meta_stringdata_CLASSControllerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "Controller"
        QT_MOC_LITERAL(11, 11),  // "QML.Element"
        QT_MOC_LITERAL(23, 4),  // "auto"
        QT_MOC_LITERAL(28, 5),  // "count"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 11),  // "liveSlurmID"
        QT_MOC_LITERAL(47, 8),  // "slurm_id"
        QT_MOC_LITERAL(56, 16),  // "connectionSignal"
        QT_MOC_LITERAL(73, 7),  // "success"
        QT_MOC_LITERAL(81, 6),  // "dataIn"
        QT_MOC_LITERAL(88, 9),  // "timestamp"
        QT_MOC_LITERAL(98, 24),  // "signalSlurmStatusChanged"
        QT_MOC_LITERAL(123, 6),  // "status"
        QT_MOC_LITERAL(130, 16),  // "copiedOutputFile"
        QT_MOC_LITERAL(147, 6),  // "output"
        QT_MOC_LITERAL(154, 15),  // "signalToConnect"
        QT_MOC_LITERAL(170, 10),  // "setProcNum"
        QT_MOC_LITERAL(181, 8),  // "proc_num"
        QT_MOC_LITERAL(190, 18),  // "signalToUpdateData"
        QT_MOC_LITERAL(209, 15),  // "signalToClearDB"
        QT_MOC_LITERAL(225, 25),  // "signalToShowTimestampData"
        QT_MOC_LITERAL(251, 10),  // "timestampA"
        QT_MOC_LITERAL(262, 10),  // "timestampB"
        QT_MOC_LITERAL(273, 22),  // "fetchEduMPIJobsForUser"
        QT_MOC_LITERAL(296, 6),  // "userId"
        QT_MOC_LITERAL(303, 17),  // "connectionChanged"
        QT_MOC_LITERAL(321, 24),  // "clusterConnectionChanged"
        QT_MOC_LITERAL(346, 20),  // "time_display_changed"
        QT_MOC_LITERAL(367, 22),  // "buildClusterComponents"
        QT_MOC_LITERAL(390, 24),  // "QMap<QString,QList<int>>"
        QT_MOC_LITERAL(415, 15),  // "handleTimestamp"
        QT_MOC_LITERAL(431, 20),  // "slurm_status_changed"
        QT_MOC_LITERAL(452, 10),  // "getSlurmID"
        QT_MOC_LITERAL(463, 2),  // "id"
        QT_MOC_LITERAL(466, 19),  // "slotFetchEduMPIJobs"
        QT_MOC_LITERAL(486, 7),  // "connect"
        QT_MOC_LITERAL(494, 8),  // "hostname"
        QT_MOC_LITERAL(503, 12),  // "databasename"
        QT_MOC_LITERAL(516, 4),  // "port"
        QT_MOC_LITERAL(521, 8),  // "UserName"
        QT_MOC_LITERAL(530, 8),  // "password"
        QT_MOC_LITERAL(539, 18),  // "writeLocalBashFile"
        QT_MOC_LITERAL(558, 10),  // "local_path"
        QT_MOC_LITERAL(569, 4),  // "file"
        QT_MOC_LITERAL(574, 8),  // "closeApp"
        QT_MOC_LITERAL(583, 16),  // "cancelRunningJob"
        QT_MOC_LITERAL(600, 9),  // "startBash"
        QT_MOC_LITERAL(610, 8),  // "readBash"
        QT_MOC_LITERAL(619, 9),  // "writeBash"
        QT_MOC_LITERAL(629, 7),  // "content"
        QT_MOC_LITERAL(637, 9),  // "checkFile"
        QT_MOC_LITERAL(647, 6),  // "source"
        QT_MOC_LITERAL(654, 7),  // "program"
        QT_MOC_LITERAL(662, 19),  // "writeRemoteBashFile"
        QT_MOC_LITERAL(682, 12),  // "program_name"
        QT_MOC_LITERAL(695, 6),  // "option"
        QT_MOC_LITERAL(702, 15),  // "showConditionAt"
        QT_MOC_LITERAL(718, 12),  // "timeSecondsA"
        QT_MOC_LITERAL(731, 12),  // "timeSecondsB"
        QT_MOC_LITERAL(744, 12),  // "startAndStop"
        QT_MOC_LITERAL(757, 5),  // "start"
        QT_MOC_LITERAL(763, 14),  // "connectCluster"
        QT_MOC_LITERAL(778, 7),  // "address"
        QT_MOC_LITERAL(786, 5),  // "ident"
        QT_MOC_LITERAL(792, 4),  // "path"
        QT_MOC_LITERAL(797, 19),  // "connectClusterAsync"
        QT_MOC_LITERAL(817, 8),  // "QJSValue"
        QT_MOC_LITERAL(826, 8),  // "callback"
        QT_MOC_LITERAL(835, 21),  // "getDatabaseConnection"
        QT_MOC_LITERAL(857, 20),  // "Database_Connection*"
        QT_MOC_LITERAL(878, 18),  // "setComponentsBuild"
        QT_MOC_LITERAL(897, 1),  // "b"
        QT_MOC_LITERAL(899, 12),  // "setTimestamp"
        QT_MOC_LITERAL(912, 11),  // "getJobTable"
        QT_MOC_LITERAL(924, 13),  // "Table_UserID*"
        QT_MOC_LITERAL(938, 15),  // "getClusterIdent"
        QT_MOC_LITERAL(954, 13),  // "db_connection"
        QT_MOC_LITERAL(968, 18),  // "cluster_connection"
        QT_MOC_LITERAL(987, 12)   // "time_display"
    },
    "Controller",
    "QML.Element",
    "auto",
    "count",
    "",
    "liveSlurmID",
    "slurm_id",
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
    "connectionChanged",
    "clusterConnectionChanged",
    "time_display_changed",
    "buildClusterComponents",
    "QMap<QString,QList<int>>",
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
    "getDatabaseConnection",
    "Database_Connection*",
    "setComponentsBuild",
    "b",
    "setTimestamp",
    "getJobTable",
    "Table_UserID*",
    "getClusterIdent",
    "db_connection",
    "cluster_connection",
    "time_display"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSControllerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       1,   14, // classinfo
      38,   16, // methods
       4,  376, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  244,    4, 0x106,    5 /* Public | MethodIsConst  */,
       5,    1,  245,    4, 0x06,    6 /* Public */,
       7,    1,  248,    4, 0x06,    8 /* Public */,
       9,    1,  251,    4, 0x06,   10 /* Public */,
      11,    1,  254,    4, 0x06,   12 /* Public */,
      13,    1,  257,    4, 0x06,   14 /* Public */,
      15,    5,  260,    4, 0x06,   16 /* Public */,
      16,    1,  271,    4, 0x06,   22 /* Public */,
      18,    1,  274,    4, 0x06,   24 /* Public */,
      19,    0,  277,    4, 0x06,   26 /* Public */,
      20,    2,  278,    4, 0x06,   27 /* Public */,
      23,    1,  283,    4, 0x06,   30 /* Public */,
      25,    0,  286,    4, 0x06,   32 /* Public */,
      26,    0,  287,    4, 0x06,   33 /* Public */,
      27,    0,  288,    4, 0x06,   34 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      28,    1,  289,    4, 0x0a,   35 /* Public */,
      30,    1,  292,    4, 0x0a,   37 /* Public */,
      31,    1,  295,    4, 0x0a,   39 /* Public */,
      32,    1,  298,    4, 0x0a,   41 /* Public */,
      34,    0,  301,    4, 0x0a,   43 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      35,    5,  302,    4, 0x02,   44 /* Public */,
      41,    3,  313,    4, 0x02,   50 /* Public */,
      44,    0,  320,    4, 0x02,   54 /* Public */,
      45,    0,  321,    4, 0x02,   55 /* Public */,
      46,    1,  322,    4, 0x02,   56 /* Public */,
      47,    0,  325,    4, 0x02,   58 /* Public */,
      48,    1,  326,    4, 0x02,   59 /* Public */,
      50,    3,  329,    4, 0x02,   61 /* Public */,
      53,    3,  336,    4, 0x02,   65 /* Public */,
      56,    2,  343,    4, 0x02,   69 /* Public */,
      59,    1,  348,    4, 0x02,   72 /* Public */,
      61,    3,  351,    4, 0x02,   74 /* Public */,
      65,    4,  358,    4, 0x02,   78 /* Public */,
      68,    0,  367,    4, 0x02,   83 /* Public */,
      70,    1,  368,    4, 0x02,   84 /* Public */,
      72,    1,  371,    4, 0x02,   86 /* Public */,
      73,    0,  374,    4, 0x02,   88 /* Public */,
      75,    0,  375,    4, 0x02,   89 /* Public */,

 // signals: parameters
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    4,    4,    4,    4,    4,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime, QMetaType::QTime,   21,   22,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 29,    4,
    QMetaType::Void, QMetaType::QTime,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,   36,   37,   38,   39,   40,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Int,   42,   43,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   49,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   51,   52,   43,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   54,   17,   55,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   57,   58,
    QMetaType::Void, QMetaType::Bool,   60,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   62,   63,   64,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 66,   62,   63,   64,   67,
    0x80000000 | 69,
    QMetaType::Void, QMetaType::Bool,   71,
    QMetaType::Void, QMetaType::QTime,   10,
    0x80000000 | 74,
    QMetaType::QString,

 // properties: name, type, flags
       3, QMetaType::Int, 0x00015401, uint(-1), 0,
      76, QMetaType::Bool, 0x00015003, uint(12), 0,
      77, QMetaType::Bool, 0x00015003, uint(13), 0,
      78, QMetaType::Int, 0x00015003, uint(14), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Controller::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'count'
        int,
        // property 'db_connection'
        bool,
        // property 'cluster_connection'
        bool,
        // property 'time_display'
        int,
        // Q_OBJECT / Q_GADGET
        Controller,
        // method 'count'
        int,
        // method 'liveSlurmID'
        void,
        int,
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
        // method 'connectionChanged'
        void,
        // method 'clusterConnectionChanged'
        void,
        // method 'time_display_changed'
        void,
        // method 'buildClusterComponents'
        void,
        const QMap<QString,QVector<int>> &,
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
        // method 'getDatabaseConnection'
        Database_Connection *,
        // method 'setComponentsBuild'
        void,
        bool,
        // method 'setTimestamp'
        void,
        QTime,
        // method 'getJobTable'
        Table_UserID *,
        // method 'getClusterIdent'
        QString
    >,
    nullptr
} };

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->count();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->liveSlurmID((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->connectionSignal((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->dataIn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->signalSlurmStatusChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->copiedOutputFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->signalToConnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 7: _t->setProcNum((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->signalToUpdateData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->signalToClearDB(); break;
        case 10: _t->signalToShowTimestampData((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[2]))); break;
        case 11: _t->fetchEduMPIJobsForUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->connectionChanged(); break;
        case 13: _t->clusterConnectionChanged(); break;
        case 14: _t->time_display_changed(); break;
        case 15: _t->buildClusterComponents((*reinterpret_cast< std::add_pointer_t<QMap<QString,QList<int>>>>(_a[1]))); break;
        case 16: _t->handleTimestamp((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1]))); break;
        case 17: _t->slurm_status_changed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->getSlurmID((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->slotFetchEduMPIJobs(); break;
        case 20: _t->connect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 21: _t->writeLocalBashFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 22: _t->closeApp(); break;
        case 23: _t->cancelRunningJob(); break;
        case 24: _t->startBash((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: { QString _r = _t->readBash();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->writeBash((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 27: { bool _r = _t->checkFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 28: _t->writeRemoteBashFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 29: _t->showConditionAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 30: _t->startAndStop((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 31: { QString _r = _t->connectCluster((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 32: _t->connectClusterAsync((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QJSValue>>(_a[4]))); break;
        case 33: { Database_Connection* _r = _t->getDatabaseConnection();
            if (_a[0]) *reinterpret_cast< Database_Connection**>(_a[0]) = std::move(_r); }  break;
        case 34: _t->setComponentsBuild((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 35: _t->setTimestamp((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1]))); break;
        case 36: { Table_UserID* _r = _t->getJobTable();
            if (_a[0]) *reinterpret_cast< Table_UserID**>(_a[0]) = std::move(_r); }  break;
        case 37: { QString _r = _t->getClusterIdent();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 32:
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
            using _t = int (Controller::*)() const;
            if (_t _q_method = &Controller::count; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Controller::*)(int );
            if (_t _q_method = &Controller::liveSlurmID; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Controller::*)(bool );
            if (_t _q_method = &Controller::connectionSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Controller::*)(int );
            if (_t _q_method = &Controller::dataIn; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Controller::*)(QString );
            if (_t _q_method = &Controller::signalSlurmStatusChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Controller::*)(QString );
            if (_t _q_method = &Controller::copiedOutputFile; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Controller::*)(const QString & , const QString & , const int & , const QString & , const QString & );
            if (_t _q_method = &Controller::signalToConnect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Controller::*)(const int );
            if (_t _q_method = &Controller::setProcNum; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Controller::*)(const int & );
            if (_t _q_method = &Controller::signalToUpdateData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (_t _q_method = &Controller::signalToClearDB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Controller::*)(const QTime , const QTime );
            if (_t _q_method = &Controller::signalToShowTimestampData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Controller::*)(const QString & );
            if (_t _q_method = &Controller::fetchEduMPIJobsForUser; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (_t _q_method = &Controller::connectionChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (_t _q_method = &Controller::clusterConnectionChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (_t _q_method = &Controller::time_display_changed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Controller *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->count(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->m_connection_ready; break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->m_cluster_connection_ready; break;
        case 3: *reinterpret_cast< int*>(_v) = _t->m_time_display; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Controller *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 1:
            if (_t->m_connection_ready != *reinterpret_cast< bool*>(_v)) {
                _t->m_connection_ready = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->connectionChanged();
            }
            break;
        case 2:
            if (_t->m_cluster_connection_ready != *reinterpret_cast< bool*>(_v)) {
                _t->m_cluster_connection_ready = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->clusterConnectionChanged();
            }
            break;
        case 3:
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

const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
int Controller::count()const
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))) };
    QMetaObject::activate(const_cast< Controller *>(this), &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
void Controller::liveSlurmID(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Controller::connectionSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Controller::dataIn(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Controller::signalSlurmStatusChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Controller::copiedOutputFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Controller::signalToConnect(const QString & _t1, const QString & _t2, const int & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Controller::setProcNum(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Controller::signalToUpdateData(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Controller::signalToClearDB()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void Controller::signalToShowTimestampData(const QTime _t1, const QTime _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Controller::fetchEduMPIJobsForUser(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Controller::connectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void Controller::clusterConnectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void Controller::time_display_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}
QT_WARNING_POP
