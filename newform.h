#ifndef NEWFORM_H
#define NEWFORM_H

#include <QDialog>
#include "mainwindow.h"
#include <QDateTime>

namespace Ui {
class NewForm;
}

class NewForm : public QDialog
{
    Q_OBJECT

public:
    explicit NewForm(MainWindow *parent = nullptr);
    ~NewForm();

private slots:

    void on_Create_client_clicked();

private:
    Ui::NewForm *ui;
    MainWindow* parent;
};

#endif // NEWFORM_H
