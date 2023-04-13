#ifndef NEWFORM_H
#define NEWFORM_H

#include <QDialog>

namespace Ui {
class NewForm;
}

class NewForm : public QDialog
{
    Q_OBJECT

public:
    explicit NewForm(QWidget *parent = nullptr);
    ~NewForm();

private:
    Ui::NewForm *ui;
};

#endif // NEWFORM_H
