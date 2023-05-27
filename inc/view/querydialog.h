#ifndef QUERYDIALOG_H
#define QUERYDIALOG_H

#include "stable.h"
#include "database.h"

namespace Ui {
class QueryDialog;
}

class QueryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QueryDialog(int state, QWidget *parent = nullptr);
    ~QueryDialog();

private:
    Ui::QueryDialog *ui;
    QSqlRelationalTableModel *model;
};

#endif // QUERYDIALOG_H
