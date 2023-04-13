#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newform.h"

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
    NewForm w;
    w.setModal(true);
    w.exec();
}

