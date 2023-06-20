#include <stdexcept>
#include "square_multiply_enumerable_parameter.h"

namespace calc {

price calc::SquareMultiplyEnumerableParameter::Cost() const {
  return EnumerableParameter::Cost() * parent_->Square();
}

calc::SquareMultiplyEnumerableParameter::SquareMultiplyEnumerableParameter(std::string name,
                                                                           std::string id,
                                                                           std::unique_ptr<IValueEnumerable> value,
                                                                           SizedParameterHolder* const parent,
                                                                           std::string default_value)
    : EnumerableParameter(std::move(name), std::move(id), std::move(value), std::move(default_value)),
      parent_(parent) {}

std::unique_ptr<ICloneable> SquareMultiplyEnumerableParameter::Clone() const {
  auto enum_clone = EnumerableParameter::Clone();

  auto* const kClone = dynamic_cast<EnumerableParameter*>(enum_clone.release());

  if (kClone == nullptr) {
    throw std::runtime_error("SquareMultiplyEnumerableParameter::Clone() failed to cast clone to EnumerableParameter");
  }

  return std::make_unique<SquareMultiplyEnumerableParameter>(
      std::move(*kClone),
      parent_
  );
}

SquareMultiplyEnumerableParameter::SquareMultiplyEnumerableParameter(EnumerableParameter&& other,
                                                                     SizedParameterHolder* const parent)
    : EnumerableParameter(std::move(other)), parent_(parent) {}

SizedParameterHolder* SquareMultiplyEnumerableParameter::Parent() const {
  return parent_;
}

void SquareMultiplyEnumerableParameter::SetParent(SizedParameterHolder* const parent) {
  parent_ = parent;
}

} // calc
