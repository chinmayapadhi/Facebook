/****************************************************************************
** Meta object code from reading C++ file 'fblogindialog.h'
**
** Created: Thu Nov 11 12:19:04 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qfacebook_lib_inc/fblogindialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fblogindialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FBLoginDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   15,   14,   14, 0x08,
      55,   48,   14,   14, 0x08,
     100,   95,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FBLoginDialog[] = {
    "FBLoginDialog\0\0aResult\0requestDidLoad(QVariant)\0"
    "aError\0requestFailedWithFacebookError(FBError)\0"
    "code\0requestFailedWithNetworkError(QNetworkReply::NetworkError)\0"
};

const QMetaObject FBLoginDialog::staticMetaObject = {
    { &FBDialog::staticMetaObject, qt_meta_stringdata_FBLoginDialog,
      qt_meta_data_FBLoginDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FBLoginDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FBLoginDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FBLoginDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FBLoginDialog))
        return static_cast<void*>(const_cast< FBLoginDialog*>(this));
    return FBDialog::qt_metacast(_clname);
}

int FBLoginDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = FBDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: requestDidLoad((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 1: requestFailedWithFacebookError((*reinterpret_cast< const FBError(*)>(_a[1]))); break;
        case 2: requestFailedWithNetworkError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
