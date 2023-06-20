#include <stdexcept>
#include "single_parameter.h"
#include "calculator/value_interfaces/value_visitor/i_value_visitor.h"

namespace calc {
SingleParameter::SingleParameter(std::string name,
                                 std::string id,
                                 std::unique_ptr<IValue> value,
                                 std::string default_value)
    : name_(std::move(name)), id_(std::move(id)), value_(std::move(value)) {
  if (!default_value.empty()) {
    value_->SetValue(std::move(default_value));
  }
}

const std::string& SingleParameter::Value() const {
  return value_->Value();
}

void SingleParameter::SetValue(std::string value) {
  value_->SetValue(std::move(value));
}

price SingleParameter::Cost() const {
  return value_->Cost();
}

void SingleParameter::Update() {
  value_->Update();
}

const std::string& SingleParameter::Name() const {
  return name_;
}

void SingleParameter::Accept(IValueVisitor& visitor) {
  visitor.Visit(*this);
}

const std::string& SingleParameter::Id() const {
  return id_;
}
std::unique_ptr<ICloneable> SingleParameter::Clone() const {
  auto value_clone = value_->Clone();

  std::unique_ptr<IValue> value(dynamic_cast<IValue*>(value_clone.release()));
  if (!value) {
    throw std::runtime_error("Failed to cast value_clone to IValue");
  }

  return std::make_unique<SingleParameter>(name_, id_, std::move(value));
}

} // calc
