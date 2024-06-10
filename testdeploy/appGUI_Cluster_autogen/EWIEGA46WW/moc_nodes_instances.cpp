/****************************************************************************
** Meta object code from reading C++ file 'nodes_instances.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../nodes_instances.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nodes_instances.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSNodes_InstancesENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSNodes_InstancesENDCLASS = QtMocHelpers::stringData(
    "Nodes_Instances",
    "QML.Element",
    "auto",
    "instanceCountChanged",
    "",
    "setInstanceCount",
    "count",
    "instanceCount"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSNodes_InstancesENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[16];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[21];
    char stringdata4[1];
    char stringdata5[17];
    char stringdata6[6];
    char stringdata7[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSNodes_InstancesENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSNodes_InstancesENDCLASS_t qt_meta_stringdata_CLASSNodes_InstancesENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "Nodes_Instances"
        QT_MOC_LITERAL(16, 11),  // "QML.Element"
        QT_MOC_LITERAL(28, 4),  // "auto"
        QT_MOC_LITERAL(33, 20),  // "instanceCountChanged"
        QT_MOC_LITERAL(54, 0),  // ""
        QT_MOC_LITERAL(55, 16),  // "setInstanceCount"
        QT_MOC_LITERAL(72, 5),  // "count"
        QT_MOC_LITERAL(78, 13)   // "instanceCount"
    },
    "Nodes_Instances",
    "QML.Element",
    "auto",
    "instanceCountChanged",
    "",
    "setInstanceCount",
    "count",
    "instanceCount"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSNodes_InstancesENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       1,   14, // classinfo
       2,   16, // methods
       1,   32, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   28,    4, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   29,    4, 0x0a,    3 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,

 // properties: name, type, flags
       7, QMetaType::Int, 0x00015103, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Nodes_Instances::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuick3DInstancing::staticMetaObject>(),
    qt_meta_stringdata_CLASSNodes_InstancesENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSNodes_InstancesENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'instanceCount'
        int,
        // Q_OBJECT / Q_GADGET
        Nodes_Instances,
        // method 'instanceCountChanged'
        void,
        // method 'setInstanceCount'
        void,
        int
    >,
    nullptr
} };

void Nodes_Instances::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Nodes_Instances *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->instanceCountChanged(); break;
        case 1: _t->setInstanceCount((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Nodes_Instances::*)();
            if (_t _q_method = &Nodes_Instances::instanceCountChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Nodes_Instances *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->instanceCount(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Nodes_Instances *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setInstanceCount(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Nodes_Instances::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Nodes_Instances::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSNodes_InstancesENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QQuick3DInstancing::qt_metacast(_clname);
}

int Nodes_Instances::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuick3DInstancing::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void Nodes_Instances::instanceCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
