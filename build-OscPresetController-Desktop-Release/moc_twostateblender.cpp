/****************************************************************************
** Meta object code from reading C++ file 'twostateblender.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OscPresetController/twostateblender.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'twostateblender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TwoStateBlender_t {
    QByteArrayData data[12];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TwoStateBlender_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TwoStateBlender_t qt_meta_stringdata_TwoStateBlender = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TwoStateBlender"
QT_MOC_LITERAL(1, 16, 20), // "stateSet1NameChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 7), // "newName"
QT_MOC_LITERAL(4, 46, 20), // "stateSet2NameChanged"
QT_MOC_LITERAL(5, 67, 10), // "applyBlend"
QT_MOC_LITERAL(6, 78, 11), // "fractionOf1"
QT_MOC_LITERAL(7, 90, 18), // "setCurrentAsState1"
QT_MOC_LITERAL(8, 109, 18), // "setCurrentAsState2"
QT_MOC_LITERAL(9, 128, 10), // "loadState1"
QT_MOC_LITERAL(10, 139, 8), // "filename"
QT_MOC_LITERAL(11, 148, 10) // "loadState2"

    },
    "TwoStateBlender\0stateSet1NameChanged\0"
    "\0newName\0stateSet2NameChanged\0applyBlend\0"
    "fractionOf1\0setCurrentAsState1\0"
    "setCurrentAsState2\0loadState1\0filename\0"
    "loadState2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TwoStateBlender[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   55,    2, 0x0a /* Public */,
       7,    0,   58,    2, 0x0a /* Public */,
       8,    0,   59,    2, 0x0a /* Public */,
       9,    1,   60,    2, 0x0a /* Public */,
      11,    1,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void TwoStateBlender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TwoStateBlender *_t = static_cast<TwoStateBlender *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stateSet1NameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->stateSet2NameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->applyBlend((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setCurrentAsState1(); break;
        case 4: _t->setCurrentAsState2(); break;
        case 5: _t->loadState1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->loadState2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TwoStateBlender::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TwoStateBlender::stateSet1NameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TwoStateBlender::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TwoStateBlender::stateSet2NameChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject TwoStateBlender::staticMetaObject = {
    { &AbstractTransition::staticMetaObject, qt_meta_stringdata_TwoStateBlender.data,
      qt_meta_data_TwoStateBlender,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TwoStateBlender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TwoStateBlender::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TwoStateBlender.stringdata0))
        return static_cast<void*>(this);
    return AbstractTransition::qt_metacast(_clname);
}

int TwoStateBlender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractTransition::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void TwoStateBlender::stateSet1NameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TwoStateBlender::stateSet2NameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
