#include "dialog.h"
#include "./ui_dialog.h"
#include <QMessageBox>
#include "mainwindow.h"

#include <QFile>
#include <QTextStream>

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
    QString login = ui->login->text();
    QString password = ui->password->text();
    QFile file("C:/Users/ivpus/Desktop/Hse/qt exemple/project/logins.csv");
    if ( !file.open(QFile::ReadOnly | QFile::Text)) {
        return;
    }
    QTextStream in(&file);
    int index = 0;
    while(!in.atEnd() and index == 0){
        QString line = in.readLine();
        QStringList information = line.split(";");
        if (information[1] != login) continue;
        if (information[2] != password) continue;
        index++;
        hide();
        window = new MainWindow(this);
        window->show();
    }
    if (index == 0) QMessageBox::warning(this, "Warning", "Wrong login or password");
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

