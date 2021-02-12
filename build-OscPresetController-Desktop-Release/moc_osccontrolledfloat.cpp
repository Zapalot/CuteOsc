/****************************************************************************
** Meta object code from reading C++ file 'osccontrolledfloat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OscPresetController/osccontrolledfloat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'osccontrolledfloat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OscControlledFloat_t {
    QByteArrayData data[9];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OscControlledFloat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OscControlledFloat_t qt_meta_stringdata_OscControlledFloat = {
    {
QT_MOC_LITERAL(0, 0, 18), // "OscControlledFloat"
QT_MOC_LITERAL(1, 19, 8), // "setValue"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "newValue"
QT_MOC_LITERAL(4, 38, 15), // "setValueFromInt"
QT_MOC_LITERAL(5, 54, 9), // "sliderInt"
QT_MOC_LITERAL(6, 64, 16), // "sendCurrentValue"
QT_MOC_LITERAL(7, 81, 11), // "QOscClient*"
QT_MOC_LITERAL(8, 93, 9) // "oscClient"

    },
    "OscControlledFloat\0setValue\0\0newValue\0"
    "setValueFromInt\0sliderInt\0sendCurrentValue\0"
    "QOscClient*\0oscClient"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OscControlledFloat[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       6,    1,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void OscControlledFloat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OscControlledFloat *_t = static_cast<OscControlledFloat *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->setValueFromInt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sendCurrentValue((*reinterpret_cast< QOscClient*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QOscClient* >(); break;
            }
            break;
        }
    }
}

const QMetaObject OscControlledFloat::staticMetaObject = {
    { &OscControlledState::staticMetaObject, qt_meta_stringdata_OscControlledFloat.data,
      qt_meta_data_OscControlledFloat,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OscControlledFloat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OscControlledFloat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OscControlledFloat.stringdata0))
        return static_cast<void*>(this);
    return OscControlledState::qt_metacast(_clname);
}

int OscControlledFloat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = OscControlledState::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
