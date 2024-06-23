#ifndef KITAPVER_H
#define KITAPVER_H

// 21100011001 - Derya Nailiye Kımırtı

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

namespace Ui {
class kitapver;
}

class kitapver : public QDialog
{
    Q_OBJECT

public:
    explicit kitapver(QSqlDatabase,QWidget *parent = nullptr);
    ~kitapver();
    void goster();

private slots:
    void on_btn_odunver_clicked();

    void on_tableView_oduncal_clicked(const QModelIndex &index);

private:
    Ui::kitapver *ui;
    QSqlQuery *sorgu1;
    QSqlQuery *sorgu2;
    QSqlQuery *sorgu3;
    QSqlQueryModel *model1;
    QSqlQueryModel *model2;
    QSqlQueryModel *model3;
    QString oduncAlmaTarihi;

};

#endif // KITAPVER_H
