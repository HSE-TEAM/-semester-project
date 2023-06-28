#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"
#include <iostream>
#include <string>


CalculatorWindow::CalculatorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalculatorWindow)
{
    ui->setupUi(this);
    db->Open("calculator/data/csv_db");
    std::unique_ptr<Window> window;
    std::unique_ptr<SquareMultiplyEnumerableParameter> profile;
    std::unique_ptr<JustMultiplyEnumerableParameter> number_of_open_flaps;
    std::unique_ptr<SquareMultiplyEnumerableParameter> painting_lamination;
    std::unique_ptr<SquareMultiplyEnumerableParameter> double_glazing;
    std::unique_ptr<BottomSquareMultiplyEnumerableParameter> tinting_bottom;
    std::unique_ptr<TopSquareMultiplyEnumerableParameter> tinting_top;
    std::unique_ptr<BottomSquareMultiplyEnumerableParameter> tinting_in_mass_bottom;
    std::unique_ptr<TopSquareMultiplyEnumerableParameter> tinting_in_mass_top;
    std::unique_ptr<JustMultiplyEnumerableParameter> mosquito_net;
    std::unique_ptr<TopSquareMultiplyEnumerableParameter> triplex_top;
    std::unique_ptr<BottomSquareMultiplyEnumerableParameter> triplex_bottom;
    std::unique_ptr<SquareMeterPriceSingleParameter> product_assembly;
    std::unique_ptr<HandlesEnumerableParameter> handles;
    window_group = std::make_unique<WindowGroup>(
                "Window group",
                "window_group"
    );
    window = std::make_unique<Window>(
                "Front window",
                "front_window",
                true,
                12,
                window_group.get()
    );
    profile = std::make_unique<SquareMultiplyEnumerableParameter>(
                "Profile",
                "profile",
                std::make_unique<EnumerableValue>(
                    db->DataSheetHandler("profile")
                ),
                window.get(),
                "Grazio"
    );

    window_group->SetBottomRowHeight(0);
    window_group->SetTopRowHeight(0);
    window->SetWidth(0);
    setComboBoxParameters(*(ui->frontWindowProfileComboBox), profile->Enumeration());
    setComboBoxParameters(*(ui->rightWindowProfileComboBox), profile->Enumeration());
    setComboBoxParameters(*(ui->leftWindowProfileComboBox), profile->Enumeration());
    number_of_open_flaps = std::make_unique<JustMultiplyEnumerableParameter>(
                "Number of open flaps",
                "number_of_open_flaps",
                std::make_unique<SingleValue>(
                    db->DataSheetHandler("num_of_open_flaps")
                ),
                "0"
                );
    painting_lamination = std::make_unique<SquareMultiplyEnumerableParameter>(
                "Painting laminating",
                "painting_laminating",
                std::make_unique<EnumerableValue>(
                    db->DataSheetHandler("painting_laminating")
                ),
                window.get(),
                "Bel/Bel"
                );
    setComboBoxParameters(*(ui->frontWindowLaminationComboBox), painting_lamination->Enumeration());
    setComboBoxParameters(*(ui->rightWindowLaminationComboBox), painting_lamination->Enumeration());
    setComboBoxParameters(*(ui->leftWindowLaminationComboBox), painting_lamination->Enumeration());
    double_glazing = std::make_unique<SquareMultiplyEnumerableParameter>(
                "Double glazing",
                "double_glazing",
                std::make_unique<EnumerableValue>(
                    db->DataSheetHandler("double_glazing")
                ),
                window.get(),
                "12"
                );
    setComboBoxParameters(*(ui->frontWindowGlazingComboBox), double_glazing->Enumeration());
    setComboBoxParameters(*(ui->rightWindowGlazingComboBox), double_glazing->Enumeration());
    setComboBoxParameters(*(ui->leftWindowGlazingComboBox), double_glazing->Enumeration());
    tinting_bottom = std::make_unique<BottomSquareMultiplyEnumerableParameter>(
                "Tinting bottom",
                "tinting_bottom",
                std::make_unique<EnumerableValue>(
                    db->DataSheetHandler("tinting")
                ),
                window.get(),
                "no"
            );
    tinting_top = std::make_unique<TopSquareMultiplyEnumerableParameter>(
                "Tinting top",
                "tinting_top",
                std::make_unique<EnumerableValue>(
                    db->DataSheetHandler("tinting")
                ),
                window.get(),
                "no"
            );
    tinting_in_mass_bottom = std::make_unique<BottomSquareMultiplyEnumerableParameter>(
                "Tinting in mass bottom",
                "tinting_in_mass_bottom",
                std::make_unique<EnumerableValue>(
                    db->DataSheetHandler("tinting_in_mass")
                ),
                window.get(),
                "No"
            );
    tinting_in_mass_top = std::make_unique<TopSquareMultiplyEnumerableParameter>(
                "Tinting in mass top",
                "tinting_in_mass_top",
                std::make_unique<EnumerableValue>(
                    db->DataSheetHandler("tinting_in_mass")
                ),
                window.get(),
                "No"
            );
    setComboBoxParameters(*(ui->frontWindowBulkToningComboBox), tinting_in_mass_bottom->Enumeration());
    setComboBoxParameters(*(ui->rightWindowBulkToningComboBox), tinting_in_mass_bottom->Enumeration());
    setComboBoxParameters(*(ui->leftWindowBulkToningComboBox), tinting_in_mass_bottom->Enumeration());
    mosquito_net = std::make_unique<JustMultiplyEnumerableParameter>(
                "Mosquito net",
                "mosquito_net",
                std::make_unique<SingleValue>(
                    db->DataSheetHandler("mosquito_net")
                ),
                "0"
    );
    triplex_bottom = std::make_unique<BottomSquareMultiplyEnumerableParameter>(
                "Triplex bottom",
                "triplex_bottom",
                std::make_unique<EnumerableValue>(
                    db->DataSheetHandler("triplex")
                ),
                window.get(),
                "no"
            );
    triplex_top = std::make_unique<TopSquareMultiplyEnumerableParameter>(
                "Triplex top",
                "triplex_top",
                std::make_unique<EnumerableValue>(
                    db->DataSheetHandler("triplex")
                ),
                window.get(),
                "no"
            );
    setComboBoxParameters(*(ui->frontWindowTriplexComboBox), triplex_bottom->Enumeration());
    setComboBoxParameters(*(ui->rightWindowTriplexComboBox), triplex_bottom->Enumeration());
    setComboBoxParameters(*(ui->leftWindowTriplexComboBox), triplex_bottom->Enumeration());
    product_assembly = std::make_unique<SquareMeterPriceSingleParameter>(
                "Product assembly",
                "product_assembly",
                std::make_unique<SingleValue>(
                    db->DataSheetHandler("product_assembly")
                ),
                window.get()
    );
    handles = std::make_unique<HandlesEnumerableParameter>(
                "Handles",
                "handles",
                std::make_unique<EnumerableValue>(
                    db->DataSheetHandler("handles")
                ),
                window.get(),
                "10"
            );
    setComboBoxParameters(*(ui->frontWindowHandlesComboBox), handles->Enumeration());
    setComboBoxParameters(*(ui->rightWindowHandlesComboBox), handles->Enumeration());
    setComboBoxParameters(*(ui->leftWindowHandlesComboBox), handles->Enumeration());
    window_group->AddParameter(std::move(profile));
      window_group->AddParameter(std::move(painting_lamination));
      window_group->AddParameter(std::move(double_glazing));
      window_group->AddParameter(std::move(tinting_bottom));
      window_group->AddParameter(std::move(tinting_top));
      window_group->AddParameter(std::move(tinting_in_mass_bottom));
      window_group->AddParameter(std::move(tinting_in_mass_top));
      window_group->AddParameter(std::move(triplex_bottom));
      window_group->AddParameter(std::move(triplex_top));
      window_group->AddParameter(std::move(product_assembly));
      window->AddParameter(std::move(number_of_open_flaps));
      window->AddParameter(std::move(handles));
      window->AddParameter(std::move(mosquito_net));
      auto window_clone = window->Clone();
      std::unique_ptr<Window> left_window(dynamic_cast<Window*>(window_clone.release()));
      left_window->SetName("Left window");
      left_window->SetId("left_window");

      auto window_clone2 = window->Clone();
      std::unique_ptr<Window> right_window(dynamic_cast<Window*>(window_clone2.release()));
      right_window->SetName("Right window");
      right_window->SetId("right_window");

    window_group->AddWindow(std::move(window));
    window_group->AddWindow(std::move(left_window));
    window_group->AddWindow(std::move(right_window));
    setComboBoxParameters(*(ui->frontWindowProfileComboBox), dynamic_cast<SquareMultiplyEnumerableParameter*>(window_group->GetParameter("profile"))->Enumeration());
    setComboBoxParameters(*(ui->rightWindowProfileComboBox), dynamic_cast<SquareMultiplyEnumerableParameter*>(window_group->GetParameter("profile"))->Enumeration());
    setComboBoxParameters(*(ui->leftWindowProfileComboBox), dynamic_cast<SquareMultiplyEnumerableParameter*>(window_group->GetParameter("profile"))->Enumeration());
    balcony_group = std::make_unique<BalconyGroup>(
                  "Balcony group",
                  "balcony_group"
                  );
    auto ceiling = std::make_unique<BalconyParameterHolder>(
          "Ceiling",
          "ceiling"
      );

    ceiling->SetWidth(0);
    ceiling->SetHeight(0);
    auto ceiling_material = std::make_unique<CountableSquareMultiplyEnumerableParameter>(
          "Ceiling material",
          "ceiling_material",
          std::make_unique<EnumerableValue>(
              db->DataSheetHandler("ceiling_material")
          ),
          ceiling.get(),
          "Stretched"
      );
    ceiling_material->SetIsCounted(true);
    setComboBoxParameters(*(ui->ceilingMaterialComboBox), ceiling_material->Enumeration());
    auto insulation = std::make_unique<SquareMultiplyEnumerableParameter>(
           "Insulation",
           "insulation",
           std::make_unique<EnumerableValue>(
               db->DataSheetHandler("insulation")
           ),
           ceiling.get(),
           "20"
       );

    auto steam_insulation = std::make_unique<SquareMeterPriceSingleParameter>(
          "Steam insulation",
          "steam_insulation",
          std::make_unique<SingleValue>(
              db->DataSheetHandler("steam_insulation")
          ),
          ceiling.get()
      );

      ceiling->AddParameter(std::move(ceiling_material));
      ceiling->AddParameter(std::move(insulation));
      ceiling->AddParameter(std::move(steam_insulation));

      balcony_group->AddParameterHolder(std::move(ceiling));



}

