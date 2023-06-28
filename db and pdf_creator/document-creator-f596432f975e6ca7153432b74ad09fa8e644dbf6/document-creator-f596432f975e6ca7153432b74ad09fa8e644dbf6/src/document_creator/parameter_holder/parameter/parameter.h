#pragma once

#include <string>

namespace document_creator {

class Parameter {
 public:
  explicit Parameter(std::string id);
  Parameter(std::string id, std::string value);
  ~Parameter() = default;

  [[nodiscard]] std::string Id() const;

  void SetId(std::string id);

  [[nodiscard]] std::string Value() const;

  void SetValue(std::string value);

 private:
  std::string id_;
  std::string value_;
};

} // doc_creator