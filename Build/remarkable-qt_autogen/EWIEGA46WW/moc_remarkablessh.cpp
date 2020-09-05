/****************************************************************************
** Meta object code from reading C++ file 'remarkablessh.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../remarkablessh.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'remarkablessh.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RemarkableSSH_t {
    QByteArrayData data[14];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RemarkableSSH_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RemarkableSSH_t qt_meta_stringdata_RemarkableSSH = {
    {
QT_MOC_LITERAL(0, 0, 13), // "RemarkableSSH"
QT_MOC_LITERAL(1, 14, 14), // "restartXochitl"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "stopXochitl"
QT_MOC_LITERAL(4, 42, 12), // "startXochitl"
QT_MOC_LITERAL(5, 55, 12), // "rebootDevice"
QT_MOC_LITERAL(6, 68, 14), // "shutdownDevice"
QT_MOC_LITERAL(7, 83, 11), // "mountToTemp"
QT_MOC_LITERAL(8, 95, 15), // "unmountFromTemp"
QT_MOC_LITERAL(9, 111, 23), // "readyReadStandardOutput"
QT_MOC_LITERAL(10, 135, 8), // "finished"
QT_MOC_LITERAL(11, 144, 8), // "exitCode"
QT_MOC_LITERAL(12, 153, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(13, 174, 10) // "exitStatus"

    },
    "RemarkableSSH\0restartXochitl\0\0stopXochitl\0"
    "startXochitl\0rebootDevice\0shutdownDevice\0"
    "mountToTemp\0unmountFromTemp\0"
    "readyReadStandardOutput\0finished\0"
    "exitCode\0QProcess::ExitStatus\0exitStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RemarkableSSH[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    2,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 12,   11,   13,

       0        // eod
};

void RemarkableSSH::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RemarkableSSH *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->restartXochitl(); break;
        case 1: _t->stopXochitl(); break;
        case 2: _t->startXochitl(); break;
        case 3: _t->rebootDevice(); break;
        case 4: _t->shutdownDevice(); break;
        case 5: _t->mountToTemp(); break;
        case 6: _t->unmountFromTemp(); break;
        case 7: _t->readyReadStandardOutput(); break;
        case 8: _t->finished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RemarkableSSH::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_RemarkableSSH.data,
    qt_meta_data_RemarkableSSH,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RemarkableSSH::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RemarkableSSH::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RemarkableSSH.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RemarkableSSH::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
