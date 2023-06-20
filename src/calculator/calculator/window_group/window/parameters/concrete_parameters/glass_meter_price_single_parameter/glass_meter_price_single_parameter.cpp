#include "glass_meter_price_single_parameter.h"

namespace calc {

SquareMeterPriceSingleParameter::SquareMeterPriceSingleParameter(std::string name,
                                                                 std::string id,
                                                                 std::unique_ptr<IValue> value,
                                                                 SizedParameterHolder* const parent)
    : SingleParameter(std::move(name), std::move(id), std::move(value)), parent_(parent) {}

price SquareMeterPriceSingleParameter::Cost() const {
  return SingleParameter::Cost() * parent_->Square();
}

const std::string& SquareMeterPriceSingleParameter::Value() const {
  value_ = std::to_string(parent_->Square());
  return value_;
}

void SquareMeterPriceSingleParameter::SetValue(const std::string value) {
  value_ = std::to_string(parent_->Square());
  SingleParameter::SetValue(value_);
  throw std::runtime_error("GlassMeterPriceParameter::SetValue() should not be called (it's a read-only parameter)");
}

std::unique_ptr<ICloneable> SquareMeterPriceSingleParameter::Clone() const {
  auto single_clone = SingleParameter::Clone();

  auto* const kClone = dynamic_cast<SingleParameter*>(single_clone.release());

  if (kClone == nullptr) {
    throw std::runtime_error("SquareMeterPriceSingleParameter::Clone() failed to cast clone to SingleParameter");
  }

  return std::make_unique<SquareMeterPriceSingleParameter>(
      std::move(*kClone),
      parent_
  );
}

SquareMeterPriceSingleParameter::SquareMeterPriceSingleParameter(SingleParameter&& other,
                                                                 SizedParameterHolder* const parent) :
    SingleParameter(std::move(other)), parent_(parent) {}

SizedParameterHolder* SquareMeterPriceSingleParameter::Parent() const {
  return parent_;
}

void SquareMeterPriceSingleParameter::SetParent(SizedParameterHolder* const parent) {
  parent_ = parent;
}

} // calc
