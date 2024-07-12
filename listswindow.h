#ifndef LISTSWINDOW_H
#define LISTSWINDOW_H

#include <QMainWindow>
#include "user.h"
#include <QTreeWidgetItem>

namespace Ui {
class listsWindow;
}

class listsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit listsWindow(User & u , QWidget *parent = nullptr);
    ~listsWindow();

private slots:

    void on_AddButton_clicked();

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::listsWindow *ui;
    User user;
};

#endif // LISTSWINDOW_H
