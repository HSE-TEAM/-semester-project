#pragma once

#include <map>
#include "i_value.h"

namespace calc {

class IValueEnumerable : virtual public IValue {
 public:
  virtual ~IValueEnumerable() = default;

  [[nodiscard]] virtual const std::map<std::string, price, std::less<>>& Enumeration() const = 0;
};

} // calc

