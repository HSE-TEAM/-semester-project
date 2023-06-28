#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QDialog>
#include <map>
#include <string>
#include <memory>
#include <iostream>
#include <QString>
#include <QComboBox>
#include "database/db_accessor/filesystem_db_accessor/filesystem_db_accessor.h"
#include "calculator/window_group/window/parameters/enumerable_parameter/enumerable_value/enumerable_value.h"
#include "calculator/window_group/window/parameters/single_parameter/single_value/single_value.h"
#include "calculator/window_group/window/window.h"
#include "calculator/window_group/window/parameters/concrete_parameters/glass_meter_price_single_parameter/glass_meter_price_single_parameter.h"
#include "calculator/window_group/window/parameters/concrete_parameters/bottom_square_multiply_enumerable_parameter/bottom_square_multiply_enumerable_parameter.h"
#include "calculator/window_group/window/parameters/concrete_parameters/top_square_multiply_enumerable_parameter/top_square_multiply_enumerable_parameter.h"
#include "calculator/window_group/window/parameters/concrete_parameters/just_multiply_enumerable_parameter/just_multiply_enumerable_parameter.h"
#include "calculator/window_group/window/parameters/concrete_parameters/square_multiply_enumerable_parameter/square_multiply_enumerable_parameter.h"
#include "calculator/window_group/window/parameters/concrete_parameters/handles_enumerable_parameter/handles_enumerable_parameter.h"
#include "calculator/sized_parameter_holder/parameter_holder/base_holder/base_holder_visitor/concrete_visitors/i_base_holder_printing_visitor/i_base_holder_printing_visitor.h"
#include "calculator/balcony_group/balcony_group.h"
#include "calculator/balcony_group/balcony_parameter_holder/balcony_parameter_holder.h"
#include "calculator/balcony_group/balcony_parameter_holder/concrete_parameters/countable_square_multiply_enumerable_parameter/countable_square_multiply_enumerable_parameter.h"
#include "calculator/calculator.h"
#include "document_creator/text_replacer/text_replacer.h"
using namespace db;
using namespace calc;

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
    void on_frontWindowUpperRowLineEdit_editingFinished();

    void on_rightWindowUpperRowLineEdit_editingFinished();

    void on_leftWindowUpperRowLineEdit_editingFinished();

    void on_frontWindowLowerRowLineEdit_editingFinished();

    void on_rightWindowLowerRowLineEdit_editingFinished();

    void on_leftWindowLowerRowLineEdit_editingFinished();

    void on_frontWindowWidthLineEdit_editingFinished();

    void on_rightWindowWidthLineEdit_editingFinished();

    void on_leftWindowWidthLineEdit_editingFinished();


    void on_frontWindowProfileComboBox_currentIndexChanged(int index);

    void on_rightWindowProfileComboBox_currentIndexChanged(int index);

    void on_leftWindowProfileComboBox_currentIndexChanged(int index);

    void on_frontWindowNumberOfOpeningsComboBox_currentIndexChanged(int index);

    void on_rightWindowNumberOfOpeningsComboBox_currentIndexChanged(int index);

    void on_leftWindowNumberOfOpeningsComboBox_currentIndexChanged(int index);

    void on_frontWindowLaminationComboBox_currentIndexChanged(int index);

    void on_rightWindowLaminationComboBox_currentIndexChanged(int index);

    void on_leftWindowLaminationComboBox_currentIndexChanged(int index);

    void on_frontWindowGlazingComboBox_currentIndexChanged(int index);

    void on_rightWindowGlazingComboBox_currentIndexChanged(int index);

    void on_leftWindowGlazingComboBox_currentIndexChanged(int index);

    void on_frontWindowBulkToningSqareComboBox_currentIndexChanged(int index);

    void on_frontWindowBulkToningComboBox_currentIndexChanged(int index);

    void on_rightWindowBulkToningSqareComboBox_currentIndexChanged(int index);

    void on_rightWindowBulkToningComboBox_currentIndexChanged(int index);

    void on_leftWindowBulkToningSqareComboBox_currentIndexChanged(int index);

    void on_leftWindowBulkToningComboBox_currentIndexChanged(int index);

    void on_frontWindowToningComboBox_currentIndexChanged(int index);

    void on_rightWindowToningComboBox_currentIndexChanged(int index);

    void on_leftWindowToningComboBox_currentIndexChanged(int index);

    void on_frontWindowMosquitoNetComboBox_currentIndexChanged(int index);

    void on_rightWindowMosquitoNetComboBox_currentIndexChanged(int index);

    void on_leftWindowMosquitoNetComboBox_currentIndexChanged(int index);

    void on_frontWindowTriplexSquareComboBox_currentIndexChanged(int index);

    void on_frontWindowTriplexComboBox_currentIndexChanged(int index);

    void on_rightWindowTriplexSquareComboBox_currentIndexChanged(int index);

    void on_rightWindowTriplexComboBox_currentIndexChanged(int index);

    void on_leftWindowTriplexSquareComboBox_currentIndexChanged(int index);

    void on_leftWindowTriplexComboBox_currentIndexChanged(int index);

    void on_frontWindowHandlesComboBox_currentIndexChanged(int index);

    void on_rightWindowHandlesComboBox_currentIndexChanged(int index);

    void on_leftWindowHandlesComboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::CalculatorWindow *ui;
    std::unique_ptr<IDbAccessor> db = std::make_unique<FilesystemDbAccessor>();
    std::unique_ptr<Calculator> calculator = std::make_unique<Calculator>(
          "Calculator",
          "calculator"
    );
    std::unique_ptr<WindowGroup> window_group;
    std::unique_ptr<BalconyGroup> balcony_group;

    void setComboBoxParameters(QComboBox& comboBox, const std::map<std::string, price, std::less<>>& parameters);
};

#endif // CALCULATORWINDOW_H
