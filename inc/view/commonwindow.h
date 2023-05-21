#ifndef COMMONWINDOW_H
#define COMMONWINDOW_H

#include <QMainWindow>

namespace Ui {
class CommonWindow;
}

class CommonWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CommonWindow(QWidget *parent = nullptr);
    ~CommonWindow();

private slots:
    void about();
    void logout();

private:
    Ui::CommonWindow *ui;
};

#endif // COMMONWINDOW_H
