#include "glassy_object.h"

namespace calc {

GlassyObject::GlassyObject(std::string name, std::string id) : SizedParameterHolder(std::move(name), std::move(id)) {}

length GlassyObject::Height() const {
  return TopRowHeight() + BottomRowHeight();
}

} // calc
