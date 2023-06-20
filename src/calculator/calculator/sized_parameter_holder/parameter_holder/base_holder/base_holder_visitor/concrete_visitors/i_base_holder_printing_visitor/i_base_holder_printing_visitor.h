#pragma once

#include "calculator/window_group/window/parameters/concrete_visitors/value_printing_visitor/value_printing_visitor.h"
#include "calculator/window_group/window/window.h"

namespace calc {

class BaseHolderPrintingVisitor : public IBaseHolderVisitor {
 public:
  explicit BaseHolderPrintingVisitor(int indent = 0, int indent_step = 4);

  void Visit(Calculator& calculator) override;

  void Visit(Window& window) override;

  void Visit(WindowGroup& window_group) override;

  void Visit(BalconyParameterHolder& balcony_parameter_holder) override;

  void Visit(ParameterHolder& param_holder) override;

  void Visit(BalconyGroup& balcony_group) override;

  void ResetIndent();
  void PrintOnlyCost(bool only_cost);

 private:
  int indent_;
  int indent_step_;
  ValuePrintingVisitor visitor_;
  bool only_cost_ = false;
};

} // calc
