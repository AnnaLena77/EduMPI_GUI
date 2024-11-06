/****************************************************************************
** Meta object code from reading C++ file 'cluster_rank.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../cluster_rank.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cluster_rank.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
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
struct qt_meta_stringdata_CLASSCluster_RankENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSCluster_RankENDCLASS = QtMocHelpers::stringData(
    "Cluster_Rank",
    "QML.Element",
    "auto",
    "send_p2p_datasizeChanged",
    "",
    "recv_p2p_datasizeChanged",
    "send_coll_datasizeChanged",
    "recv_coll_datasizeChanged",
    "p2p_late_senderChanged",
    "p2p_late_recvrChanged",
    "p2p_timediffChanged",
    "coll_late_senderChanged",
    "coll_late_recvrChanged",
    "coll_timediffChanged",
    "positionChanged",
    "getId",
    "p2p_send_datasize",
    "p2p_recv_datasize",
    "p2p_late_sender",
    "p2p_late_recvr",
    "coll_send_datasize",
    "coll_recv_datasize",
    "coll_late_sender",
    "coll_late_recvr",
    "coll_timediff",
    "p2p_timediff",
    "position"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCluster_RankENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       1,   14, // classinfo
      12,   16, // methods
      11,  100, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   88,    4, 0x06,   12 /* Public */,
       5,    0,   89,    4, 0x06,   13 /* Public */,
       6,    0,   90,    4, 0x06,   14 /* Public */,
       7,    0,   91,    4, 0x06,   15 /* Public */,
       8,    0,   92,    4, 0x06,   16 /* Public */,
       9,    0,   93,    4, 0x06,   17 /* Public */,
      10,    0,   94,    4, 0x06,   18 /* Public */,
      11,    0,   95,    4, 0x06,   19 /* Public */,
      12,    0,   96,    4, 0x06,   20 /* Public */,
      13,    0,   97,    4, 0x06,   21 /* Public */,
      14,    0,   98,    4, 0x06,   22 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      15,    0,   99,    4, 0x102,   23 /* Public | MethodIsConst  */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int,

 // properties: name, type, flags, notifyId, revision
      16, QMetaType::Long, 0x00015003, uint(0), 0,
      17, QMetaType::Long, 0x00015003, uint(1), 0,
      18, QMetaType::Float, 0x00015003, uint(4), 0,
      19, QMetaType::Float, 0x00015003, uint(5), 0,
      20, QMetaType::Long, 0x00015003, uint(2), 0,
      21, QMetaType::Long, 0x00015003, uint(3), 0,
      22, QMetaType::Float, 0x00015003, uint(7), 0,
      23, QMetaType::Float, 0x00015003, uint(8), 0,
      24, QMetaType::Float, 0x00015003, uint(9), 0,
      25, QMetaType::Float, 0x00015003, uint(6), 0,
      26, QMetaType::QVector3D, 0x00015003, uint(10), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Cluster_Rank::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSCluster_RankENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCluster_RankENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'p2p_send_datasize'
        long,
        // property 'p2p_recv_datasize'
        long,
        // property 'p2p_late_sender'
        float,
        // property 'p2p_late_recvr'
        float,
        // property 'coll_send_datasize'
        long,
        // property 'coll_recv_datasize'
        long,
        // property 'coll_late_sender'
        float,
        // property 'coll_late_recvr'
        float,
        // property 'coll_timediff'
        float,
        // property 'p2p_timediff'
        float,
        // property 'position'
        QVector3D,
        // Q_OBJECT / Q_GADGET
        Cluster_Rank,
        // method 'send_p2p_datasizeChanged'
        void,
        // method 'recv_p2p_datasizeChanged'
        void,
        // method 'send_coll_datasizeChanged'
        void,
        // method 'recv_coll_datasizeChanged'
        void,
        // method 'p2p_late_senderChanged'
        void,
        // method 'p2p_late_recvrChanged'
        void,
        // method 'p2p_timediffChanged'
        void,
        // method 'coll_late_senderChanged'
        void,
        // method 'coll_late_recvrChanged'
        void,
        // method 'coll_timediffChanged'
        void,
        // method 'positionChanged'
        void,
        // method 'getId'
        int
    >,
    nullptr
} };

