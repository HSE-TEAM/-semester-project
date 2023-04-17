#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "clients.h"
#include <vector>
#include <memory>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void addNewClient(QString name, QString surname, QString adress, QString data);
    ~MainWindow();

private slots:

    void on_open_new_people_clicked();

    void on_create_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<client> clients;
};

#endif // MAINWINDOW_H
