/****************************************************************************
** Meta object code from reading C++ file 'cluster_rank.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../cluster_rank.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cluster_rank.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSCluster_RankENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCluster_RankENDCLASS = QtMocHelpers::stringData(
    "Cluster_Rank",
    "QML.Element",
    "auto",
    "send_p2p_datasizeChanged",
    "",
    "recv_p2p_datasizeChanged",
    "send_coll_datasizeChanged",
    "recv_coll_datasizeChanged",
    "getId",
    "p2p_send_datasize",
    "p2p_recv_datasize",
    "coll_send_datasize",
    "coll_recv_datasize"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCluster_RankENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[13];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[25];
    char stringdata4[1];
    char stringdata5[25];
    char stringdata6[26];
    char stringdata7[26];
    char stringdata8[6];
    char stringdata9[18];
    char stringdata10[18];
    char stringdata11[19];
    char stringdata12[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCluster_RankENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCluster_RankENDCLASS_t qt_meta_stringdata_CLASSCluster_RankENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "Cluster_Rank"
        QT_MOC_LITERAL(13, 11),  // "QML.Element"
        QT_MOC_LITERAL(25, 4),  // "auto"
        QT_MOC_LITERAL(30, 24),  // "send_p2p_datasizeChanged"
        QT_MOC_LITERAL(55, 0),  // ""
        QT_MOC_LITERAL(56, 24),  // "recv_p2p_datasizeChanged"
        QT_MOC_LITERAL(81, 25),  // "send_coll_datasizeChanged"
        QT_MOC_LITERAL(107, 25),  // "recv_coll_datasizeChanged"
        QT_MOC_LITERAL(133, 5),  // "getId"
        QT_MOC_LITERAL(139, 17),  // "p2p_send_datasize"
        QT_MOC_LITERAL(157, 17),  // "p2p_recv_datasize"
        QT_MOC_LITERAL(175, 18),  // "coll_send_datasize"
        QT_MOC_LITERAL(194, 18)   // "coll_recv_datasize"
    },
    "Cluster_Rank",
    "QML.Element",
    "auto",
    "send_p2p_datasizeChanged",
    "",
    "recv_p2p_datasizeChanged",
    "send_coll_datasizeChanged",
    "recv_coll_datasizeChanged",
    "getId",
    "p2p_send_datasize",
    "p2p_recv_datasize",
    "coll_send_datasize",
    "coll_recv_datasize"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCluster_RankENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       1,   14, // classinfo
       5,   16, // methods
       4,   51, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   46,    4, 0x06,    5 /* Public */,
       5,    0,   47,    4, 0x06,    6 /* Public */,
       6,    0,   48,    4, 0x06,    7 /* Public */,
       7,    0,   49,    4, 0x06,    8 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   50,    4, 0x102,    9 /* Public | MethodIsConst  */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int,

 // properties: name, type, flags
       9, QMetaType::Long, 0x00015003, uint(0), 0,
      10, QMetaType::Long, 0x00015003, uint(1), 0,
      11, QMetaType::Long, 0x00015003, uint(2), 0,
      12, QMetaType::Long, 0x00015003, uint(3), 0,

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
        // property 'coll_send_datasize'
        long,
        // property 'coll_recv_datasize'
        long,
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
        case 4: { int _r = _t->getId();
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
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Cluster_Rank *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< long*>(_v) = _t->p2p_send_datasize(); break;
        case 1: *reinterpret_cast< long*>(_v) = _t->p2p_recv_datasize(); break;
        case 2: *reinterpret_cast< long*>(_v) = _t->coll_send_datasize(); break;
        case 3: *reinterpret_cast< long*>(_v) = _t->coll_recv_datasize(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Cluster_Rank *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_p2p_sendDatasize(*reinterpret_cast< long*>(_v)); break;
        case 1: _t->set_p2p_recvDatasize(*reinterpret_cast< long*>(_v)); break;
        case 2: _t->set_coll_sendDatasize(*reinterpret_cast< long*>(_v)); break;
        case 3: _t->set_coll_recvDatasize(*reinterpret_cast< long*>(_v)); break;
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
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
QT_WARNING_POP
