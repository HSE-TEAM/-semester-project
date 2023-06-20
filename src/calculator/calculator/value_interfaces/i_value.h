#pragma once

#include <string>
#include "calculator/common_interfaces/i_costable.h"
#include "calculator/common_interfaces/i_updatable.h"
#include "calculator/common_interfaces/i_cloneable.h"

namespace calc {

class IValueVisitor;

class IValue : virtual public ICostable, virtual public IUpdatable, virtual public ICloneable {
 public:
  virtual ~IValue() = default;

  [[nodiscard]] virtual const std::string& Value() const = 0;
  virtual void SetValue(std::string value) = 0;

  virtual void Accept(IValueVisitor& visitor) = 0;

};

} // calc

