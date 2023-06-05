#pragma once

#include "../i_value.h"
#include "../../i_nameable.h"

namespace calc {

class IParameter : virtual public IValue, virtual public INameable {
 public:
  virtual ~IParameter() = default;
};

} // calc
