#include "mainclientswindow.h"
#include "ui_mainclientswindow.h"

MainClientsWindow::MainClientsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainClientsWindow)
{
    ui->setupUi(this);
}

MainClientsWindow::~MainClientsWindow()
{
    delete ui;
}

void MainClientsWindow::on_addClientButton_clicked()
{
    AddNewClientWindow addNewClientWindow(this);
    if(addNewClientWindow.exec() == QDialog::Accepted) {
            clients.push_back(Client(addNewClientWindow.getClientName(), addNewClientWindow.getClientSurname(), addNewClientWindow.getClientEmail(), addNewClientWindow.getClientAdress(), addNewClientWindow.getClientWorker()));
            displayClients();
    }
}

void MainClientsWindow::displayClients(){
    ui->textEditClients->clear();
    for (const Client &client : clients) {
        ui->textEditClients->append(client.name + ", " + client.surname + ", " + client.email + ", " + client.adress + ", " + client.worker);
    }
}

