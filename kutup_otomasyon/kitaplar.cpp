#include "kitaplar.h"
#include "ui_kitaplar.h"

// 21100011001 - Derya Nailiye Kımırtı

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
    Aksi halde silinmemelidir.*/
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
