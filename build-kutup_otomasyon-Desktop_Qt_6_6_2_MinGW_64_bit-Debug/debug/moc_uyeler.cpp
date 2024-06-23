/****************************************************************************
** Meta object code from reading C++ file 'uyeler.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../kutup_otomasyon/uyeler.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uyeler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSuyelerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSuyelerENDCLASS = QtMocHelpers::stringData(
    "uyeler",
    "on_tableView_uyeler_clicked",
    "",
    "QModelIndex",
    "index",
    "on_btn_yeni_kayit_clicked",
    "on_btn_guncelle_clicked",
    "on_btn_sil_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSuyelerENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[7];
    char stringdata1[28];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[6];
    char stringdata5[26];
    char stringdata6[24];
    char stringdata7[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSuyelerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSuyelerENDCLASS_t qt_meta_stringdata_CLASSuyelerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "uyeler"
        QT_MOC_LITERAL(7, 27),  // "on_tableView_uyeler_clicked"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 11),  // "QModelIndex"
        QT_MOC_LITERAL(48, 5),  // "index"
        QT_MOC_LITERAL(54, 25),  // "on_btn_yeni_kayit_clicked"
        QT_MOC_LITERAL(80, 23),  // "on_btn_guncelle_clicked"
        QT_MOC_LITERAL(104, 18)   // "on_btn_sil_clicked"
    },
    "uyeler",
    "on_tableView_uyeler_clicked",
    "",
    "QModelIndex",
    "index",
    "on_btn_yeni_kayit_clicked",
    "on_btn_guncelle_clicked",
    "on_btn_sil_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSuyelerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x08,    1 /* Private */,
       5,    0,   41,    2, 0x08,    3 /* Private */,
       6,    0,   42,    2, 0x08,    4 /* Private */,
       7,    0,   43,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject uyeler::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSuyelerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSuyelerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSuyelerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<uyeler, std::true_type>,
        // method 'on_tableView_uyeler_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_btn_yeni_kayit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_guncelle_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_sil_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void uyeler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<uyeler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_tableView_uyeler_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 1: _t->on_btn_yeni_kayit_clicked(); break;
        case 2: _t->on_btn_guncelle_clicked(); break;
        case 3: _t->on_btn_sil_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *uyeler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *uyeler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSuyelerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int uyeler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