CalculatorWindow::~CalculatorWindow()
{
    delete ui;
}

void CalculatorWindow::setComboBoxParameters(QComboBox& comboBox, const std::map<std::string, price, std::less<>>& parameters){
    comboBox.blockSignals(true);
    for (const auto& parameter : parameters){
        comboBox.addItem(QString::fromStdString(parameter.first));
    }
    comboBox.blockSignals(false);
}

void CalculatorWindow::on_frontWindowUpperRowLineEdit_editingFinished()
{
    window_group->SetTopRowHeight(ui->frontWindowUpperRowLineEdit->text().toDouble() / 1e3);
    ui->rightWindowUpperRowLineEdit->setText(ui->frontWindowUpperRowLineEdit->text());
    ui->leftWindowUpperRowLineEdit->setText(ui->frontWindowUpperRowLineEdit->text());
    ui->frontWindowSquareLabel->setText(QString::number(window_group->Windows()[0]->Square()));
    ui->leftWindowSquareLabel->setText(QString::number(window_group->Windows()[1]->Square()));
    ui->rightWindowSquareLabel->setText(QString::number(window_group->Windows()[2]->Square()));
    ui->frontWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->leftWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->rightWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->frontWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->leftWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->rightWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->frontWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->rightWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->leftWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->frontWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->leftWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->rightWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->frontWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->rightWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->leftWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->frontWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->rightWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->leftWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
}

