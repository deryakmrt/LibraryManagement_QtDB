#ifndef KITAPLAR_H
#define KITAPLAR_H

// 21100011001 - Derya Nailiye Kımırtı

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
namespace Ui {
class kitaplar;
}

class kitaplar : public QDialog
{
    Q_OBJECT

public:
    explicit kitaplar(QSqlDatabase, QWidget *parent = nullptr);
    ~kitaplar();
    void goster();

private slots:
    void on_tableView_kitaplar_clicked(const QModelIndex &index);

    void on_byn_yeni_kayit_clicked();

    void on_btn_guncelle_clicked();

    void on_btn_sil_clicked();

private:
    Ui::kitaplar *ui;
    QSqlQuery *sorgu1;
    QSqlQuery *sorgu2;
    QSqlQuery *sorgu3;
    QSqlQueryModel *model1;
    QSqlQueryModel *model2;
    QSqlQueryModel *model3;

};

#endif // KITAPLAR_H
