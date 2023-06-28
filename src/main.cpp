#include "mainwindow.h"
#include "authorisationwindow.h"
#include "db_admins.h"
#include "db_customers.h"
#include "db_orders.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if (!db.open()) {
        qDebug() << "Failed to open database";
        return -1;
    }

    CustomerDatabase customerDb;
    OrderDatabase orderDb;
    AdminDatabase adminDb;

    customerDb.createCustomers();
    orderDb.createOrders();
    adminDb.createAdmins();

    customerDb.addCustomer("John", "Doe", "123 Main St");
    customerDb.addCustomer("Jane", "Smith", "456 Elm St");

    QSqlQuery customersQuery = customerDb.getCustomers();
    while (customersQuery.next()) {
        int id = customersQuery.value("id").toInt();
        QString firstName = customersQuery.value("first_name").toString();
        QString lastName = customersQuery.value("last_name").toString();
        QString address = customersQuery.value("address").toString();
        qDebug() << "Customer: ID" << id << "-" << firstName << lastName << "-" << address;
    }

    orderDb.addOrder(1, "Pending");
    orderDb.addOrder(2, "Completed");

    QSqlQuery ordersQuery = orderDb.getOrders();
    while (ordersQuery.next()) {
        int id = ordersQuery.value("id").toInt();
        int customerId = ordersQuery.value("customer_id").toInt();
        QString status = ordersQuery.value("status").toString();
        qDebug() << "Order: ID" << id << "- Customer ID" << customerId << "-" << status;
    }
    adminDb.addAdmin("admin1", "password1");
    adminDb.addAdmin("admin2", "password2");

    QSqlQuery adminsQuery = adminDb.getAdmins();
    while (adminsQuery.next()) {
        int id = adminsQuery.value("id").toInt();
        QString login = adminsQuery.value("login").toString();
        QString password = adminsQuery.value("password").toString();
        qDebug() << "Admin: ID" << id << "-" << login << "-" << password;
    }

    QSqlQuery customerOrdersQuery = orderDb.getCustomerOrders(1);
    while (customerOrdersQuery.next()) {
        int id = customerOrdersQuery.value("id").toInt();
        int customerId = customerOrdersQuery.value("customer_id").toInt();
        QString status = customerOrdersQuery.value("status").toString();
        qDebug() << "Customer Order: ID" << id << "- Customer ID" << customerId << "-" << status;
    }

    AuthorisationWindow authorisationWindow;
    authorisationWindow.show();
    return a.exec();
}






