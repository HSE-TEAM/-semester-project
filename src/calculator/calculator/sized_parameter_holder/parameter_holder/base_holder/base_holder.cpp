#include "base_holder.h"

namespace calc {

BaseHolder::BaseHolder(std::string name, std::string id) : name_(std::move(name)), id_(std::move(id)) {}

void BaseHolder::SetName(std::string name) {
  name_ = std::move(name);
}

void BaseHolder::SetId(std::string id) {
  id_ = std::move(id);
}

const std::string& BaseHolder::Name() const {
  return name_;
}

const std::string& BaseHolder::Id() const {
  return id_;
}

} // calc
