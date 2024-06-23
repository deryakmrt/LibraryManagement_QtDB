#ifndef UYELER_H
#define UYELER_H

// 21100011001 - Derya Nailiye Kımırtı

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

namespace Ui {
class uyeler;
}

class uyeler : public QDialog
{
    Q_OBJECT

public:
    explicit uyeler(QSqlDatabase, QWidget *parent = nullptr); //QSqlDatabase ekle
    ~uyeler();
    void goster();

private slots:
    void on_tableView_uyeler_clicked(const QModelIndex &index);

    void on_btn_yeni_kayit_clicked();

    void on_btn_guncelle_clicked();

    void on_btn_sil_clicked();

private:
    Ui::uyeler *ui;
    QSqlQuery *sorgu1;
    QSqlQuery *sorgu2;
    QSqlQueryModel *model1;
};

#endif // UYELER_H
