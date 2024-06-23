#include "uyeler.h"
#include "ui_uyeler.h"

// 21100011001 - Derya Nailiye Kımırtı

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
    kontrol edilip silme işlemi yapılmalıdır. Henüz teslim etmediği kitap varsa üye silinemez. */

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
