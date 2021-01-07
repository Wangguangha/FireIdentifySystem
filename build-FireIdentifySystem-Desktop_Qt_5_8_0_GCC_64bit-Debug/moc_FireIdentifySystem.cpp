/****************************************************************************
** Meta object code from reading C++ file 'FireIdentifySystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FireIdentifySystem/FireIdentifySystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FireIdentifySystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FireIdentifySystem_t {
    QByteArrayData data[11];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FireIdentifySystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FireIdentifySystem_t qt_meta_stringdata_FireIdentifySystem = {
    {
QT_MOC_LITERAL(0, 0, 18), // "FireIdentifySystem"
QT_MOC_LITERAL(1, 19, 19), // "on_tBtn_Set_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 13), // "timer_timeout"
QT_MOC_LITERAL(4, 54, 19), // "updateTimer_timeout"
QT_MOC_LITERAL(5, 74, 19), // "on_tBtn_LED_clicked"
QT_MOC_LITERAL(6, 94, 22), // "on_tBtn_Buzzer_clicked"
QT_MOC_LITERAL(7, 117, 23), // "on_tBtn_Network_clicked"
QT_MOC_LITERAL(8, 141, 16), // "serverNewConnect"
QT_MOC_LITERAL(9, 158, 14), // "serverReadData"
QT_MOC_LITERAL(10, 173, 19) // "serverDisconnection"

    },
    "FireIdentifySystem\0on_tBtn_Set_clicked\0"
    "\0timer_timeout\0updateTimer_timeout\0"
    "on_tBtn_LED_clicked\0on_tBtn_Buzzer_clicked\0"
    "on_tBtn_Network_clicked\0serverNewConnect\0"
    "serverReadData\0serverDisconnection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FireIdentifySystem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FireIdentifySystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FireIdentifySystem *_t = static_cast<FireIdentifySystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tBtn_Set_clicked(); break;
        case 1: _t->timer_timeout(); break;
        case 2: _t->updateTimer_timeout(); break;
        case 3: _t->on_tBtn_LED_clicked(); break;
        case 4: _t->on_tBtn_Buzzer_clicked(); break;
        case 5: _t->on_tBtn_Network_clicked(); break;
        case 6: _t->serverNewConnect(); break;
        case 7: _t->serverReadData(); break;
        case 8: _t->serverDisconnection(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject FireIdentifySystem::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FireIdentifySystem.data,
      qt_meta_data_FireIdentifySystem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FireIdentifySystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FireIdentifySystem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FireIdentifySystem.stringdata0))
        return static_cast<void*>(const_cast< FireIdentifySystem*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FireIdentifySystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
