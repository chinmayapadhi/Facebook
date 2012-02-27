/****************************************************************************
** Meta object code from reading C++ file 'fbrequest.h'
**
** Created: Thu Nov 11 12:19:03 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qfacebook_lib_inc/fbrequest.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fbrequest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FBRequest[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      33,   28,   10,   10, 0x05,
      99,   92,   10,   10, 0x05,
     147,  139,   10,   10, 0x05,
     172,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     194,   28,   10,   10, 0x08,
     241,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FBRequest[] = {
    "FBRequest\0\0requestLoading()\0code\0"
    "requestFailedWithNetworkError(QNetworkReply::NetworkError)\0"
    "aError\0requestFailedWithFacebookError(FBError)\0"
    "aResult\0requestDidLoad(QVariant)\0"
    "requestWasCancelled()\0"
    "networkReplyError(QNetworkReply::NetworkError)\0"
    "networkReplyFinished()\0"
};

const QMetaObject FBRequest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FBRequest,
      qt_meta_data_FBRequest, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FBRequest::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FBRequest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FBRequest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FBRequest))
        return static_cast<void*>(const_cast< FBRequest*>(this));
    return QObject::qt_metacast(_clname);
}

int FBRequest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: requestLoading(); break;
        case 1: requestFailedWithNetworkError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 2: requestFailedWithFacebookError((*reinterpret_cast< const FBError(*)>(_a[1]))); break;
        case 3: requestDidLoad((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 4: requestWasCancelled(); break;
        case 5: networkReplyError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 6: networkReplyFinished(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FBRequest::requestLoading()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void FBRequest::requestFailedWithNetworkError(QNetworkReply::NetworkError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FBRequest::requestFailedWithFacebookError(const FBError & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FBRequest::requestDidLoad(const QVariant & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FBRequest::requestWasCancelled()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
