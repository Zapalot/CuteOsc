/****************************************************************************
** Meta object code from reading C++ file 'osccontrolledstate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OscPresetController/osccontrolledstate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'osccontrolledstate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OscControlledState_t {
    QByteArrayData data[9];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OscControlledState_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OscControlledState_t qt_meta_stringdata_OscControlledState = {
    {
QT_MOC_LITERAL(0, 0, 18), // "OscControlledState"
QT_MOC_LITERAL(1, 19, 12), // "valueChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 19), // "OscControlledState*"
QT_MOC_LITERAL(4, 53, 5), // "state"
QT_MOC_LITERAL(5, 59, 13), // "valueAsString"
QT_MOC_LITERAL(6, 73, 16), // "sendCurrentValue"
QT_MOC_LITERAL(7, 90, 11), // "QOscClient*"
QT_MOC_LITERAL(8, 102, 9) // "oscClient"

    },
    "OscControlledState\0valueChanged\0\0"
    "OscControlledState*\0state\0valueAsString\0"
    "sendCurrentValue\0QOscClient*\0oscClient"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OscControlledState[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       1,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void OscControlledState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OscControlledState *_t = static_cast<OscControlledState *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< OscControlledState*(*)>(_a[1]))); break;
        case 1: _t->valueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendCurrentValue((*reinterpret_cast< QOscClient*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< OscControlledState* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QOscClient* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (OscControlledState::*_t)(OscControlledState * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OscControlledState::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (OscControlledState::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OscControlledState::valueChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject OscControlledState::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_OscControlledState.data,
      qt_meta_data_OscControlledState,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OscControlledState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OscControlledState::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OscControlledState.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int OscControlledState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void OscControlledState::valueChanged(OscControlledState * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OscControlledState::valueChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
