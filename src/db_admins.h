#ifndef DB_ADMINS_H
#define DB_ADMINS_H

#include <QSqlQuery>
class AdminDatabase
{
public:
    bool createAdmins()
    {
        QSqlQuery query;
        return query.exec("CREATE TABLE admins (id INTEGER PRIMARY KEY AUTOINCREMENT, login TEXT, password TEXT)");
    }
    bool addAdmin(const QString& login, const QString& password)
    {
        QSqlQuery query;
        query.prepare("INSERT INTO admins (login, password) VALUES (?, ?)");
        query.addBindValue(login);
        query.addBindValue(password);
        return query.exec();
    }

    bool deleteAdmin(int adminId)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM admins WHERE id = ?");
        query.addBindValue(adminId);
        return query.exec();
    }

    bool updateAdmin(int adminId, const QString& login, const QString& password)
    {
        QSqlQuery query;
        query.prepare("UPDATE admins SET login = ?, password = ? WHERE id = ?");
        query.addBindValue(login);
        query.addBindValue(password);
        query.addBindValue(adminId);
        return query.exec();
    }

    QSqlQuery getAdmins()
    {
        QSqlQuery query("SELECT * FROM admins");
        return query;
    }
};

#endif // DB_ADMINS_H
