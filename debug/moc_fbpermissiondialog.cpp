/****************************************************************************
** Meta object code from reading C++ file 'fbpermissiondialog.h'
**
** Created: Thu Nov 11 12:19:04 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qfacebook_lib_inc/fbpermissiondialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fbpermissiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FBPermissionDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FBPermissionDialog[] = {
    "FBPermissionDialog\0\0redirectToLoginDelayed()\0"
};

const QMetaObject FBPermissionDialog::staticMetaObject = {
    { &FBLoginDialog::staticMetaObject, qt_meta_stringdata_FBPermissionDialog,
      qt_meta_data_FBPermissionDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FBPermissionDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FBPermissionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FBPermissionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FBPermissionDialog))
        return static_cast<void*>(const_cast< FBPermissionDialog*>(this));
    return FBLoginDialog::qt_metacast(_clname);
}

int FBPermissionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = FBLoginDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: redirectToLoginDelayed(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
