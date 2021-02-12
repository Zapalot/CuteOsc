/****************************************************************************
** Meta object code from reading C++ file 'osccontrolledquad2f.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OscPresetController/osccontrolledquad2f.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'osccontrolledquad2f.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OscControlledQuad2f_t {
    QByteArrayData data[5];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OscControlledQuad2f_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OscControlledQuad2f_t qt_meta_stringdata_OscControlledQuad2f = {
    {
QT_MOC_LITERAL(0, 0, 19), // "OscControlledQuad2f"
QT_MOC_LITERAL(1, 20, 16), // "sendCurrentValue"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 11), // "QOscClient*"
QT_MOC_LITERAL(4, 50, 9) // "oscClient"

    },
    "OscControlledQuad2f\0sendCurrentValue\0"
    "\0QOscClient*\0oscClient"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OscControlledQuad2f[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void OscControlledQuad2f::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OscControlledQuad2f *_t = static_cast<OscControlledQuad2f *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendCurrentValue((*reinterpret_cast< QOscClient*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QOscClient* >(); break;
            }
            break;
        }
    }
}

const QMetaObject OscControlledQuad2f::staticMetaObject = {
    { &OscControlledState::staticMetaObject, qt_meta_stringdata_OscControlledQuad2f.data,
      qt_meta_data_OscControlledQuad2f,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OscControlledQuad2f::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OscControlledQuad2f::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OscControlledQuad2f.stringdata0))
        return static_cast<void*>(this);
    return OscControlledState::qt_metacast(_clname);
}

int OscControlledQuad2f::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = OscControlledState::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
