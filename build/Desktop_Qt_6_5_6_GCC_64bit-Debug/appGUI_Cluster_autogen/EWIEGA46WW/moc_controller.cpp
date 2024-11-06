/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../controller.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSControllerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSControllerENDCLASS = QtMocHelpers::stringData(
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
    "signalToClearDB",
    "fetchEduMPIJobsForUser",
    "userId",
    "connectionChanged",
    "clusterConnectionChanged",
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
    "connectCluster",
    "address",
    "ident",
    "path",
    "connectClusterAsync",
    "QJSValue",
    "callback",
    "getDatabaseConnection",
    "setComponentsBuild",
    "b",
    "setTimestamp",
    "getJobTable",
    "Table_UserID*",
    "getClusterIdent",
    "db_connection",
    "cluster_connection"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSControllerENDCLASS_t {
    uint offsetsAndSizes[128];
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
    char stringdata18[16];
    char stringdata19[23];
    char stringdata20[7];
    char stringdata21[18];
    char stringdata22[25];
    char stringdata23[21];
    char stringdata24[11];
    char stringdata25[3];
    char stringdata26[20];
    char stringdata27[8];
    char stringdata28[9];
    char stringdata29[13];
    char stringdata30[5];
    char stringdata31[9];
    char stringdata32[9];
    char stringdata33[19];
    char stringdata34[11];
    char stringdata35[5];
    char stringdata36[9];
    char stringdata37[17];
    char stringdata38[10];
    char stringdata39[9];
    char stringdata40[10];
    char stringdata41[8];
    char stringdata42[10];
    char stringdata43[7];
    char stringdata44[8];
    char stringdata45[20];
    char stringdata46[13];
    char stringdata47[7];
    char stringdata48[15];
    char stringdata49[8];
    char stringdata50[6];
    char stringdata51[5];
    char stringdata52[20];
    char stringdata53[9];
    char stringdata54[9];
    char stringdata55[22];
    char stringdata56[19];
    char stringdata57[2];
    char stringdata58[13];
    char stringdata59[12];
    char stringdata60[14];
    char stringdata61[16];
    char stringdata62[14];
    char stringdata63[19];
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
        QT_MOC_LITERAL(190, 15),  // "signalToClearDB"
        QT_MOC_LITERAL(206, 22),  // "fetchEduMPIJobsForUser"
        QT_MOC_LITERAL(229, 6),  // "userId"
        QT_MOC_LITERAL(236, 17),  // "connectionChanged"
        QT_MOC_LITERAL(254, 24),  // "clusterConnectionChanged"
        QT_MOC_LITERAL(279, 20),  // "slurm_status_changed"
        QT_MOC_LITERAL(300, 10),  // "getSlurmID"
        QT_MOC_LITERAL(311, 2),  // "id"
        QT_MOC_LITERAL(314, 19),  // "slotFetchEduMPIJobs"
        QT_MOC_LITERAL(334, 7),  // "connect"
        QT_MOC_LITERAL(342, 8),  // "hostname"
        QT_MOC_LITERAL(351, 12),  // "databasename"
        QT_MOC_LITERAL(364, 4),  // "port"
        QT_MOC_LITERAL(369, 8),  // "UserName"
        QT_MOC_LITERAL(378, 8),  // "password"
        QT_MOC_LITERAL(387, 18),  // "writeLocalBashFile"
        QT_MOC_LITERAL(406, 10),  // "local_path"
        QT_MOC_LITERAL(417, 4),  // "file"
        QT_MOC_LITERAL(422, 8),  // "closeApp"
        QT_MOC_LITERAL(431, 16),  // "cancelRunningJob"
        QT_MOC_LITERAL(448, 9),  // "startBash"
        QT_MOC_LITERAL(458, 8),  // "readBash"
        QT_MOC_LITERAL(467, 9),  // "writeBash"
        QT_MOC_LITERAL(477, 7),  // "content"
        QT_MOC_LITERAL(485, 9),  // "checkFile"
        QT_MOC_LITERAL(495, 6),  // "source"
        QT_MOC_LITERAL(502, 7),  // "program"
        QT_MOC_LITERAL(510, 19),  // "writeRemoteBashFile"
        QT_MOC_LITERAL(530, 12),  // "program_name"
        QT_MOC_LITERAL(543, 6),  // "option"
        QT_MOC_LITERAL(550, 14),  // "connectCluster"
        QT_MOC_LITERAL(565, 7),  // "address"
        QT_MOC_LITERAL(573, 5),  // "ident"
        QT_MOC_LITERAL(579, 4),  // "path"
        QT_MOC_LITERAL(584, 19),  // "connectClusterAsync"
        QT_MOC_LITERAL(604, 8),  // "QJSValue"
        QT_MOC_LITERAL(613, 8),  // "callback"
        QT_MOC_LITERAL(622, 21),  // "getDatabaseConnection"
        QT_MOC_LITERAL(644, 18),  // "setComponentsBuild"
        QT_MOC_LITERAL(663, 1),  // "b"
        QT_MOC_LITERAL(665, 12),  // "setTimestamp"
        QT_MOC_LITERAL(678, 11),  // "getJobTable"
        QT_MOC_LITERAL(690, 13),  // "Table_UserID*"
        QT_MOC_LITERAL(704, 15),  // "getClusterIdent"
        QT_MOC_LITERAL(720, 13),  // "db_connection"
        QT_MOC_LITERAL(734, 18)   // "cluster_connection"
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
    "signalToClearDB",
    "fetchEduMPIJobsForUser",
    "userId",
    "connectionChanged",
    "clusterConnectionChanged",
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
    "connectCluster",
    "address",
    "ident",
    "path",
    "connectClusterAsync",
    "QJSValue",
    "callback",
    "getDatabaseConnection",
    "setComponentsBuild",
    "b",
    "setTimestamp",
    "getJobTable",
    "Table_UserID*",
    "getClusterIdent",
    "db_connection",
    "cluster_connection"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSControllerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       1,   14, // classinfo
      31,   16, // methods
       3,  311, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  202,    4, 0x106,    4 /* Public | MethodIsConst  */,
       5,    1,  203,    4, 0x06,    5 /* Public */,
       7,    1,  206,    4, 0x06,    7 /* Public */,
       9,    1,  209,    4, 0x06,    9 /* Public */,
      11,    1,  212,    4, 0x06,   11 /* Public */,
      13,    1,  215,    4, 0x06,   13 /* Public */,
      15,    5,  218,    4, 0x06,   15 /* Public */,
      16,    1,  229,    4, 0x06,   21 /* Public */,
      18,    0,  232,    4, 0x06,   23 /* Public */,
      19,    1,  233,    4, 0x06,   24 /* Public */,
      21,    0,  236,    4, 0x06,   26 /* Public */,
      22,    0,  237,    4, 0x06,   27 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      23,    1,  238,    4, 0x0a,   28 /* Public */,
      24,    1,  241,    4, 0x0a,   30 /* Public */,
      26,    0,  244,    4, 0x0a,   32 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      27,    5,  245,    4, 0x02,   33 /* Public */,
      33,    3,  256,    4, 0x02,   39 /* Public */,
      36,    0,  263,    4, 0x02,   43 /* Public */,
      37,    0,  264,    4, 0x02,   44 /* Public */,
      38,    1,  265,    4, 0x02,   45 /* Public */,
      39,    0,  268,    4, 0x02,   47 /* Public */,
      40,    1,  269,    4, 0x02,   48 /* Public */,
      42,    3,  272,    4, 0x02,   50 /* Public */,
      45,    3,  279,    4, 0x02,   54 /* Public */,
      48,    3,  286,    4, 0x02,   58 /* Public */,
      52,    4,  293,    4, 0x02,   62 /* Public */,
      55,    0,  302,    4, 0x02,   67 /* Public */,
      56,    1,  303,    4, 0x02,   68 /* Public */,
      58,    1,  306,    4, 0x02,   70 /* Public */,
      59,    0,  309,    4, 0x02,   72 /* Public */,
      61,    0,  310,    4, 0x02,   73 /* Public */,

 // signals: parameters
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    4,    4,    4,    4,    4,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,   28,   29,   30,   31,   32,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Int,   34,   35,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   43,   44,   35,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   46,   17,   47,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   49,   50,   51,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 53,   49,   50,   51,   54,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Bool,   57,
    QMetaType::Void, QMetaType::QTime,   10,
    0x80000000 | 60,
    QMetaType::QString,

 // properties: name, type, flags
       3, QMetaType::Int, 0x00015401, uint(-1), 0,
      62, QMetaType::Bool, 0x00015003, uint(10), 0,
      63, QMetaType::Bool, 0x00015003, uint(11), 0,

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
        // method 'signalToClearDB'
        void,
        // method 'fetchEduMPIJobsForUser'
        void,
        const QString &,
        // method 'connectionChanged'
        void,
        // method 'clusterConnectionChanged'
        void,
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
        QString,
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
        case 8: _t->signalToClearDB(); break;
        case 9: _t->fetchEduMPIJobsForUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->connectionChanged(); break;
        case 11: _t->clusterConnectionChanged(); break;
        case 12: _t->slurm_status_changed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->getSlurmID((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->slotFetchEduMPIJobs(); break;
        case 15: _t->connect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 16: _t->writeLocalBashFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 17: _t->closeApp(); break;
        case 18: _t->cancelRunningJob(); break;
        case 19: _t->startBash((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: { QString _r = _t->readBash();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 21: _t->writeBash((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 22: { bool _r = _t->checkFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->writeRemoteBashFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 24: { QString _r = _t->connectCluster((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 25: _t->connectClusterAsync((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QJSValue>>(_a[4]))); break;
        case 26: { QString _r = _t->getDatabaseConnection();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 27: _t->setComponentsBuild((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 28: _t->setTimestamp((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1]))); break;
        case 29: { Table_UserID* _r = _t->getJobTable();
            if (_a[0]) *reinterpret_cast< Table_UserID**>(_a[0]) = std::move(_r); }  break;
        case 30: { QString _r = _t->getClusterIdent();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 25:
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
            using _t = void (Controller::*)();
            if (_t _q_method = &Controller::signalToClearDB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Controller::*)(const QString & );
            if (_t _q_method = &Controller::fetchEduMPIJobsForUser; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (_t _q_method = &Controller::connectionChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (_t _q_method = &Controller::clusterConnectionChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
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
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
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
void Controller::signalToClearDB()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Controller::fetchEduMPIJobsForUser(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Controller::connectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void Controller::clusterConnectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}
QT_WARNING_POP
