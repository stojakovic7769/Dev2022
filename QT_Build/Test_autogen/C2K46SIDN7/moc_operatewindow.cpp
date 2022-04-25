/****************************************************************************
** Meta object code from reading C++ file 'operatewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Inc/operatewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'operatewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OperateWindow_t {
    QByteArrayData data[12];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OperateWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OperateWindow_t qt_meta_stringdata_OperateWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "OperateWindow"
QT_MOC_LITERAL(1, 14, 20), // "on_btnImport_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 21), // "on_btnInputDB_clicked"
QT_MOC_LITERAL(4, 58, 23), // "on_btnClearList_clicked"
QT_MOC_LITERAL(5, 82, 19), // "on_btnQuery_clicked"
QT_MOC_LITERAL(6, 102, 23), // "on_btnQueryByGS_clicked"
QT_MOC_LITERAL(7, 126, 30), // "on_btnMarkManageImport_clicked"
QT_MOC_LITERAL(8, 157, 33), // "on_btnClearListMarkManage_cli..."
QT_MOC_LITERAL(9, 191, 32), // "on_btnMarkManageImportDB_clicked"
QT_MOC_LITERAL(10, 224, 40), // "on_cbxExerciseOption_currentI..."
QT_MOC_LITERAL(11, 265, 4) // "arg1"

    },
    "OperateWindow\0on_btnImport_clicked\0\0"
    "on_btnInputDB_clicked\0on_btnClearList_clicked\0"
    "on_btnQuery_clicked\0on_btnQueryByGS_clicked\0"
    "on_btnMarkManageImport_clicked\0"
    "on_btnClearListMarkManage_clicked\0"
    "on_btnMarkManageImportDB_clicked\0"
    "on_cbxExerciseOption_currentIndexChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OperateWindow[] = {

 // content:
       8,       // revision
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
      10,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void OperateWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OperateWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnImport_clicked(); break;
        case 1: _t->on_btnInputDB_clicked(); break;
        case 2: _t->on_btnClearList_clicked(); break;
        case 3: _t->on_btnQuery_clicked(); break;
        case 4: _t->on_btnQueryByGS_clicked(); break;
        case 5: _t->on_btnMarkManageImport_clicked(); break;
        case 6: _t->on_btnClearListMarkManage_clicked(); break;
        case 7: _t->on_btnMarkManageImportDB_clicked(); break;
        case 8: _t->on_cbxExerciseOption_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OperateWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_OperateWindow.data,
    qt_meta_data_OperateWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OperateWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OperateWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OperateWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int OperateWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
