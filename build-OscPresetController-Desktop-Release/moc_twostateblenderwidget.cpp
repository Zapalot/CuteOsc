/****************************************************************************
** Meta object code from reading C++ file 'twostateblenderwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OscPresetController/twostateblenderwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'twostateblenderwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TwoStateBlenderWidget_t {
    QByteArrayData data[19];
    char stringdata0[326];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TwoStateBlenderWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TwoStateBlenderWidget_t qt_meta_stringdata_TwoStateBlenderWidget = {
    {
QT_MOC_LITERAL(0, 0, 21), // "TwoStateBlenderWidget"
QT_MOC_LITERAL(1, 22, 13), // "loadFileToOne"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 8), // "filename"
QT_MOC_LITERAL(4, 46, 13), // "loadFileToTwo"
QT_MOC_LITERAL(5, 60, 16), // "loadCurrentToOne"
QT_MOC_LITERAL(6, 77, 16), // "loadCurrentToTwo"
QT_MOC_LITERAL(7, 94, 15), // "fractionChanged"
QT_MOC_LITERAL(8, 110, 13), // "fractionOfOne"
QT_MOC_LITERAL(9, 124, 10), // "setOneName"
QT_MOC_LITERAL(10, 135, 4), // "name"
QT_MOC_LITERAL(11, 140, 10), // "setTwoName"
QT_MOC_LITERAL(12, 151, 11), // "setFraction"
QT_MOC_LITERAL(13, 163, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(14, 196, 5), // "value"
QT_MOC_LITERAL(15, 202, 34), // "on_setCurrentAs2PushButton_cl..."
QT_MOC_LITERAL(16, 237, 34), // "on_setCurrentAs1PushButton_cl..."
QT_MOC_LITERAL(17, 272, 26), // "on_load2pushButton_clicked"
QT_MOC_LITERAL(18, 299, 26) // "on_load1PushButton_clicked"

    },
    "TwoStateBlenderWidget\0loadFileToOne\0"
    "\0filename\0loadFileToTwo\0loadCurrentToOne\0"
    "loadCurrentToTwo\0fractionChanged\0"
    "fractionOfOne\0setOneName\0name\0setTwoName\0"
    "setFraction\0on_horizontalSlider_valueChanged\0"
    "value\0on_setCurrentAs2PushButton_clicked\0"
    "on_setCurrentAs1PushButton_clicked\0"
    "on_load2pushButton_clicked\0"
    "on_load1PushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TwoStateBlenderWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       5,    0,   85,    2, 0x06 /* Public */,
       6,    0,   86,    2, 0x06 /* Public */,
       7,    1,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   90,    2, 0x0a /* Public */,
      11,    1,   93,    2, 0x0a /* Public */,
      12,    1,   96,    2, 0x0a /* Public */,
      13,    1,   99,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,
      17,    0,  104,    2, 0x08 /* Private */,
      18,    0,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TwoStateBlenderWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TwoStateBlenderWidget *_t = static_cast<TwoStateBlenderWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadFileToOne((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->loadFileToTwo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->loadCurrentToOne(); break;
        case 3: _t->loadCurrentToTwo(); break;
        case 4: _t->fractionChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setOneName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setTwoName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setFraction((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_setCurrentAs2PushButton_clicked(); break;
        case 10: _t->on_setCurrentAs1PushButton_clicked(); break;
        case 11: _t->on_load2pushButton_clicked(); break;
        case 12: _t->on_load1PushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TwoStateBlenderWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TwoStateBlenderWidget::loadFileToOne)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TwoStateBlenderWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TwoStateBlenderWidget::loadFileToTwo)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TwoStateBlenderWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TwoStateBlenderWidget::loadCurrentToOne)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (TwoStateBlenderWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TwoStateBlenderWidget::loadCurrentToTwo)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (TwoStateBlenderWidget::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TwoStateBlenderWidget::fractionChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject TwoStateBlenderWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TwoStateBlenderWidget.data,
      qt_meta_data_TwoStateBlenderWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TwoStateBlenderWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TwoStateBlenderWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TwoStateBlenderWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TwoStateBlenderWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void TwoStateBlenderWidget::loadFileToOne(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TwoStateBlenderWidget::loadFileToTwo(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TwoStateBlenderWidget::loadCurrentToOne()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TwoStateBlenderWidget::loadCurrentToTwo()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void TwoStateBlenderWidget::fractionChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
