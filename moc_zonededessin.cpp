/****************************************************************************
** Meta object code from reading C++ file 'zonededessin.h'
**
** Created: Tue Mar 6 15:47:54 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "zonededessin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zonededessin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ZoneDeDessin[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   14,   13,   13, 0x0a,
      40,   38,   13,   13, 0x0a,
      70,   38,   13,   13, 0x0a,
     102,   38,   13,   13, 0x0a,
     131,   38,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ZoneDeDessin[] = {
    "ZoneDeDessin\0\0color\0setColor(QColor&)\0"
    "e\0mousePressEvent(QMouseEvent*)\0"
    "mouseReleaseEvent(QMouseEvent*)\0"
    "mouseMoveEvent(QMouseEvent*)\0"
    "mouseDoubleClickEvent(QMouseEvent*)\0"
};

const QMetaObject ZoneDeDessin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ZoneDeDessin,
      qt_meta_data_ZoneDeDessin, 0 }
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
        switch (_id) {
        case 0: setColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: mouseDoubleClickEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
