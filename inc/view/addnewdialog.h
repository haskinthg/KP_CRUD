#ifndef ADDNEWDIALOG_H
#define ADDNEWDIALOG_H

#include <stable.h>

#include <user.h>

namespace Ui {
class AddNewDialog;
}

class AddNewDialog : public QDialog {
    Q_OBJECT
public:
    explicit AddNewDialog(QWidget* parent = nullptr);
    ~AddNewDialog();
    User data;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddNewDialog* ui;
};

#endif // ADDNEWDIALOG_H
