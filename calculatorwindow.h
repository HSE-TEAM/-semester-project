#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H
#include "window_system.h"
#include <QDialog>
#include <QString>
#include <unordered_map>

namespace Ui {
class CalculatorWindow;
}

class CalculatorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CalculatorWindow(QWidget *parent = nullptr);
    ~CalculatorWindow();

private slots:
    void on_frontUpperRowHeightEdit_textEdited(const QString &arg1);

    void on_frontLowerRowHeightEdit_textEdited(const QString &arg1);

    void on_frontWidthEdit_textEdited(const QString &arg1);

private:
    double grandTotal = 0;
    Calculator::WindowSystem windowSystem = Calculator::WindowSystem(grandTotal);
    Ui::CalculatorWindow *ui;
};
#endif // CALCULATORWINDOW_H
