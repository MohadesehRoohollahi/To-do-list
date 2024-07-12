#ifndef TWINDOW_H
#define TWINDOW_H

#include <QMainWindow>
#include "user.h"

namespace Ui {
class TWindow;
}

class TWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TWindow(User & u , QString title, QWidget *parent = nullptr);
    ~TWindow();

private slots:

    void on_OkButton_clicked();

private:
    Ui::TWindow *ui;
    User user;
    QString tTitle;
};

#endif // TWINDOW_H
