/****************************************************************************
** Meta object code from reading C++ file 'diagramscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../diagramscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'diagramscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DiagramScene_t {
    QByteArrayData data[8];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DiagramScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DiagramScene_t qt_meta_stringdata_DiagramScene = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DiagramScene"
QT_MOC_LITERAL(1, 13, 12), // "itemInserted"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "DiagramItem*"
QT_MOC_LITERAL(4, 40, 4), // "item"
QT_MOC_LITERAL(5, 45, 7), // "setMode"
QT_MOC_LITERAL(6, 53, 4), // "Mode"
QT_MOC_LITERAL(7, 58, 4) // "mode"

    },
    "DiagramScene\0itemInserted\0\0DiagramItem*\0"
    "item\0setMode\0Mode\0mode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DiagramScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void DiagramScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DiagramScene *_t = static_cast<DiagramScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->itemInserted((*reinterpret_cast< DiagramItem*(*)>(_a[1]))); break;
        case 1: _t->setMode((*reinterpret_cast< Mode(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DiagramScene::*_t)(DiagramItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DiagramScene::itemInserted)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DiagramScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_DiagramScene.data,
      qt_meta_data_DiagramScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DiagramScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DiagramScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DiagramScene.stringdata0))
        return static_cast<void*>(const_cast< DiagramScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int DiagramScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DiagramScene::itemInserted(DiagramItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
