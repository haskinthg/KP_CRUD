#include "commonwindow.h"
#include "ui_commonwindow.h"

#include <mainwindow.h>

CommonWindow::CommonWindow(QWidget* parent, const QString title, const QString table)
    : QMainWindow(parent)
    , ui(new Ui::CommonWindow)
{
    ui->setupUi(this);
    if(User::getAuth().role != "Администратор"){
                ui->addBtn->setEnabled(false);
                ui->detBtn->setEnabled(false);
    }

    this->tablename = table;
    this->setWindowTitle(title);
    ui->logout->addAction("Выход", this, SLOT(logout()));
    ui->about->addAction("О программе", this, SLOT(about()));

    this->model = new QSqlRelationalTableModel(this);

    this->model->setTable(tablename);

    setRelations();

    this->ui->tableView->setModel(model);

    setHeaders();

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    if(User::getAuth().role != "Администратор"){
                model->setEditStrategy(QSqlRelationalTableModel::EditStrategy::OnManualSubmit);
                ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    } else model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    model->select();
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

void CommonWindow::setHeaders()
{
    QStringList headers;
    if(this->tablename == "licenses")
        headers << tr("ID") << tr("Начало") << tr("Окончание")<< tr("Цена")<< tr("Название")<< tr("Рабочая станция")<< tr("ПО")<< tr("Орг.");
    else if(this->tablename == "users") {
        headers << tr("ID") << tr("Имя") << tr("Фамилия") << tr("Логин") << tr("Пароль") << tr("Роль");
        this->ui->tableView->setColumnHidden(4, true);
    } else if (this->tablename == "programs")
        headers << tr("ID") << tr("Название");
    else if (this->tablename == "licensors")
        headers << tr("ID") << tr("Наименование") << tr("Адрес");
    else if (this->tablename == "computers")
        headers << tr("ID") << tr("Название");
    for(int i = 0, j = 0; i < model->columnCount(); i++, j++)
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
}

void CommonWindow::setRelations()
{
    if(this->tablename == "licenses"){
        model->setRelation(5, QSqlRelation("computers", "id", "name"));
        model->setRelation(6, QSqlRelation("programs", "id", "name"));
        model->setRelation(7, QSqlRelation("licensors", "id", "name"));
    }
}

void CommonWindow::on_users_triggered()
{
    CommonWindow* w = new CommonWindow(this, "Пользователи", "users");
    w->show();
}


void CommonWindow::on_licensors_triggered()
{
    CommonWindow* w = new CommonWindow(this, "Организации", "licensors");
    w->show();
}


void CommonWindow::on_pos_triggered()
{
    CommonWindow* w = new CommonWindow(this, "Программное обеспечение", "programs");
    w->show();
}


void CommonWindow::on_pks_triggered()
{
    CommonWindow* w = new CommonWindow(this, "Рабочие станции", "computers");
    w->show();
}


void CommonWindow::on_addBtn_clicked()
{
    this->model->insertRow(model->rowCount());
}


void CommonWindow::on_detBtn_clicked()
{
    this->model->removeRow(ui->tableView->selectionModel()->selectedRows().at(0).row());
    model->select();
}


void CommonWindow::on_updateTable_clicked()
{
    this->model->select();
}

