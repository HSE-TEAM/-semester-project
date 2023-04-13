#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <unordered_map>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    std::unordered_map<std::string, std::string> users;
    Ui::Dialog *ui;
    MainWindow *window;
};
#endif // DIALOG_H
