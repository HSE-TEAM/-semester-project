#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "clients.h"
#include <vector>
#include <memory>
#include <QGroupBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, int ID = 0);
    void addNewClient(QString name, QString surname, QString adress, QString data, int ID);
    ~MainWindow();

private slots:

    void on_open_new_people_clicked();

    void on_pushButton_clicked();
    void clientUpdate();

private:
    Ui::MainWindow *ui;
    std::vector<client> clients;
    std::vector<QGroupBox*> table;
    int ID;
};

#endif // MAINWINDOW_H
