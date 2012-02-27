/****************************************************************************
** Meta object code from reading C++ file 'commentobject.h'
**
** Created: Thu Nov 11 12:19:06 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../commentobject.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commentobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CommentObject[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       5,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      22,   14, 0x0a095001,
      27,   14, 0x0a095001,
      35,   14, 0x0a095003,
      45,   14, 0x0a095003,
      53,   49, 0x02095001,

       0        // eod
};

static const char qt_meta_stringdata_CommentObject[] = {
    "CommentObject\0QString\0name\0comment\0"
    "full_name\0pic\0int\0last\0"
};

const QMetaObject CommentObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CommentObject,
      qt_meta_data_CommentObject, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CommentObject::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CommentObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CommentObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CommentObject))
        return static_cast<void*>(const_cast< CommentObject*>(this));
    return QObject::qt_metacast(_clname);
}

int CommentObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = name(); break;
        case 1: *reinterpret_cast< QString*>(_v) = comment(); break;
        case 2: *reinterpret_cast< QString*>(_v) = full_name(); break;
        case 3: *reinterpret_cast< QString*>(_v) = pic(); break;
        case 4: *reinterpret_cast< int*>(_v) = last(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 2: set_full_name(*reinterpret_cast< QString*>(_v)); break;
        case 3: set_pic(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
