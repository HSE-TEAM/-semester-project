#include <stdexcept>
#include "handles_enumerable_parameter.h"

namespace calc {

price HandlesEnumerableParameter::Cost() const {
  return EnumerableParameter::Cost() * std::stoi(parent_->GetParameter("number_of_open_flaps")->Value());
}
HandlesEnumerableParameter::HandlesEnumerableParameter(
    std::string name,
    std::string id,
    std::unique_ptr<IValueEnumerable> value,
    SizedParameterHolder* const parent,
    std::string default_value)
    : EnumerableParameter(std::move(name), std::move(id), std::move(value), std::move(default_value)), parent_(parent) {

}

std::unique_ptr<ICloneable> HandlesEnumerableParameter::Clone() const {
  auto enum_clone = EnumerableParameter::Clone();

  auto* const kClone = dynamic_cast<EnumerableParameter*>(enum_clone.release());

  if (kClone == nullptr) {
    throw std::runtime_error(
        "HandlesEnumerableParameter::Clone() failed to cast clone to EnumerableParameter");
  }

  return std::make_unique<HandlesEnumerableParameter>(
      std::move(*kClone),
      parent_
  );
}

HandlesEnumerableParameter::HandlesEnumerableParameter(EnumerableParameter&& other, SizedParameterHolder* const parent)
    : EnumerableParameter(std::move(other)), parent_(parent) {}

SizedParameterHolder* HandlesEnumerableParameter::Parent() const {
  return parent_;
}

void HandlesEnumerableParameter::SetParent(SizedParameterHolder* const parent) {
  parent_ = parent;
}

} // calc
