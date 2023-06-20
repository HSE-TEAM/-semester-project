#include <stdexcept>
#include "balcony_parameter_holder.h"

namespace calc {

length BalconyParameterHolder::Height() const {
  return height_;
}

length BalconyParameterHolder::Width() const {
  return width_;
}

void BalconyParameterHolder::Accept(IBaseHolderVisitor& visitor) {
  visitor.Visit(*this);
}

std::unique_ptr<ICloneable> BalconyParameterHolder::Clone() const {
  auto clone = std::make_unique<BalconyParameterHolder>(Name(), Id());
  clone->SetHeight(Height());
  clone->SetWidth(Width());
  for (const auto& kParameter : Parameters()) {
    std::unique_ptr<IParameter> param(dynamic_cast<IParameter*>(kParameter->Clone().release()));
    if (!param) {
      throw std::runtime_error("Failed to cast parameter to IParameter");
    }
    clone->AddParameter(std::move(param));
  }
  return clone;
}

void BalconyParameterHolder::SetHeight(const length height) {
  height_ = height;
}

void BalconyParameterHolder::SetWidth(const length width) {
  width_ = width;
}

BalconyParameterHolder::BalconyParameterHolder(std::string name, std::string id) :
    SizedParameterHolder(std::move(name), std::move(id)) {}

} // calc
