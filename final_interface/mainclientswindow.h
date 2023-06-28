#ifndef MAINCLIENTSWINDOW_H
#define MAINCLIENTSWINDOW_H

#include <QDialog>
#include <vector>
#include "addnewclientwindow.h"

class Client {
public:
    Client(const QString &name, const QString &surname, const QString &email, const QString &adress, const QString &worker) : name(name), surname(surname), email(email), adress(adress), worker(worker) {}
    QString name;
    QString surname;
    QString email;
    QString adress;
    QString worker;
};

namespace Ui {
class MainClientsWindow;
}

class MainClientsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainClientsWindow(QWidget *parent = nullptr);
    ~MainClientsWindow();

private slots:
    void on_addClientButton_clicked();


private:
    Ui::MainClientsWindow *ui;
    std::vector<Client> clients;

    void displayClients();
};

#endif // MAINCLIENTSWINDOW_H
