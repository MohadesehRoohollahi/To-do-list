#include "dutieswindow.h"
#include "ui_dutieswindow.h"
#include <string>
#include <fstream>
#include <QMessageBox>
#include <QCheckBox>
#include "twindow.h"
#include "functions.h"
#include "taskswindow.h"

using namespace std;


dutiesWindow::dutiesWindow(User & u , QString title , QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::dutiesWindow)
    , user(u)
    , lTitle(title)
{
    ui->setupUi(this);
    ui->Deadline->setDate(QDate::currentDate());
    ui->treeWidget->resizeColumnToContents(2);

    Node<Task> * tmp = user.tasks.getHead();
    while(tmp != nullptr){
        if(tmp->getData().getList() == "Duty"){

            QCheckBox * checkbox = new QCheckBox();
            if(tmp->getData().getIsDone()){
                checkbox->setChecked(true);
            }
            else
                checkbox->setChecked(false);

            checkbox->setStyleSheet("background:none;border:none;");

            QTreeWidgetItem * item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0 , QString::fromStdString(tmp->getData().getTitle()));
            QString deadline = QString::number(tmp->getData().getMonth()) + "/" + QString::number(tmp->getData().getDay()) + "/" + QString::number(tmp->getData().getYear());
            item->setText(1 , deadline);
            ui->treeWidget->setItemWidget(item, 2 , checkbox);
        }
        tmp = tmp->getNext();
    }


}

dutiesWindow::~dutiesWindow()
{
    delete ui;
}

void dutiesWindow::on_OkButton_clicked()
{
    string username = ui->UsernamelineEdit->text().toStdString();
    string tTitle = ui->TitleineEdit->text().toStdString();
    string description = ui->DescriptiontextEdit->toPlainText().toStdString();
    int year = ui->Deadline->date().year();
    int month = ui->Deadline->date().month();
    int day = ui->Deadline->date().day();

    ofstream accountsInformations("Accounts.txt" , ios::app);
    if (!accountsInformations.is_open())
        QMessageBox::warning(this , "Error" , "File not open");


    accountsInformations << "T," << username  << "," << "Duty" << "," << tTitle << "," << description << "," << year << ","
                         << month << "," << day << ","  << "0" << ",/," << "0" << "," << endl;

    QMessageBox * message = new QMessageBox(this);
    message->setStyleSheet("background:#daeaf6;color:#404565;font-weight:bold;");
    message->setText("Task set successfully");
    message->show();

    ui->UsernamelineEdit->setText("");
    ui->TitleineEdit->setText("");
    ui->DescriptiontextEdit->setText("");
    ui->Deadline->setDate(QDate::currentDate());

}

void dutiesWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    if(column == 0){

        TWindow * newPage = new TWindow(user , item->text(0));
        newPage->show();
    }

    else if(column == 2){

        Node<Task> * tmp = user.tasks.getHead();
        QWidget *widget = ui->treeWidget->itemWidget(item, 2);

        while(tmp != nullptr){
            if(tmp->getData().getList() == "Duty"){
                if(tmp->getData().getTitle() == item->text(0).toStdString()){
                    if(!tmp->getData().getIsDone()){

                        if (QCheckBox *checkbox = qobject_cast<QCheckBox*>(widget))
                            checkbox->setChecked(true);
                        tmp->getData().setIsDone("1");
                        changingFile(user.username , "Duty" , tmp->getData().getTitle() , ",0," , ",1,");
                        break;

                    }

                    else{

                        if (QCheckBox *checkbox = qobject_cast<QCheckBox*>(widget))
                            checkbox->setChecked(false);
                        tmp->getData().setIsDone("0");
                        changingFile(user.username , "Duty" , tmp->getData().getTitle() , ",1," , ",0,");
                        break;

                    }
                }
            }
            tmp = tmp->getNext();
        }
    }
}


void dutiesWindow::on_pushButton_clicked()
{
    tasksWindow * n = new tasksWindow(user , lTitle);
    n->show();
    this->close();
}

