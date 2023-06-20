#pragma once

#include "calculator/window_group/window/parameters/enumerable_parameter/enumerable_parameter.h"
#include "calculator/window_group/window/glassy_object/glassy_object.h"
#include "calculator/window_group/window/parameters/concrete_parameters/i_glassy_object_parentable.h"
#include "calculator/sized_parameter_holder/i_sized_parameter_holder_parentable.h"

namespace calc {

class SquareMultiplyEnumerableParameter : public EnumerableParameter, public ISizedParameterHolderParentable {
 public:
  SquareMultiplyEnumerableParameter(
      std::string name,
      std::string id,
      std::unique_ptr<IValueEnumerable> value,
      SizedParameterHolder* parent,
      std::string default_value = ""
  );

  SquareMultiplyEnumerableParameter(EnumerableParameter&& other, SizedParameterHolder* parent);

  ~SquareMultiplyEnumerableParameter() override = default;

  [[nodiscard]] price Cost() const override;

  [[nodiscard]] std::unique_ptr<ICloneable> Clone() const override;

  [[nodiscard]] SizedParameterHolder* Parent() const override;

  void SetParent(SizedParameterHolder* parent) override;

 private:
  SizedParameterHolder* parent_ = nullptr;
};

} // calc
