#include <memory>
#include <stdexcept>
#include "enumerable_value.h"
#include "calculator/value_interfaces/value_visitor/i_value_visitor.h"

namespace calc {

EnumerableValue::EnumerableValue(std::shared_ptr<db::IDataSheetHandler> handler)
    : handler_(std::move(handler)),
      body_(handler_->BodyPairs()),
      current_(body_.begin()->first) {}

const std::map<std::string, price, std::less<>>& EnumerableValue::Enumeration() const {
  return body_;
}

void EnumerableValue::SetValue(std::string value) {
  if (body_.find(value) == body_.end()) {
    throw std::runtime_error("Invalid name " + value);
  }
  current_ = std::move(value);
}

const std::string& EnumerableValue::Value() const {
  return current_;
}

price EnumerableValue::Cost() const {
  return body_.at(current_);
}

void EnumerableValue::Update() {
  body_ = handler_->BodyPairs();
}
void EnumerableValue::Accept(IValueVisitor& visitor) {
  visitor.Visit(*this);
}
std::unique_ptr<ICloneable> EnumerableValue::Clone() const {
  return std::make_unique<EnumerableValue>(*this);
}

} // calc
