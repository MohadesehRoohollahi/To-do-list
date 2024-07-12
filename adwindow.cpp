#include "adwindow.h"
#include "ui_adwindow.h"
#include "ad2window.h"

AdWindow::AdWindow(User & u , QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdWindow)
    , user(u)
{
    ui->setupUi(this);
}

AdWindow::~AdWindow()
{
    delete ui;
}

void AdWindow::on_ContinueButton_clicked()
{
    Ad2Window * newPage = new Ad2Window(user);
    newPage->show();
    this->close();
}

