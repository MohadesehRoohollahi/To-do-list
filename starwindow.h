#ifndef STARWINDOW_H
#define STARWINDOW_H

#include <QMainWindow>
#include "user.h"

namespace Ui {
class StarWindow;
}

class StarWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StarWindow(User & u , QWidget *parent = nullptr);
    ~StarWindow();

private:
    Ui::StarWindow *ui;
    User user;
};

#endif // STARWINDOW_H
