/****************************************************************************
** Meta object code from reading C++ file 'database_thread.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../database_thread.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'database_thread.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSDatabase_ThreadENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDatabase_ThreadENDCLASS = QtMocHelpers::stringData(
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
    "eduMPIJobsFetched",
    "QVariantList",
    "jobIds",
    "connectToDB",
    "threadbuildClusterComponents",
    "updateData",
    "time_display",
    "showDataFromTimePeriod",
    "timestampA",
    "timestampB",
    "clearDatabase",
    "getProcNum",
    "proc_num",
    "fetchEduMPIJobs",
    "userId"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDatabase_ThreadENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    2, 0x06,    1 /* Public */,
       4,    1,   95,    2, 0x06,    3 /* Public */,
       7,    1,   98,    2, 0x06,    5 /* Public */,
      10,    0,  101,    2, 0x06,    7 /* Public */,
      11,    1,  102,    2, 0x06,    8 /* Public */,
      13,    1,  105,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      16,    0,  108,    2, 0x0a,   12 /* Public */,
      17,    0,  109,    2, 0x0a,   13 /* Public */,
      18,    1,  110,    2, 0x0a,   14 /* Public */,
      20,    2,  113,    2, 0x0a,   16 /* Public */,
      23,    0,  118,    2, 0x0a,   19 /* Public */,
      24,    1,  119,    2, 0x0a,   20 /* Public */,
      26,    1,  122,    2, 0x0a,   22 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,   12,
    QMetaType::Void, 0x80000000 | 14,   15,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime,   21,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::QString,   27,

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
        QtPrivate::TypeAndForceComplete<QDateTime, std::false_type>,
        // method 'eduMPIJobsFetched'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantList &, std::false_type>,
        // method 'connectToDB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'threadbuildClusterComponents'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'showDataFromTimePeriod'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime, std::false_type>,
        // method 'clearDatabase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getProcNum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'fetchEduMPIJobs'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
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
        case 4: _t->setTimestamp((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1]))); break;
        case 5: _t->eduMPIJobsFetched((*reinterpret_cast< std::add_pointer_t<QVariantList>>(_a[1]))); break;
        case 6: _t->connectToDB(); break;
        case 7: _t->threadbuildClusterComponents(); break;
        case 8: _t->updateData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->showDataFromTimePeriod((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[2]))); break;
        case 10: _t->clearDatabase(); break;
        case 11: _t->getProcNum((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->fetchEduMPIJobs((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
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
            using _t = void (Database_Thread::*)(QDateTime );
            if (_t _q_method = &Database_Thread::setTimestamp; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Database_Thread::*)(const QVariantList & );
            if (_t _q_method = &Database_Thread::eduMPIJobsFetched; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
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
void Database_Thread::setTimestamp(QDateTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Database_Thread::eduMPIJobsFetched(const QVariantList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
