#include "parameter.h"

namespace document_creator {
Parameter::Parameter(std::string id) : id_(std::move(id)) {}
Parameter::Parameter(std::string id, std::string value) : id_(std::move(id)), value_(std::move(value)) {}
std::string Parameter::Id() const { return id_; }
void Parameter::SetId(std::string id) { id_ = std::move(id); }
std::string Parameter::Value() const { return value_; }
void Parameter::SetValue(std::string value) {
  value_ = std::move(value);
}
} // doc_creator