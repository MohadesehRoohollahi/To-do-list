#include "ad2window.h"
#include "ui_ad2window.h"
#include "listswindow.h"

Ad2Window::Ad2Window(User & u , QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ad2Window)
    , user(u)
{
    ui->setupUi(this);
}

Ad2Window::~Ad2Window()
{
    delete ui;
}

void Ad2Window::on_pushButton_clicked()
{
    listsWindow * newPage = new listsWindow(user);
    newPage->show();
    this->close();
}

