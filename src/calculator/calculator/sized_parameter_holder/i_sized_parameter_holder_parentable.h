#pragma once

#include "sized_parameter_holder.h"

namespace calc {

class ISizedParameterHolderParentable {
 public:
  virtual ~ISizedParameterHolderParentable() = default;

  [[nodiscard]] virtual SizedParameterHolder* Parent() const = 0;
  virtual void SetParent(SizedParameterHolder* parent) = 0;
};

} // calc
