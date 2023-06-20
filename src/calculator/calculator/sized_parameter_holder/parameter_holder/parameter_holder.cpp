#include "parameter_holder.h"

#include <utility>

namespace calc {
price ParameterHolder::Cost() const {
  price result = 0;
  for (const auto& kParameter : parameters_) {
    result += kParameter->Cost();
  }
  return result;
}

void ParameterHolder::Update() {
  for (const auto& kParameter : parameters_) {
    kParameter->Update();
  }
}

void ParameterHolder::AddParameter(std::unique_ptr<IParameter> parameter) {
  parameters_.push_back(std::move(parameter));
}

const std::vector<std::unique_ptr<IParameter>>& ParameterHolder::Parameters() const {
  return parameters_;
}

const IParameter* ParameterHolder::GetParameter(const std::string_view& id) const {
  for (const auto& kParameter : parameters_) {
    if (kParameter->Id() == id) {
      return kParameter.get();
    }
  }
  return nullptr;
}

IParameter* ParameterHolder::GetParameter(const std::string_view& id) {
  for (auto const& kParameter : parameters_) {
    if (kParameter->Id() == id) {
      return kParameter.get();
    }
  }
  return nullptr;
}

bool ParameterHolder::HasParameter(const std::string_view& id) const {
  return GetParameter(id) != nullptr;
}

ParameterHolder::ParameterHolder(std::string name, std::string id) : BaseHolder(std::move(name), std::move(id)) {}

void ParameterHolder::Accept(IBaseHolderVisitor& visitor) {
  visitor.Visit(*this);
}

} // calc
