/****************************************************************************
** Meta object code from reading C++ file 'cluster_architecture.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../cluster_architecture.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cluster_architecture.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN20Cluster_ArchitectureE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN20Cluster_ArchitectureE = QtMocHelpers::stringData(
    "Cluster_Architecture",
    "QML.Element",
    "auto",
    "p2p_send_max_changed",
    "",
    "coll_send_max_changed",
    "p2p_recv_max_changed",
    "coll_recv_max_changed",
    "slurm_id_changed",
    "proc_num_changed",
    "end_timeChanged",
    "time",
    "signalToConnect",
    "signalToUpdateData",
    "signalToClearDB",
    "signalToShowTimestampData",
    "timestampA",
    "timestampB",
    "startDatabaseThread",
    "signalToDBConnection",
    "waitForEnd",
    "componentsBuilt",
    "connectionSignal",
    "success",
    "dataIn",
    "timestamp",
    "qTimestamp",
    "start",
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
    "nodeAt",
    "Cluster_Node*",
    "index",
    "set_end_time",
    "count",
    "p2p_send_max",
    "coll_send_max",
    "p2p_recv_max",
    "coll_recv_max",
    "slurm_id",
    "proc_num",
    "end_time"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN20Cluster_ArchitectureE[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
      32,   16, // methods
       8,  298, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      19,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  208,    4, 0x06,    9 /* Public */,
       5,    0,  209,    4, 0x06,   10 /* Public */,
       6,    0,  210,    4, 0x06,   11 /* Public */,
       7,    0,  211,    4, 0x06,   12 /* Public */,
       8,    0,  212,    4, 0x06,   13 /* Public */,
       9,    0,  213,    4, 0x06,   14 /* Public */,
      10,    1,  214,    4, 0x06,   15 /* Public */,
      12,    5,  217,    4, 0x06,   17 /* Public */,
      13,    1,  228,    4, 0x06,   23 /* Public */,
      14,    0,  231,    4, 0x06,   25 /* Public */,
      15,    2,  232,    4, 0x06,   26 /* Public */,
      18,    0,  237,    4, 0x06,   29 /* Public */,
      19,    0,  238,    4, 0x06,   30 /* Public */,
      20,    0,  239,    4, 0x06,   31 /* Public */,
      21,    0,  240,    4, 0x06,   32 /* Public */,
      22,    1,  241,    4, 0x06,   33 /* Public */,
      24,    3,  244,    4, 0x06,   35 /* Public */,
      28,    1,  251,    4, 0x06,   39 /* Public */,
      30,    1,  254,    4, 0x06,   41 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      32,    1,  257,    4, 0x0a,   43 /* Public */,
      34,    1,  260,    4, 0x0a,   45 /* Public */,
      36,    0,  263,    4, 0x0a,   47 /* Public */,
      37,    2,  264,    4, 0x0a,   48 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      38,    2,  269,    4, 0x02,   51 /* Public */,
      41,    0,  274,    4, 0x02,   54 /* Public */,
      42,    1,  275,    4, 0x02,   55 /* Public */,
      44,    1,  278,    4, 0x02,   57 /* Public */,
      46,    1,  281,    4, 0x02,   59 /* Public */,
      48,    2,  284,    4, 0x02,   61 /* Public */,
      51,    1,  289,    4, 0x02,   64 /* Public */,
      52,    1,  292,    4, 0x02,   66 /* Public */,
      55,    1,  295,    4, 0x02,   68 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,    4,    4,    4,    4,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::QTime, QMetaType::Bool,   25,   26,   27,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QString,   31,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 33,    4,
    QMetaType::Void, 0x80000000 | 35,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::Bool,   25,   27,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   39,   40,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void, QMetaType::Int,   45,
    QMetaType::Void, QMetaType::Int,   47,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   49,   50,
    QMetaType::Void, QMetaType::Bool,   27,
    0x80000000 | 53, QMetaType::Int,   54,
    QMetaType::Void, QMetaType::Int,   11,

 // properties: name, type, flags, notifyId, revision
      56, QMetaType::Int, 0x00015401, uint(-1), 0,
      57, QMetaType::Long, 0x00015003, uint(0), 0,
      58, QMetaType::Long, 0x00015003, uint(1), 0,
      59, QMetaType::Long, 0x00015003, uint(2), 0,
      60, QMetaType::Long, 0x00015003, uint(3), 0,
      61, QMetaType::Int, 0x00015003, uint(4), 0,
      62, QMetaType::Int, 0x00015003, uint(5), 0,
      63, QMetaType::Int, 0x00015003, uint(6), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Cluster_Architecture::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN20Cluster_ArchitectureE.offsetsAndSizes,
    qt_meta_data_ZN20Cluster_ArchitectureE,
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
        // property 'slurm_id'
        int,
        // property 'proc_num'
        int,
        // property 'end_time'
        int,
        // Q_OBJECT / Q_GADGET
        Cluster_Architecture,
        // method 'p2p_send_max_changed'
        void,
        // method 'coll_send_max_changed'
        void,
        // method 'p2p_recv_max_changed'
        void,
        // method 'coll_recv_max_changed'
        void,
        // method 'slurm_id_changed'
        void,
        // method 'proc_num_changed'
        void,
        // method 'end_timeChanged'
        void,
        QDateTime,
        // method 'signalToConnect'
        void,
        const QString &,
        const QString &,
        const int &,
        const QString &,
        const QString &,
        // method 'signalToUpdateData'
        void,
        const int &,
        // method 'signalToClearDB'
        void,
        // method 'signalToShowTimestampData'
        void,
        const QDateTime,
        const QDateTime,
        // method 'startDatabaseThread'
        void,
        // method 'signalToDBConnection'
        void,
        // method 'waitForEnd'
        void,
        // method 'componentsBuilt'
        void,
        // method 'connectionSignal'
        void,
        bool,
        // method 'dataIn'
        void,
        int,
        QTime,
        bool,
        // method 'signalSlurmStatusChanged'
        void,
        QString,
        // method 'copiedOutputFile'
        void,
        QString,
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
        QDateTime,
        bool,
        // method 'initialize'
        void,
        QString,
        bool,
        // method 'startThread'
        void,
        // method 'set_slurm_id'
        void,
        int,
        // method 'set_proc_num'
        void,
        int,
        // method 'setOption'
        void,
        int,
        // method 'showConditionAt'
        void,
        int,
        int,
        // method 'startAndStop'
        void,
        bool,
        // method 'nodeAt'
        Cluster_Node *,
        int,
        // method 'set_end_time'
        void,
        int
    >,
    nullptr
} };

