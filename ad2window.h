#ifndef AD2WINDOW_H
#define AD2WINDOW_H

#include <QMainWindow>
#include "user.h"

namespace Ui {
class Ad2Window;
}

class Ad2Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ad2Window(User & u , QWidget *parent = nullptr);
    ~Ad2Window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ad2Window *ui;
    User user;
};

#endif // AD2WINDOW_H
