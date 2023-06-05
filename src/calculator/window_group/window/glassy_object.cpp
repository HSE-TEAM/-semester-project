#include "glassy_object.h"

namespace calc {

GlassyObject::GlassyObject(std::string name, std::string id) : name_(std::move(name)), id_(std::move(id)) {}

price GlassyObject::Cost() const {
  price result = 0;
  for (const auto& kParameter : parameters_) {
    result += kParameter->Cost();
  }
  return result;
}

void GlassyObject::Update() {
  for (const auto& kParameter : parameters_) {
    kParameter->Update();
  }
}

void GlassyObject::AddParameter(std::unique_ptr<IParameter> parameter) {
  parameters_.push_back(std::move(parameter));
}

const std::vector<std::unique_ptr<IParameter>>& GlassyObject::Parameters() const {
  return parameters_;
}

square GlassyObject::Square() const {
  return Width() * Height();
}

length GlassyObject::Height() const {
  return TopRowHeight() + BottomRowHeight();
}

const std::string& GlassyObject::Name() const {
  return name_;
}

const std::string& GlassyObject::Id() const {
  return id_;
}

} // calc