void CalculatorWindow::on_rightWindowUpperRowLineEdit_editingFinished()
{
    window_group->SetTopRowHeight(ui->rightWindowUpperRowLineEdit->text().toDouble() / 1e3);
    ui->frontWindowUpperRowLineEdit->setText(ui->rightWindowUpperRowLineEdit->text());
    ui->leftWindowUpperRowLineEdit->setText(ui->rightWindowUpperRowLineEdit->text());
    ui->frontWindowSquareLabel->setText(QString::number(window_group->Windows()[0]->Square()));
    ui->leftWindowSquareLabel->setText(QString::number(window_group->Windows()[1]->Square()));
    ui->rightWindowSquareLabel->setText(QString::number(window_group->Windows()[2]->Square()));
    ui->frontWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->leftWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->rightWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->frontWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->leftWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->rightWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->frontWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->rightWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->leftWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->frontWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->leftWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->rightWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->frontWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->rightWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->leftWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->frontWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->rightWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->leftWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
}




void CalculatorWindow::on_leftWindowUpperRowLineEdit_editingFinished()
{
    window_group->SetTopRowHeight(ui->leftWindowUpperRowLineEdit->text().toDouble() / 1e3);
    ui->frontWindowUpperRowLineEdit->setText(ui->leftWindowUpperRowLineEdit->text());
    ui->rightWindowUpperRowLineEdit->setText(ui->leftWindowUpperRowLineEdit->text());
    ui->frontWindowSquareLabel->setText(QString::number(window_group->Windows()[0]->Square()));
    ui->leftWindowSquareLabel->setText(QString::number(window_group->Windows()[1]->Square()));
    ui->rightWindowSquareLabel->setText(QString::number(window_group->Windows()[2]->Square()));
    ui->frontWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->leftWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->rightWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->frontWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->leftWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->rightWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->frontWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->rightWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->leftWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->frontWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->leftWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->rightWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->frontWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->rightWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->leftWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->frontWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->rightWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->leftWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
}



void CalculatorWindow::on_frontWindowLowerRowLineEdit_editingFinished()
{
    window_group->SetBottomRowHeight(ui->frontWindowLowerRowLineEdit->text().toDouble() / 1e3);
    ui->rightWindowLowerRowLineEdit->setText(ui->frontWindowLowerRowLineEdit->text());
    ui->leftWindowLowerRowLineEdit->setText(ui->frontWindowLowerRowLineEdit->text());
    ui->frontWindowSquareLabel->setText(QString::number(window_group->Windows()[0]->Square()));
    ui->leftWindowSquareLabel->setText(QString::number(window_group->Windows()[1]->Square()));
    ui->rightWindowSquareLabel->setText(QString::number(window_group->Windows()[2]->Square()));
    ui->frontWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->leftWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->rightWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->frontWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->leftWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->rightWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->frontWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->rightWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->leftWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->frontWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->leftWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->rightWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->frontWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->rightWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->leftWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->frontWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->rightWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->leftWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
}

void CalculatorWindow::on_rightWindowLowerRowLineEdit_editingFinished()
{
    window_group->SetBottomRowHeight(ui->rightWindowLowerRowLineEdit->text().toDouble() / 1e3);
    ui->frontWindowLowerRowLineEdit->setText(ui->rightWindowLowerRowLineEdit->text());
    ui->leftWindowLowerRowLineEdit->setText(ui->rightWindowLowerRowLineEdit->text());
    ui->frontWindowSquareLabel->setText(QString::number(window_group->Windows()[0]->Square()));
    ui->leftWindowSquareLabel->setText(QString::number(window_group->Windows()[1]->Square()));
    ui->rightWindowSquareLabel->setText(QString::number(window_group->Windows()[2]->Square()));
    ui->frontWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->leftWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->rightWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->frontWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->leftWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->rightWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->frontWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->rightWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->leftWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->frontWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->leftWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->rightWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->frontWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->rightWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->leftWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->frontWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->rightWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->leftWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));

}

