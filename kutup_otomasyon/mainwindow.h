#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// 21100011001 - Derya Nailiye Kımırtı

#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase> //eklendi
#include <QSqlTableModel> //eklendi
#include <QSqlQueryModel> //eklendi
#include <QSqlQuery> //++
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_uye_clicked();

    void on_btn_kitap_clicked();

    void on_btn_oduncAl_clicked();

    void on_btn_teslimEt_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE"); //eklendi
};
#endif // MAINWINDOW_H
