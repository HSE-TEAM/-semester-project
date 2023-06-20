#include <stdexcept>
#include "countable_square_multiply_enumerable_parameter.h"

namespace calc {

price calc::CountableSquareMultiplyEnumerableParameter::Cost() const {
  return EnumerableParameter::Cost() * parent_->Square() * static_cast<int>(is_counted_);
}

calc::CountableSquareMultiplyEnumerableParameter::CountableSquareMultiplyEnumerableParameter(
    std::string name,
    std::string id,
    std::unique_ptr<IValueEnumerable> value,
    SizedParameterHolder* const parent,
    std::string default_value)
    : EnumerableParameter(std::move(name), std::move(id), std::move(value), std::move(default_value)),
      parent_(parent) {}

std::unique_ptr<ICloneable> CountableSquareMultiplyEnumerableParameter::Clone() const {
  auto enum_clone = EnumerableParameter::Clone();

  auto* const kClone = dynamic_cast<EnumerableParameter*>(enum_clone.release());

  if (kClone == nullptr) {
    throw std::runtime_error("SquareMultiplyEnumerableParameter::Clone() failed to cast clone to EnumerableParameter");
  }

  return std::make_unique<CountableSquareMultiplyEnumerableParameter>(
      std::move(*kClone),
      parent_
  );
}

CountableSquareMultiplyEnumerableParameter::CountableSquareMultiplyEnumerableParameter(EnumerableParameter&& other,
                                                                                       SizedParameterHolder* const parent)
    : EnumerableParameter(std::move(other)), parent_(parent) {}

SizedParameterHolder* CountableSquareMultiplyEnumerableParameter::Parent() const {
  return parent_;
}

void CountableSquareMultiplyEnumerableParameter::SetParent(SizedParameterHolder* const parent) {
  parent_ = parent;
}

void CountableSquareMultiplyEnumerableParameter::SetIsCounted(const bool is_counted) {
  is_counted_ = is_counted;
}

bool CountableSquareMultiplyEnumerableParameter::IsCounted() const {
  return is_counted_;
}

} // calc
