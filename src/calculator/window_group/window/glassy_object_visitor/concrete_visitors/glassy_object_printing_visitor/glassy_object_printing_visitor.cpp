#include "glassy_object_printing_visitor.h"

namespace calc {
GlassyObjectPrintingVisitor::GlassyObjectPrintingVisitor(int indent, int indent_step)
    : indent_(indent), indent_step_(indent_step) {}

void GlassyObjectPrintingVisitor::Visit(WindowGroup& window_group) {
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
  if (window_group.Parameters().empty()) {
    std::cout << std::string(indent_ + indent_step_ * 2, ' ')
              << "none\n";
  } else {
    visitor_ = ValuePrintingVisitor(indent_ + indent_step_ * 2, indent_step_);
    for (const auto& kParameter : window_group.Parameters()) {
      kParameter->Accept(visitor_);
    }
  }
  if (window_group.Windows().empty()) {
    std::cout << std::string(indent_ + indent_step_, ' ')
              << "none\n";
  } else {
    std::cout << std::string(indent_ + indent_step_, ' ')
              << "windows:\n";
    indent_ += indent_step_ * 2;
    for (const auto& kWindow : window_group.Windows()) {
      kWindow->Accept(*this);
    }
  }
}

void GlassyObjectPrintingVisitor::Visit(Window& window) {
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
            << "is counted: " << (window.IsCounted() == true ? "true" : "false") << "\n"
            << std::string(indent_ + indent_step_, ' ')
            << "parameters:\n";
  if (window.Parameters().empty()) {
    std::cout << std::string(indent_ + indent_step_ * 2, ' ')
              << "none\n";
  } else {
    visitor_ = ValuePrintingVisitor(indent_ + indent_step_ * 2, indent_step_);
    for (const auto& kParameter : window.Parameters()) {
      kParameter->Accept(visitor_);
    }
  }
}
} // calc
