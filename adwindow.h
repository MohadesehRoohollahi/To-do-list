#ifndef ADWINDOW_H
#define ADWINDOW_H

#include <QMainWindow>
#include "user.h"

namespace Ui {
class AdWindow;
}

class AdWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdWindow(User & u , QWidget *parent = nullptr);
    ~AdWindow();

private slots:
    void on_ContinueButton_clicked();

private:
    Ui::AdWindow *ui;
    User user;
};

#endif // ADWINDOW_H
