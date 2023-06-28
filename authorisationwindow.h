#ifndef AUTHORISATIONWINDOW_H
#define AUTHORISATIONWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class AuthorisationWindow;
}

class AuthorisationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AuthorisationWindow(QWidget *parent = nullptr);
    ~AuthorisationWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AuthorisationWindow *ui;
    MainWindow *mainWindow;

};

#endif // AUTHORISATIONWINDOW_H
