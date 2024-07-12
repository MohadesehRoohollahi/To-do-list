#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signupwindow.h"
#include "listswindow.h"
#include "fstream"
#include "sstream"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SignUpButton_clicked()
{
    SignUpWindow * newPage = new SignUpWindow;
    newPage->show();
    this->close();
}


void MainWindow::on_LogInButton_clicked(){

    if(ui->UsernamelineEdit->text().isEmpty() || ui->PasswordlineEdit->text().isEmpty()){
        QMessageBox * message = new QMessageBox(this);
        message->setStyleSheet("background:#daeaf6;color:#404565;font-weight:bold;");
        message->setText("You must fill all fields!");
        message->show();
    }

    else{
        User user;
        string username , password;

        ifstream usersInformations("Users.txt");
        if (!usersInformations.is_open()) {
            QMessageBox::warning(this , "Error!" , "Can't open file");
        }

        string line;
        bool accept = false;

        while(getline(usersInformations , line)){

            istringstream x(line);
            getline(x ,username , ',');
            getline(x , password , ',');

            if(username == ui->UsernamelineEdit->text().toStdString() && password == ui->PasswordlineEdit->text().toStdString()){

                accept = true;
                user.setUsername(username);
                user.setPassword(password);

                string email;
                getline(x ,email , ',');
                user.setEmail(email);

                break;
            }
        }

        ifstream accountsInformations("Accounts.txt");
        if (!accountsInformations.is_open())
            QMessageBox::warning(this , "Error" , "File not open");

        string kind , lName , lColor , tName ,  tDescription , tYear , tMonth , tDay , tDone , tStarrd , m;

        while(getline(accountsInformations , line)){

            istringstream x(line);
            getline(x , kind , ',');

            if(kind == "L"){
                getline(x , username , ',');
                if(username == ui->UsernamelineEdit->text().toStdString()){
                    getline(x , lName , ',');
                    getline(x , lColor , ',');
                    List list;
                    list.setTitle(lName);
                    list.setColor(lColor);
                    user.lists << list;
                }
            }
            else if(kind == "T"){
                getline(x , username , ',');
                if(username == ui->UsernamelineEdit->text().toStdString()){
                    getline(x , lName , ',');
                    getline(x , tName , ',');
                    getline(x , tDescription , ',');
                    getline(x , tYear , ',');
                    getline(x , tMonth , ',');
                    getline(x , tDay , ',');
                    getline(x , tDone , ',');
                    getline(x , m , ',');
                    getline(x , tStarrd , ',');
                    Task task;
                    task.setTitle(tName);
                    task.setList(lName);
                    task.setDescription(tDescription);
                    task.setYear(stoi(tYear));
                    task.setMonth(stoi(tMonth));
                    task.setDay(stoi(tDay));
                    task.setIsDone(tDone);
                    task.setIsStarred(m);
                    task.setIsStarred(tStarrd);
                    user.tasks << task;
                }
            }
        }

        if(accept){

            listsWindow * newPage = new listsWindow(user);
            newPage->show();
            this->close();
        }

        else{
            if(username != ui->UsernamelineEdit->text().toStdString()){
                QMessageBox * message = new QMessageBox(this);
                message->setStyleSheet("background:#daeaf6;color:#404565;font-weight:bold;");
                message->setText("You can't log in.Your username is wrong!");
                message->show();
            }

            else if(password != ui->PasswordlineEdit->text().toStdString()){
                QMessageBox * message = new QMessageBox(this);
                message->setStyleSheet("background:#daeaf6;color:#404565;font-weight:bold;");
                message->setText("You can't log in.Your password is wrong!");
                message->show();
            }
        }
    }
}