void CalculatorWindow::on_leftWindowLowerRowLineEdit_editingFinished()
{
    window_group->SetBottomRowHeight(ui->leftWindowLowerRowLineEdit->text().toDouble() / 1e3);
    ui->frontWindowLowerRowLineEdit->setText(ui->leftWindowLowerRowLineEdit->text());
    ui->rightWindowLowerRowLineEdit->setText(ui->leftWindowLowerRowLineEdit->text());
    ui->frontWindowSquareLabel->setText(QString::number(window_group->Windows()[0]->Square()));
    ui->leftWindowSquareLabel->setText(QString::number(window_group->Windows()[1]->Square()));
    ui->rightWindowSquareLabel->setText(QString::number(window_group->Windows()[2]->Square()));
    ui->frontWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->leftWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->rightWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->frontWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->leftWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->rightWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->frontWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->rightWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->leftWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->frontWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->leftWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->rightWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->frontWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->rightWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->leftWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->frontWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->rightWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->leftWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
}



void CalculatorWindow::on_frontWindowWidthLineEdit_editingFinished()
{
    window_group->Windows()[0]->SetWidth(ui->frontWindowWidthLineEdit->text().toDouble() / 1e3);
    ui->frontWindowSquareLabel->setText(QString::number(window_group->Windows()[0]->Square()));
    ui->frontWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->frontWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->frontWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->frontWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->frontWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->frontWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->rightWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->leftWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
}


void CalculatorWindow::on_rightWindowWidthLineEdit_editingFinished()
{
    window_group->Windows()[2]->SetWidth(ui->rightWindowWidthLineEdit->text().toDouble() / 1e3);
    ui->rightWindowSquareLabel->setText(QString::number(window_group->Windows()[1]->Square()));
    ui->rightWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->rightWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->rightWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->rightWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->rightWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->frontWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->rightWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->leftWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
}




void CalculatorWindow::on_leftWindowWidthLineEdit_editingFinished()
{
    window_group->Windows()[1]->SetWidth(ui->leftWindowWidthLineEdit->text().toDouble() / 1e3);
    ui->leftWindowSquareLabel->setText(QString::number(window_group->Windows()[2]->Square()));
    ui->leftWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->leftWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->leftWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_bottom")->Cost() + window_group->GetParameter("tinting_top")->Cost()));
    ui->leftWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_bottom")->Cost()+ window_group->GetParameter("tinting_in_mass_top")->Cost()));
    ui->leftWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->frontWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->rightWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
    ui->leftWindowWorkPriceLabel->setText(QString::number(window_group->GetParameter("product_assembly")->Cost()));
}

void CalculatorWindow::on_frontWindowProfileComboBox_currentIndexChanged(int index)
{
      ui->leftWindowProfileComboBox->setCurrentIndex(index);
      ui->rightWindowProfileComboBox->setCurrentIndex(index);
      window_group->GetParameter("profile")->SetValue(ui->frontWindowProfileComboBox->currentText().toStdString());
      ui->frontWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
      ui->leftWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
      ui->rightWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
}

void CalculatorWindow::on_rightWindowProfileComboBox_currentIndexChanged(int index)
{
    ui->leftWindowProfileComboBox->setCurrentIndex(index);
    ui->frontWindowProfileComboBox->setCurrentIndex(index);
    window_group->GetParameter("profile")->SetValue(ui->rightWindowProfileComboBox->currentText().toStdString());
    ui->frontWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->leftWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->rightWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
}

void CalculatorWindow::on_leftWindowProfileComboBox_currentIndexChanged(int index)
{
    ui->rightWindowProfileComboBox->setCurrentIndex(index);
    ui->frontWindowProfileComboBox->setCurrentIndex(index);
    window_group->GetParameter("profile")->SetValue(ui->leftWindowProfileComboBox->currentText().toStdString());
    ui->frontWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->leftWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
    ui->rightWindowProfilePriceLabel->setText(QString::number(window_group->GetParameter("profile")->Cost()));
}


void CalculatorWindow::on_frontWindowNumberOfOpeningsComboBox_currentIndexChanged(int index)
{
    window_group->Windows()[0]->GetParameter("number_of_open_flaps")->SetValue(ui->frontWindowNumberOfOpeningsComboBox->currentText().toStdString());
    ui->frontWindowNumberOfOpeningsPriceLabel->setText(QString::number(window_group->Windows()[0]->GetParameter("number_of_open_flaps")->Cost()));
}




void CalculatorWindow::on_rightWindowNumberOfOpeningsComboBox_currentIndexChanged(int index)
{
    window_group->Windows()[2]->GetParameter("number_of_open_flaps")->SetValue(ui->rightWindowNumberOfOpeningsComboBox->currentText().toStdString());
    ui->rightWindowNumberOfOpeningsPriceLabel->setText(QString::number(window_group->Windows()[2]->GetParameter("number_of_open_flaps")->Cost()));
}


void CalculatorWindow::on_leftWindowNumberOfOpeningsComboBox_currentIndexChanged(int index)
{
    window_group->Windows()[1]->GetParameter("number_of_open_flaps")->SetValue(ui->leftWindowNumberOfOpeningsComboBox->currentText().toStdString());
    ui->leftWindowNumberOfOpeningsPriceLabel->setText(QString::number(window_group->Windows()[1]->GetParameter("number_of_open_flaps")->Cost()));
}


void CalculatorWindow::on_frontWindowLaminationComboBox_currentIndexChanged(int index)
{
    ui->rightWindowLaminationComboBox->setCurrentIndex(index);
    ui->leftWindowLaminationComboBox->setCurrentIndex(index);
    window_group->GetParameter("painting_laminating")->SetValue(ui->frontWindowLaminationComboBox->currentText().toStdString());
    ui->frontWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->leftWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->rightWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
}





