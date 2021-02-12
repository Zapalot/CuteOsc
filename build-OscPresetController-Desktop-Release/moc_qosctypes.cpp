/****************************************************************************
** Meta object code from reading C++ file 'qosctypes.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../libofqf/qosctypes.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qosctypes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QOscBase_t {
    QByteArrayData data[1];
    char stringdata0[9];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QOscBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QOscBase_t qt_meta_stringdata_QOscBase = {
    {
QT_MOC_LITERAL(0, 0, 8) // "QOscBase"

    },
    "QOscBase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QOscBase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void QOscBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject QOscBase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QOscBase.data,
      qt_meta_data_QOscBase,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QOscBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QOscBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QOscBase.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QOscBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_PathObject_t {
    QByteArrayData data[4];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PathObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PathObject_t qt_meta_stringdata_PathObject = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PathObject"
QT_MOC_LITERAL(1, 11, 4), // "data"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 4) // "send"

    },
    "PathObject\0data\0\0send"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PathObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       1,    1,   67,    2, 0x06 /* Public */,
       1,    1,   70,    2, 0x06 /* Public */,
       1,    1,   73,    2, 0x06 /* Public */,
       1,    0,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   77,    2, 0x0a /* Public */,
       3,    1,   80,    2, 0x0a /* Public */,
       3,    1,   83,    2, 0x0a /* Public */,
       3,    1,   86,    2, 0x0a /* Public */,
       3,    0,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,

       0        // eod
};

void PathObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PathObject *_t = static_cast<PathObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->data((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->data((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->data((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->data((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->data(); break;
        case 5: _t->send((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 6: _t->send((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->send((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->send((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->send(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PathObject::*_t)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PathObject::data)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PathObject::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PathObject::data)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PathObject::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PathObject::data)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (PathObject::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PathObject::data)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (PathObject::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PathObject::data)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject PathObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PathObject.data,
      qt_meta_data_PathObject,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PathObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PathObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PathObject.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PathObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void PathObject::data(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PathObject::data(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PathObject::data(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PathObject::data(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PathObject::data()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
