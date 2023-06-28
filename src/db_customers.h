#ifndef DB_CUSTOMERS_H
#define DB_CUSTOMERS_H

#include <QSqlQuery>
class CustomerDatabase
{
public:
    bool createCustomers()
    {
        QSqlQuery query;
        query.exec("CREATE TABLE customers (id INTEGER PRIMARY KEY AUTOINCREMENT, first_name TEXT, last_name TEXT, address TEXT)");
        return query.exec();
    }
    bool addCustomer(const QString& firstName, const QString& lastName, const QString& address)
    {
        QSqlQuery query;
        query.prepare("INSERT INTO customers (first_name, last_name, address) VALUES (?, ?, ?)");
        query.addBindValue(firstName);
        query.addBindValue(lastName);
        query.addBindValue(address);
        return query.exec();
    }

    bool deleteCustomer(int customerId)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM customers WHERE id = ?");
        query.addBindValue(customerId);
        return query.exec();
    }

    bool updateCustomer(int customerId, const QString& firstName, const QString& lastName, const QString& address)
    {
        QSqlQuery query;
        query.prepare("UPDATE customers SET first_name = ?, last_name = ?, address = ? WHERE id = ?");
        query.addBindValue(firstName);
        query.addBindValue(lastName);
        query.addBindValue(address);
        query.addBindValue(customerId);
        return query.exec();
    }

    QSqlQuery getCustomers()
    {
        QSqlQuery query("SELECT * FROM customers");
        return query;
    }
};



#endif // DB_CUSTOMERS_H
