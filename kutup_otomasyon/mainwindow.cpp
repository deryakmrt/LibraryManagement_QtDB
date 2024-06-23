#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uyeler.h"
#include "kitaplar.h"
#include "kitapal.h"
#include "kitapver.h"

// 21100011001 - Derya Nailiye Kımırtı

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //VT bağlantısı
    db.setDatabaseName("kutuphane.db"); //olusturulan db dosyasının yolunu ekliyoruz
                                        //build dosyasına eklendi
    if (!db.open())
    {
        ui->statusbar->showMessage("Veri tabanına bağlanılamadı!");
    }
    else
    {
        ui->statusbar->showMessage("Veri tabanına bağlanıldı :)");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_uye_clicked()
{
    uyeler *uye = new uyeler(db);
    uye->show();
}


void MainWindow::on_btn_kitap_clicked()
{
    kitaplar *kitapp = new kitaplar(db);
    kitapp->show();
}


void MainWindow::on_btn_oduncAl_clicked()
{
    kitapal *kitappal = new kitapal(db);
    kitappal->show();
}


void MainWindow::on_btn_teslimEt_clicked()
{
    kitapver *kitappver = new kitapver(db);
    kitappver->show();
}
