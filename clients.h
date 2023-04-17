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
public:
    explicit client(QString name, QString surname, QString adress, QString lastChanges) : name(name), surname(surname), adress(adress) , lastChanges(lastChanges) {
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
};
