/****************************************************************************
** Meta object code from reading C++ file 'zonededessin.h'
**
** Created: Mon Apr 16 23:06:44 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "zonededessin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zonededessin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ZoneDeDessin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   14,   13,   13, 0x0a,
      43,   38,   13,   13, 0x0a,
      60,   13,   13,   13, 0x0a,
      72,   13,   13,   13, 0x0a,
      82,   13,   13,   13, 0x0a,
      92,   13,   13,   13, 0x0a,
     105,   13,   13,   13, 0x0a,
     117,   13,   13,   13, 0x0a,
     163,  136,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ZoneDeDessin[] = {
    "ZoneDeDessin\0\0color\0setColor(QColor&)\0"
    "form\0setForm(QString)\0startDraw()\0"
    "drawing()\0endDraw()\0deleteLast()\0"
    "deleteAll()\0initStateMachine()\0"
    "from,to,object,type,button\0"
    "addTrans(QState*,QState*,QObject*,QEvent::Type,Qt::MouseButton)\0"
};

void ZoneDeDessin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ZoneDeDessin *_t = static_cast<ZoneDeDessin *>(_o);
        switch (_id) {
        case 0: _t->setColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->setForm((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->startDraw(); break;
        case 3: _t->drawing(); break;
        case 4: _t->endDraw(); break;
        case 5: _t->deleteLast(); break;
        case 6: _t->deleteAll(); break;
        case 7: _t->initStateMachine(); break;
        case 8: _t->addTrans((*reinterpret_cast< QState*(*)>(_a[1])),(*reinterpret_cast< QState*(*)>(_a[2])),(*reinterpret_cast< QObject*(*)>(_a[3])),(*reinterpret_cast< QEvent::Type(*)>(_a[4])),(*reinterpret_cast< Qt::MouseButton(*)>(_a[5]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ZoneDeDessin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ZoneDeDessin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ZoneDeDessin,
      qt_meta_data_ZoneDeDessin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ZoneDeDessin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ZoneDeDessin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ZoneDeDessin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ZoneDeDessin))
        return static_cast<void*>(const_cast< ZoneDeDessin*>(this));
    return QWidget::qt_metacast(_clname);
}

int ZoneDeDessin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
