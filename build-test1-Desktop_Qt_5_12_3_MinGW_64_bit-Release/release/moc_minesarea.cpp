/****************************************************************************
** Meta object code from reading C++ file 'minesarea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test1/minesarea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'minesarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MinesArea_t {
    QByteArrayData data[16];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MinesArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MinesArea_t qt_meta_stringdata_MinesArea = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MinesArea"
QT_MOC_LITERAL(1, 10, 4), // "flag"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 6), // "Tstart"
QT_MOC_LITERAL(4, 23, 10), // "sendStatus"
QT_MOC_LITERAL(5, 34, 22), // "QVector<QVector<int> >"
QT_MOC_LITERAL(6, 57, 5), // "mines"
QT_MOC_LITERAL(7, 63, 23), // "QVector<QVector<bool> >"
QT_MOC_LITERAL(8, 87, 7), // "isPress"
QT_MOC_LITERAL(9, 95, 6), // "isFlag"
QT_MOC_LITERAL(10, 102, 8), // "sendStop"
QT_MOC_LITERAL(11, 111, 14), // "updateComplete"
QT_MOC_LITERAL(12, 126, 6), // "replay"
QT_MOC_LITERAL(13, 133, 12), // "returnStatus"
QT_MOC_LITERAL(14, 146, 9), // "setStatus"
QT_MOC_LITERAL(15, 156, 12) // "QVector<int>"

    },
    "MinesArea\0flag\0\0Tstart\0sendStatus\0"
    "QVector<QVector<int> >\0mines\0"
    "QVector<QVector<bool> >\0isPress\0isFlag\0"
    "sendStop\0updateComplete\0replay\0"
    "returnStatus\0setStatus\0QVector<int>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MinesArea[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    1,   57,    2, 0x06 /* Public */,
       4,    3,   60,    2, 0x06 /* Public */,
      10,    0,   67,    2, 0x06 /* Public */,
      11,    0,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   69,    2, 0x0a /* Public */,
      13,    0,   70,    2, 0x0a /* Public */,
      14,    2,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 7,    6,    8,    9,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Bool,    2,    2,

       0        // eod
};

void MinesArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MinesArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->flag((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->Tstart((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sendStatus((*reinterpret_cast< QVector<QVector<int> >(*)>(_a[1])),(*reinterpret_cast< QVector<QVector<bool> >(*)>(_a[2])),(*reinterpret_cast< QVector<QVector<bool> >(*)>(_a[3]))); break;
        case 3: _t->sendStop(); break;
        case 4: _t->updateComplete(); break;
        case 5: _t->replay(); break;
        case 6: _t->returnStatus(); break;
        case 7: _t->setStatus((*reinterpret_cast< QVector<int>(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
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
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MinesArea::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MinesArea::flag)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MinesArea::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MinesArea::Tstart)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MinesArea::*)(QVector<QVector<int>> , QVector<QVector<bool>> , QVector<QVector<bool>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MinesArea::sendStatus)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MinesArea::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MinesArea::sendStop)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MinesArea::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MinesArea::updateComplete)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MinesArea::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_MinesArea.data,
    qt_meta_data_MinesArea,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MinesArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MinesArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MinesArea.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MinesArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MinesArea::flag(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MinesArea::Tstart(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MinesArea::sendStatus(QVector<QVector<int>> _t1, QVector<QVector<bool>> _t2, QVector<QVector<bool>> _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MinesArea::sendStop()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MinesArea::updateComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
