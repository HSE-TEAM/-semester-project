#pragma once

namespace calc {

class IBaseHolderVisitor {
 public:
  virtual ~IBaseHolderVisitor() = default;

  virtual void Visit(class Calculator& calculator) = 0;
  virtual void Visit(class Window& window) = 0;
  virtual void Visit(class WindowGroup& window_group) = 0;
  virtual void Visit(class BalconyParameterHolder& balcony_parameter_holder) = 0;
  virtual void Visit(class ParameterHolder& param_holder) = 0;
  virtual void Visit(class BalconyGroup& balcony_group) = 0;
};

} // calc
