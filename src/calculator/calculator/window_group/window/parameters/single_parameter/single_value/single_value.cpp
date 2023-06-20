#include "single_value.h"
#include "calculator/value_interfaces/value_visitor/i_value_visitor.h"

namespace calc {

SingleValue::SingleValue(std::shared_ptr<db::IDataSheetHandler> handler)
    : handler_(std::move(handler)),
      cost_(std::stod(handler_->BodyLines().begin()->at(1))) {}
//      count_(std::stod(handler_->BodyLines().begin()->at(0)))

price SingleValue::Cost() const {
  return cost_;// / count_;
}

void SingleValue::Update() {
//  count_ = std::stod(handler_->BodyLines().begin()->at(0));
  cost_ = std::stod(handler_->BodyLines().begin()->at(1));
}

const std::string& SingleValue::Value() const {
  return value_;
}

void SingleValue::SetValue(std::string value) {
  value_ = std::move(value);
}

void SingleValue::Accept(IValueVisitor& visitor) {
  visitor.Visit(*this);
}

std::unique_ptr<ICloneable> SingleValue::Clone() const {
  return std::make_unique<SingleValue>(*this);
}

} // calc
