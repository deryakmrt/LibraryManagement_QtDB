/*#include "kitapal.h"
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

void kitapal::on_btn_odunc_al_clicked()
{
    QString uyeNo = ui->lineEdit_uyeno->text();
    QString kitapNo = ui->lineEdit_kitapno->text();
    QDate oduncTarihi = ui->dateEdit->date();  //lineeditlerdeki bilgileri tut

    // Boş bırakılan yer varsa uyar
    if (uyeNo.isEmpty() || kitapNo.isEmpty()) {
        QMessageBox::critical(this, "Hata!", "Lütfen gerekli yerleri doldurunuz!","OK");
        return;
    }

    // Kitap stok kontrolü
    sorgu1->prepare("select kitap_sayisi FROM kitap WHERE kitap_no = ?");// kitap_sayisi sutununu çağır
    sorgu1->addBindValue(kitapNo);
    if(!sorgu1->exec())
    {
        QMessageBox::critical(this,"Hata!","lkdsjdsb!");
        return;
    }

    int kitapSayisi = sorgu1->value(0).toInt(); //sorgudan geleni değişkene ata

    if (kitapSayisi = 0) { //stok kalmamışsa uyarı ver
        QMessageBox::critical(this, "Hata!", "Seçilen kitabın stoğu yoktur!","OK");
        return;
    }

    // üye aynı kitabı daha önce odunc almış mı
    sorgu2->prepare("select count (*) from odunc_alinan WHERE uye_no = ? AND kitap_no = ?");//secilen "uye ve kitap"(kesişmesi) tabloda var mı--> say
    sorgu2->addBindValue(uyeNo);
    sorgu2->addBindValue(kitapNo);

    int oduncKontrol = sorgu2->value(0).toInt();//sorgudan geleni değişkene ata

    if (oduncKontrol > 0) { //odunc alma 0 değilse yani daha once kitabı almışsa
        QMessageBox::information(this, "Hata", "Bu üye bu kitabın bir tanesini şuan ödünç almış. Tekrar ödünç verilemez!");
        return;
    }

    // Kitap ödünç verme
    sorgu3->prepare("INSERT INTO odunc_alinan (uye_no, kitap_no, odunc_alma_tarihi) VALUES (?, ?, ?)"); //yapılan işlemi kaydetme
    sorgu3->addBindValue(uyeNo);
    sorgu3->addBindValue(kitapNo);
    sorgu3->addBindValue(oduncTarihi.toString("dd-MM-yyyy"));
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
    goster();//listeyi yeniler

    QMessageBox::information(this, "Tebrikler", "Kitap başarıyla ödünç alındı.");
}
//----------------------------------------------------------------------------------------------------
#include "kitaplar.h"
#include "ui_kitaplar.h"

kitaplar::kitaplar(QSqlDatabase db, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::kitaplar)
{
    ui->setupUi(this);
    sorgu1 = new QSqlQuery(db);
    sorgu2 = new QSqlQuery(db);
    sorgu3 = new QSqlQuery(db);
    goster();
}

kitaplar::~kitaplar()
{
    delete ui;
}
void kitaplar::goster()
{
    sorgu1->prepare("select * from kitap"); //db browser'dan sql komutlarıyla çekmeye başlıyoruz
    if(!sorgu1->exec())
    {
        QMessageBox::critical(this,"Hata!","Tablo çekilemedi!");
        return;
    }
    model1=new QSqlQueryModel();
    model1->setQuery(*sorgu1);
    ui->tableView_kitaplar->setModel(model1);
}

void kitaplar::on_tableView_kitaplar_clicked(const QModelIndex &index)
{
    //bu fonksiyonda tablonun üzerindeki isimlere basınca isimler kitap_ad lineeditlerine düşecek
    ui->lineEdit_kitapNo->setText(model1->index(index.row(),0).data().toString()); //0. sütunu çağır
    ui->lineEdit_kitapAd->setText(model1->index(index.row(),1).data().toString()); //1. sütunu çağır
    ui->lineEdit_stok->setText(model1->index(index.row(),2).data().toString()); //2. sütunu çağır
    //diğer tableview bilgilerini de göster!!!!!!!!!!
    //------------------
    sorgu2->prepare("select * from odunc_alinan where kitap_no=?");
    sorgu2->addBindValue(ui->lineEdit_kitapNo->text().toInt());
    if(!sorgu2->exec())
    {
        QMessageBox::critical(this,"Hata!","Tablo Çekilemedi(odunc alınan)");
        return;
    }

    model2=new QSqlQueryModel();
    model2->setQuery(*sorgu2); //çekilen bilgiler model2 ye atılsın
    ui->tableView_oduncAlinma->setModel(model2); //model2 tableview de gösterilsin


    sorgu3->prepare("select * from odunc_teslim_edilen where kitap_no=?");
    sorgu3->addBindValue(ui->lineEdit_kitapNo->text().toInt());
    if(!sorgu3->exec())
    {
        QMessageBox::critical(this,"Hata!","Tablo Çekilemedi(teslim edilen)");
        return;
    }

    model3=new QSqlQueryModel();
    model3->setQuery(*sorgu3);
    ui->tableView_oncedenOdunAlinma->setModel(model3);
}


void kitaplar::on_byn_yeni_kayit_clicked()
{
    if(ui->lineEdit_kitapAd->text()=="" || ui->lineEdit_stok->text()=="") //lineEdit kısımları boş olamaz!
    {
        QMessageBox::critical(this,"Hata!","Gerekli Alanları Doldurunuz!","OK");
        return;
    }
    sorgu1->prepare("insert into kitap(kitap_ad,kitap_sayisi) values(?,?)"); //lineEdit bilgilerine ekleme fonk. (insert into)
    sorgu1->addBindValue(ui->lineEdit_kitapAd->text());//lineEdit'teki veriler sorgu1'den db'ye eklenir
    sorgu1->addBindValue(ui->lineEdit_stok->text());
    if(!sorgu1->exec()){
        QMessageBox::critical(this,"Hata!","Yeni Kayıt yapılırken sorun oluştu","OK");
        return;
    }
    else
    {
        QMessageBox::information(this, "Information!", "Yeni Kayıt işlemi başarıyla gerçekleşti!", "OK");
    }
    goster();
}



void kitaplar::on_btn_guncelle_clicked()
{
    //update fonksiyonu kullanılır
    sorgu1->prepare("update kitap set kitap_ad=?,kitap_sayisi=? where kitap_no=?");

    sorgu1->addBindValue(ui->lineEdit_kitapAd->text());
    sorgu1->addBindValue(ui->lineEdit_stok->text());
    sorgu1->addBindValue(ui->lineEdit_kitapNo->text().toInt());
    if(!sorgu1->exec()){
        QMessageBox::critical(this,"Hata!","Yeni Kayıt yapılırken sorun oluştu","OK");
        return;
    }
    else
    {
        QMessageBox::information(this, "Information!", "Güncelleme işlemi başarıyla gerçekleşti!", "OK");
    }
    goster();
    ui->lineEdit_kitapAd->clear();
    ui->lineEdit_kitapNo->clear();
    ui->lineEdit_stok->clear();
}


void kitaplar::on_btn_sil_clicked()
/*  Sil Butonu; Bu butona tıklandığında tabloda seçilen ve LineEdit’larda bilgileri yazan kitap
    silinmelidir. Kitap silme işlemi yapılırken bu kitabın şu an ödünç verilmemesi gerekmektedir.
    Aksi halde silinmemelidir.
{
    int secilen_kitap_no = ui->lineEdit_kitapNo->text().toInt(); //silmek istenen uye_no
    sorgu2->exec("select * from odunc_alinan");
    //kitap ödünç verilmiş mi kontrol et!!
    if (sorgu2->next())
    {
        QMessageBox::critical(this,"Hata!","Bu kitap silinemez. Bu kitap bir üyeye ödünç verilmiştir!","OK");
        return;
    }
    //ödünç verilmemişse...sil
    sorgu2->prepare("delete from kitap where kitap_no = ?");
    sorgu2->addBindValue(secilen_kitap_no);

    if (!sorgu2->exec())
    {
        QMessageBox::critical(this, "Hata!", "Silme işlemi yapılırken hata oluştu!", "OK");
        return;
    }
    else
    {
        QMessageBox::information(this, "Information!", "Silme işlemi başarıyla gerçekleşti!", "OK");
    }
    goster();
}

//----------------------------------------------------------------------------------------------------
#include "kitapver.h"
#include "ui_kitapver.h"
#include <QMessageBox>


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
    }

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
//----------------------------------------------------------------------------------------------------
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uyeler.h"
#include "kitaplar.h"
#include "kitapal.h"
#include "kitapver.h"

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

//----------------------------------------------------------------------------------------------------
#include "uyeler.h"
#include "ui_uyeler.h"

uyeler::uyeler(QSqlDatabase db,QWidget *parent) //QSqlDatabase db eklemeyi unutma!
    : QDialog(parent)
    , ui(new Ui::uyeler)
{
    ui->setupUi(this);
    sorgu1 = new QSqlQuery(db);
    sorgu2 = new QSqlQuery(db);
    goster();
}

uyeler::~uyeler()
{
    delete ui;
}

void uyeler::goster()
{
    sorgu1->prepare("select * from uye"); //db browser'dan sql komutlarıyla çekmeye başlıyoruz
    if(!sorgu1->exec())
    {
        QMessageBox::critical(this,"Hata!","Tablo çekilemedi!");
        return;
    }
    model1=new QSqlQueryModel();
    model1->setQuery(*sorgu1);
    ui->tableView_uyeler->setModel(model1);
}
void uyeler::on_tableView_uyeler_clicked(const QModelIndex &index)
{
    //bu fonksiyonda tablonun üzerindeki isimlere basınca isimler uye_ad lineeditlerine düşecek
    ui->line_uye_no->setText(model1->index(index.row(),0).data().toString()); //0. sütunu çağır
    ui->line_uye_ad->setText(model1->index(index.row(),1).data().toString()); //1. sütunu çağır
    ui->line_uye_soyad->setText(model1->index(index.row(),2).data().toString()); //2. sütunu çağır
}

void uyeler::on_btn_yeni_kayit_clicked()
{
    if(ui->line_uye_ad->text()=="" ||ui->line_uye_soyad->text()=="") //ad-soyad kısımları boş olamaz!
    {
        QMessageBox::critical(this,"Hata!","Gerekli Alanları Doldurunuz!","OK");
        return;
    }
    sorgu1->prepare("insert into uye(uye_ad,uye_soyad) values(?,?)"); //ad-soyad bilgilerine ekleme fonk. (insert into)
    sorgu1->addBindValue(ui->line_uye_ad->text()); //lineEdit'teki veriler sorgu1'den db'ye eklenir
    sorgu1->addBindValue(ui->line_uye_soyad->text());
    if(!sorgu1->exec()){
        QMessageBox::critical(this,"Hata!","Yeni Kayıt yapılırken sorun oluştu","OK");
        return;
    }
    else
    {
        QMessageBox::information(this, "Information!", "Yeni Kayıt işlemi başarıyla gerçekleşti!", "OK");
    }
    goster();
}

void uyeler::on_btn_guncelle_clicked()
{
    //update fonksiyonu kullanılır
    sorgu1->prepare("update uye set uye_ad=?,uye_soyad=? where uye_no=?");

    sorgu1->addBindValue(ui->line_uye_ad->text());
    sorgu1->addBindValue(ui->line_uye_soyad->text());
    sorgu1->addBindValue(ui->line_uye_no->text().toInt());
    if(!sorgu1->exec()){
        QMessageBox::critical(this,"Hata!","Yeni Kayıt yapılırken sorun oluştu","OK");
        return;
    }
    else
    {
        QMessageBox::information(this, "Information!", "Güncelleme işlemi başarıyla gerçekleşti!", "OK");
    }
    goster();
    ui->line_uye_ad->clear();
    ui->line_uye_soyad->clear();
    ui->line_uye_no->clear();

}

void uyeler::on_btn_sil_clicked()
{
    /* Üye silme işlemi yapılırken bu üyenin ödünç alıp teslim etmediği kitap var mı
    kontrol edilip silme işlemi yapılmalıdır. Henüz teslim etmediği kitap varsa üye silinemez.

    int secilen_uye_no = ui->line_uye_no->text().toInt(); //silmek istenen uye_no
    sorgu2->exec("select * from odunc_alinan");
    int hata=0;

    while(sorgu2->next()) //BURASI ÇALIŞMIYOR!!!--------------------------------
    {
        int odunc_uye_no=sorgu2->value(0).toInt();//odun_alinan tablosunun 0. sutunu(uye_no)

        if(odunc_uye_no==secilen_uye_no)
        {
            hata=1; //secilen uye odunc aldığı kitap var! yani silinemez
            break;
        }
    }

    if(hata)
    {
        QMessageBox::critical(this,"Hata!","Bu üye silinemez. Üyenin henüz teslim etmediği kitaplar vardır!","OK");
    }
    else
    {
        sorgu2->prepare("delete from uye where uye_no = ?");
        sorgu2->addBindValue(secilen_uye_no);
        if (!sorgu2->exec()) {
            QMessageBox::critical(this, "Hata!", "Silme işlemi yapılırken hata oluştu!", "OK");
            return;
        }
        else
        {
            QMessageBox::information(this, "Information!", "Silme işlemi başarıyla gerçekleşti!", "OK");
        }
        goster();
    }

}
*/
