/********************************************************************************
** Form generated from reading UI file 'uyeler.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UYELER_H
#define UI_UYELER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_uyeler
{
public:
    QLabel *label_2;
    QLineEdit *line_uye_no;
    QLineEdit *line_uye_ad;
    QLabel *label_3;
    QLineEdit *line_uye_soyad;
    QPushButton *btn_sil;
    QLabel *label_5;
    QTableView *tableView_uyeler;
    QLabel *label_4;
    QPushButton *btn_yeni_kayit;
    QPushButton *btn_guncelle;
    QLabel *label;

    void setupUi(QDialog *uyeler)
    {
        if (uyeler->objectName().isEmpty())
            uyeler->setObjectName("uyeler");
        uyeler->resize(702, 538);
        label_2 = new QLabel(uyeler);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(450, 220, 63, 20));
        QFont font;
        font.setBold(true);
        label_2->setFont(font);
        line_uye_no = new QLineEdit(uyeler);
        line_uye_no->setObjectName("line_uye_no");
        line_uye_no->setEnabled(false);
        line_uye_no->setGeometry(QRect(540, 160, 113, 26));
        line_uye_ad = new QLineEdit(uyeler);
        line_uye_ad->setObjectName("line_uye_ad");
        line_uye_ad->setGeometry(QRect(540, 220, 113, 26));
        label_3 = new QLabel(uyeler);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(450, 280, 81, 20));
        label_3->setFont(font);
        line_uye_soyad = new QLineEdit(uyeler);
        line_uye_soyad->setObjectName("line_uye_soyad");
        line_uye_soyad->setGeometry(QRect(540, 280, 113, 26));
        btn_sil = new QPushButton(uyeler);
        btn_sil->setObjectName("btn_sil");
        btn_sil->setGeometry(QRect(480, 450, 93, 29));
        label_5 = new QLabel(uyeler);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 60, 91, 20));
        label_5->setFont(font);
        tableView_uyeler = new QTableView(uyeler);
        tableView_uyeler->setObjectName("tableView_uyeler");
        tableView_uyeler->setGeometry(QRect(40, 100, 321, 371));
        label_4 = new QLabel(uyeler);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(280, 20, 131, 20));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        label_4->setFont(font1);
        btn_yeni_kayit = new QPushButton(uyeler);
        btn_yeni_kayit->setObjectName("btn_yeni_kayit");
        btn_yeni_kayit->setGeometry(QRect(410, 360, 93, 29));
        btn_guncelle = new QPushButton(uyeler);
        btn_guncelle->setObjectName("btn_guncelle");
        btn_guncelle->setGeometry(QRect(580, 360, 93, 29));
        label = new QLabel(uyeler);
        label->setObjectName("label");
        label->setGeometry(QRect(450, 160, 63, 20));
        label->setFont(font);

        retranslateUi(uyeler);

        QMetaObject::connectSlotsByName(uyeler);
    } // setupUi

    void retranslateUi(QDialog *uyeler)
    {
        uyeler->setWindowTitle(QCoreApplication::translate("uyeler", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("uyeler", "uye ad", nullptr));
        label_3->setText(QCoreApplication::translate("uyeler", "uye soyad", nullptr));
        btn_sil->setText(QCoreApplication::translate("uyeler", "sil", nullptr));
        label_5->setText(QCoreApplication::translate("uyeler", "T\303\274m \303\234yeler", nullptr));
        label_4->setText(QCoreApplication::translate("uyeler", "\303\234YE \304\260\305\236LEMLER\304\260", nullptr));
        btn_yeni_kayit->setText(QCoreApplication::translate("uyeler", "yeni kay\304\261t", nullptr));
        btn_guncelle->setText(QCoreApplication::translate("uyeler", "g\303\274ncelle", nullptr));
        label->setText(QCoreApplication::translate("uyeler", "uye no", nullptr));
    } // retranslateUi

};

namespace Ui {
    class uyeler: public Ui_uyeler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UYELER_H
