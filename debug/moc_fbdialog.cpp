/****************************************************************************
** Meta object code from reading C++ file 'fbdialog.h'
**
** Created: Thu Nov 11 12:19:05 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qfacebook_lib_inc/fbdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fbdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FBCustomNetworkAccessManager[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_FBCustomNetworkAccessManager[] = {
    "FBCustomNetworkAccessManager\0"
};

const QMetaObject FBCustomNetworkAccessManager::staticMetaObject = {
    { &QNetworkAccessManager::staticMetaObject, qt_meta_stringdata_FBCustomNetworkAccessManager,
      qt_meta_data_FBCustomNetworkAccessManager, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FBCustomNetworkAccessManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FBCustomNetworkAccessManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FBCustomNetworkAccessManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FBCustomNetworkAccessManager))
        return static_cast<void*>(const_cast< FBCustomNetworkAccessManager*>(this));
    return QNetworkAccessManager::qt_metacast(_clname);
}

int FBCustomNetworkAccessManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QNetworkAccessManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_FBDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      29,    9,    9,    9, 0x05,
      53,   47,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      85,    9,    9,    9, 0x08,
      98,   94,    9,    9, 0x08,
     116,    9,    9,    9, 0x08,
     133,  130,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FBDialog[] = {
    "FBDialog\0\0dialogDidSucceed()\0"
    "dialogDidCancel()\0error\0"
    "dialogDidFailWithError(FBError)\0"
    "cancel()\0url\0linkClicked(QUrl)\0"
    "loadStarted()\0ok\0loadFinished(bool)\0"
};

const QMetaObject FBDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FBDialog,
      qt_meta_data_FBDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FBDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FBDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FBDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FBDialog))
        return static_cast<void*>(const_cast< FBDialog*>(this));
    if (!strcmp(_clname, "FBCustomNetworkAccessManagerObserver"))
        return static_cast< FBCustomNetworkAccessManagerObserver*>(const_cast< FBDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int FBDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: dialogDidSucceed(); break;
        case 1: dialogDidCancel(); break;
        case 2: dialogDidFailWithError((*reinterpret_cast< const FBError(*)>(_a[1]))); break;
        case 3: cancel(); break;
        case 4: linkClicked((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 5: loadStarted(); break;
        case 6: loadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FBDialog::dialogDidSucceed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void FBDialog::dialogDidCancel()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void FBDialog::dialogDidFailWithError(const FBError & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
