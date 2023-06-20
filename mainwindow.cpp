#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newform.h"
#include "calculatorwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QRadioButton>

MainWindow::MainWindow(QWidget *parent, int ID) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ID(ID)
{
    ui->setupUi(this);
    int count;
    QFile file("C:/Users/ivpus/Desktop/Hse/qt exemple/project/clients.csv");
    if ( !file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "broken file");
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QString line = in.readLine();
        QStringList inf = line.split(";");
        clients.emplace_back(inf[3], inf[2], inf[4], inf[5], inf[0].toInt());
    }
    if (clients.empty()) QMessageBox::warning(this, "Warning", "You haven't clients");
    file.close();
    clientUpdate();
}

void clearLayout(QLayout *layout) {
    if (layout == NULL)
        return;
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
           delete item->widget();
        }
        delete item;
    }
}

void MainWindow::clientUpdate() {
    clearLayout(ui->verticalLayout);
    for (auto & person :clients) {
        QFont font;
        QGroupBox *groupBox = new QGroupBox("Клиент №" + QString::number(person.getID()));
        font = groupBox->font();
        font.setPixelSize(25);
        groupBox->setFont(font);

        QLabel *surname = new QLabel(person.getSurname());
        font = surname->font();
        font.setPixelSize(14);
        surname->setFont(font);

        QLabel *name = new QLabel(person.getName());
        font = name->font();
        font.setPixelSize(14);
        name->setFont(font);

        QLabel *address = new QLabel(person.getAdress());
        font = address->font();
        font.setPixelSize(14);
        address->setFont(font);

        QLabel *lastChange = new QLabel(person.getChanges());
        font = lastChange->font();
        font.setPixelSize(14);
        lastChange->setFont(font);

        QPushButton * open = new QPushButton("Перейти", this);
        font = open->font();
        font.setPixelSize(14);
        open->setFont(font);
        connect(open, SIGNAL(clicked()), this, SLOT(deleteClient(person)));


        QHBoxLayout *hbox = new QHBoxLayout(this);
        hbox->addWidget(surname);
        hbox->addWidget(name);
        hbox->addWidget(address);
        hbox->addWidget(lastChange);
        hbox->addWidget(open);

        groupBox->setLayout(hbox);
        ui->verticalLayout->addWidget(groupBox);
    }
    /*QGroupBox *groupBox = new QGroupBox(tr("Exclusive Radio Buttons"));
    QLabel *name = new QLabel("Имя");
    QFont font = name->font();
    font.setPixelSize(13);
    name->setFont(font);



    QHBoxLayout *vbox = new QHBoxLayout;
    vbox->addWidget(name);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);
    ui->verticalLayout->addWidget(groupBox);*/
    QFile file("C:/Users/ivpus/Desktop/Hse/qt exemple/project/clients.csv");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            QMessageBox::warning(this, "Warning", "broken file");
    QTextStream out(&file);
    for (auto &i: clients) {
        out << i.getID() << ';' << ID << ';' << i.getSurname() << ';' << i.getName() << ';' << i.getAdress() << ';' << i.getChanges() << '\n';
    }
    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::deleteClient(client &person) {
    for (auto &i: clients) {
        if (i.getID() == person.getID()) {
            if (clients.back().getID() == i.getID()) clients.pop_back();
            else {
                std::swap(clients.back(), i);
                clients.pop_back();
            }
        }
    }
    clientUpdate();
}


void MainWindow::on_open_new_people_clicked()
{
    NewForm w(this);
    w.setModal(true);
    w.exec();
    clientUpdate();
    /*ui->name_1->setText(clients.back().getName());
    ui->surname_1->setText(clients.back().getSurname());
    ui->adress_1->setText(clients.back().getAdress());
    ui->changes_1->setText(clients.back().getChanges());*/
}
void MainWindow::addNewClient(QString name, QString surname, QString adress, QString data, int ID) {
    std::reverse(clients.begin(), clients.end());
    clients.emplace_back(name, surname, adress, data, ID);
    std::reverse(clients.begin(), clients.end());
}


void MainWindow::on_pushButton_clicked()
{
    CalculatorWindow w;
    w.setModal(true);
    w.exec();
}


void MainWindow::on_updateWindowNow_clicked()
{
    clientUpdate();
}

