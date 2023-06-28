#include "mainwindow.h"
#include "authorisationwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AuthorisationWindow authorisationWindow;
    authorisationWindow.show();
    return a.exec();
}
