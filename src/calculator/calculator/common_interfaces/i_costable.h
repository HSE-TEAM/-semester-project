#pragma once
#include "common/dimensions.h"

namespace calc {

class ICostable {
 public:
  virtual ~ICostable() = default;

  [[nodiscard]] virtual price Cost() const = 0;
};

} // calc

