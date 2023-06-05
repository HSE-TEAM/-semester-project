#pragma once

#include "window_group/window/parameters/concrete_visitors/value_printing_visitor/value_printing_visitor.h"
#include "window_group/window/window.h"

namespace calc {

class GlassyObjectPrintingVisitor : public IGlassyObjectVisitor {
 public:
  GlassyObjectPrintingVisitor(int indent = 0, int indent_step = 4);

  void Visit(Window& window) override;

  void Visit(WindowGroup& window_group) override;

 private:
  int indent_;
  int indent_step_;
  ValuePrintingVisitor visitor_;
};

} // calc