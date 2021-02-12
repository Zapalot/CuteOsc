/****************************************************************************
** Meta object code from reading C++ file 'osccontrolledfloatvector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OscPresetController/osccontrolledfloatvector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'osccontrolledfloatvector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OscControlledFloatVector_t {
    QByteArrayData data[17];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OscControlledFloatVector_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OscControlledFloatVector_t qt_meta_stringdata_OscControlledFloatVector = {
    {
QT_MOC_LITERAL(0, 0, 24), // "OscControlledFloatVector"
QT_MOC_LITERAL(1, 25, 13), // "valuesChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 13), // "QList<double>"
QT_MOC_LITERAL(4, 54, 9), // "newValues"
QT_MOC_LITERAL(5, 64, 10), // "saveToFile"
QT_MOC_LITERAL(6, 75, 6), // "QFile*"
QT_MOC_LITERAL(7, 82, 4), // "file"
QT_MOC_LITERAL(8, 87, 8), // "setValue"
QT_MOC_LITERAL(9, 96, 8), // "newValue"
QT_MOC_LITERAL(10, 105, 5), // "index"
QT_MOC_LITERAL(11, 111, 9), // "setValues"
QT_MOC_LITERAL(12, 121, 16), // "setFromFractions"
QT_MOC_LITERAL(13, 138, 12), // "newFractions"
QT_MOC_LITERAL(14, 151, 16), // "sendCurrentValue"
QT_MOC_LITERAL(15, 168, 11), // "QOscClient*"
QT_MOC_LITERAL(16, 180, 9) // "oscClient"

    },
    "OscControlledFloatVector\0valuesChanged\0"
    "\0QList<double>\0newValues\0saveToFile\0"
    "QFile*\0file\0setValue\0newValue\0index\0"
    "setValues\0setFromFractions\0newFractions\0"
    "sendCurrentValue\0QOscClient*\0oscClient"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OscControlledFloatVector[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x0a /* Public */,
       8,    2,   50,    2, 0x0a /* Public */,
      11,    1,   55,    2, 0x0a /* Public */,
      12,    1,   58,    2, 0x0a /* Public */,
      14,    1,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::Int,    9,   10,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,   13,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void OscControlledFloatVector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OscControlledFloatVector *_t = static_cast<OscControlledFloatVector *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valuesChanged((*reinterpret_cast< QList<double>(*)>(_a[1]))); break;
        case 1: _t->saveToFile((*reinterpret_cast< QFile*(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->setValues((*reinterpret_cast< QList<double>(*)>(_a[1]))); break;
        case 4: _t->setFromFractions((*reinterpret_cast< QList<double>(*)>(_a[1]))); break;
        case 5: _t->sendCurrentValue((*reinterpret_cast< QOscClient*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<double> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFile* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<double> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<double> >(); break;
            }
            break;
        case 5:
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
            typedef void (OscControlledFloatVector::*_t)(QList<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&OscControlledFloatVector::valuesChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject OscControlledFloatVector::staticMetaObject = {
    { &OscControlledState::staticMetaObject, qt_meta_stringdata_OscControlledFloatVector.data,
      qt_meta_data_OscControlledFloatVector,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OscControlledFloatVector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OscControlledFloatVector::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OscControlledFloatVector.stringdata0))
        return static_cast<void*>(this);
    return OscControlledState::qt_metacast(_clname);
}

int OscControlledFloatVector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = OscControlledState::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void OscControlledFloatVector::valuesChanged(QList<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
