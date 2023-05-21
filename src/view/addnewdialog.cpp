#include "addnewdialog.h"
#include "ui_addnew.h"

AddNewDialog::AddNewDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::AddNewDialog)
{
    ui->setupUi(this);
}

AddNewDialog::~AddNewDialog()
{
    delete ui;
}

void AddNewDialog::on_buttonBox_accepted()
{
    data.fname = ui->fname->text();
    data.lname = ui->lname->text();
    data.login = ui->login->text();
    data.password = ui->password->text();
    data.role = ui->role->currentText();
    this->accept();
}
