#include "commonwindow.h"
#include "ui_commonwindow.h"

#include <mainwindow.h>

CommonWindow::CommonWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::CommonWindow)
{
    ui->setupUi(this);
    ui->logout->addAction("Выход", this, SLOT(logout()));
    ui->about->addAction("О программе", this, SLOT(about()));
}

CommonWindow::~CommonWindow()
{
    delete ui;
}

void CommonWindow::about()
{
    QMessageBox::about(this, "О программе", "Программа создана для учета лицензий программного обеспечения.");
}

void CommonWindow::logout()
{
    this->parentWidget()->show();
    this->close();
}
