#ifndef KITAPAL_H
#define KITAPAL_H

// 21100011001 - Derya Nailiye Kımırtı

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
namespace Ui {
class kitapal;
}

class kitapal : public QDialog
{
    Q_OBJECT

public:
    explicit kitapal(QSqlDatabase,QWidget *parent = nullptr);
    ~kitapal();
    void goster();

private slots:
    void on_tableView_uyeler_clicked(const QModelIndex &index);

    void on_tableView_kitaplar_clicked(const QModelIndex &index);

    void on_btn_odunc_al_clicked();

private:
    Ui::kitapal *ui;
    QSqlQuery *sorgu1;
    QSqlQuery *sorgu2;
    QSqlQuery *sorgu3;
    QSqlQueryModel *model1;
    QSqlQueryModel *model2;
    QSqlQueryModel *model3;
};

#endif // KITAPAL_H
