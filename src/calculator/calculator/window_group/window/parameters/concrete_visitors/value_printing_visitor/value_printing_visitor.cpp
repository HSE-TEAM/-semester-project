#include "value_printing_visitor.h"

namespace calc {

void ValuePrintingVisitor::Visit(IParameter& parameter) {
  if (only_cost_) {
    std::cout << std::string(indent_, ' ')
              << "Parameter \"" << parameter.Name() << "\": " << parameter.Cost() << "\n";
    return;
  }
  std::cout << std::string(indent_, ' ')
            << "Parameter \"" << parameter.Name() << "\" (single):\n"
            << std::string(indent_ + indent_step_, ' ')
            << "id: " << parameter.Id() << "\n"
            << std::string(indent_ + indent_step_, ' ')
            << "value: " << parameter.Value() << "\n"
            << std::string(indent_ + indent_step_, ' ')
            << "cost: " << parameter.Cost() << "\n";
}

void ValuePrintingVisitor::Visit(IParameterEnumerable& parameter) {
  if (only_cost_) {
    std::cout << std::string(indent_, ' ')
              << "Parameter \"" << parameter.Name() << "\": " << parameter.Cost() << "\n";
    return;
  }
  std::cout << std::string(indent_, ' ')
            << "Parameter \"" << parameter.Name() << "\" (enumerable):\n"
            << std::string(indent_ + indent_step_, ' ')
            << "id: " << parameter.Id() << "\n"
            << std::string(indent_ + indent_step_, ' ')
            << "value: " << parameter.Value() << "\n"
            << std::string(indent_ + indent_step_, ' ')
            << "cost: " << parameter.Cost() << "\n"
            << std::string(indent_ + indent_step_, ' ')
            << "enumeration:\n";
  int i = 1;
  for (const auto& [kName, kCost] : parameter.Enumeration()) {
    std::cout << std::string(indent_ + indent_step_ * 2, ' ')
              << "entry " << i++ << ":\n"
              << std::string(indent_ + indent_step_ * 3, ' ')
              << "name: "
              << kName << "\n"
              << std::string(indent_ + indent_step_ * 3, ' ')
              << "cost: "
              << kCost << "\n";
  }
}

void ValuePrintingVisitor::PrintOnlyCost(const bool only_cost) {
  only_cost_ = only_cost;
}

} // calc