void CalculatorWindow::on_rightWindowLaminationComboBox_currentIndexChanged(int index)
{
    ui->leftWindowLaminationComboBox->setCurrentIndex(index);
    ui->frontWindowLaminationComboBox->setCurrentIndex(index);
    window_group->GetParameter("painting_laminating")->SetValue(ui->rightWindowLaminationComboBox->currentText().toStdString());
    ui->frontWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->leftWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->rightWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
}




void CalculatorWindow::on_leftWindowLaminationComboBox_currentIndexChanged(int index)
{
    ui->rightWindowLaminationComboBox->setCurrentIndex(index);
    ui->frontWindowLaminationComboBox->setCurrentIndex(index);
    window_group->GetParameter("painting_laminating")->SetValue(ui->leftWindowLaminationComboBox->currentText().toStdString());
    ui->frontWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->leftWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
    ui->rightWindowLaminationPriceLabel->setText(QString::number(window_group->GetParameter("painting_laminating")->Cost()));
}

void CalculatorWindow::on_frontWindowGlazingComboBox_currentIndexChanged(int index)
{
    ui->rightWindowGlazingComboBox->setCurrentIndex(index);
    ui->leftWindowGlazingComboBox->setCurrentIndex(index);
    window_group->GetParameter("double_glazing")->SetValue(ui->frontWindowGlazingComboBox->currentText().toStdString());
    ui->frontWindowGlazingLabel->setText(QString::number(window_group->GetParameter("double_glazing")->Cost()));
    ui->leftWindowGlazingLabel->setText(QString::number(window_group->GetParameter("double_glazing")->Cost()));
    ui->rightWindowGlazingLabel->setText(QString::number(window_group->GetParameter("double_glazing")->Cost()));
}




void CalculatorWindow::on_rightWindowGlazingComboBox_currentIndexChanged(int index)
{
    ui->frontWindowGlazingComboBox->setCurrentIndex(index);
    ui->leftWindowGlazingComboBox->setCurrentIndex(index);
    window_group->GetParameter("double_glazing")->SetValue(ui->rightWindowGlazingComboBox->currentText().toStdString());
    ui->frontWindowGlazingLabel->setText(QString::number(window_group->GetParameter("double_glazing")->Cost()));
    ui->leftWindowGlazingLabel->setText(QString::number(window_group->GetParameter("double_glazing")->Cost()));
    ui->rightWindowGlazingLabel->setText(QString::number(window_group->GetParameter("double_glazing")->Cost()));
}




void CalculatorWindow::on_leftWindowGlazingComboBox_currentIndexChanged(int index)
{
    ui->rightWindowGlazingComboBox->setCurrentIndex(index);
    ui->frontWindowGlazingComboBox->setCurrentIndex(index);
    window_group->GetParameter("double_glazing")->SetValue(ui->leftWindowGlazingComboBox->currentText().toStdString());
    ui->frontWindowGlazingLabel->setText(QString::number(window_group->GetParameter("double_glazing")->Cost()));
    ui->leftWindowGlazingLabel->setText(QString::number(window_group->GetParameter("double_glazing")->Cost()));
    ui->rightWindowGlazingLabel->setText(QString::number(window_group->GetParameter("double_glazing")->Cost()));
}




