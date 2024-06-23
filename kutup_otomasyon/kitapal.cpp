#include "kitapal.h"
#include "ui_kitapal.h"
#include <QMessageBox>

// 21100011001 - Derya Nailiye Kımırtı


kitapal::kitapal(QSqlDatabase db,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::kitapal)
{
    ui->setupUi(this);
    sorgu1 = new QSqlQuery(db);
    sorgu2 = new QSqlQuery(db);
    sorgu3 = new QSqlQuery(db);
    goster();
}

kitapal::~kitapal()
{
    delete ui;
}

void kitapal::goster()
{
    sorgu1->prepare("select * from uye"); //UYELERİ ÇEK
    if(!sorgu1->exec())
    {
        QMessageBox::critical(this,"Hata!","Tablo çekilemedi!");
        return;
    }
    model1=new QSqlQueryModel();
    model1->setQuery(*sorgu1);
    ui->tableView_uyeler->setModel(model1);
//--------------
    sorgu2->prepare("select * from kitap"); //KİTAPLARI ÇEK
    if(!sorgu2->exec())
    {
        QMessageBox::critical(this,"Hata!","Tablo çekilemedi!");
        return;
    }
    model2=new QSqlQueryModel();
    model2->setQuery(*sorgu2);
    ui->tableView_kitaplar->setModel(model2);
//---------------
    sorgu3->prepare("select * from odunc_alinan"); //ODUNCLERİ ÇEK
    if(!sorgu3->exec())
    {
        QMessageBox::critical(this,"Hata!","Tablo çekilemedi!");
        return;
    }
    model3=new QSqlQueryModel();
    model3->setQuery(*sorgu3);
    ui->tableView_oduncler->setModel(model3);

}

void kitapal::on_tableView_uyeler_clicked(const QModelIndex &index)
{
    ui->lineEdit_uyeno->setText(model1->index(index.row(),0).data().toString());
}


void kitapal::on_tableView_kitaplar_clicked(const QModelIndex &index)
{
    ui->lineEdit_kitapno->setText(model2->index(index.row(),0).data().toString());
}

  /*Ödünç Al; Bu butona tıklandığında üye tablosundan gelen üyenin nosu, kitap tablosundan gelen
    kitabın nosu ve ödünç alma tarihi bilgilerine göre üyenin ödünç aldığı kitap odunc_alinan
    tablosuna eklemelidir. Aynı zamanda ödünç alınan kitaplar listesinin güncel hali ekrandaki
    tabloda görünmelidir. Bir üye aldığı kitabı henüz teslim etmemişken aynı kitaptan tekrar ödünç
    alamaz, bu durumun da kontrolü yapılmalıdır. Bir kitap ödünç alınırken kütüphanede stoğu olup
    olmadığı da kontrol edilmelidir. Örneğin; Eylül kitabından kütüphanede 4 tane varsa ve bu 4’ü
    de ödünç verilmemişse bu kitap birine tekrar ödünç verilemez çünkü kütüphanede yoktur hepsi
    üyelere ödünç olarak verilmiştir.
*/
void kitapal::on_btn_odunc_al_clicked()
{
    QString uyeNo = ui->lineEdit_uyeno->text();
    QString kitapNo = ui->lineEdit_kitapno->text();
    QDate oduncTarihi = ui->dateEdit->date();  //lineeditlerdeki bilgileri tut

    // Boş bırakılan yer varsa uyar
    if (uyeNo.isEmpty() || kitapNo.isEmpty()) {
        QMessageBox::critical(this, "Hata!", "Lütfen gerekli yerleri doldurunuz!");
        return;
    }

    // Kitap stok kontrolü
    sorgu1->prepare("select kitap_sayisi FROM kitap WHERE kitap_no = ?"); // kitap_sayisi sutununu çağır
    sorgu1->addBindValue(kitapNo);
    if(!sorgu1->exec())
    {
        QMessageBox::critical(this, "Hata!", "Kitap stoğu sorgulanamadı!");
        return;
    }

    if (!sorgu1->next()) { // Kitap bulunamadıysa
        QMessageBox::critical(this, "Hata!", "Kitap bulunamadı!");
        return;
    }

    int kitapSayisi = sorgu1->value(0).toInt(); //sorgudan geleni değişkene ata

    if (kitapSayisi <= 0) { //stok kalmamışsa uyarı ver
        QMessageBox::critical(this, "Hata!", "Seçilen kitabın stoğu yoktur!");
        return;
    }

    // Üye aynı kitabı daha önce ödünç almış mı kontrol et
    sorgu2->prepare("select count(*) from odunc_alinan WHERE uye_no = ? AND kitap_no = ?"); //secilen "uye ve kitap"(kesişmesi) tabloda var mı--> say
    sorgu2->addBindValue(uyeNo);
    sorgu2->addBindValue(kitapNo);

    if (!sorgu2->exec()) {
        QMessageBox::critical(this, "Hata!", "Ödünç kontrolü yapılamadı!");
        return;
    }

    if (!sorgu2->next()) {
        QMessageBox::critical(this, "Hata!", "Ödünç kontrol sonucu alınamadı!");
        return;
    }

    int oduncKontrol = sorgu2->value(0).toInt(); //sorgudan geleni değişkene ata

    if (oduncKontrol > 0) { //odunc alma 0 değilse yani daha once kitabı almışsa
        QMessageBox::information(this, "Hata", "Bu üye bu kitabın bir tanesini şu an ödünç almış. Tekrar ödünç verilemez!");
        return;
    }

    // Kitap ödünç verme
    sorgu3->prepare("INSERT INTO odunc_alinan (uye_no, kitap_no, odunc_alma_tarihi) VALUES (?, ?, ?)"); //yapılan işlemi kaydetme
    sorgu3->addBindValue(uyeNo);
    sorgu3->addBindValue(kitapNo);
    sorgu3->addBindValue(oduncTarihi.toString("dd-MM-yyyy")); // Tarih formatı değiştirildi
    if (!sorgu3->exec()) {
        QMessageBox::critical(this, "Hata", "Ödünç verme işlemi gerçekleştirilemedi.");
        return;
    }

    // Kitap stok güncelleme yani 1 azalt
    sorgu1->prepare("update kitap SET kitap_sayisi = kitap_sayisi - 1 WHERE kitap_no = ?");
    sorgu1->addBindValue(kitapNo);
    if (!sorgu1->exec()) {
        QMessageBox::critical(this, "Hata", "Kitap stoğu güncellenemedi.");
        return;
    }
    goster(); //listeyi yeniler

    QMessageBox::information(this, "Tebrikler", "Kitap başarıyla ödünç alındı.");
}


