#pragma once

#include "calculator/window_group/window/parameters/enumerable_parameter/enumerable_parameter.h"
#include "calculator/window_group/window/glassy_object/glassy_object.h"
#include "calculator/window_group/window/parameters/concrete_parameters/i_glassy_object_parentable.h"

namespace calc {

class TopSquareMultiplyEnumerableParameter : public EnumerableParameter, public IGlassyObjectParentable {
 public:
  TopSquareMultiplyEnumerableParameter(
      std::string name,
      std::string id,
      std::unique_ptr<IValueEnumerable> value,
      GlassyObject* parent,
      std::string default_value = ""
  );

  TopSquareMultiplyEnumerableParameter(EnumerableParameter&& other, GlassyObject* parent);

  ~TopSquareMultiplyEnumerableParameter() override = default;

  [[nodiscard]] price Cost() const override;

  [[nodiscard]] std::unique_ptr<ICloneable> Clone() const override;

  [[nodiscard]] GlassyObject* Parent() const override;

  void SetParent(GlassyObject* parent) override;

 private:
  GlassyObject* parent_ = nullptr;
};

} // calc
