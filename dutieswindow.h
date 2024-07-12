#ifndef DUTIESWINDOW_H
#define DUTIESWINDOW_H

#include <QMainWindow>
#include "user.h"
#include <QTreeWidgetItem>>

namespace Ui {
class dutiesWindow;
}

class dutiesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit dutiesWindow(User & u  , QString title , QWidget *parent = nullptr);
    ~dutiesWindow();

private slots:
    void on_OkButton_clicked();

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_pushButton_clicked();

private:
    Ui::dutiesWindow *ui;
    User user;
    QString lTitle;
};

#endif // DUTIESWINDOW_H
