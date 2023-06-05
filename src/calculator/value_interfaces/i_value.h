#pragma once

#include <string>
#include "../i_costable.h"
#include "../i_updateable.h"

namespace calc {

class IValueVisitor;

class IValue : virtual public ICostable, virtual public IUpdateable {
 public:
  virtual ~IValue() = default;

  [[nodiscard]] virtual const std::string& Value() const = 0;
  virtual void SetValue(std::string value) = 0;

  virtual void Accept(IValueVisitor& visitor) = 0;

};

} // calc
