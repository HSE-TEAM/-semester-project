#ifndef ADDNEWCLIENTWINDOW_H
#define ADDNEWCLIENTWINDOW_H

#include <QDialog>
#include <QString>

namespace Ui {
class AddNewClientWindow;
}

class AddNewClientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewClientWindow(QWidget *parent = nullptr);
    ~AddNewClientWindow();

    QString getClientName() const;
    QString getClientSurname() const;
    QString getClientEmail() const;
    QString getClientAdress() const;
    QString getClientWorker() const;

private:
    Ui::AddNewClientWindow *ui;
};

#endif // ADDNEWCLIENTWINDOW_H
