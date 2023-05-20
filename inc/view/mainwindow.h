#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stable.h"

#include "database.h"

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


private:
    Ui::MainWindow *ui;
    Database& db = Database::instance();
};
#endif // MAINWINDOW_H
