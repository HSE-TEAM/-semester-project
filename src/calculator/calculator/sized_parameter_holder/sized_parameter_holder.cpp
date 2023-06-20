#include "sized_parameter_holder.h"

namespace calc {

SizedParameterHolder::SizedParameterHolder(std::string name, std::string id)
    : ParameterHolder(std::move(name), std::move(id)) {}

square SizedParameterHolder::Square() const {
  return Width() * Height();
}

} // calc
