#include "twindow.h"
#include "ui_twindow.h"
#include "taskswindow.h"

TWindow::TWindow(User & u  , QString title , QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TWindow)
    , user(u)
    , tTitle(title)
{
    ui->setupUi(this);

    Node<Task>* tmp = user.tasks.getHead();
    while (tmp != nullptr) {
        if (tmp->getData().getTitle() == tTitle.toStdString()){
            ui->TitlelineEdit->setText(tTitle);
            ui->DescriptionlineEdit->setText(QString::fromStdString(tmp->getData().getDescription()));

            QString deadline = QString::number(tmp->getData().getMonth()) + "/" + QString::number(tmp->getData().getDay()) + "/" + QString::number(tmp->getData().getYear());
            ui->DeadlinelineEdit->setText(deadline);

            if(tmp->getData().getIsDone()){
                ui->icon->setStyleSheet("background-image:url(:t3.png);border-radius:10px;");
            }
            else{
                ui->icon->setStyleSheet("background-image:url(:c3.png);border-radius:10px;");
            }
            break;
        }
        tmp = tmp->getNext();
    }
}

TWindow::~TWindow()
{
    delete ui;
}


void TWindow::on_OkButton_clicked()
{
    this->close();
}

