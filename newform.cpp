#include "newform.h"
#include "ui_newform.h"

NewForm::NewForm(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::NewForm),
    parent(parent)
{
    ui->setupUi(this);
}

NewForm::~NewForm()
{
    delete ui;
}

void NewForm::on_Create_client_clicked()
{
    QString name = ui->name->text();
    QString surname = ui->surname->text();
    QString adress = ui->adress->text();

    //добавление параметров заказа...
    parent->addNewClient(name, surname, adress, QDateTime::currentDateTime().toString("hh:mm dd.MM.yyyy"), 10000 + rand() % 100);
    QWidget::close();
}

