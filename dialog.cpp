#include "dialog.h"
#include "./ui_dialog.h"
#include <QMessageBox>
//#include "mainwidget.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    QString login = ui->label->text();
    QString password = ui->label_2->text();

    if (users[login.toStdString()].empty() or users[login.toStdString()] != password.toStdString()) {
        QMessageBox::warning(this, "Warning", "Wrong login or password");
    } else {
        //window = new MainWidget(this);
        //window->show();
    }
}


void Dialog::on_pushButton_2_clicked()
{
    QString login = ui->label_3->text();
    QString password = ui->label_4->text();
    if (!users[login.toStdString()].empty()) {
        QMessageBox::warning(this, "Warning", "login already taken");
    } else {
        if (login.size() < 5 or password.size() < 5) {
            QMessageBox::warning(this, "Warning", "Username and password must contain more than 5 characters");
        } else {
            users[login.toStdString()] = password.toStdString();
            QMessageBox::information(this, "Success", "you have successfully created an account");
        }
    }
}

