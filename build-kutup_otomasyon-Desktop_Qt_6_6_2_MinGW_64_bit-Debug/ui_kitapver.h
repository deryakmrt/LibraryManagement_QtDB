/********************************************************************************
** Form generated from reading UI file 'kitapver.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KITAPVER_H
#define UI_KITAPVER_H

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

class Ui_kitapver
{
public:
    QTableView *tableView_oduncal;
    QTableView *tableView_oduncver;
    QPushButton *btn_odunver;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_6;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_uyeno;
    QLineEdit *lineEdit_kitapno;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QDateEdit *dateEdit;

    void setupUi(QDialog *kitapver)
    {
        if (kitapver->objectName().isEmpty())
            kitapver->setObjectName("kitapver");
        kitapver->resize(1215, 498);
        tableView_oduncal = new QTableView(kitapver);
        tableView_oduncal->setObjectName("tableView_oduncal");
        tableView_oduncal->setGeometry(QRect(30, 110, 350, 351));
        tableView_oduncver = new QTableView(kitapver);
        tableView_oduncver->setObjectName("tableView_oduncver");
        tableView_oduncver->setGeometry(QRect(680, 110, 521, 351));
        btn_odunver = new QPushButton(kitapver);
        btn_odunver->setObjectName("btn_odunver");
        btn_odunver->setGeometry(QRect(490, 390, 93, 29));
        QFont font;
        font.setBold(true);
        btn_odunver->setFont(font);
        label = new QLabel(kitapver);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 70, 201, 20));
        label->setFont(font);
        label_2 = new QLabel(kitapver);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(680, 70, 201, 20));
        label_2->setFont(font);
        label_6 = new QLabel(kitapver);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(400, 10, 291, 61));
        QPalette palette;
        QBrush brush(QColor(170, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        label_6->setPalette(palette);
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        label_6->setFont(font1);
        layoutWidget = new QWidget(kitapver);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(490, 180, 156, 81));
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

        layoutWidget1 = new QWidget(kitapver);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(410, 180, 65, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        verticalLayout_2->addWidget(label_4);

        layoutWidget2 = new QWidget(kitapver);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(460, 280, 143, 91));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        verticalLayout_3->addWidget(label_5);

        dateEdit = new QDateEdit(layoutWidget2);
        dateEdit->setObjectName("dateEdit");
        QFont font2;
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        dateEdit->setFont(font2);
        dateEdit->setCursor(QCursor(Qt::ArrowCursor));
        dateEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        dateEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit->setDateTime(QDateTime(QDate(2024, 1, 1), QTime(21, 0, 0)));
        dateEdit->setMaximumDateTime(QDateTime(QDate(2030, 12, 31), QTime(17, 59, 59)));
        dateEdit->setMinimumDateTime(QDateTime(QDate(2020, 9, 13), QTime(20, 0, 0)));

        verticalLayout_3->addWidget(dateEdit);


        retranslateUi(kitapver);

        QMetaObject::connectSlotsByName(kitapver);
    } // setupUi

    void retranslateUi(QDialog *kitapver)
    {
        kitapver->setWindowTitle(QCoreApplication::translate("kitapver", "Dialog", nullptr));
        btn_odunver->setText(QCoreApplication::translate("kitapver", "\303\226d\303\274nc\303\274 Ver", nullptr));
        label->setText(QCoreApplication::translate("kitapver", "\303\226d\303\274n\303\247 Al\304\261nan Kitaplar Listesi", nullptr));
        label_2->setText(QCoreApplication::translate("kitapver", "Teslim Edilen Kitaplar Listesi", nullptr));
        label_6->setText(QCoreApplication::translate("kitapver", "\303\226D\303\234N\303\207 TESL\304\260M ETME \304\260\305\236LEMLER\304\260", nullptr));
        label_3->setText(QCoreApplication::translate("kitapver", "\303\234ye no:", nullptr));
        label_4->setText(QCoreApplication::translate("kitapver", "Kitap no:", nullptr));
        label_5->setText(QCoreApplication::translate("kitapver", "\303\226d\303\274n\303\247 Verme Tarihi:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class kitapver: public Ui_kitapver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KITAPVER_H
