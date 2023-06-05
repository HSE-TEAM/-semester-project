#pragma once

namespace calc {

class IValueVisitor {
 public:
  virtual ~IValueVisitor() = default;

  virtual void Visit(class IParameter& parameter) = 0;
  virtual void Visit(class IParameterEnumerable& parameter) = 0;
  virtual void Visit(class IValue& value) = 0;
  virtual void Visit(class IValueEnumerable& value) = 0;
};

} // calc
