/****************************************************************************
** Meta object code from reading C++ file 'fbsession.h'
**
** Created: Thu Nov 11 12:19:02 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qfacebook_lib_inc/fbsession.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fbsession.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FBSession[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   11,   10,   10, 0x05,
      39,   10,   10,   10, 0x05,
      60,   11,   10,   10, 0x05,
      85,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     104,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FBSession[] = {
    "FBSession\0\0aUid\0sessionDidLogin(FBUID)\0"
    "sessionDidNotLogin()\0sessionWillLogout(FBUID)\0"
    "sessionDidLogout()\0requestTimerReady()\0"
};

const QMetaObject FBSession::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FBSession,
      qt_meta_data_FBSession, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FBSession::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FBSession::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FBSession::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FBSession))
        return static_cast<void*>(const_cast< FBSession*>(this));
    return QObject::qt_metacast(_clname);
}

int FBSession::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sessionDidLogin((*reinterpret_cast< FBUID(*)>(_a[1]))); break;
        case 1: sessionDidNotLogin(); break;
        case 2: sessionWillLogout((*reinterpret_cast< FBUID(*)>(_a[1]))); break;
        case 3: sessionDidLogout(); break;
        case 4: requestTimerReady(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FBSession::sessionDidLogin(FBUID _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FBSession::sessionDidNotLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void FBSession::sessionWillLogout(FBUID _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FBSession::sessionDidLogout()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
