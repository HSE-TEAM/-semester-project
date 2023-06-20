#pragma once

#include "calculator/value_interfaces/i_value.h"
#include "calculator/window_group/window/parameters/single_parameter/single_parameter.h"

namespace calc {

class JustMultiplyEnumerableParameter : public SingleParameter {
 public:
  JustMultiplyEnumerableParameter(
      std::string name,
      std::string id,
      std::unique_ptr<IValue> value,
      std::string default_value = ""
  );

  explicit JustMultiplyEnumerableParameter(SingleParameter&& other);

  ~JustMultiplyEnumerableParameter() override = default;

  [[nodiscard]] price Cost() const override;

  [[nodiscard]] std::unique_ptr<ICloneable> Clone() const override;
};

} // calc
