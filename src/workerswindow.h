#ifndef WORKERSWINDOW_H
#define WORKERSWINDOW_H

#include "db_admins.h"
#include <QDialog>

namespace Ui {
class WorkersWindow;
}

class WorkersWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WorkersWindow(QWidget *parent = nullptr);
    ~WorkersWindow();

private:
    Ui::WorkersWindow *ui;
};

#endif // WORKERSWINDOW_H
