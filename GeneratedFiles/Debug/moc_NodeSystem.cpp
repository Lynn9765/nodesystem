/****************************************************************************
** Meta object code from reading C++ file 'NodeSystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../NodeSystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NodeSystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NodeSystem_t {
    QByteArrayData data[13];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NodeSystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NodeSystem_t qt_meta_stringdata_NodeSystem = {
    {
QT_MOC_LITERAL(0, 0, 10), // "NodeSystem"
QT_MOC_LITERAL(1, 11, 11), // "addNodeItem"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "deleteItem"
QT_MOC_LITERAL(4, 35, 19), // "pointerGroupClicked"
QT_MOC_LITERAL(5, 55, 2), // "id"
QT_MOC_LITERAL(6, 58, 12), // "itemInserted"
QT_MOC_LITERAL(7, 71, 12), // "DiagramItem*"
QT_MOC_LITERAL(8, 84, 4), // "item"
QT_MOC_LITERAL(9, 89, 17), // "sceneScaleChanged"
QT_MOC_LITERAL(10, 107, 5), // "scale"
QT_MOC_LITERAL(11, 113, 15), // "colorBtnClicked"
QT_MOC_LITERAL(12, 129, 8) // "setColor"

    },
    "NodeSystem\0addNodeItem\0\0deleteItem\0"
    "pointerGroupClicked\0id\0itemInserted\0"
    "DiagramItem*\0item\0sceneScaleChanged\0"
    "scale\0colorBtnClicked\0setColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NodeSystem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       6,    1,   54,    2, 0x08 /* Private */,
       9,    1,   57,    2, 0x08 /* Private */,
      11,    0,   60,    2, 0x08 /* Private */,
      12,    1,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,    2,

       0        // eod
};

void NodeSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NodeSystem *_t = static_cast<NodeSystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addNodeItem(); break;
        case 1: _t->deleteItem(); break;
        case 2: _t->pointerGroupClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->itemInserted((*reinterpret_cast< DiagramItem*(*)>(_a[1]))); break;
        case 4: _t->sceneScaleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->colorBtnClicked(); break;
        case 6: _t->setColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject NodeSystem::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_NodeSystem.data,
      qt_meta_data_NodeSystem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NodeSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NodeSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NodeSystem.stringdata0))
        return static_cast<void*>(const_cast< NodeSystem*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int NodeSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
