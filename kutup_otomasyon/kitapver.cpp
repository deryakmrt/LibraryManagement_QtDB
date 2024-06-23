#include "kitapver.h"
#include "ui_kitapver.h"
#include <QMessageBox>

// 21100011001 - Derya Nailiye Kımırtı

kitapver::kitapver(QSqlDatabase db,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::kitapver)
{
    ui->setupUi(this);
    sorgu1 = new QSqlQuery(db);
    sorgu2 = new QSqlQuery(db);
    sorgu3 = new QSqlQuery(db);
    goster();
}

kitapver::~kitapver()
{
    delete ui;
}
void kitapver::goster()
{
    sorgu1->prepare("select * from odunc_alinan"); //odunc alinan ÇEK
    if(!sorgu1->exec())
    {
        QMessageBox::critical(this,"Hata!","Tablo çekilemedi!");
        return;
    }
    model1=new QSqlQueryModel();
    model1->setQuery(*sorgu1);
    ui->tableView_oduncal->setModel(model1);
    //--------------
    sorgu2->prepare("select * from odunc_teslim_edilen"); //teslimleri ÇEK
    if(!sorgu2->exec())
    {
        QMessageBox::critical(this,"Hata!","Tablo çekilemedi!");
        return;
    }
    model2=new QSqlQueryModel();
    model2->setQuery(*sorgu2);
    ui->tableView_oduncver->setModel(model2);
}

void kitapver::on_tableView_oduncal_clicked(const QModelIndex &index)
{

    //line larda göster
    ui->lineEdit_uyeno->setText(model1->index(index.row(),0).data().toString());
    ui->lineEdit_kitapno->setText(model1->index(index.row(),1).data().toString());
    oduncAlmaTarihi = model1->index(index.row(), 2).data().toString();
}

void kitapver::on_btn_odunver_clicked()
{
    /*Ödüncü Ver; Ödünç teslim edilecek kayıt soldaki tablodan seçilerek ilgili alanlara bilgileri
    aktarılır. Kitabın ödünç teslim tarihi de girilerek odunc_teslim_edilen tablosuna aktarılır ve
    sağdaki tabloda listelenir. Teslim edilen kitap odunc_alinan tablosundan silinir. Üyenin kitabı
    alış ve veriş tarihleri de odunc_teslim_edilen tablosuna kaydedilir. Ve bu tarihlere göre üyenin
    borcu olup olmadığı hesaplanır. Eğer üye kitabı 15 gün içinde teslim etmemiş ise gün başına 2
    TL olarak borcu olur. Ve bu borç bilgisi de odunc_teslim_edilen tablosuna kaydedilir.
    */

    QString uyeNo = ui->lineEdit_uyeno->text();
    QString kitapNo = ui->lineEdit_kitapno->text();
    QDate oduncTeslimTarihi = ui->dateEdit->date();  //lineeditlerdeki bilgileri tut

    //secilen bilgilere göre teslimedilme tablosuna yolla
    /*sorgu3->prepare("insert into odunc_teslim_edilen(uye_no,kitap_no,alma_tarihi,verme_tarihi) values(?,?,?,?)");
    sorgu3->addBindValue(uyeNo);
    sorgu3->addBindValue(kitapNo);
    sorgu3->addBindValue(oduncAlmaTarihi);
    sorgu3->addBindValue(oduncTeslimTarihi.toString("dd-MM-yyyy"));
    if (!sorgu3->exec()) {
        QMessageBox::critical(this, "Hata", "Ödünç teslim edilen kayıt eklenirken bir hata oluştu.");
        return;
    }*/

    // Ödünç alınan tablodan sil
    sorgu3->prepare("DELETE FROM odunc_alinan WHERE uye_no = ? AND kitap_no = ?");
    sorgu3->addBindValue(uyeNo);
    sorgu3->addBindValue(kitapNo);
    if (!sorgu3->exec()) {
        QMessageBox::critical(this, "Hata", "Ödünç alınan kayıt silinirken bir hata oluştu.");
        return;
    }

    // Üyenin ödünç alış ve veriş tarihlerine göre borcunu hesapla ve kaydet
    QDate alma = QDate::fromString(oduncAlmaTarihi, "dd-MM-yyyy"); //tarihi değişkene atadık
    int fark = alma.daysTo(oduncTeslimTarihi); //burası farkı hesaplar
    int borc = 0; //en basta 0

    if (fark > 15) {//teslim tarihi geçmişse
        borc = (fark - 15) * 2;
    }

    //secilen bilgilere göre teslimedilme tablosuna yolla
    sorgu3->prepare("INSERT INTO odunc_teslim_edilen (uye_no, kitap_no, alma_tarihi, verme_tarihi, borc) VALUES (?, ?, ?, ?, ?)");
    sorgu3->addBindValue(uyeNo);
    sorgu3->addBindValue(kitapNo);
    sorgu3->addBindValue(oduncAlmaTarihi);
    sorgu3->addBindValue(oduncTeslimTarihi.toString("dd-MM-yyyy"));
    sorgu3->addBindValue(borc);
    if (!sorgu3->exec()) {
        QMessageBox::critical(this, "Hata", "Borç hesaplanırken bir hata oluştu.");
        return;
    }
    goster();
    QMessageBox::information(this, "Bilgi", "Ödünç alınan kitap başarıyla teslim edildi.");
}

