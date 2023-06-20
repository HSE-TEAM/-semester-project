#include <stdexcept>
#include "bottom_square_multiply_enumerable_parameter.h"

namespace calc {

price calc::BottomSquareMultiplyEnumerableParameter::Cost() const {
  return EnumerableParameter::Cost() * parent_->Square();
}

calc::BottomSquareMultiplyEnumerableParameter::BottomSquareMultiplyEnumerableParameter(
    std::string name,
    std::string id,
    std::unique_ptr<IValueEnumerable> value,
    GlassyObject* const parent,
    std::string default_value) : EnumerableParameter(std::move(name),
                                                     std::move(id),
                                                     std::move(value),
                                                     std::move(default_value)), parent_(parent) {}

std::unique_ptr<ICloneable> BottomSquareMultiplyEnumerableParameter::Clone() const {
  auto enum_clone = EnumerableParameter::Clone();

  auto* const kClone = dynamic_cast<EnumerableParameter*>(enum_clone.release());

  if (kClone == nullptr) {
    throw std::runtime_error(
        "BottomSquareMultiplyEnumerableParameter::Clone() failed to cast clone to EnumerableParameter");
  }

  return std::make_unique<BottomSquareMultiplyEnumerableParameter>(
      std::move(*kClone),
      parent_
  );
}
BottomSquareMultiplyEnumerableParameter::BottomSquareMultiplyEnumerableParameter(EnumerableParameter&& other,
                                                                                 GlassyObject* const parent)
    : EnumerableParameter(std::move(other)),
      parent_(parent) {}

GlassyObject* BottomSquareMultiplyEnumerableParameter::Parent() const {
  return parent_;
}

void BottomSquareMultiplyEnumerableParameter::SetParent(GlassyObject* const parent) {
  parent_ = parent;
}

} // calc
