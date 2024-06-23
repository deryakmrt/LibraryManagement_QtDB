/********************************************************************************
** Form generated from reading UI file 'kitaplar.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KITAPLAR_H
#define UI_KITAPLAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_kitaplar
{
public:
    QTableView *tableView_kitaplar;
    QTableView *tableView_oduncAlinma;
    QTableView *tableView_oncedenOdunAlinma;
    QLineEdit *lineEdit_kitapNo;
    QLineEdit *lineEdit_kitapAd;
    QLineEdit *lineEdit_stok;
    QPushButton *byn_yeni_kayit;
    QPushButton *btn_guncelle;
    QPushButton *btn_sil;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QDialog *kitaplar)
    {
        if (kitaplar->objectName().isEmpty())
            kitaplar->setObjectName("kitaplar");
        kitaplar->resize(904, 794);
        tableView_kitaplar = new QTableView(kitaplar);
        tableView_kitaplar->setObjectName("tableView_kitaplar");
        tableView_kitaplar->setGeometry(QRect(20, 70, 321, 331));
        tableView_oduncAlinma = new QTableView(kitaplar);
        tableView_oduncAlinma->setObjectName("tableView_oduncAlinma");
        tableView_oduncAlinma->setGeometry(QRect(20, 470, 320, 280));
        tableView_oncedenOdunAlinma = new QTableView(kitaplar);
        tableView_oncedenOdunAlinma->setObjectName("tableView_oncedenOdunAlinma");
        tableView_oncedenOdunAlinma->setGeometry(QRect(380, 470, 510, 280));
        lineEdit_kitapNo = new QLineEdit(kitaplar);
        lineEdit_kitapNo->setObjectName("lineEdit_kitapNo");
        lineEdit_kitapNo->setEnabled(false);
        lineEdit_kitapNo->setGeometry(QRect(490, 120, 113, 26));
        lineEdit_kitapAd = new QLineEdit(kitaplar);
        lineEdit_kitapAd->setObjectName("lineEdit_kitapAd");
        lineEdit_kitapAd->setGeometry(QRect(490, 160, 113, 26));
        lineEdit_stok = new QLineEdit(kitaplar);
        lineEdit_stok->setObjectName("lineEdit_stok");
        lineEdit_stok->setGeometry(QRect(490, 210, 113, 26));
        byn_yeni_kayit = new QPushButton(kitaplar);
        byn_yeni_kayit->setObjectName("byn_yeni_kayit");
        byn_yeni_kayit->setGeometry(QRect(390, 300, 93, 29));
        btn_guncelle = new QPushButton(kitaplar);
        btn_guncelle->setObjectName("btn_guncelle");
        btn_guncelle->setGeometry(QRect(540, 300, 93, 29));
        btn_sil = new QPushButton(kitaplar);
        btn_sil->setObjectName("btn_sil");
        btn_sil->setGeometry(QRect(470, 360, 93, 29));
        label = new QLabel(kitaplar);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 40, 91, 20));
        label_2 = new QLabel(kitaplar);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 10, 121, 20));
        label_3 = new QLabel(kitaplar);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(400, 120, 63, 20));
        QFont font;
        font.setBold(true);
        label_3->setFont(font);
        label_4 = new QLabel(kitaplar);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(400, 170, 63, 20));
        label_4->setFont(font);
        label_5 = new QLabel(kitaplar);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(400, 210, 63, 20));
        label_5->setFont(font);
        label_6 = new QLabel(kitaplar);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 440, 251, 20));
        label_7 = new QLabel(kitaplar);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(450, 430, 351, 20));

        retranslateUi(kitaplar);

        QMetaObject::connectSlotsByName(kitaplar);
    } // setupUi

    void retranslateUi(QDialog *kitaplar)
    {
        kitaplar->setWindowTitle(QCoreApplication::translate("kitaplar", "Dialog", nullptr));
        byn_yeni_kayit->setText(QCoreApplication::translate("kitaplar", "Yeni kay\304\261t", nullptr));
        btn_guncelle->setText(QCoreApplication::translate("kitaplar", "g\303\274ncelle", nullptr));
        btn_sil->setText(QCoreApplication::translate("kitaplar", "sil", nullptr));
        label->setText(QCoreApplication::translate("kitaplar", "T\303\274m Kitaplar", nullptr));
        label_2->setText(QCoreApplication::translate("kitaplar", "K\304\260TAP \304\260\305\236LEMLER\304\260", nullptr));
        label_3->setText(QCoreApplication::translate("kitaplar", "Kitap no", nullptr));
        label_4->setText(QCoreApplication::translate("kitaplar", "Kitap Ad", nullptr));
        label_5->setText(QCoreApplication::translate("kitaplar", "Stok", nullptr));
        label_6->setText(QCoreApplication::translate("kitaplar", "se\303\247ilen kitab\304\261n \303\266d\303\274n\303\247 al\304\261nma durumu", nullptr));
        label_7->setText(QCoreApplication::translate("kitaplar", "se\303\247ilen kitab\304\261n daha \303\266nceden \303\266d\303\274n\303\247 al\304\261nma durumu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class kitaplar: public Ui_kitaplar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KITAPLAR_H
