#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"

CalculatorWindow::CalculatorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalculatorWindow)
{
    ui->setupUi(this);
}

CalculatorWindow::~CalculatorWindow()
{
    delete ui;
}

void CalculatorWindow::on_frontUpperRowHeightEdit_textEdited(const QString &arg1)
{
    windowSystem.setWindowSizesUpperRowHeight(arg1.toDouble());
    ui->frontSquareValueLabel->setText(QString::number(windowSystem.getWindowSystemSquare() / 1000000));
    ui->frontWindowSizesCostValueLabel->setText(QString::number(windowSystem.getWindowSizesServiceCost() / 1000000));
}


void CalculatorWindow::on_frontLowerRowHeightEdit_textEdited(const QString &arg1)
{
    windowSystem.setWindowSizesLowerRowHeight(arg1.toDouble());
    ui->frontSquareValueLabel->setText(QString::number(windowSystem.getWindowSystemSquare() / 1000000));
    ui->frontWindowSizesCostValueLabel->setText(QString::number(windowSystem.getWindowSizesServiceCost() / 1000000));
}


void CalculatorWindow::on_frontWidthEdit_textEdited(const QString &arg1)
{
    windowSystem.setWindowSizesWidth(arg1.toDouble());
    ui->frontSquareValueLabel->setText(QString::number(windowSystem.getWindowSystemSquare() / 1000000));
    ui->frontWindowSizesCostValueLabel->setText(QString::number(windowSystem.getWindowSizesServiceCost() / 1000000));
}
