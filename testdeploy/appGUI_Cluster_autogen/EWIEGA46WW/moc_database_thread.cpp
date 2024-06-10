/****************************************************************************
** Meta object code from reading C++ file 'database_thread.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../database_thread.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'database_thread.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSDatabase_ThreadENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDatabase_ThreadENDCLASS = QtMocHelpers::stringData(
    "Database_Thread",
    "connectedToDB",
    "",
    "success",
    "clusterComponentsReady",
    "QMap<QString,QList<int>>",
    "map",
    "updateDataReady",
    "QList<DataColumn>",
    "list",
    "dbCleared",
    "setTimestamp",
    "timestamp",
    "connectToDB",
    "hostname",
    "databasename",
    "port",
    "username",
    "password",
    "threadbuildClusterComponents",
    "proc_num",
    "updateData",
    "time_display",
    "showDataFromTimePeriod",
    "timestampA",
    "timestampB",
    "clearDatabase"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDatabase_ThreadENDCLASS_t {
    uint offsetsAndSizes[54];
    char stringdata0[16];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[23];
    char stringdata5[25];
    char stringdata6[4];
    char stringdata7[16];
    char stringdata8[18];
    char stringdata9[5];
    char stringdata10[10];
    char stringdata11[13];
    char stringdata12[10];
    char stringdata13[12];
    char stringdata14[9];
    char stringdata15[13];
    char stringdata16[5];
    char stringdata17[9];
    char stringdata18[9];
    char stringdata19[29];
    char stringdata20[9];
    char stringdata21[11];
    char stringdata22[13];
    char stringdata23[23];
    char stringdata24[11];
    char stringdata25[11];
    char stringdata26[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDatabase_ThreadENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDatabase_ThreadENDCLASS_t qt_meta_stringdata_CLASSDatabase_ThreadENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "Database_Thread"
        QT_MOC_LITERAL(16, 13),  // "connectedToDB"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 7),  // "success"
        QT_MOC_LITERAL(39, 22),  // "clusterComponentsReady"
        QT_MOC_LITERAL(62, 24),  // "QMap<QString,QList<int>>"
        QT_MOC_LITERAL(87, 3),  // "map"
        QT_MOC_LITERAL(91, 15),  // "updateDataReady"
        QT_MOC_LITERAL(107, 17),  // "QList<DataColumn>"
        QT_MOC_LITERAL(125, 4),  // "list"
        QT_MOC_LITERAL(130, 9),  // "dbCleared"
        QT_MOC_LITERAL(140, 12),  // "setTimestamp"
        QT_MOC_LITERAL(153, 9),  // "timestamp"
        QT_MOC_LITERAL(163, 11),  // "connectToDB"
        QT_MOC_LITERAL(175, 8),  // "hostname"
        QT_MOC_LITERAL(184, 12),  // "databasename"
        QT_MOC_LITERAL(197, 4),  // "port"
        QT_MOC_LITERAL(202, 8),  // "username"
        QT_MOC_LITERAL(211, 8),  // "password"
        QT_MOC_LITERAL(220, 28),  // "threadbuildClusterComponents"
        QT_MOC_LITERAL(249, 8),  // "proc_num"
        QT_MOC_LITERAL(258, 10),  // "updateData"
        QT_MOC_LITERAL(269, 12),  // "time_display"
        QT_MOC_LITERAL(282, 22),  // "showDataFromTimePeriod"
        QT_MOC_LITERAL(305, 10),  // "timestampA"
        QT_MOC_LITERAL(316, 10),  // "timestampB"
        QT_MOC_LITERAL(327, 13)   // "clearDatabase"
    },
    "Database_Thread",
    "connectedToDB",
    "",
    "success",
    "clusterComponentsReady",
    "QMap<QString,QList<int>>",
    "map",
    "updateDataReady",
    "QList<DataColumn>",
    "list",
    "dbCleared",
    "setTimestamp",
    "timestamp",
    "connectToDB",
    "hostname",
    "databasename",
    "port",
    "username",
    "password",
    "threadbuildClusterComponents",
    "proc_num",
    "updateData",
    "time_display",
    "showDataFromTimePeriod",
    "timestampA",
    "timestampB",
    "clearDatabase"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDatabase_ThreadENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       4,    1,   77,    2, 0x06,    3 /* Public */,
       7,    1,   80,    2, 0x06,    5 /* Public */,
      10,    0,   83,    2, 0x06,    7 /* Public */,
      11,    1,   84,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    5,   87,    2, 0x0a,   10 /* Public */,
      19,    1,   98,    2, 0x0a,   16 /* Public */,
      21,    1,  101,    2, 0x0a,   18 /* Public */,
      23,    2,  104,    2, 0x0a,   20 /* Public */,
      26,    0,  109,    2, 0x0a,   23 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString,   14,   15,   16,   17,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::QTime, QMetaType::QTime,   24,   25,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Database_Thread::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSDatabase_ThreadENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDatabase_ThreadENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDatabase_ThreadENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Database_Thread, std::true_type>,
        // method 'connectedToDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool &, std::false_type>,
        // method 'clusterComponentsReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QMap<QString,QVector<int>> &, std::false_type>,
        // method 'updateDataReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<DataColumn> &, std::false_type>,
        // method 'dbCleared'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setTimestamp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTime, std::false_type>,
        // method 'connectToDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'threadbuildClusterComponents'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'updateData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'showDataFromTimePeriod'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QTime, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QTime, std::false_type>,
        // method 'clearDatabase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Database_Thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Database_Thread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connectedToDB((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->clusterComponentsReady((*reinterpret_cast< std::add_pointer_t<QMap<QString,QList<int>>>>(_a[1]))); break;
        case 2: _t->updateDataReady((*reinterpret_cast< std::add_pointer_t<QList<DataColumn>>>(_a[1]))); break;
        case 3: _t->dbCleared(); break;
        case 4: _t->setTimestamp((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1]))); break;
        case 5: _t->connectToDB((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 6: _t->threadbuildClusterComponents((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->updateData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->showDataFromTimePeriod((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTime>>(_a[2]))); break;
        case 9: _t->clearDatabase(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Database_Thread::*)(const bool & );
            if (_t _q_method = &Database_Thread::connectedToDB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Database_Thread::*)(const QMap<QString,QVector<int>> & );
            if (_t _q_method = &Database_Thread::clusterComponentsReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Database_Thread::*)(const QList<DataColumn> & );
            if (_t _q_method = &Database_Thread::updateDataReady; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Database_Thread::*)();
            if (_t _q_method = &Database_Thread::dbCleared; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Database_Thread::*)(QTime );
            if (_t _q_method = &Database_Thread::setTimestamp; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *Database_Thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Database_Thread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDatabase_ThreadENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Database_Thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Database_Thread::connectedToDB(const bool & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Database_Thread::clusterComponentsReady(const QMap<QString,QVector<int>> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Database_Thread::updateDataReady(const QList<DataColumn> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Database_Thread::dbCleared()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Database_Thread::setTimestamp(QTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
