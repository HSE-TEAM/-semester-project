#include "authorisationwindow.h"
#include "ui_authorisationwindow.h"
#include "QString"
#include "QMessageBox"
#include "db_admins.h"

AuthorisationWindow::AuthorisationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthorisationWindow)
{
    ui->setupUi(this);
}

AuthorisationWindow::~AuthorisationWindow()
{
    delete ui;
}



void AuthorisationWindow::on_pushButton_clicked()
{
    QString login = ui->loginLineEdit->text();
    QString password = ui->passwordLineEdit->text();


    bool authed = false;
    AdminDatabase adm;
    QSqlQuery adminsQuery = adm.getAdmins();

    while (adminsQuery.next()) {
        int id = adminsQuery.value("id").toInt();
        QString lg = adminsQuery.value("login").toString();
        QString pwd = adminsQuery.value("password").toString();
        if (lg == login && pwd == password)
        {
            authed = true;
        }
        qDebug() << "Admin: ID" << id << "-" << login << "-" << password;
    }

    if (authed)
    {
        hide();
        mainWindow = new MainWindow(this);
        mainWindow->show();
    }
    else {
        QMessageBox::information(nullptr, "Отказ", "Ошибка входа!");
    }


}


void AuthorisationWindow::on_registrationPushButton_clicked()
{
    QString login = ui->loginLineEdit_2->text();
    QString password = ui->passwordLineEdit_2->text();

    bool registered = false;
    AdminDatabase adm;
    QSqlQuery adminsQuery = adm.getAdmins();
    while (adminsQuery.next()) {
        int id = adminsQuery.value("id").toInt();
        QString lg = adminsQuery.value("login").toString();
        QString pwd = adminsQuery.value("password").toString();
        if (lg == login)
        {
            registered = true;
        }
        qDebug() << "Admin: ID" << id << "-" << login << "-" << password;
    }
    if (!registered)
    {
       adm.addAdmin(login, password);
       ui->loginLineEdit_2->clear();
       ui->passwordLineEdit_2->clear();
       QMessageBox::information(nullptr, "Успешная регистрация", "Регистрация прошла успешно!");
    }
    else{
        QMessageBox::information(nullptr, "Ошибка регистрации", "Пользователь с таким именем уже есть");
    }
}

