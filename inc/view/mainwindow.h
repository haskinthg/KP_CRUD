#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stable.h"

#include "addnewdialog.h"
#include "commonwindow.h"
#include "database.h"

#define dbManager DbManager::instance()

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_clicked();
    void on_registration_clicked();
    void on_close_Dialog();


private:
    Ui::MainWindow *ui;
    Database& db = Database::instance();
    AddNewDialog* dialog;
    CommonWindow* main;
    QString login;
    QString password;
};
#endif // MAINWINDOW_H
