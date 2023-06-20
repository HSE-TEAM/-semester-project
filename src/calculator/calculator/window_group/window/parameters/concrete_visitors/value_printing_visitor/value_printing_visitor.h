#pragma once

#include <iostream>
#include <functional>
#include "calculator/value_interfaces/parameter_interfaces/i_parameter.h"
#include "calculator/value_interfaces/parameter_interfaces/i_parameter_enumerable.h"
#include "calculator/value_interfaces/value_visitor/i_value_visitor.h"

namespace calc {

class ValuePrintingVisitor : public IValueVisitor {
 public:
  explicit ValuePrintingVisitor(const int indent = 0,
                                const int indent_step = 4,
                                std::ostream& out = std::cout)
      : indent_(indent), indent_step_(indent_step), out_(out) {}

  void Visit(IParameter& parameter) override;
  void Visit(IParameterEnumerable& parameter) override;
  void Visit(IValue& value) override {}
  void Visit(IValueEnumerable& value) override {}

  void PrintOnlyCost(bool only_cost);

 private:
  int indent_;
  int indent_step_;
  std::reference_wrapper<std::ostream> out_;
  bool only_cost_ = false;
};

} // calc
