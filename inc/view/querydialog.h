#ifndef QUERYDIALOG_H
#define QUERYDIALOG_H

#include "database.h"
#include "stable.h"

namespace Ui {
class QueryDialog;
}

class QueryDialog : public QDialog {
    Q_OBJECT

public:
    explicit QueryDialog(int state, QWidget* parent = nullptr);
    ~QueryDialog();

private:
    Ui::QueryDialog* ui;
    QSqlQueryModel* model;
};

#endif // QUERYDIALOG_H
