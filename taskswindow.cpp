#include "taskswindow.h"
#include "ui_taskswindow.h"
#include <fstream>
#include <QMessageBox>
#include "twindow.h"
#include "listswindow.h"
#include <QCheckBox>
#include "functions.h"
#include "starwindow.h"
#include "dutieswindow.h"
#include <Qprinter>


tasksWindow::tasksWindow(User & u , QString title , QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tasksWindow)
    , user(u)
    , lTitle(title)
{
    ui->setupUi(this);

    ui->Deadline->setDate(QDate::currentDate());
    ui->treeWidget->resizeColumnToContents(2);
    ui->treeWidget->resizeColumnToContents(3);


    Node<Task>* tmp = user.tasks.getHead();
    while (tmp != nullptr) {
        if (tmp->getData().List == lTitle.toStdString()) {
            QCheckBox * checkbox = new QCheckBox();
            if(tmp->getData().isDone){
                checkbox->setChecked(true);
            }
            checkbox->setStyleSheet("background:none;");

            QPushButton * button = new QPushButton();
            if(tmp->getData().isStarred)
                button->setStyleSheet("background-image:url(:bstar.png);border-radius:10px;");
            else
                button->setStyleSheet("background-image:url(:wstar.png);border-radius:10px;");


            QTreeWidgetItem * item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0 , QString::fromStdString(tmp->getData().title));

            QString deadline = QString::number(tmp->getData().getMonth()) + "/" + QString::number(tmp->getData().getDay()) + "/" + QString::number(tmp->getData().getYear());
            item->setText(1 , deadline);

            ui->treeWidget->setItemWidget(item, 2 , checkbox);
            ui->treeWidget->setItemWidget(item, 3 , button);
        }
        tmp = tmp->getNext();
    }

}

tasksWindow::~tasksWindow()
{
    delete ui;
}

void tasksWindow::on_AddButton_clicked()
{
    QCheckBox * checkbox = new QCheckBox();
    checkbox->setStyleSheet("background:none;");

    QPushButton * button = new QPushButton();
    button->setStyleSheet("background-image:url(:wstar.png);border-radius:10px;width: 20px;height: 20px;");

    QTreeWidgetItem * item = new QTreeWidgetItem(ui->treeWidget);
    item->setText(0 , ui->TitlelineEdit->text());
    item->setText(1 , ui->Deadline->text());
    ui->treeWidget->setItemWidget(item, 2 , checkbox);
    ui->treeWidget->setItemWidget(item, 3 , button);

    Task task;
    task.List = lTitle.toStdString();
    task.title = ui->TitlelineEdit->text().toStdString();
    task.description = ui->Description->toPlainText().toStdString();
    task.deadline.year = ui->Deadline->date().year();
    task.deadline.month = ui->Deadline->date().month();
    task.deadline.day = ui->Deadline->date().day();
    user.tasks << task;


    ofstream accountsInformations("Accounts.txt" , ios::app);
    if (!accountsInformations.is_open())
        QMessageBox::warning(this , "Error" , "File not open");


    accountsInformations << "T," << user.username  << "," << lTitle.toStdString() << "," << task.title << "," << task.description << "," << task.deadline.year << ","
                         << task.deadline.month << "," << task.deadline.day << ","  << task.isDone << ",/," << task.isStarred << "," << endl;


    ui->TitlelineEdit->setText("");
    ui->Deadline->setDate(QDate::currentDate());
    ui->Description->setText("");

}


void tasksWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    if(column == 0){

        TWindow * newPage = new TWindow(user , item->text(0));
        newPage->show();
    }

    else if(column == 2){

        Node<Task> * tmp = user.tasks.getHead();
        QWidget *widget = ui->treeWidget->itemWidget(item, 2);

        while(tmp != nullptr){
            if(tmp->getData().List == lTitle.toStdString()){
                if(tmp->getData().title == item->text(0).toStdString()){
                    if(!tmp->getData().isDone){

                        if (QCheckBox *checkbox = qobject_cast<QCheckBox*>(widget))
                            checkbox->setChecked(true);
                        tmp->getData().isDone = true;
                        changingFile(user.username , lTitle.toStdString() , tmp->getData().title , ",0," , ",1,");
                        break;

                    }

                    else{

                        if (QCheckBox *checkbox = qobject_cast<QCheckBox*>(widget))
                            checkbox->setChecked(false);
                        tmp->getData().isDone = false;
                        changingFile(user.username , lTitle.toStdString() , tmp->getData().title , ",1," , ",0,");
                        break;

                    }
                }
            }
            tmp = tmp->getNext();
        }
    }

    else if(column == 3){

        Node<Task> * tmp = user.tasks.getHead();
        QWidget *widget = ui->treeWidget->itemWidget(item, 3);

        while(tmp != nullptr){
            if(tmp->getData().List == lTitle.toStdString()){
                if(tmp->getData().title == item->text(0).toStdString()){
                    if(!tmp->getData().isStarred){
                        if (QPushButton *button = qobject_cast<QPushButton*>(widget))
                            button->setStyleSheet("background-image:url(:bstar.png);border-radius:10px;width: 20px;height: 20px;");
                        tmp->getData().isStarred = true;
                        changingFile(user.username , lTitle.toStdString() , tmp->getData().title , "/,0" , "/,1");
                        break;
                    }

                    else{
                        if (QPushButton *button = qobject_cast<QPushButton*>(widget))
                            button->setStyleSheet("background-image:url(:wstar.png);border-radius:10px;width: 20px;height: 20px;");
                        tmp->getData().isStarred = false;
                        changingFile(user.username , lTitle.toStdString() , tmp->getData().title , "/,1" , "/,0");
                        break;
                    }
                }
            }
            tmp = tmp->getNext();
        }
    }
}



void tasksWindow::on_BackButton_clicked()
{
    listsWindow * newPage = new listsWindow(user);
    newPage->show();
    this->close();
}



void tasksWindow::on_StarButton_clicked()
{
    StarWindow * newPage = new StarWindow(user);
    newPage->show();
}


void tasksWindow::on_PersonButton_clicked()
{
    dutiesWindow * newPage = new dutiesWindow(user , lTitle);
    newPage->show();
    this->close();
}


void tasksWindow::on_pdfButton_clicked()
{
    string informations;
    Node<Task> * tmp = user.tasks.getHead();
    while(tmp != nullptr){
        if(tmp->getData().List == lTitle.toStdString()){
            informations += tmp->getData().title + "," + tmp->getData().description + "," + to_string(tmp->getData().deadline.year) + ","
                            + to_string(tmp->getData().deadline.month) + "," + to_string(tmp->getData().deadline.day) + "," +
                            to_string(tmp->getData().isDone) + "," + to_string(tmp->getData().isStarred) + " ------ ";
        }

        tmp = tmp->getNext();
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(lTitle + ".pdf");

    QTextDocument document;
    document.setHtml("<h3>" + QString::fromStdString(informations) + "</h3>");
    document.print(&printer);

    QMessageBox * message = new QMessageBox(this);
    message->setStyleSheet("background:#daeaf6;color:#404565;font-weight:bold;");
    message->setText("The list information was saved as PDF");
    message->show();
}

