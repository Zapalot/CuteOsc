/****************************************************************************
** Meta object code from reading C++ file 'osccontrolledmouserelay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OscPresetController/osccontrolledmouserelay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'osccontrolledmouserelay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OscControlledMouseRelay_t {
    QByteArrayData data[9];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OscControlledMouseRelay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OscControlledMouseRelay_t qt_meta_stringdata_OscControlledMouseRelay = {
    {
QT_MOC_LITERAL(0, 0, 23), // "OscControlledMouseRelay"
QT_MOC_LITERAL(1, 24, 16), // "receiveMouseData"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 1), // "x"
QT_MOC_LITERAL(4, 44, 1), // "y"
QT_MOC_LITERAL(5, 46, 7), // "buttons"
QT_MOC_LITERAL(6, 54, 16), // "sendCurrentValue"
QT_MOC_LITERAL(7, 71, 11), // "QOscClient*"
QT_MOC_LITERAL(8, 83, 9) // "oscClient"

    },
    "OscControlledMouseRelay\0receiveMouseData\0"
    "\0x\0y\0buttons\0sendCurrentValue\0QOscClient*\0"
    "oscClient"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OscControlledMouseRelay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x0a /* Public */,
       6,    1,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void OscControlledMouseRelay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OscControlledMouseRelay *_t = static_cast<OscControlledMouseRelay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveMouseData((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->sendCurrentValue((*reinterpret_cast< QOscClient*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QOscClient* >(); break;
            }
            break;
        }
    }
}

const QMetaObject OscControlledMouseRelay::staticMetaObject = {
    { &OscControlledState::staticMetaObject, qt_meta_stringdata_OscControlledMouseRelay.data,
      qt_meta_data_OscControlledMouseRelay,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OscControlledMouseRelay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OscControlledMouseRelay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OscControlledMouseRelay.stringdata0))
        return static_cast<void*>(this);
    return OscControlledState::qt_metacast(_clname);
}

int OscControlledMouseRelay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = OscControlledState::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
