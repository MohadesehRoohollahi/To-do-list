#include "listswindow.h"
#include "qdatetime.h"
#include "ui_listswindow.h"
#include "taskswindow.h"
#include "list.h"
#include "fstream"
#include "QMessageBox"

listsWindow::listsWindow(User & u , QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::listsWindow)
    , user(u)
{
    ui->setupUi(this);

    Node<List> * tmp = user.lists.getHead();
    while(tmp != nullptr){
        QTreeWidgetItem * item = new QTreeWidgetItem(ui->treeWidget);
        item->setText(0 , QString::fromStdString(tmp->getData().getTitle()));

        if(tmp->getData().getColor() == "P"){
            item->setBackground(0 , QColorConstants::Svg::pink);
            item->setBackground(1 , QColorConstants::Svg::pink);
        }

        else if(tmp->getData().getColor() == "Y"){
            item->setBackground(0 , QColorConstants::Svg::lightgoldenrodyellow);
            item->setBackground(1 , QColorConstants::Svg::lightgoldenrodyellow);
        }

        else if(tmp->getData().getColor() == "PB"){
            item->setBackground(0 , QColorConstants::Svg::powderblue);
            item->setBackground(1 , QColorConstants::Svg::powderblue);
        }

        else if(tmp->getData().getColor() == "SB"){
            item->setBackground(0 , QColorConstants::Svg::lightsteelblue);
            item->setBackground(1 , QColorConstants::Svg::lightsteelblue);
        }

        else if(tmp->getData().getColor() == "T"){
            item->setBackground(0 , QColorConstants::Svg::thistle);
            item->setBackground(1 , QColorConstants::Svg::thistle);
        }

        else if(tmp->getData().getColor() == "C"){
            item->setBackground(0 , QColorConstants::Svg::lightcyan);
            item->setBackground(1 , QColorConstants::Svg::lightcyan);
        }

        tmp = tmp->getNext();
    }


    Node<Task> * tp = user.tasks.getHead();
    QDate x;
    while(tp != nullptr){
        if(tp->getData().getYear() == x.currentDate().year() && tp->getData().getMonth() == x.currentDate().month() && tp->getData().getDay() == x.currentDate().day() && tp->getData().getIsDone() == false){
            QMessageBox * message = new QMessageBox(this);
            message->setStyleSheet("background:#daeaf6;color:#404565;font-weight:bold;");
            message->setText("It's time to " + QString::fromStdString(tp->getData().getTitle()));
            message->show();
        }
        tp = tp->getNext();
    }

}

listsWindow::~listsWindow()
{
    delete ui;
}


void listsWindow::on_AddButton_clicked()
{
    QTreeWidgetItem * item = new QTreeWidgetItem(ui->treeWidget);
    item->setText(0 , ui->TitlelineEdit->text());

    List list;
    list.setTitle(ui->TitlelineEdit->text().toStdString());
    ui->TitlelineEdit->setText("");

    if(ui->PinkButton->isChecked()){
        item->setBackground(0 , QColorConstants::Svg::pink);
        item->setBackground(1 , QColorConstants::Svg::pink);
        list.setColor("P");
    }

    else if(ui->YellowButton->isChecked()){
        item->setBackground(0 , QColorConstants::Svg::lightgoldenrodyellow);
        item->setBackground(1 , QColorConstants::Svg::lightgoldenrodyellow);
        list.setColor("Y");
    }

    else if(ui->PowderblueButton->isChecked()){
        item->setBackground(0 , QColorConstants::Svg::powderblue);
        item->setBackground(1 , QColorConstants::Svg::powderblue);
        list.setColor("PB");
    }

    else if(ui->LightsteelblueButton->isChecked()){
        item->setBackground(0 , QColorConstants::Svg::lightsteelblue);
        item->setBackground(1 , QColorConstants::Svg::lightsteelblue);
        list.setColor("SB");
    }

    else if(ui->ThistleButton->isChecked()){
        item->setBackground(0 , QColorConstants::Svg::thistle);
        item->setBackground(1 , QColorConstants::Svg::thistle);
        list.setColor("T");
    }

    else if(ui->LightcyanButton->isChecked()){
        item->setBackground(0 , QColorConstants::Svg::lightcyan);
        item->setBackground(1 , QColorConstants::Svg::lightcyan);
        list.setColor("C");
    }

    user.lists << list;

    ofstream accountsInformations("Accounts.txt" , ios::app);
    if (!accountsInformations.is_open())
        QMessageBox::warning(this , "Error" , "File not open");

    accountsInformations << "L," << user.username  << "," << list.getTitle() << "," << list.getColor() << "," << endl;

}


void listsWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    tasksWindow * newPage = new tasksWindow(user , item->text(0));
    newPage->show();
    this->close();
}

