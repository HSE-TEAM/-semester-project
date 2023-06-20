#include "calculator.h"

#include <utility>

namespace calc {
Calculator::Calculator(std::string name, std::string id) : BaseHolder(std::move(name), std::move(id)) {}

price Calculator::Cost() const {
  price cost = 0;
  for (const auto& kBaseHolder : base_holders_) {
    cost += kBaseHolder->Cost();
  }
  return cost;
}

void Calculator::Update() {
  for (const auto& kBaseHolder : base_holders_) {
    kBaseHolder->Update();
  }
}

void Calculator::AddBaseHolder(std::unique_ptr<BaseHolder> base_holder) {
  base_holders_.push_back(std::move(base_holder));
}

const std::vector<std::unique_ptr<BaseHolder>>& Calculator::BaseHolders() const {
  return base_holders_;
}

const BaseHolder* Calculator::GetBaseHolder(const std::string_view& id) const {
  for (const auto& kBaseHolder : base_holders_) {
    if (kBaseHolder->Id() == id) {
      return kBaseHolder.get();
    }
  }
  return nullptr;
}

BaseHolder* Calculator::GetBaseHolder(const std::string_view& id) {
  for (auto const& kBaseHolder : base_holders_) {
    if (kBaseHolder->Id() == id) {
      return kBaseHolder.get();
    }
  }
  return nullptr;
}

bool Calculator::HasBaseHolder(const std::string_view& id) const {
  return GetBaseHolder(id) != nullptr;
}

std::unique_ptr<ICloneable> Calculator::Clone() const {
  auto result = std::make_unique<Calculator>(Name(), Id());
  for (const auto& kBaseHolder : base_holders_) {
    result->AddBaseHolder(std::unique_ptr<BaseHolder>(dynamic_cast<BaseHolder*>(kBaseHolder->Clone().release())));
  }
  return std::move(result);
}

void Calculator::Accept(IBaseHolderVisitor& visitor) {
  visitor.Visit(*this);
}

} // calc
