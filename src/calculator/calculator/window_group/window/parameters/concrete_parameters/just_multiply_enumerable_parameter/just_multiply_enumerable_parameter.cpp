#include <stdexcept>
#include "just_multiply_enumerable_parameter.h"
#include "calculator/window_group/window/parameters/single_parameter/single_parameter.h"

namespace calc {

price JustMultiplyEnumerableParameter::Cost() const {
  return SingleParameter::Cost() * std::stod(SingleParameter::Value());
}

JustMultiplyEnumerableParameter::JustMultiplyEnumerableParameter(
    std::string name,
    std::string id,
    std::unique_ptr<IValue> value,
    std::string default_value) : SingleParameter(std::move(name),
                                                 std::move(id),
                                                 std::move(value),
                                                 std::move(default_value)) {}

std::unique_ptr<ICloneable> JustMultiplyEnumerableParameter::Clone() const {
  auto single_clone = SingleParameter::Clone();

  auto* const kSingleClonePtr = dynamic_cast<SingleParameter*>(single_clone.release());

  if (kSingleClonePtr == nullptr) {
    throw std::runtime_error("JustMultiplyEnumerableParameter::Clone() failed to cast clone to SingleParameter");
  }

  return std::make_unique<JustMultiplyEnumerableParameter>(
      std::move(*kSingleClonePtr)
  );
}

JustMultiplyEnumerableParameter::JustMultiplyEnumerableParameter(SingleParameter&& other) : SingleParameter(
    std::move(other)) {}

} // calc
