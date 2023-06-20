#pragma once

#include <memory>
#include <vector>
#include "calculator/common_interfaces/i_costable.h"
#include "calculator/common_interfaces/i_updatable.h"
#include "calculator/common_interfaces/i_nameable.h"
#include "calculator/common_interfaces/i_cloneable.h"
#include "calculator/value_interfaces/parameter_interfaces/i_parameter.h"
#include "calculator/sized_parameter_holder/parameter_holder/parameter_holder.h"

namespace calc {

class SizedParameterHolder : public ParameterHolder {
 public:
  explicit SizedParameterHolder(std::string name, std::string id);
  ~SizedParameterHolder() override = default;

  [[nodiscard]] square Square() const;

  [[nodiscard]] virtual length Height() const = 0;

  [[nodiscard]] virtual length Width() const = 0;
};

} // calc
