#pragma once

#include "../i_value.h"
#include "calculator/common_interfaces/i_nameable.h"

namespace calc {

class IParameter : virtual public IValue, virtual public INameable {
 public:
  virtual ~IParameter() = default;
};

} // calc

