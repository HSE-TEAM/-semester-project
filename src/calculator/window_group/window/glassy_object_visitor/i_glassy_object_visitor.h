#pragma once

namespace calc {

class IGlassyObjectVisitor {
 public:
  virtual ~IGlassyObjectVisitor() = default;

  virtual void Visit(class Window& window) = 0;
  virtual void Visit(class WindowGroup& window_group) = 0;
};

} // calc