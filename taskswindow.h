#ifndef TASKSWINDOW_H
#define TASKSWINDOW_H

#include <QMainWindow>
#include "user.h"
#include <QTreeWidgetItem>

namespace Ui {
class tasksWindow;
}

class tasksWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit tasksWindow(User & u , QString title , QWidget *parent = nullptr);
    ~tasksWindow();

private slots:

    void on_AddButton_clicked();

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item , int column);

    void on_BackButton_clicked();

    void on_StarButton_clicked();

    void on_PersonButton_clicked();

    void on_pdfButton_clicked();

private:
    Ui::tasksWindow *ui;
    User user;
    QString lTitle;
};

#endif // TASKSWINDOW_H
