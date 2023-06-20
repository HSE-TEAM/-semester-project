#pragma once

#include "../i_value_enumerable.h"
#include "i_parameter.h"

namespace calc {

class IParameterEnumerable : virtual public IValueEnumerable, virtual public IParameter {
 public:
  virtual ~IParameterEnumerable() = default;
};

} // calc

