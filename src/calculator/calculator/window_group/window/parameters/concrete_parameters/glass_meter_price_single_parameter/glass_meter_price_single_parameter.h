#pragma once

#include <stdexcept>
#include "calculator/window_group/window/parameters/single_parameter/single_parameter.h"
#include "calculator/window_group/window/glassy_object/glassy_object.h"
#include "calculator/sized_parameter_holder/i_sized_parameter_holder_parentable.h"

namespace calc {

class SquareMeterPriceSingleParameter : public SingleParameter, public ISizedParameterHolderParentable {
 public:
  SquareMeterPriceSingleParameter(
      std::string name,
      std::string id,
      std::unique_ptr<IValue> value,
      SizedParameterHolder* parent
  );

  SquareMeterPriceSingleParameter(SingleParameter&& other, SizedParameterHolder* parent);

  ~SquareMeterPriceSingleParameter() override = default;

  [[nodiscard]] price Cost() const override;

  [[nodiscard]] const std::string& Value() const override;

  void SetValue(std::string value) override;

  [[nodiscard]] std::unique_ptr<ICloneable> Clone() const override;

  [[nodiscard]] SizedParameterHolder* Parent() const override;

  void SetParent(SizedParameterHolder* parent) override;

 private:
  SizedParameterHolder* parent_ = nullptr;
  mutable std::string value_;
};

} // calc
