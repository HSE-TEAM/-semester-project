#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newform.h"
#include "calculatorwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_open_new_people_clicked()
{
    NewForm w(this);
    w.setModal(true);
    w.exec();
    ui->name_1->setText(clients.back().getName());
    ui->surname_1->setText(clients.back().getSurname());
    ui->adress_1->setText(clients.back().getAdress());
    ui->changes_1->setText(clients.back().getChanges());
}
void MainWindow::addNewClient(QString name, QString surname, QString adress, QString data) {
    clients.emplace_back(name, surname, adress, data);
}


void MainWindow::on_create_clicked()
{

}


void MainWindow::on_pushButton_clicked()
{
    CalculatorWindow w(this);
    w.setModal(true);
    w.exec();
}

