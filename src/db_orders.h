#ifndef DB_ORDERS_H
#define DB_ORDERS_H

#include <QSqlQuery>
class OrderDatabase
{
public:
    bool createOrders()
    {
        QSqlQuery query;

        return query.exec("CREATE TABLE orders (id INTEGER PRIMARY KEY AUTOINCREMENT, customer_id INTEGER, status TEXT, FOREIGN KEY(customer_id) REFERENCES customers(id))");
    }
    bool addOrder(int customerId, const QString& status)
    {
        QSqlQuery query;
        query.prepare("INSERT INTO orders (customer_id, status) VALUES (?, ?)");
        query.addBindValue(customerId);
        query.addBindValue(status);
        return query.exec();
    }

    bool deleteOrder(int orderId)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM orders WHERE id = ?");
        query.addBindValue(orderId);
        return query.exec();
    }

    bool updateOrder(int orderId, const QString& status)
    {
        QSqlQuery query;
        query.prepare("UPDATE orders SET status = ? WHERE id = ?");
        query.addBindValue(status);
        query.addBindValue(orderId);
        return query.exec();
    }

    QSqlQuery getOrders()
    {
        QSqlQuery query("SELECT * FROM orders");
        return query;
    }

    QSqlQuery getCustomerOrders(int customerId)
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM orders WHERE customer_id = ?");
        query.addBindValue(customerId);
        return query;
    }
};

#endif // DB_ORDERS_H
