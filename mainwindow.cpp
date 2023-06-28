#include "mainwindow.h"
#include "./ui_mainwindow.h"

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


void MainWindow::on_pushButton_clicked()
{
    calculatorWindow = new CalculatorWindow(this);
    calculatorWindow->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    mainClientsWindow = new MainClientsWindow(this);
    mainClientsWindow->show();
}

