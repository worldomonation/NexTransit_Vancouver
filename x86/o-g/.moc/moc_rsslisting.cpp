/****************************************************************************
** Meta object code from reading C++ file 'rsslisting.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/rsslisting.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rsslisting.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RSSListing[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       3,   59, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      25,   11,   11,   11, 0x05,
      40,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      56,   11,   11,   11, 0x0a,
      64,   11,   11,   11, 0x0a,
      92,   86,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,
     129,   11,   11,   11, 0x08,
     147,   11,   11,   11, 0x08,

 // properties: name, type, flags
     190,  182, 0x0a495103,
     194,  182, 0x0a495001,
     205,  200, 0x01495001,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

static const char qt_meta_stringdata_RSSListing[] = {
    "RSSListing\0\0urlChanged()\0feedsChanged()\0"
    "activeChanged()\0fetch()\0showVirtualKeyboard()\0"
    "reply\0finished(QNetworkReply*)\0"
    "readyRead()\0metaDataChanged()\0"
    "error(QNetworkReply::NetworkError)\0"
    "QString\0url\0feeds\0bool\0active\0"
};

void RSSListing::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RSSListing *_t = static_cast<RSSListing *>(_o);
        switch (_id) {
        case 0: _t->urlChanged(); break;
        case 1: _t->feedsChanged(); break;
        case 2: _t->activeChanged(); break;
        case 3: _t->fetch(); break;
        case 4: _t->showVirtualKeyboard(); break;
        case 5: _t->finished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->readyRead(); break;
        case 7: _t->metaDataChanged(); break;
        case 8: _t->error((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RSSListing::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RSSListing::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RSSListing,
      qt_meta_data_RSSListing, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RSSListing::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RSSListing::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RSSListing::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RSSListing))
        return static_cast<void*>(const_cast< RSSListing*>(this));
    return QObject::qt_metacast(_clname);
}

int RSSListing::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = url(); break;
        case 1: *reinterpret_cast< QString*>(_v) = feeds(); break;
        case 2: *reinterpret_cast< bool*>(_v) = active(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setUrl(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void RSSListing::urlChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void RSSListing::feedsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void RSSListing::activeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
