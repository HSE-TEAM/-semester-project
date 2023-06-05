#include <map>
#include <string>
#include <memory>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <windows.h>
#include "database/db_accessor/filesystem_db_accesor/filesystem_db_accesor.h"
#include "value_interfaces/parameter_interfaces/i_parameter_enumerable.h"
#include "window_group/window/parameters/enumerable_parameter/enumerable_parameter.h"
#include "window_group/window/parameters/enumerable_parameter/enumerable_value/enumerable_value.h"
#include "window_group/window/parameters/single_parameter/single_parameter.h"
#include "window_group/window/parameters/single_parameter/single_value/single_value.h"
#include "window_group/window/window.h"
#include "value_interfaces/value_visitor/i_value_visitor.h"
#include "window_group/window/glassy_object_visitor/i_glassy_object_visitor.h"
#include "window_group/window/glassy_object_visitor/concrete_visitors/glassy_object_printing_visitor/glassy_object_printing_visitor.h"
#include "window_group/window/parameters/concrete_parameters/glass_meter_price_single_parameter/glass_meter_price_single_parameter.h"
#include "window_group/window/parameters/concrete_parameters/bottom_square_multiply_enumerable_parameter/bottom_square_multiply_enumerable_parameter.h"
#include "window_group/window/parameters/concrete_parameters/top_square_multiply_enumerable_parameter/top_square_multiply_enumerable_parameter.h"
#include "window_group/window/parameters/concrete_parameters/just_multiply_enumerable_parameter/just_multiply_enumerable_parameter.h"
#include "window_group/window/parameters/concrete_parameters/square_multiply_enumerable_parameter/square_multiply_enumerable_parameter.h"
#include "window_group/window/parameters/concrete_parameters/handles_enumerable_parameter/handles_enumerable_parameter.h"
#include "utils/database/database_creator/filesystem_database_creator/filesystem_database_creator.h"

using namespace db;
using namespace calc;
using namespace utils;

int main() {

  std::cout.setf(std::ios::fixed);
  std::cout.precision(2);

  std::unique_ptr<IDBAccessor> db = std::make_unique<FilesystemDBAccessor>();
  db->Open("data/db");
  std::cout << db->Info() << std::endl;

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

  auto num_of_open_flaps = std::make_unique<JustMultiplyEnumerableParameter>(
      "Num of open flaps",
      "num_of_open_flaps",
      std::make_unique<SingleValue>(
          db->DataSheetHandler("num_of_open_flaps")
      ),
      "1"
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

  auto product_assembly = std::make_unique<GlassMeterPriceSingleParameter>(
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
      "Interika"
  );

  window_group->AddParameter(std::move(profile));
  window->AddParameter(std::move(num_of_open_flaps));
  window_group->AddParameter(std::move(painting_laminating));
  window_group->AddParameter(std::move(double_glazing));
  window_group->AddParameter(std::move(tinting_bottom));
  window_group->AddParameter(std::move(tinting_top));
  window_group->AddParameter(std::move(tinting_in_mass_bottom));
  window_group->AddParameter(std::move(tinting_in_mass_top));
  window->AddParameter(std::move(mosquito_net));
  window_group->AddParameter(std::move(triplex_bottom));
  window_group->AddParameter(std::move(triplex_top));
  window_group->AddParameter(std::move(product_assembly));
  window_group->AddParameter(std::move(handles));

  window_group->AddWindow(std::move(window));

  GlassyObjectPrintingVisitor visitor;
  window_group->Accept(visitor);

  return 0;
}

