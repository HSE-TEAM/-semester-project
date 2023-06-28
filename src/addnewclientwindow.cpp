#include "addnewclientwindow.h"
#include "ui_addnewclientwindow.h"

AddNewClientWindow::AddNewClientWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewClientWindow)
{
    ui->setupUi(this);
}

AddNewClientWindow::~AddNewClientWindow()
{
    delete ui;
}

QString AddNewClientWindow::getClientName() const{
    return ui->nameLineEdit->text();
}

QString AddNewClientWindow::getClientSurname() const{
    return ui->surnameLineEdit->text();
}

QString AddNewClientWindow::getClientEmail() const{
    return ui->emailLineEdit->text();
}

QString AddNewClientWindow::getClientAdress() const{
    return ui->adressLineEdit->text();
}

QString AddNewClientWindow::getClientWorker() const{
    return ui->workerComboBox->currentText();
}