void Cluster_Architecture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Cluster_Architecture *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->p2p_send_max_changed(); break;
        case 1: _t->coll_send_max_changed(); break;
        case 2: _t->p2p_recv_max_changed(); break;
        case 3: _t->coll_recv_max_changed(); break;
        case 4: _t->slurm_id_changed(); break;
        case 5: _t->proc_num_changed(); break;
        case 6: _t->end_timeChanged((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1]))); break;
        case 7: _t->signalToConnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 8: _t->signalToUpdateData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->signalToClearDB(); break;
        case 10: _t->signalToShowTimestampData((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[2]))); break;
        case 11: _t->startDatabaseThread(); break;
        case 12: _t->signalToDBConnection(); break;
        case 13: _t->waitForEnd(); break;
        case 14: _t->componentsBuilt(); break;
        case 15: _t->connectionSignal((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 16: _t->dataIn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 17: _t->signalSlurmStatusChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->copiedOutputFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 19: _t->buildClusterComponents((*reinterpret_cast< std::add_pointer_t<QMap<QString,QList<int>>>>(_a[1]))); break;
        case 20: _t->updateDataToUI((*reinterpret_cast< std::add_pointer_t<QList<DataColumn>>>(_a[1]))); break;
        case 21: _t->removeClusterComponents(); break;
        case 22: _t->handleTimestamp((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 23: _t->initialize((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 24: _t->startThread(); break;
        case 25: _t->set_slurm_id((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 26: _t->set_proc_num((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->setOption((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->showConditionAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 29: _t->startAndStop((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 30: { Cluster_Node* _r = _t->nodeAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< Cluster_Node**>(_a[0]) = std::move(_r); }  break;
        case 31: _t->set_end_time((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (Cluster_Architecture::*)();
            if (_q_method_type _q_method = &Cluster_Architecture::p2p_send_max_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)();
            if (_q_method_type _q_method = &Cluster_Architecture::coll_send_max_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)();
            if (_q_method_type _q_method = &Cluster_Architecture::p2p_recv_max_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)();
            if (_q_method_type _q_method = &Cluster_Architecture::coll_recv_max_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)();
            if (_q_method_type _q_method = &Cluster_Architecture::slurm_id_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)();
            if (_q_method_type _q_method = &Cluster_Architecture::proc_num_changed; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)(QDateTime );
            if (_q_method_type _q_method = &Cluster_Architecture::end_timeChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)(const QString & , const QString & , const int & , const QString & , const QString & );
            if (_q_method_type _q_method = &Cluster_Architecture::signalToConnect; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)(const int & );
            if (_q_method_type _q_method = &Cluster_Architecture::signalToUpdateData; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)();
            if (_q_method_type _q_method = &Cluster_Architecture::signalToClearDB; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)(const QDateTime , const QDateTime );
            if (_q_method_type _q_method = &Cluster_Architecture::signalToShowTimestampData; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)();
            if (_q_method_type _q_method = &Cluster_Architecture::startDatabaseThread; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)();
            if (_q_method_type _q_method = &Cluster_Architecture::signalToDBConnection; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)();
            if (_q_method_type _q_method = &Cluster_Architecture::waitForEnd; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)();
            if (_q_method_type _q_method = &Cluster_Architecture::componentsBuilt; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)(bool );
            if (_q_method_type _q_method = &Cluster_Architecture::connectionSignal; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)(int , QTime , bool );
            if (_q_method_type _q_method = &Cluster_Architecture::dataIn; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)(QString );
            if (_q_method_type _q_method = &Cluster_Architecture::signalSlurmStatusChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
        {
            using _q_method_type = void (Cluster_Architecture::*)(QString );
            if (_q_method_type _q_method = &Cluster_Architecture::copiedOutputFile; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 18;
                return;
            }
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->count(); break;
        case 1: *reinterpret_cast< long*>(_v) = _t->p2p_send_max(); break;
        case 2: *reinterpret_cast< long*>(_v) = _t->coll_send_max(); break;
        case 3: *reinterpret_cast< long*>(_v) = _t->p2p_recv_max(); break;
        case 4: *reinterpret_cast< long*>(_v) = _t->coll_recv_max(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->slurm_id(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->proc_num(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->end_time(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->set_p2p_send_max(*reinterpret_cast< long*>(_v)); break;
        case 2: _t->set_coll_send_max(*reinterpret_cast< long*>(_v)); break;
        case 3: _t->set_p2p_recv_max(*reinterpret_cast< long*>(_v)); break;
        case 4: _t->set_coll_recv_max(*reinterpret_cast< long*>(_v)); break;
        case 5: _t->set_slurm_id(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->set_proc_num(*reinterpret_cast< int*>(_v)); break;
        case 7: _t->set_end_time(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *Cluster_Architecture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cluster_Architecture::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN20Cluster_ArchitectureE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Cluster_Architecture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 32;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
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
void Cluster_Architecture::end_timeChanged(QDateTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Cluster_Architecture::signalToConnect(const QString & _t1, const QString & _t2, const int & _t3, const QString & _t4, const QString & _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Cluster_Architecture::signalToUpdateData(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Cluster_Architecture::signalToClearDB()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void Cluster_Architecture::signalToShowTimestampData(const QDateTime _t1, const QDateTime _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Cluster_Architecture::startDatabaseThread()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void Cluster_Architecture::signalToDBConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void Cluster_Architecture::waitForEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void Cluster_Architecture::componentsBuilt()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void Cluster_Architecture::connectionSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Cluster_Architecture::dataIn(int _t1, QTime _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Cluster_Architecture::signalSlurmStatusChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void Cluster_Architecture::copiedOutputFile(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}
QT_WARNING_POP
