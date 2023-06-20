#include <stdexcept>
#include "enumerable_parameter.h"
#include "calculator/value_interfaces/value_visitor/i_value_visitor.h"

namespace calc {

EnumerableParameter::EnumerableParameter(std::string name,
                                         std::string id,
                                         std::unique_ptr<IValueEnumerable> value,
                                         std::string default_value)
    : name_(std::move(name)), id_(std::move(id)), value_(std::move(value)) {
  if (!default_value.empty()) {
    value_->SetValue(std::move(default_value));
  } else {
    value_->SetValue(value_->Enumeration().begin()->first);
  }
}

const std::map<std::string, price, std::less<>>& EnumerableParameter::Enumeration() const {
  return value_->Enumeration();
}

void EnumerableParameter::SetValue(std::string value) {
  value_->SetValue(std::move(value));
}

const std::string& EnumerableParameter::Value() const {
  return value_->Value();
}

price EnumerableParameter::Cost() const {
  return value_->Cost();
}

void EnumerableParameter::Update() {
  value_->Update();
}

const std::string& EnumerableParameter::Name() const {
  return name_;
}

void EnumerableParameter::Accept(IValueVisitor& visitor) {
  visitor.Visit(*this);
}

const std::string& EnumerableParameter::Id() const {
  return id_;
}
std::unique_ptr<ICloneable> EnumerableParameter::Clone() const {
  auto value_clone = value_->Clone();

  std::unique_ptr<IValueEnumerable> value(dynamic_cast<IValueEnumerable*>(value_clone.release()));
  if (!value) {
    throw std::runtime_error("Failed to cast value_clone to IValue");
  }

  return std::make_unique<EnumerableParameter>(name_, id_, std::move(value), value_->Value());
}

} // calc
