#include "workerswindow.h"
#include "ui_workerswindow.h"

WorkersWindow::WorkersWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkersWindow)
{
    ui->setupUi(this);
    AdminDatabase adm;
    QSqlQuery adminsQuery = adm.getAdmins();

    while (adminsQuery.next()) {
        QString id = adminsQuery.value("id").toString();
        QString lg = adminsQuery.value("login").toString();
        QString pwd = adminsQuery.value("password").toString();
        ui->textEdit->append(id + ", " + lg + ", " +  pwd);
    }


}

WorkersWindow::~WorkersWindow()
{
    delete ui;
}
