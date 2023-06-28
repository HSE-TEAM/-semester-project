#include "authorisationwindow.h"
#include "ui_authorisationwindow.h"
#include "QString"

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


        mainWindow = new MainWindow(this);
        mainWindow->show();


}