void CalculatorWindow::on_frontWindowBulkToningSqareComboBox_currentIndexChanged(int index)
{
    if(index == 0){
        window_group->GetParameter("tinting_in_mass_top")->SetValue("No");
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue("No");
    } else if (index == 1){
        window_group->GetParameter("tinting_in_mass_top")->SetValue(ui->frontWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue("No");
    } else if (index == 2){
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue(ui->frontWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_top")->SetValue("No");
    } else {
        window_group->GetParameter("tinting_in_mass_top")->SetValue(ui->frontWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue(ui->frontWindowBulkToningComboBox->currentText().toStdString());
    }
    ui->rightWindowBulkToningSqareComboBox->setCurrentIndex(index);
    ui->leftWindowBulkToningSqareComboBox->setCurrentIndex(index);
    ui->frontWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
    ui->leftWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
    ui->rightWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
}



void CalculatorWindow::on_frontWindowBulkToningComboBox_currentIndexChanged(int index)
{
    if(ui->frontWindowBulkToningSqareComboBox->currentIndex() == 1){
        window_group->GetParameter("tinting_in_mass_top")->SetValue(ui->frontWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue("No");
    } else if(ui->frontWindowBulkToningSqareComboBox->currentIndex() == 2){
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue(ui->frontWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_top")->SetValue("No");
    } else if(ui->frontWindowBulkToningSqareComboBox->currentIndex() == 3){
        window_group->GetParameter("tinting_in_mass_top")->SetValue(ui->frontWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue(ui->frontWindowBulkToningComboBox->currentText().toStdString());
    }
    ui->rightWindowBulkToningComboBox->setCurrentIndex(index);
    ui->leftWindowBulkToningComboBox->setCurrentIndex(index);
    ui->frontWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
    ui->leftWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
    ui->rightWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
}




void CalculatorWindow::on_rightWindowBulkToningSqareComboBox_currentIndexChanged(int index)
{
    if(index == 0){
        window_group->GetParameter("tinting_in_mass_top")->SetValue("No");
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue("No");
    } else if (index == 1){
        window_group->GetParameter("tinting_in_mass_top")->SetValue(ui->frontWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue("No");
    } else if (index == 2){
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue(ui->frontWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_top")->SetValue("No");
    } else {
        window_group->GetParameter("tinting_in_mass_top")->SetValue(ui->frontWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue(ui->frontWindowBulkToningComboBox->currentText().toStdString());
    }
    ui->frontWindowBulkToningSqareComboBox->setCurrentIndex(index);
    ui->leftWindowBulkToningSqareComboBox->setCurrentIndex(index);
    ui->frontWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
    ui->leftWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
    ui->rightWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
}




void CalculatorWindow::on_rightWindowBulkToningComboBox_currentIndexChanged(int index)
{
    if(ui->frontWindowBulkToningSqareComboBox->currentIndex() == 1){
        window_group->GetParameter("tinting_in_mass_top")->SetValue(ui->rightWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue("No");
    } else if(ui->frontWindowBulkToningSqareComboBox->currentIndex() == 2){
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue(ui->rightWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_top")->SetValue("No");
    } else if(ui->frontWindowBulkToningSqareComboBox->currentIndex() == 3){
        window_group->GetParameter("tinting_in_mass_top")->SetValue(ui->rightWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue(ui->rightWindowBulkToningComboBox->currentText().toStdString());
    }
    ui->frontWindowBulkToningComboBox->setCurrentIndex(index);
    ui->leftWindowBulkToningComboBox->setCurrentIndex(index);
    ui->frontWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
    ui->leftWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
    ui->rightWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
}




void CalculatorWindow::on_leftWindowBulkToningSqareComboBox_currentIndexChanged(int index)
{
    ui->frontWindowBulkToningSqareComboBox->setCurrentIndex(index);
    ui->rightWindowBulkToningSqareComboBox->setCurrentIndex(index);
    if(index == 0){
        window_group->GetParameter("tinting_in_mass_top")->SetValue("No");
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue("No");
    } else if (index == 1){
        window_group->GetParameter("tinting_in_mass_top")->SetValue(ui->frontWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue("No");
    } else if (index == 2){
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue(ui->frontWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_top")->SetValue("No");
    } else {
        window_group->GetParameter("tinting_in_mass_top")->SetValue(ui->frontWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue(ui->frontWindowBulkToningComboBox->currentText().toStdString());
    }
    ui->frontWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
    ui->leftWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
    ui->rightWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
}




void CalculatorWindow::on_leftWindowBulkToningComboBox_currentIndexChanged(int index)
{
    ui->rightWindowBulkToningComboBox->setCurrentIndex(index);
    ui->leftWindowBulkToningComboBox->setCurrentIndex(index);
    if(ui->frontWindowBulkToningSqareComboBox->currentIndex() == 1){
        window_group->GetParameter("tinting_in_mass_top")->SetValue(ui->rightWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue("No");
    } else if(ui->frontWindowBulkToningSqareComboBox->currentIndex() == 2){
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue(ui->rightWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_top")->SetValue("No");
    } else if(ui->frontWindowBulkToningSqareComboBox->currentIndex() == 3){
        window_group->GetParameter("tinting_in_mass_top")->SetValue(ui->rightWindowBulkToningComboBox->currentText().toStdString());
        window_group->GetParameter("tinting_in_mass_bottom")->SetValue(ui->rightWindowBulkToningComboBox->currentText().toStdString());
    }
    ui->frontWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
    ui->leftWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
    ui->rightWindowBulkToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_in_mass_top")->Cost() + window_group->GetParameter("tinting_in_mass_bottom")->Cost()));
}




void CalculatorWindow::on_frontWindowToningComboBox_currentIndexChanged(int index)
{
    ui->leftWindowToningComboBox->setCurrentIndex(index);
    ui->rightWindowToningComboBox->setCurrentIndex(index);
    if(index == 0){
        window_group->GetParameter("tinting_top")->SetValue("no");
        window_group->GetParameter("tinting_bottom")->SetValue("no");
    } else if (index == 1){
        window_group->GetParameter("tinting_top")->SetValue("yes");
        window_group->GetParameter("tinting_bottom")->SetValue("no");
    } else if (index == 2){
        window_group->GetParameter("tinting_bottom")->SetValue("yes");
        window_group->GetParameter("tinting_top")->SetValue("no");
    } else {
        window_group->GetParameter("tinting_top")->SetValue("yes");
        window_group->GetParameter("tinting_bottom")->SetValue("yes");
    }
    ui->frontWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_top")->Cost() + window_group->GetParameter("tinting_bottom")->Cost()));
    ui->leftWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_top")->Cost() + window_group->GetParameter("tinting_bottom")->Cost()));
    ui->rightWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_top")->Cost() + window_group->GetParameter("tinting_bottom")->Cost()));
}




void CalculatorWindow::on_rightWindowToningComboBox_currentIndexChanged(int index)
{
    ui->leftWindowToningComboBox->setCurrentIndex(index);
    ui->frontWindowToningComboBox->setCurrentIndex(index);
    if(index == 0){
        window_group->GetParameter("tinting_top")->SetValue("no");
        window_group->GetParameter("tinting_bottom")->SetValue("no");
    } else if (index == 1){
        window_group->GetParameter("tinting_top")->SetValue("yes");
        window_group->GetParameter("tinting_bottom")->SetValue("no");
    } else if (index == 2){
        window_group->GetParameter("tinting_bottom")->SetValue("yes");
        window_group->GetParameter("tinting_top")->SetValue("no");
    } else {
        window_group->GetParameter("tinting_top")->SetValue("yes");
        window_group->GetParameter("tinting_bottom")->SetValue("yes");
    }
    ui->frontWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_top")->Cost() + window_group->GetParameter("tinting_bottom")->Cost()));
    ui->leftWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_top")->Cost() + window_group->GetParameter("tinting_bottom")->Cost()));
    ui->rightWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_top")->Cost() + window_group->GetParameter("tinting_bottom")->Cost()));
}




void CalculatorWindow::on_leftWindowToningComboBox_currentIndexChanged(int index)
{
    ui->frontWindowToningComboBox->setCurrentIndex(index);
    ui->rightWindowToningComboBox->setCurrentIndex(index);
    if(index == 0){
        window_group->GetParameter("tinting_top")->SetValue("no");
        window_group->GetParameter("tinting_bottom")->SetValue("no");
    } else if (index == 1){
        window_group->GetParameter("tinting_top")->SetValue("yes");
        window_group->GetParameter("tinting_bottom")->SetValue("no");
    } else if (index == 2){
        window_group->GetParameter("tinting_bottom")->SetValue("yes");
        window_group->GetParameter("tinting_top")->SetValue("no");
    } else {
        window_group->GetParameter("tinting_top")->SetValue("yes");
        window_group->GetParameter("tinting_bottom")->SetValue("yes");
    }
    ui->frontWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_top")->Cost() + window_group->GetParameter("tinting_bottom")->Cost()));
    ui->leftWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_top")->Cost() + window_group->GetParameter("tinting_bottom")->Cost()));
    ui->rightWindowToningPriceLabel->setText(QString::number(window_group->GetParameter("tinting_top")->Cost() + window_group->GetParameter("tinting_bottom")->Cost()));
}




void CalculatorWindow::on_frontWindowMosquitoNetComboBox_currentIndexChanged(int index)
{
    window_group->Windows()[0]->GetParameter("mosquito_net")->SetValue(ui->frontWindowMosquitoNetComboBox->currentText().toStdString());
    ui->frontWindowMosquitoNetPriceLabel->setText(QString::number(window_group->Windows()[0]->GetParameter("mosquito_net")->Cost()));
}


void CalculatorWindow::on_rightWindowMosquitoNetComboBox_currentIndexChanged(int index)
{
    window_group->Windows()[2]->GetParameter("mosquito_net")->SetValue(ui->rightWindowMosquitoNetComboBox->currentText().toStdString());
    ui->rightWindowMosquitoNetPriceLabel->setText(QString::number(window_group->Windows()[2]->GetParameter("mosquito_net")->Cost()));
}


void CalculatorWindow::on_leftWindowMosquitoNetComboBox_currentIndexChanged(int index)
{
    window_group->Windows()[1]->GetParameter("mosquito_net")->SetValue(ui->leftWindowMosquitoNetComboBox->currentText().toStdString());
    ui->leftWindowMosquitoNetPriceLabel->setText(QString::number(window_group->Windows()[1]->GetParameter("mosquito_net")->Cost()));
}




void CalculatorWindow::on_frontWindowTriplexSquareComboBox_currentIndexChanged(int index)
{
    if(index == 0){
        window_group->GetParameter("triplex_top")->SetValue("no");
        window_group->GetParameter("triplex_bottom")->SetValue("no");
    } else if (index == 1){
        window_group->GetParameter("triplex_top")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_bottom")->SetValue("no");
    } else if (index == 2){
        window_group->GetParameter("triplex_bottom")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_top")->SetValue("no");
    } else {
        window_group->GetParameter("triplex_top")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_bottom")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
    }
    ui->rightWindowTriplexSquareComboBox->setCurrentIndex(index);
    ui->leftWindowTriplexSquareComboBox->setCurrentIndex(index);
    ui->frontWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->leftWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->rightWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
}



void CalculatorWindow::on_frontWindowTriplexComboBox_currentIndexChanged(int index)
{
    ui->rightWindowTriplexComboBox->setCurrentIndex(index);
    ui->leftWindowTriplexComboBox->setCurrentIndex(index);
    if(ui->frontWindowTriplexSquareComboBox->currentIndex() == 0){
        window_group->GetParameter("triplex_top")->SetValue("no");
        window_group->GetParameter("triplex_bottom")->SetValue("no");
    } else if (ui->frontWindowTriplexSquareComboBox->currentIndex() == 1){
        window_group->GetParameter("triplex_top")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_bottom")->SetValue("no");
    } else if (ui->frontWindowTriplexSquareComboBox->currentIndex() == 2){
        window_group->GetParameter("triplex_bottom")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_top")->SetValue("no");
    } else {
        window_group->GetParameter("triplex_top")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_bottom")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
    }
    ui->frontWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->leftWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->rightWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
}


void CalculatorWindow::on_rightWindowTriplexSquareComboBox_currentIndexChanged(int index)
{
    if(index == 0){
        window_group->GetParameter("triplex_top")->SetValue("no");
        window_group->GetParameter("triplex_bottom")->SetValue("no");
    } else if (index == 1){
        window_group->GetParameter("triplex_top")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_bottom")->SetValue("no");
    } else if (index == 2){
        window_group->GetParameter("triplex_bottom")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_top")->SetValue("no");
    } else {
        window_group->GetParameter("triplex_top")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_bottom")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
    }
    ui->frontWindowTriplexSquareComboBox->setCurrentIndex(index);
    ui->leftWindowTriplexSquareComboBox->setCurrentIndex(index);
    ui->frontWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->leftWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->rightWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
}




void CalculatorWindow::on_rightWindowTriplexComboBox_currentIndexChanged(int index)
{
    ui->frontWindowTriplexComboBox->setCurrentIndex(index);
    ui->leftWindowTriplexComboBox->setCurrentIndex(index);
    if(ui->frontWindowTriplexSquareComboBox->currentIndex() == 0){
        window_group->GetParameter("triplex_top")->SetValue("no");
        window_group->GetParameter("triplex_bottom")->SetValue("no");
    } else if (ui->frontWindowTriplexSquareComboBox->currentIndex() == 1){
        window_group->GetParameter("triplex_top")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_bottom")->SetValue("no");
    } else if (ui->frontWindowTriplexSquareComboBox->currentIndex() == 2){
        window_group->GetParameter("triplex_bottom")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_top")->SetValue("no");
    } else {
        window_group->GetParameter("triplex_top")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_bottom")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
    }
    ui->frontWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->leftWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->rightWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
}




void CalculatorWindow::on_leftWindowTriplexSquareComboBox_currentIndexChanged(int index)
{
    if(index == 0){
        window_group->GetParameter("triplex_top")->SetValue("no");
        window_group->GetParameter("triplex_bottom")->SetValue("no");
    } else if (index == 1){
        window_group->GetParameter("triplex_top")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_bottom")->SetValue("no");
    } else if (index == 2){
        window_group->GetParameter("triplex_bottom")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_top")->SetValue("no");
    } else {
        window_group->GetParameter("triplex_top")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_bottom")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
    }
    ui->frontWindowTriplexSquareComboBox->setCurrentIndex(index);
    ui->rightWindowTriplexSquareComboBox->setCurrentIndex(index);
    ui->frontWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->leftWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->rightWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
}


void CalculatorWindow::on_leftWindowTriplexComboBox_currentIndexChanged(int index)
{
    ui->frontWindowTriplexComboBox->setCurrentIndex(index);
    ui->rightWindowTriplexComboBox->setCurrentIndex(index);
    if(ui->frontWindowTriplexSquareComboBox->currentIndex() == 0){
        window_group->GetParameter("triplex_top")->SetValue("no");
        window_group->GetParameter("triplex_bottom")->SetValue("no");
    } else if (ui->frontWindowTriplexSquareComboBox->currentIndex() == 1){
        window_group->GetParameter("triplex_top")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_bottom")->SetValue("no");
    } else if (ui->frontWindowTriplexSquareComboBox->currentIndex() == 2){
        window_group->GetParameter("triplex_bottom")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_top")->SetValue("no");
    } else {
        window_group->GetParameter("triplex_top")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
        window_group->GetParameter("triplex_bottom")->SetValue(ui->frontWindowTriplexComboBox->currentText().toStdString());
    }
    ui->frontWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->leftWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    ui->rightWindowTriplexPriceLabel->setText(QString::number(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
}


void CalculatorWindow::on_frontWindowHandlesComboBox_currentIndexChanged(int index)
{
    window_group->Windows()[0]->GetParameter("handles")->SetValue(ui->frontWindowHandlesComboBox->currentText().toStdString());
    ui->frontWindowHandlesPriceComboBox->setText(QString::number(window_group->Windows()[0]->GetParameter("handles")->Cost()));
}




void CalculatorWindow::on_rightWindowHandlesComboBox_currentIndexChanged(int index)
{
    window_group->Windows()[2]->GetParameter("handles")->SetValue(ui->rightWindowHandlesComboBox->currentText().toStdString());
    ui->rightWindowHandlesPriceComboBox->setText(QString::number(window_group->Windows()[2]->GetParameter("handles")->Cost()));
}


void CalculatorWindow::on_leftWindowHandlesComboBox_currentIndexChanged(int index)
{
    window_group->Windows()[1]->GetParameter("handles")->SetValue(ui->leftWindowHandlesComboBox->currentText().toStdString());
    ui->leftWindowHandlesPriceComboBox->setText(QString::number(window_group->Windows()[1]->GetParameter("handles")->Cost()));
}



void CalculatorWindow::on_pushButton_clicked()
{
    auto parameter_holder = std::make_unique<document_creator::ParameterHolder>();
    parameter_holder->AddParameter("name", ui->nameLineEdit->text().toStdString());
    parameter_holder->AddParameter("surname", ui->surnameLineEdit->text().toStdString());
    parameter_holder->AddParameter("product_assembly", std::to_string(window_group->GetParameter("product_assembly")->Cost()));
    parameter_holder->AddParameter("triplex", std::to_string(window_group->GetParameter("triplex_top")->Cost() + window_group->GetParameter("triplex_bottom")->Cost()));
    parameter_holder->AddParameter("profile", std::to_string(window_group->GetParameter("profile")->Cost()));
    parameter_holder->AddParameter("painting_laminating", std::to_string(window_group->GetParameter("painting_laminating")->Cost()));
    parameter_holder->AddParameter("double_glazing", std::to_string(window_group->GetParameter("double_glazing")->Cost()));
    parameter_holder->AddParameter("toning", std::to_string(window_group->GetParameter("tinting_top")->Cost() + window_group->GetParameter("tinting_bottom")->Cost()));
    document_creator::TextReplacer text_replacer;
    text_replacer
        .SetExecutablePath("executable\\main.exe")
        .AddTemplateDirsPath("data/input_files")
        .SetOutputDirPath("data/output_files")
        .SetParameterHolder(std::move(parameter_holder))
        .SetId("user_1")
        .Replace();
    close();
}

