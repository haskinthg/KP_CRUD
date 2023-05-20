#include <view/mainwindow.h>
#include "ui_mainwindow.h"
#include "DbManager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //подключение  к бд

    if(DbManager::instance().connect()) QMessageBox::information(this, "OK", "Подключение к базе данных прошло успешно!");
    else {
        QMessageBox::warning(this, "Ошибка", db.lastError());
        exit(1);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


//вход
void MainWindow::on_login_clicked()
{

}

//регистрация
void MainWindow::on_registration_clicked()
{

}
