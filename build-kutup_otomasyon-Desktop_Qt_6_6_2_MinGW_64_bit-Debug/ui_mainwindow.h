/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_oduncAl;
    QLabel *label_6;
    QPushButton *btn_kitap;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *btn_teslimEt;
    QPushButton *btn_uye;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1040, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btn_oduncAl = new QPushButton(centralwidget);
        btn_oduncAl->setObjectName("btn_oduncAl");
        btn_oduncAl->setGeometry(QRect(560, 250, 171, 171));
        btn_oduncAl->setStyleSheet(QString::fromUtf8("border-image: url(:/images/odunc_1.jpg);"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(310, 450, 171, 20));
        QFont font;
        font.setBold(true);
        font.setStrikeOut(false);
        label_6->setFont(font);
        label_6->setLayoutDirection(Qt::LeftToRight);
        label_6->setAlignment(Qt::AlignCenter);
        btn_kitap = new QPushButton(centralwidget);
        btn_kitap->setObjectName("btn_kitap");
        btn_kitap->setGeometry(QRect(310, 250, 171, 171));
        btn_kitap->setStyleSheet(QString::fromUtf8("border-image: url(:/images/book.jpg);"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 450, 171, 20));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setStrikeOut(false);
        label_5->setFont(font1);
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(230, 110, 591, 61));
        QPalette palette;
        QBrush brush(QColor(212, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        label_9->setPalette(palette);
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        label_9->setFont(font2);
        label_9->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(560, 450, 171, 20));
        label_7->setFont(font);
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(790, 450, 211, 20));
        label_8->setFont(font);
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setAlignment(Qt::AlignCenter);
        btn_teslimEt = new QPushButton(centralwidget);
        btn_teslimEt->setObjectName("btn_teslimEt");
        btn_teslimEt->setGeometry(QRect(810, 250, 171, 171));
        btn_teslimEt->setStyleSheet(QString::fromUtf8("border-image: url(:/images/odunc_2.jpg);"));
        btn_uye = new QPushButton(centralwidget);
        btn_uye->setObjectName("btn_uye");
        btn_uye->setGeometry(QRect(60, 250, 171, 171));
        btn_uye->setStyleSheet(QString::fromUtf8("border-image: url(:/images/user.jpg);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1040, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_oduncAl->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Kitap \304\260\305\237lemleri", nullptr));
        btn_kitap->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "\303\234ye \304\260\305\237lemleri", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "K\303\234T\303\234PHANE OTOMASYONUNA HO\305\236GELD\304\260N\304\260Z!", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\303\226d\303\274n\303\247 Alma \304\260\305\237lemleri", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\303\226d\303\274n\303\247 Teslim Etme \304\260\305\237lemleri", nullptr));
        btn_teslimEt->setText(QString());
        btn_uye->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
