#include "querydialog.h"
#include "ui_querydialog.h"

QueryDialog::QueryDialog(int state, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::QueryDialog)
{
    ui->setupUi(this);
    QStringList headers;
    model = new QSqlQueryModel(this);

    ui->tableView->setModel(model);

    switch (state) {
    case 1:
        model->setQuery(Database::instance().getQueryEndedLics());
        qDebug() << model->lastError();
        headers << tr("ID") << tr("Начало") << tr("Окончание") << tr("Цена") << tr("Название") << tr("Рабочая станция") << tr("ПО") << tr("Орг.");
        //        model->setRelation(5, QSqlRelation("computers", "id", "name"));
        //        model->setRelation(6, QSqlRelation("programs", "id", "name"));
        //        model->setRelation(7, QSqlRelation("licensors", "id", "name"));
        for (int i = 0, j = 0; i < model->columnCount(); i++, j++)
            model->setHeaderData(i, Qt::Horizontal, headers[j]);
    }

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    // ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // model->setEditStrategy(QSqlRelationalTableModel::EditStrategy::OnManualSubmit);
    // ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSortingEnabled(true);
}

QueryDialog::~QueryDialog()
{
    delete ui;
}
