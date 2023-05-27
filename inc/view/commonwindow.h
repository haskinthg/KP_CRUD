#ifndef COMMONWINDOW_H
#define COMMONWINDOW_H

#include "stable.h"
#include <QMainWindow>

namespace Ui {
class CommonWindow;
}

class CommonWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit CommonWindow(QWidget* parent = nullptr, const QString title = "Window", const QString table = "licenses");
    ~CommonWindow();

private slots:
    void about();
    void logout();

    void on_users_triggered();

    void on_licensors_triggered();

    void on_pos_triggered();

    void on_pks_triggered();

    void on_addBtn_clicked();

    void on_detBtn_clicked();

    void on_updateTable_clicked();


    void on_action_triggered();

private:
    Ui::CommonWindow* ui;
    QString tablename;
    QSqlRelationalTableModel *model;
    void setHeaders();
    void setRelations();
};

#endif // COMMONWINDOW_H
