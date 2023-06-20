#pragma once

#include "calculator/window_group/window/glassy_object/glassy_object.h"

namespace calc {

class IGlassyObjectParentable {
 public:
  virtual ~IGlassyObjectParentable() = default;

  [[nodiscard]] virtual GlassyObject* Parent() const = 0;
  virtual void SetParent(GlassyObject* parent) = 0;
};

} // calc
