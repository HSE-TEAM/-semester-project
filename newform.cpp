#include "newform.h"
#include "ui_newform.h"

NewForm::NewForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewForm)
{
    ui->setupUi(this);
}

NewForm::~NewForm()
{
    delete ui;
}
