#pragma once

#include <vector>
#include <memory>
#include "document_creator/parameter_holder/parameter/parameter.h"

namespace document_creator {

class ParameterHolder {
 public:
  ParameterHolder() = default;
  ~ParameterHolder() = default;

  void AddParameter(std::unique_ptr<Parameter> parameter);
  void AddParameter(std::string id);
  void AddParameter(std::string id, std::string value);

  [[nodiscard]] std::vector<std::unique_ptr<Parameter>>& Parameters();

  [[nodiscard]] std::unique_ptr<Parameter> GetParameter(std::string id) const;

  [[nodiscard]] bool HasParameter(std::string id) const;

 private:
  std::vector<std::unique_ptr<Parameter>> parameters_;
};

} // doc_creator