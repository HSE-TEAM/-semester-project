#include <stdexcept>
#include "parameter_holder.h"

namespace document_creator {
void ParameterHolder::AddParameter(std::unique_ptr<Parameter> parameter) {
  parameters_.push_back(std::move(parameter));
}
void ParameterHolder::AddParameter(std::string id) {
  parameters_.push_back(std::make_unique<Parameter>(std::move(id)));
}
std::vector<std::unique_ptr<Parameter>>& ParameterHolder::Parameters() {
  return parameters_;
}
std::unique_ptr<Parameter> ParameterHolder::GetParameter(std::string id) const {
  for (auto& parameter : parameters_) {
    if (parameter->Id() == id) {
      return std::make_unique<Parameter>(parameter->Id());
    }
  }
  throw std::runtime_error("ParameterHolder::GetParameter() failed to find parameter with id: " + id);
}
bool ParameterHolder::HasParameter(std::string id) const {
  for (auto& kParameter : parameters_) {
    if (kParameter->Id() == id) {
      return true;
    }
  }
  return false;
}
void ParameterHolder::AddParameter(std::string id, std::string value) {
  parameters_.push_back(std::make_unique<Parameter>(std::move(id), std::move(value)));
}
} // doc_creator