# LibraryManagement_QtDB
Bir kütüphane otomasyonu yapılacaktır. Bu otomasyon kütüphaneye üye olan kişileri, kitapları ve bu üyelerin ödünç kitap alma ve ödünç kitabı verme durumlarının tutulduğu bir otomasyondur. Ödevde veri tabanı kullanılacaktır ve Qt ile veri tabanı arasında bağlantı yapılacaktır. Bu ödev veri tabanı üzerinde işlemler içermektedir. Veri tabanındaki tabloların adları ve alanları aşağıdaki gibi olmalıdır;  
üye:  
• uye_no (int)  • uye_ad (text) • uye_soyad (text)  

kitap:  
• kitap_no (int)  • kitap_ad (text)  • kitap_sayisi (int)  

odunc_alinan:  
• uye_no (int)  • kitap_no (int)  • odunc_alma_tarihi(text)  

odunc_teslim_edilen:  
• uye_no (int)  • kitap_no (int)  • alma_tarihi(text)  • verme_tarihi(text)  • borc (int)  

1) GİRİŞ EKRANI  
Ekran açıldığında veri tabanına bağlanıldığını belirten mesaj status-bar’da gösterilmelidir. Her bir butona tıklandığında sırasıyla Üye işlemleri ekranına, Kitap işlemleri ekranına, Ödünç alma ve Ödünç teslim etme işlemleri ekranına gitmelidir.  

2) ÜYE İŞLEMLERİ  
Ekrandaki tabloya tıklandığında tıklanan üyenin bilgileri yandaki alanlara aktarılmalıdır. Yeni Kayıt Butonu; Bu butona tıklandığında girilen bilgilere göre veri tabanındaki üye tablosuna yeni kayıt eklenmelidir. Aynı zamanda ekrandaki tablo güncellenerek yeni kayıt ekrandaki tabloda görünmelidir.Üyelerin bilgilerinin girildiği LineEdit’lar kontrol edilip bu alanların boş olması durumunda uyarı verilmelidir. Güncelle Butonu; Bu butona tıklandığında girilen bilgilere göre üyenin bilgileri güncellenmelidir. Aynı zamanda ekrandaki tablo güncellenerek veri tabanının güncel hali tabloda görünmelidir. Sil Butonu; Bu butona tıklandığında tabloda seçilen ve LineEdit’larda bilgileri yazan üye silinmelidir. Üye silme işlemi yapılırken bu üyenin ödünç alıp teslim etmediği kitap var mı kontrol edilip silme işlemi yapılmalıdır. Henüz teslim etmediği kitap varsa üye silinemez. Aynı zamanda ekrandaki tablo güncellenerek veri tabanının güncel hali tabloda görünmelidir.  

3) KİTAP İŞLEMLERİ
Ekrandaki üstteki tabloda tüm kitaplar listelenmelidir. Kitaplar tablosunda bir kitaba tıklanınca o kitabı şu an ödünç alınmış ve daha önce ödünç alınmış kayıtların bilgileri alttaki tablolarda listelenmelidir. Aynı şekilde kitaplar tablosunda bir kitaba tıklanınca o kitaba ait bilgiler ilgili LineEdit’lara aktarılmalıdır. Yeni Kayıt Butonu; Bu butona tıklandığında girilen bilgilere göre veri tabanındaki kitap tablosuna yeni kayıt eklemelidir. Yeni kayıt eklenirken LineEdit’lar kontrol edilip bu alanların boş olması durumunda uyarı verilmelidir. Aynı zamanda ekrandaki tablo güncellenerek yeni kayıt ekrandaki tabloda görünmelidir. Güncelle Butonu; Bu butona tıklandığında girilen bilgilere göre kitap bilgileri güncellenmelidir. Aynı zamanda ekrandaki kitapları gösteren tablo güncellenerek veri tabanının güncel hali tabloda görünmelidir. Sil Butonu; Bu butona tıklandığında tabloda seçilen ve LineEdit’larda bilgileri yazan kitap silinmelidir. Kitap silme işlemi yapılırken bu kitabın şu an ödünç verilmemesi gerekmektedir. Aksi halde silinmemelidir. Aynı zamanda ekrandaki tablo güncellenerek veri tabanının güncel hali tabloda görünmelidir.  

4) ÖDÜNÇ ALMA İŞLEMLERİ
Ekrandaki üst soldaki tabloda tüm üyeler, üst sağdaki tabloda tüm kitaplar, alttaki tabloda da şu an ödünç verilmiş kitapların listesi listelenmelidir. Üye ve kitap tablolarında bir satıra tıklandığında bu satırların no bilgileri aşağıdaki ilgili LineEdit’lara aktarılmalıdır. Ödünç Al; Bu butona tıklandığında üye tablosundan gelen üyenin nosu, kitap tablosundan gelen kitabın nosu ve ödünç alma tarihi bilgilerine göre üyenin ödünç aldığı kitap odunc_alinan tablosuna eklemelidir. Aynı zamanda ödünç alınan kitaplar listesinin güncel hali ekrandaki tabloda görünmelidir. Bir üye aldığı kitabı henüz teslim etmemişken aynı kitaptan tekrar ödünç alamaz, bu durumun da kontrolü yapılmalıdır. Bir kitap ödünç alınırken kütüphanede stoğu olup olmadığı da kontrol edilmelidir. Örneğin; Eylül kitabından kütüphanede 4 tane varsa ve bu 4’ü de ödünç verilmemişse bu kitap birine tekrar ödünç verilemez çünkü kütüphanede yoktur hepsi üyelere ödünç olarak verilmiştir.  

5) ÖDÜNÇ TESLİM ETME İŞLEMLERİ
Ekrandaki sol tarafında şu an ödünç alınan kitaplar listesi, sağ tarafında ise teslim edilen ödünç kitapların listesi listelenmelidir. Ödüncü Ver; Ödünç teslim edilecek kayıt soldaki tablodan seçilerek ilgili alanlara bilgileri aktarılır. Kitabın ödünç teslim tarihi de girilerek odunc_teslim_edilen tablosuna aktarılır ve sağdaki tabloda listelenir. Teslim edilen kitap odunc_alinan tablosundan silinir. Üyenin kitabı alış ve veriş tarihleri de odunc_teslim_edilen tablosuna kaydedilir. Ve bu tarihlere göre üyenin borcu olup olmadığı hesaplanır. Eğer üye kitabı 15 gün içinde teslim etmemiş ise gün başına 2 TL olarak borcu olur. Ve bu borç bilgisi de odunc_teslim_edilen tablosuna kaydedilir.  
