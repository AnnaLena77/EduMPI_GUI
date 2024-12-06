/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../controller.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
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
struct qt_meta_tag_ZN10ControllerE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10ControllerE = QtMocHelpers::stringData(
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
    "signalEndTime",
    "time",
    "signalToConnect",
    "setProcNum",
    "proc_num",
    "signalToClearDB",
    "fetchEduMPIJobsForUser",
    "userId",
    "connectionChanged",
    "clusterConnectionChanged",
    "slotEndTime",
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
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10ControllerE[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
      33,   16, // methods
       3,  329, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  214,    4, 0x106,    4 /* Public | MethodIsConst  */,
       5,    1,  215,    4, 0x06,    5 /* Public */,
       7,    1,  218,    4, 0x06,    7 /* Public */,
       9,    1,  221,    4, 0x06,    9 /* Public */,
      11,    1,  224,    4, 0x06,   11 /* Public */,
      13,    1,  227,    4, 0x06,   13 /* Public */,
      15,    1,  230,    4, 0x06,   15 /* Public */,
      17,    5,  233,    4, 0x06,   17 /* Public */,
      18,    1,  244,    4, 0x06,   23 /* Public */,
      20,    0,  247,    4, 0x06,   25 /* Public */,
      21,    1,  248,    4, 0x06,   26 /* Public */,
      23,    0,  251,    4, 0x06,   28 /* Public */,
      24,    0,  252,    4, 0x06,   29 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      25,    1,  253,    4, 0x0a,   30 /* Public */,
      26,    1,  256,    4, 0x0a,   32 /* Public */,
      27,    1,  259,    4, 0x0a,   34 /* Public */,
      29,    0,  262,    4, 0x0a,   36 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      30,    5,  263,    4, 0x02,   37 /* Public */,
      36,    3,  274,    4, 0x02,   43 /* Public */,
      39,    0,  281,    4, 0x02,   47 /* Public */,
      40,    0,  282,    4, 0x02,   48 /* Public */,
      41,    1,  283,    4, 0x02,   49 /* Public */,
      42,    0,  286,    4, 0x02,   51 /* Public */,
      43,    1,  287,    4, 0x02,   52 /* Public */,
      45,    3,  290,    4, 0x02,   54 /* Public */,
      48,    3,  297,    4, 0x02,   58 /* Public */,
      51,    3,  304,    4, 0x02,   62 /* Public */,
      55,    4,  311,    4, 0x02,   66 /* Public */,
      58,    0,  320,    4, 0x02,   71 /* Public */,
      59,    1,  321,    4, 0x02,   72 /* Public */,
      61,    1,  324,    4, 0x02,   74 /* Public */,
      62,    0,  327,    4, 0x02,   76 /* Public */,
      64,    0,  328,    4, 0x02,   77 /* Public */,

 // signals: parameters
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    4,    4,    4,    4,    4,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QDateTime,   16,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,   31,   32,   33,   34,   35,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::Int,   37,   38,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   44,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   46,   47,   38,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   49,   19,   50,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   52,   53,   54,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 56,   52,   53,   54,   57,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Bool,   60,
    QMetaType::Void, QMetaType::QTime,   10,
    0x80000000 | 63,
    QMetaType::QString,

 // properties: name, type, flags, notifyId, revision
       3, QMetaType::Int, 0x00015401, uint(-1), 0,
      65, QMetaType::Bool, 0x00015003, uint(11), 0,
      66, QMetaType::Bool, 0x00015003, uint(12), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Controller::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN10ControllerE.offsetsAndSizes,
    qt_meta_data_ZN10ControllerE,
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
        // method 'signalEndTime'
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
        // method 'signalToClearDB'
        void,
        // method 'fetchEduMPIJobsForUser'
        void,
        const QString &,
        // method 'connectionChanged'
        void,
        // method 'clusterConnectionChanged'
        void,
        // method 'slotEndTime'
        void,
        QDateTime,
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
    auto *_t = static_cast<Controller *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { int _r = _t->count();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->liveSlurmID((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->connectionSignal((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->dataIn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->signalSlurmStatusChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->copiedOutputFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->signalEndTime((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->signalToConnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 8: _t->setProcNum((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->signalToClearDB(); break;
        case 10: _t->fetchEduMPIJobsForUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->connectionChanged(); break;
        case 12: _t->clusterConnectionChanged(); break;
        case 13: _t->slotEndTime((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1]))); break;
        case 14: _t->slurm_status_changed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->getSlurmID((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->slotFetchEduMPIJobs(); break;
        case 17: _t->connect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 18: _t->writeLocalBashFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 19: _t->closeApp(); break;
        case 20: _t->cancelRunningJob(); break;
        case 21: _t->startBash((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: { QString _r = _t->readBash();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->writeBash((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 24: { bool _r = _t->checkFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 25: _t->writeRemoteBashFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 26: { QString _r = _t->connectCluster((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 27: _t->connectClusterAsync((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QJSValue>>(_a[4]))); break;
        case 28: { QString _r = _t->getDatabaseConnection();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 29: _t->setComponentsBuild((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 30: _t->setTimestamp((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1]))); break;
        case 31: { Table_UserID* _r = _t->getJobTable();
            if (_a[0]) *reinterpret_cast< Table_UserID**>(_a[0]) = std::move(_r); }  break;
        case 32: { QString _r = _t->getClusterIdent();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 27:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 3:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QJSValue >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = int (Controller::*)() const;
            if (_q_method_type _q_method = &Controller::count; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (Controller::*)(int );
            if (_q_method_type _q_method = &Controller::liveSlurmID; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (Controller::*)(bool );
            if (_q_method_type _q_method = &Controller::connectionSignal; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (Controller::*)(int );
            if (_q_method_type _q_method = &Controller::dataIn; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (Controller::*)(QString );
            if (_q_method_type _q_method = &Controller::signalSlurmStatusChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (Controller::*)(QString );
            if (_q_method_type _q_method = &Controller::copiedOutputFile; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (Controller::*)(int );
            if (_q_method_type _q_method = &Controller::signalEndTime; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _q_method_type = void (Controller::*)(const QString & , const QString & , const int & , const QString & , const QString & );
            if (_q_method_type _q_method = &Controller::signalToConnect; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _q_method_type = void (Controller::*)(const int );
            if (_q_method_type _q_method = &Controller::setProcNum; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _q_method_type = void (Controller::*)();
            if (_q_method_type _q_method = &Controller::signalToClearDB; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _q_method_type = void (Controller::*)(const QString & );
            if (_q_method_type _q_method = &Controller::fetchEduMPIJobsForUser; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _q_method_type = void (Controller::*)();
            if (_q_method_type _q_method = &Controller::connectionChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _q_method_type = void (Controller::*)();
            if (_q_method_type _q_method = &Controller::clusterConnectionChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->count(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->m_connection_ready; break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->m_cluster_connection_ready; break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
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
    }
}

const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10ControllerE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
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
void Controller::signalEndTime(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Controller::signalToConnect(const QString & _t1, const QString & _t2, const int & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Controller::setProcNum(const int _t1)
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
void Controller::fetchEduMPIJobsForUser(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Controller::connectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void Controller::clusterConnectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}
QT_WARNING_POP
