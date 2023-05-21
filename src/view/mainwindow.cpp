#include <mainwindow.h>
#include "ui_mainwindow.h"
#include "DbManager.h"
#include "addnewdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //подключение  к бд

    if(!dbManager.connect()){
        QMessageBox::warning(this, "Ошибка", db.lastError());
        exit(1);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dialog;
}


//вход
void MainWindow::on_login_clicked()
{
    if(dbManager.login(ui->login_->text(), ui->password->text())){
        main = new CommonWindow(this);
        main->show();
        ui->login_->setText("");
        ui->password->setText("");
        this->hide();
    }
    else QMessageBox::warning(this, "Ошибка", "Неправильный логин или пароль.");
    ui->login_->setText("");
    ui->password->setText("");
}

//регистрация
void MainWindow::on_registration_clicked()
{
    dialog = new AddNewDialog(this);
    QObject::connect(dialog, SIGNAL(accepted()), this, SLOT(on_close_Dialog()));
    dialog->exec();
}

void MainWindow::on_close_Dialog()
{
    if (dialog->data.fname!="" && dialog->data.lname!=""&&  dialog->data.login!=""&&  dialog->data.password!=""&&  dialog->data.role!=""){
        User usr = dialog->data;
        dbManager.addUser(usr);
    }
}
