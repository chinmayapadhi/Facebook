/****************************************************************************
** Meta object code from reading C++ file 'newsobject.h'
**
** Created: Thu Nov 11 12:19:00 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../newsobject.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newsobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewsObject[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       7,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      19,   11, 0x0a095001,
      26,   11, 0x0a095001,
      35,   11, 0x0a095001,
      40,   11, 0x0a095001,
      44,   11, 0x0a095001,
      52,   11, 0x0a095001,
      61,   57, 0x02095001,

       0        // eod
};

static const char qt_meta_stringdata_NewsObject[] = {
    "NewsObject\0QString\0status\0actor_id\0"
    "name\0pic\0post_id\0time\0int\0comments\0"
};

const QMetaObject NewsObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NewsObject,
      qt_meta_data_NewsObject, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewsObject::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewsObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewsObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewsObject))
        return static_cast<void*>(const_cast< NewsObject*>(this));
    return QObject::qt_metacast(_clname);
}

int NewsObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = status(); break;
        case 1: *reinterpret_cast< QString*>(_v) = actor_id(); break;
        case 2: *reinterpret_cast< QString*>(_v) = name(); break;
        case 3: *reinterpret_cast< QString*>(_v) = pic(); break;
        case 4: *reinterpret_cast< QString*>(_v) = post_id(); break;
        case 5: *reinterpret_cast< QString*>(_v) = time(); break;
        case 6: *reinterpret_cast< int*>(_v) = comments(); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 7;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
