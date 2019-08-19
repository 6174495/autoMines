/****************************************************************************
** Meta object code from reading C++ file 'aicontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test1/aicontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aicontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AIControl_t {
    QByteArrayData data[13];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AIControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AIControl_t qt_meta_stringdata_AIControl = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AIControl"
QT_MOC_LITERAL(1, 10, 9), // "getStatus"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "setStatus"
QT_MOC_LITERAL(4, 31, 12), // "QVector<int>"
QT_MOC_LITERAL(5, 44, 10), // "gainStatus"
QT_MOC_LITERAL(6, 55, 22), // "QVector<QVector<int> >"
QT_MOC_LITERAL(7, 78, 5), // "mines"
QT_MOC_LITERAL(8, 84, 23), // "QVector<QVector<bool> >"
QT_MOC_LITERAL(9, 108, 7), // "isPress"
QT_MOC_LITERAL(10, 116, 6), // "isFlag"
QT_MOC_LITERAL(11, 123, 6), // "beStop"
QT_MOC_LITERAL(12, 130, 14) // "updateComplete"

    },
    "AIControl\0getStatus\0\0setStatus\0"
    "QVector<int>\0gainStatus\0QVector<QVector<int> >\0"
    "mines\0QVector<QVector<bool> >\0isPress\0"
    "isFlag\0beStop\0updateComplete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AIControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    2,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,   45,    2, 0x0a /* Public */,
      11,    0,   52,    2, 0x0a /* Public */,
      12,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Bool,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8, 0x80000000 | 8,    7,    9,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AIControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AIControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getStatus(); break;
        case 1: _t->setStatus((*reinterpret_cast< QVector<int>(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->gainStatus((*reinterpret_cast< QVector<QVector<int> >(*)>(_a[1])),(*reinterpret_cast< QVector<QVector<bool> >(*)>(_a[2])),(*reinterpret_cast< QVector<QVector<bool> >(*)>(_a[3]))); break;
        case 3: _t->beStop(); break;
        case 4: _t->updateComplete(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<bool> > >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<int> > >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AIControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AIControl::getStatus)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AIControl::*)(QVector<int> , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AIControl::setStatus)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AIControl::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_AIControl.data,
    qt_meta_data_AIControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AIControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AIControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AIControl.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int AIControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void AIControl::getStatus()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AIControl::setStatus(QVector<int> _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
