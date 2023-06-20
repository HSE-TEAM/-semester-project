#ifndef CLIENTS_H
#define CLIENTS_H

#endif // CLIENTS_H
#include <vector>
#include <string>
#include <QString>

class client {
private:
    QString name;
    QString surname;
    QString adress;
    QString lastChanges;
    int ID;
public:
    explicit client(QString name, QString surname, QString adress, QString lastChanges, int id) :
        name(name), surname(surname), adress(adress) , lastChanges(lastChanges), ID(id) {
    }
    QString getName() const {
        return name;
    }
    QString getSurname() const {
        return surname;
    }
    QString getAdress() const {
        return adress;
    }
    QString getChanges() const {
        return lastChanges;
    }
    int getID() const {
        return ID;
    }
};
