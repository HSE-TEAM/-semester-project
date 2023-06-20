#pragma once

#include "calculator/sized_parameter_holder/sized_parameter_holder.h"

namespace calc {

class GlassyObject : public SizedParameterHolder {
 public:
  explicit GlassyObject(std::string name, std::string id);
  ~GlassyObject() override = default;

  [[nodiscard]] length Height() const override;

  [[nodiscard]] virtual length TopRowHeight() const = 0;

  [[nodiscard]] virtual length BottomRowHeight() const = 0;
};

} // calc
