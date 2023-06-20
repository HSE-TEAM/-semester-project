#include <map>
#include <string>
#include <memory>
#include <iostream>
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

using namespace db;
using namespace calc;

int main() {

  std::cout.setf(std::ios::fixed);
  std::cout.precision(2);

  std::unique_ptr<IDbAccessor> db = std::make_unique<FilesystemDbAccessor>();
  db->Open("data/csv_db");
  std::cout << db->Info() << std::endl;

  auto calculator = std::make_unique<Calculator>(
      "Calculator",
      "calculator"
  );

  auto window_group = std::make_unique<WindowGroup>(
      "Window group",
      "window_group"
  );

  window_group->SetBottomRowHeight(1480);
  window_group->SetTopRowHeight(1200);

  auto window = std::make_unique<Window>(
      "Front window",
      "front_window",
      true,
      12,
      window_group.get()
  );

  window->SetWidth(1000);

  auto profile = std::make_unique<SquareMultiplyEnumerableParameter>(
      "Profile",
      "profile",
      std::make_unique<EnumerableValue>(
          db->DataSheetHandler("profile")
      ),
      window.get(),
      "Grazio"
  );

  auto number_of_open_flaps = std::make_unique<JustMultiplyEnumerableParameter>(
      "Number of open flaps",
      "number_of_open_flaps",
      std::make_unique<SingleValue>(
          db->DataSheetHandler("num_of_open_flaps")
      ),
      "2"
  );

  auto painting_laminating = std::make_unique<SquareMultiplyEnumerableParameter>(
      "Painting laminating",
      "painting_laminating",
      std::make_unique<EnumerableValue>(
          db->DataSheetHandler("painting_laminating")
      ),
      window.get(),
      "Ral/Bel"
  );

  auto double_glazing = std::make_unique<SquareMultiplyEnumerableParameter>(
      "Double glazing",
      "double_glazing",
      std::make_unique<EnumerableValue>(
          db->DataSheetHandler("double_glazing")
      ),
      window.get(),
      "4*16*4"
  );

  auto tinting_bottom = std::make_unique<BottomSquareMultiplyEnumerableParameter>(
      "Tinting bottom",
      "tinting_bottom",
      std::make_unique<EnumerableValue>(
          db->DataSheetHandler("tinting")
      ),
      window.get(),
      "1"
  );

  auto tinting_top = std::make_unique<TopSquareMultiplyEnumerableParameter>(
      "Tinting top",
      "tinting_top",
      std::make_unique<EnumerableValue>(
          db->DataSheetHandler("tinting")
      ),
      window.get(),
      "1"
  );

  auto tinting_in_mass_bottom = std::make_unique<BottomSquareMultiplyEnumerableParameter>(
      "Tinting in mass bottom",
      "tinting_in_mass_bottom",
      std::make_unique<EnumerableValue>(
          db->DataSheetHandler("tinting_in_mass")
      ),
      window.get(),
      "StpPhnxClear"
  );

  auto tinting_in_mass_top = std::make_unique<TopSquareMultiplyEnumerableParameter>(
      "Tinting in mass top",
      "tinting_in_mass_top",
      std::make_unique<EnumerableValue>(
          db->DataSheetHandler("tinting_in_mass")
      ),
      window.get(),
      "StpPhnxGrey"
  );

  auto mosquito_net = std::make_unique<JustMultiplyEnumerableParameter>(
      "Mosquito net",
      "mosquito_net",
      std::make_unique<EnumerableValue>(
          db->DataSheetHandler("mosquito_net")
      ),
      "1"
  );

  auto triplex_bottom = std::make_unique<BottomSquareMultiplyEnumerableParameter>(
      "Triplex bottom",
      "triplex_bottom",
      std::make_unique<EnumerableValue>(
          db->DataSheetHandler("triplex")
      ),
      window.get(),
      "A1"
  );

  auto triplex_top = std::make_unique<TopSquareMultiplyEnumerableParameter>(
      "Triplex top",
      "triplex_top",
      std::make_unique<EnumerableValue>(
          db->DataSheetHandler("triplex")
      ),
      window.get(),
      "A1"
  );

  auto product_assembly = std::make_unique<SquareMeterPriceSingleParameter>(
      "Product assembly",
      "product_assembly",
      std::make_unique<SingleValue>(
          db->DataSheetHandler("product_assembly")
      ),
      window.get()
  );

  auto handles = std::make_unique<HandlesEnumerableParameter>(
      "Handles",
      "handles",
      std::make_unique<EnumerableValue>(
          db->DataSheetHandler("handles")
      ),
      window.get(),
      "10"
  );

  window_group->AddParameter(std::move(profile));
  window_group->AddParameter(std::move(painting_laminating));
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

  auto balcony_group = std::make_unique<BalconyGroup>(
      "Balcony group",
      "balcony_group"
  );

  auto ceiling = std::make_unique<BalconyParameterHolder>(
      "Ceiling",
      "ceiling"
  );

  ceiling->SetWidth(10);
  ceiling->SetHeight(10);

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

  calculator->AddBaseHolder(std::move(window_group));
  calculator->AddBaseHolder(std::move(balcony_group));

  BaseHolderPrintingVisitor visitor;
  visitor.PrintOnlyCost(true);
  calculator->Accept(visitor);
  visitor.ResetIndent();

  return 0;
}


