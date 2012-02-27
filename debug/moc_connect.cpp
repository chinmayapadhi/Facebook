/****************************************************************************
** Meta object code from reading C++ file 'connect.h'
**
** Created: Thu Nov 11 12:19:05 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../connect.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FBConnect[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      19,   10,   10,   10, 0x0a,
      26,   10,   10,   10, 0x0a,
      49,   10,   10,   10, 0x0a,
      65,   10,   10,   10, 0x0a,
      86,   79,   10,   10, 0x0a,
     105,   10,   10,   10, 0x0a,
     130,  120,   10,   10, 0x0a,
     155,  151,   10,   10, 0x0a,
     179,  174,   10,   10, 0x0a,
     209,  201,   10,   10, 0x0a,
     244,  238,   10,   10, 0x0a,
     258,   10,   10,   10, 0x0a,
     267,   10,   10,   10, 0x0a,
     276,   10,   10,   10, 0x0a,
     307,   10,   10,   10, 0x0a,
     340,   10,   10,   10, 0x0a,
     370,   10,   10,   10, 0x0a,
     401,   10,   10,   10, 0x0a,
     433,   10,   10,   10, 0x0a,
     452,   10,   10,   10, 0x0a,

 // methods: signature, parameters, type, tag, flags
     474,   10,  469,   10, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_FBConnect[] = {
    "FBConnect\0\0start()\0stop()\0"
    "sessionDidLogin(FBUID)\0getFriendList()\0"
    "getNewsFeed()\0userid\0getAlbums(QString)\0"
    "getOwnAlbums()\0object_id\0getComments(QString)\0"
    "aid\0getPhotos(QString)\0text\0"
    "updateStatus(QString)\0id,text\0"
    "sendComment(QString,QString)\0error\0"
    "test(FBError)\0update()\0logout()\0"
    "friendRequestDidLoad(QVariant)\0"
    "newsFeedRequestDidLoad(QVariant)\0"
    "albumRequestDidLoad(QVariant)\0"
    "photosRequestDidLoad(QVariant)\0"
    "commentRequestDidLoad(QVariant)\0"
    "sessionDidLogout()\0gotPermissions()\0"
    "bool\0getName()\0"
};

const QMetaObject FBConnect::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FBConnect,
      qt_meta_data_FBConnect, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FBConnect::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FBConnect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FBConnect::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FBConnect))
        return static_cast<void*>(const_cast< FBConnect*>(this));
    return QObject::qt_metacast(_clname);
}

int FBConnect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: start(); break;
        case 1: stop(); break;
        case 2: sessionDidLogin((*reinterpret_cast< FBUID(*)>(_a[1]))); break;
        case 3: getFriendList(); break;
        case 4: getNewsFeed(); break;
        case 5: getAlbums((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: getOwnAlbums(); break;
        case 7: getComments((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: getPhotos((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: updateStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: sendComment((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: test((*reinterpret_cast< const FBError(*)>(_a[1]))); break;
        case 12: update(); break;
        case 13: logout(); break;
        case 14: friendRequestDidLoad((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 15: newsFeedRequestDidLoad((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 16: albumRequestDidLoad((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 17: photosRequestDidLoad((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 18: commentRequestDidLoad((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 19: sessionDidLogout(); break;
        case 20: gotPermissions(); break;
        case 21: { bool _r = getName();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
