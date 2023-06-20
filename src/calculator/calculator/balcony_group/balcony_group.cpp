#include "balcony_group.h"

#include <utility>
#include <algorithm>

namespace calc {
BalconyGroup::BalconyGroup(std::string name, std::string id) : BaseHolder(std::move(name), std::move(id)) {}

price BalconyGroup::Cost() const {
  price result = 0;
  for (const auto& kParameter : parameter_holders_) {
    result += kParameter->Cost();
  }
  return result;
}

void BalconyGroup::Update() {
  for (const auto& kParameter : parameter_holders_) {
    kParameter->Update();
  }
}

void BalconyGroup::AddParameterHolder(std::unique_ptr<BalconyParameterHolder> parameter) {
  parameter_holders_.push_back(std::move(parameter));
}

const std::vector<std::unique_ptr<BalconyParameterHolder>>& BalconyGroup::ParameterHolders() const {
  return parameter_holders_;
}

const BalconyParameterHolder* BalconyGroup::GetParameterHolder(const std::string_view& id) const {
  for (const auto& kParameter : parameter_holders_) {
    if (kParameter->Id() == id) {
      return kParameter.get();
    }
  }
  return nullptr;
}

BalconyParameterHolder* BalconyGroup::GetParameterHolder(const std::string_view& id) {
  for (auto const& kParameter : parameter_holders_) {
    if (kParameter->Id() == id) {
      return kParameter.get();
    }
  }
  return nullptr;
}

std::unique_ptr<ICloneable> BalconyGroup::Clone() const {
  auto result = std::make_unique<BalconyGroup>(Name(), Id());
  for (const auto& kParameter : parameter_holders_) {
    result->AddParameterHolder(std::unique_ptr<BalconyParameterHolder>(dynamic_cast<BalconyParameterHolder*>(kParameter->Clone().release())));
  }
  return std::move(result);
}

void BalconyGroup::Accept(IBaseHolderVisitor& visitor) {
  visitor.Visit(*this);
}

bool BalconyGroup::HasParameterHolder(const std::string_view& id) const {
  return std::any_of(parameter_holders_.begin(), parameter_holders_.end(), [&id](const auto& parameter) {
    return parameter->Id() == id;
  });
}

} // calc
