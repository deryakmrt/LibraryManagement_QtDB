/********************************************************************************
** Form generated from reading UI file 'kitapal.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KITAPAL_H
#define UI_KITAPAL_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_kitapal
{
public:
    QTableView *tableView_uyeler;
    QTableView *tableView_kitaplar;
    QTableView *tableView_oduncler;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btn_odunc_al;
    QLabel *label_7;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_uyeno;
    QLineEdit *lineEdit_kitapno;
    QDateEdit *dateEdit;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *kitapal)
    {
        if (kitapal->objectName().isEmpty())
            kitapal->setObjectName("kitapal");
        kitapal->resize(813, 764);
        tableView_uyeler = new QTableView(kitapal);
        tableView_uyeler->setObjectName("tableView_uyeler");
        tableView_uyeler->setGeometry(QRect(20, 70, 321, 391));
        tableView_kitaplar = new QTableView(kitapal);
        tableView_kitaplar->setObjectName("tableView_kitaplar");
        tableView_kitaplar->setGeometry(QRect(409, 70, 341, 300));
        tableView_oduncler = new QTableView(kitapal);
        tableView_oduncler->setObjectName("tableView_oduncler");
        tableView_oduncler->setGeometry(QRect(409, 440, 341, 300));
        label = new QLabel(kitapal);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 40, 141, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(kitapal);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(520, 40, 141, 20));
        label_2->setFont(font);
        label_3 = new QLabel(kitapal);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(470, 410, 241, 20));
        label_3->setFont(font);
        btn_odunc_al = new QPushButton(kitapal);
        btn_odunc_al->setObjectName("btn_odunc_al");
        btn_odunc_al->setGeometry(QRect(130, 690, 93, 29));
        btn_odunc_al->setCheckable(false);
        label_7 = new QLabel(kitapal);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(170, 20, 441, 20));
        QPalette palette;
        QBrush brush(QColor(170, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        label_7->setPalette(palette);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(kitapal);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(180, 510, 156, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_uyeno = new QLineEdit(layoutWidget);
        lineEdit_uyeno->setObjectName("lineEdit_uyeno");
        lineEdit_uyeno->setEnabled(false);

        verticalLayout->addWidget(lineEdit_uyeno);

        lineEdit_kitapno = new QLineEdit(layoutWidget);
        lineEdit_kitapno->setObjectName("lineEdit_kitapno");
        lineEdit_kitapno->setEnabled(false);

        verticalLayout->addWidget(lineEdit_kitapno);

        dateEdit = new QDateEdit(layoutWidget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setDateTime(QDateTime(QDate(2024, 1, 1), QTime(0, 0, 0)));
        dateEdit->setMaximumDateTime(QDateTime(QDate(2030, 12, 31), QTime(20, 59, 59)));
        dateEdit->setMinimumDateTime(QDateTime(QDate(2019, 12, 31), QTime(23, 0, 0)));
        dateEdit->setDate(QDate(2024, 1, 1));

        verticalLayout->addWidget(dateEdit);

        layoutWidget1 = new QWidget(kitapal);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 510, 156, 141));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName("label_5");
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName("label_6");
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_6);


        retranslateUi(kitapal);

        btn_odunc_al->setDefault(true);


        QMetaObject::connectSlotsByName(kitapal);
    } // setupUi

    void retranslateUi(QDialog *kitapal)
    {
        kitapal->setWindowTitle(QCoreApplication::translate("kitapal", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("kitapal", "T\303\274m \303\234yeler", nullptr));
        label_2->setText(QCoreApplication::translate("kitapal", "T\303\274m Kitaplar", nullptr));
        label_3->setText(QCoreApplication::translate("kitapal", "\303\226d\303\274n\303\247 Al\304\261nan Kitaplar Listesi", nullptr));
        btn_odunc_al->setText(QCoreApplication::translate("kitapal", "\303\226d\303\274n\303\247 Al", nullptr));
        label_7->setText(QCoreApplication::translate("kitapal", "\303\226D\303\234N\303\207 ALMA \304\260\305\236LEMLER\304\260", nullptr));
        label_4->setText(QCoreApplication::translate("kitapal", "\303\234ye No:", nullptr));
        label_5->setText(QCoreApplication::translate("kitapal", "Kitap No:", nullptr));
        label_6->setText(QCoreApplication::translate("kitapal", "\303\226d\303\274n\303\247 Alma Tarihi:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class kitapal: public Ui_kitapal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KITAPAL_H
