#include "starwindow.h"
#include "ui_starwindow.h"
#include <QMovie>

StarWindow::StarWindow(User & u , QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StarWindow)
    , user(u)
{
    ui->setupUi(this);
    Node<Task> * tmp = user.tasks.getHead();
    while(tmp != nullptr){
        if(tmp->getData().getIsStarred()){
            QTreeWidgetItem * item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0 , QString::fromStdString(tmp->getData().getTitle()));
            QString deadline = QString::number(tmp->getData().getMonth()) + "/" + QString::number(tmp->getData().getDay()) + "/" + QString::number(tmp->getData().getYear());
            item->setText(1 , deadline);
        }
        tmp = tmp->getNext();
    }


    QMovie * movie = new QMovie(":gif.gif");
    ui->label->setMovie(movie);
    ui->label_2->setMovie(movie);
    ui->label_3->setMovie(movie);
    ui->label_4->setMovie(movie);
    ui->label_5->setMovie(movie);
    ui->label_6->setMovie(movie);
    ui->label_7->setMovie(movie);
    ui->label_8->setMovie(movie);
    movie->start();
}

StarWindow::~StarWindow()
{
    delete ui;
}
