#pragma once

#include "calculator/window_group/window/parameters/enumerable_parameter/enumerable_parameter.h"
#include "calculator/sized_parameter_holder/i_sized_parameter_holder_parentable.h"
namespace calc {

class CountableSquareMultiplyEnumerableParameter : public EnumerableParameter, public ISizedParameterHolderParentable {
 public:
  CountableSquareMultiplyEnumerableParameter(
      std::string name,
      std::string id,
      std::unique_ptr<IValueEnumerable> value,
      SizedParameterHolder* parent,
      std::string default_value = ""
  );

  CountableSquareMultiplyEnumerableParameter(EnumerableParameter&& other, SizedParameterHolder* parent);

  ~CountableSquareMultiplyEnumerableParameter() override = default;

  void SetIsCounted(bool is_counted);

  [[nodiscard]] bool IsCounted() const;

  [[nodiscard]] price Cost() const override;

  [[nodiscard]] std::unique_ptr<ICloneable> Clone() const override;

  [[nodiscard]] SizedParameterHolder* Parent() const override;

  void SetParent(SizedParameterHolder* parent) override;

 private:
  SizedParameterHolder* parent_ = nullptr;
  bool is_counted_ = false;
};

} // calc
