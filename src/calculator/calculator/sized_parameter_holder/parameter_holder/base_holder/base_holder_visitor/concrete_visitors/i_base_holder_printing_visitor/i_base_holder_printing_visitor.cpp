#include "i_base_holder_printing_visitor.h"
#include "calculator/balcony_group/balcony_parameter_holder/balcony_parameter_holder.h"
#include "calculator/balcony_group/balcony_group.h"
#include "calculator/calculator.h"

namespace calc {
BaseHolderPrintingVisitor::BaseHolderPrintingVisitor(const int indent, const int indent_step)
    : indent_(indent), indent_step_(indent_step) {}

void BaseHolderPrintingVisitor::Visit(Calculator& calculator) {
  if (only_cost_) {
    std::cout << std::string(indent_, ' ')
              << "Calculator \"" << calculator.Name() << "\": " << calculator.Cost() << "\n";
  } else {
    std::cout << std::string(indent_, ' ')
              << "Calculator \"" << calculator.Name() << "\":\n"
              << std::string(indent_ + indent_step_, ' ')
              << "id: " << calculator.Id() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "cost: " << calculator.Cost() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "holders:\n";
  }
  if (calculator.BaseHolders().empty()) {
    std::cout << std::string(indent_ + indent_step_ * 2, ' ')
              << "none\n";
  } else {
    for (const auto& kParam : calculator.BaseHolders()) {
      kParam->Accept(*this);
    }
  }
}

void BaseHolderPrintingVisitor::Visit(WindowGroup& window_group) {
  if (only_cost_) {
    std::cout << std::string(indent_, ' ')
              << "Window Group \"" << window_group.Name() << "\": " << window_group.Cost() << "\n";
  } else {
    std::cout << std::string(indent_, ' ')
              << "Window Group \"" << window_group.Name() << "\":\n"
              << std::string(indent_ + indent_step_, ' ')
              << "id: " << window_group.Id() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "square: " << window_group.Square() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "height: " << window_group.Height() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "top row height: " << window_group.TopRowHeight() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "bottom row height: " << window_group.BottomRowHeight() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "width: " << window_group.Width() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "cost: " << window_group.Cost() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "parameters:\n";
  }
  if (window_group.Parameters().empty()) {
    std::cout << std::string(indent_ + indent_step_ * 2, ' ')
              << "none\n";
  } else {
    visitor_ = ValuePrintingVisitor(indent_ + indent_step_ * 2, indent_step_);
    visitor_.PrintOnlyCost(only_cost_);
    for (const auto& kParameter : window_group.Parameters()) {
      kParameter->Accept(visitor_);
    }
  }
  std::cout << std::string(indent_ + indent_step_, ' ')
            << "windows:\n";
  if (window_group.Windows().empty()) {
    std::cout << std::string(indent_ + indent_step_, ' ')
              << "none\n";
  } else {
    indent_ += indent_step_ * 2;
    for (const auto& kWindow : window_group.Windows()) {
      kWindow->Accept(*this);
    }
  }
}

void BaseHolderPrintingVisitor::Visit(Window& window) {
  if (only_cost_) {
    std::cout << std::string(indent_, ' ')
              << "Window \"" << window.Name() << "\": " << window.Cost() << "\n";
  } else {
    std::cout << std::string(indent_, ' ')
              << "Window \"" << window.Name() << "\":\n"
              << std::string(indent_ + indent_step_, ' ')
              << "id: " << window.Id() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "square: " << window.Square() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "height: " << window.Height() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "top row height: " << window.TopRowHeight() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "bottom row height: " << window.BottomRowHeight() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "width: " << window.Width() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "cost: " << window.Cost() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "section count: " << window.SectionCount() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "is counted: " << (window.IsCounted() ? "true" : "false") << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "parameters:\n";
  }
  if (window.Parameters().empty()) {
    std::cout << std::string(indent_ + indent_step_ * 2, ' ')
              << "none\n";
  } else {
    visitor_ = ValuePrintingVisitor(indent_ + indent_step_ * 2, indent_step_);
    visitor_.PrintOnlyCost(only_cost_);
    for (const auto& kParameter : window.Parameters()) {
      kParameter->Accept(visitor_);
    }
  }
}

void BaseHolderPrintingVisitor::Visit(BalconyParameterHolder& balcony_parameter_holder) {
  if (only_cost_) {
    std::cout << std::string(indent_, ' ')
              << "Balcony Parameter Holder \"" << balcony_parameter_holder.Name() << "\": "
              << balcony_parameter_holder.Cost() << "\n";
  } else {
    std::cout << std::string(indent_, ' ')
              << "Balcony Parameter Holder \"" << balcony_parameter_holder.Name() << "\":\n"
              << std::string(indent_ + indent_step_, ' ')
              << "id: " << balcony_parameter_holder.Id() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "square: " << balcony_parameter_holder.Square() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "height: " << balcony_parameter_holder.Height() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "width: " << balcony_parameter_holder.Width() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "cost: " << balcony_parameter_holder.Cost() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "parameters:\n";
  }
  if (balcony_parameter_holder.Parameters().empty()) {
    std::cout << std::string(indent_ + indent_step_ * 2, ' ')
              << "none\n";
  } else {
    visitor_ = ValuePrintingVisitor(indent_ + indent_step_ * 2, indent_step_);
    visitor_.PrintOnlyCost(only_cost_);
    for (const auto& kParameter : balcony_parameter_holder.Parameters()) {
      kParameter->Accept(visitor_);
    }
  }
}

void BaseHolderPrintingVisitor::ResetIndent() {
  indent_ = 0;
}

void BaseHolderPrintingVisitor::PrintOnlyCost(const bool only_cost) {
  only_cost_ = only_cost;
}

void BaseHolderPrintingVisitor::Visit(ParameterHolder& param_holder) {
  if (only_cost_) {
    std::cout << std::string(indent_, ' ')
              << "Parameter Holder \"" << param_holder.Name() << "\": " << param_holder.Cost() << "\n";
  } else {
    std::cout << std::string(indent_, ' ')
              << "Parameter Holder \"" << param_holder.Name() << "\":\n"
              << std::string(indent_ + indent_step_, ' ')
              << "id: " << param_holder.Id() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "cost: " << param_holder.Cost() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "parameters:\n";
  }
  if (param_holder.Parameters().empty()) {
    std::cout << std::string(indent_ + indent_step_ * 2, ' ')
              << "none\n";
  } else {
    visitor_ = ValuePrintingVisitor(indent_ + indent_step_ * 2, indent_step_);
    visitor_.PrintOnlyCost(only_cost_);
    for (const auto& kParameter : param_holder.Parameters()) {
      kParameter->Accept(visitor_);
    }
  }
}

void BaseHolderPrintingVisitor::Visit(BalconyGroup& balcony_group) {
  if (only_cost_) {
    std::cout << std::string(indent_, ' ')
              << "Balcony Group \"" << balcony_group.Name() << "\": " << balcony_group.Cost() << "\n";
  } else {
    std::cout << std::string(indent_, ' ')
              << "Balcony Group \"" << balcony_group.Name() << "\":\n"
              << std::string(indent_ + indent_step_, ' ')
              << "id: " << balcony_group.Id() << "\n"
              << std::string(indent_ + indent_step_, ' ')
              << "cost: " << balcony_group.Cost() << "\n";
  }
  std::cout << std::string(indent_ + indent_step_, ' ')
            << "Parameter holders:\n";
  if (balcony_group.ParameterHolders().empty()) {
    std::cout << std::string(indent_ + indent_step_, ' ')
              << "none\n";
  } else {
    indent_ += indent_step_ * 2;
    for (const auto& kBalcony : balcony_group.ParameterHolders()) {
      kBalcony->Accept(*this);
    }
  }
}

} // calc