void Cluster_Rank::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Cluster_Rank *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->send_p2p_datasizeChanged(); break;
        case 1: _t->recv_p2p_datasizeChanged(); break;
        case 2: _t->send_coll_datasizeChanged(); break;
        case 3: _t->recv_coll_datasizeChanged(); break;
        case 4: _t->p2p_late_senderChanged(); break;
        case 5: _t->p2p_late_recvrChanged(); break;
        case 6: _t->p2p_timediffChanged(); break;
        case 7: _t->coll_late_senderChanged(); break;
        case 8: _t->coll_late_recvrChanged(); break;
        case 9: _t->coll_timediffChanged(); break;
        case 10: _t->positionChanged(); break;
        case 11: { int _r = _t->getId();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Cluster_Rank::*)();
            if (_t _q_method = &Cluster_Rank::send_p2p_datasizeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Cluster_Rank::*)();
            if (_t _q_method = &Cluster_Rank::recv_p2p_datasizeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Cluster_Rank::*)();
            if (_t _q_method = &Cluster_Rank::send_coll_datasizeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Cluster_Rank::*)();
            if (_t _q_method = &Cluster_Rank::recv_coll_datasizeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Cluster_Rank::*)();
            if (_t _q_method = &Cluster_Rank::p2p_late_senderChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Cluster_Rank::*)();
            if (_t _q_method = &Cluster_Rank::p2p_late_recvrChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Cluster_Rank::*)();
            if (_t _q_method = &Cluster_Rank::p2p_timediffChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Cluster_Rank::*)();
            if (_t _q_method = &Cluster_Rank::coll_late_senderChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Cluster_Rank::*)();
            if (_t _q_method = &Cluster_Rank::coll_late_recvrChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Cluster_Rank::*)();
            if (_t _q_method = &Cluster_Rank::coll_timediffChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Cluster_Rank::*)();
            if (_t _q_method = &Cluster_Rank::positionChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Cluster_Rank *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< long*>(_v) = _t->p2p_send_datasize(); break;
        case 1: *reinterpret_cast< long*>(_v) = _t->p2p_recv_datasize(); break;
        case 2: *reinterpret_cast< float*>(_v) = _t->p2p_late_sender(); break;
        case 3: *reinterpret_cast< float*>(_v) = _t->p2p_late_recvr(); break;
        case 4: *reinterpret_cast< long*>(_v) = _t->coll_send_datasize(); break;
        case 5: *reinterpret_cast< long*>(_v) = _t->coll_recv_datasize(); break;
        case 6: *reinterpret_cast< float*>(_v) = _t->coll_late_sender(); break;
        case 7: *reinterpret_cast< float*>(_v) = _t->coll_late_recvr(); break;
        case 8: *reinterpret_cast< float*>(_v) = _t->coll_timediff(); break;
        case 9: *reinterpret_cast< float*>(_v) = _t->p2p_timediff(); break;
        case 10: *reinterpret_cast< QVector3D*>(_v) = _t->position(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Cluster_Rank *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_p2p_sendDatasize(*reinterpret_cast< long*>(_v)); break;
        case 1: _t->set_p2p_recvDatasize(*reinterpret_cast< long*>(_v)); break;
        case 2: _t->set_p2p_late_sender(*reinterpret_cast< float*>(_v)); break;
        case 3: _t->set_p2p_late_recvr(*reinterpret_cast< float*>(_v)); break;
        case 4: _t->set_coll_sendDatasize(*reinterpret_cast< long*>(_v)); break;
        case 5: _t->set_coll_recvDatasize(*reinterpret_cast< long*>(_v)); break;
        case 6: _t->set_coll_late_sender(*reinterpret_cast< float*>(_v)); break;
        case 7: _t->set_coll_late_recvr(*reinterpret_cast< float*>(_v)); break;
        case 8: _t->set_coll_timediff(*reinterpret_cast< float*>(_v)); break;
        case 9: _t->set_p2p_timediff(*reinterpret_cast< float*>(_v)); break;
        case 10: _t->set_position(*reinterpret_cast< QVector3D*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Cluster_Rank::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cluster_Rank::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCluster_RankENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Cluster_Rank::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Cluster_Rank::send_p2p_datasizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Cluster_Rank::recv_p2p_datasizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Cluster_Rank::send_coll_datasizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Cluster_Rank::recv_coll_datasizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Cluster_Rank::p2p_late_senderChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Cluster_Rank::p2p_late_recvrChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Cluster_Rank::p2p_timediffChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Cluster_Rank::coll_late_senderChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Cluster_Rank::coll_late_recvrChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Cluster_Rank::coll_timediffChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void Cluster_Rank::positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
