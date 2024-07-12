using namespace std;

#include "signupwindow.h"
#include "ui_signupwindow.h"
#include "adwindow.h"
#include "QMessageBox"
#include "fstream"
#include "sstream"
#include "user.h"

SignUpWindow::SignUpWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::on_OkButton_clicked()
{
    if(ui->EmaillineEdit->text().isEmpty() || ui->PasswordlineEdit->text().isEmpty() || ui->UsernamelineEdit->text().isEmpty()){
        QMessageBox * message = new QMessageBox(this);
        message->setStyleSheet("background:#daeaf6;color:#404565;font-weight:bold;");
        message->setText("You must fill all fields");
        message->show();
    }
    else{
        string username = ui->UsernamelineEdit->text().toStdString();
        string password = ui->PasswordlineEdit->text().toStdString();
        string email = ui->EmaillineEdit->text().toStdString();

        ifstream usersInformations("Users.txt");
        if (!usersInformations.is_open())
            QMessageBox::warning(this , "Error" , "File not open1");

        string line , fUsername;
        bool exist = false;
        while(getline(usersInformations , line)){
            istringstream x(line);
            getline(x , fUsername , ',');
            if(username == fUsername){
                exist = true;
                QMessageBox * message = new QMessageBox(this);
                message->setStyleSheet("background:#daeaf6;color:#404565;font-weight:bold;");
                message->setText("This username already exists");
                message->show();
                break;
            }
        }

        if(!exist){

            ofstream usersInformations("Users.txt" , ios::app);
            if (!usersInformations.is_open())
                QMessageBox::warning(this , "Error" , "File not open2");

            usersInformations << username << "," << password << "," << email << "," << endl;

            User user;
            user.setUsername(username);
            user.setPassword(password);
            user.setEmail(email);

            AdWindow * newPage = new AdWindow(user);
            newPage->show();
            this->close();
        }
    }
}

