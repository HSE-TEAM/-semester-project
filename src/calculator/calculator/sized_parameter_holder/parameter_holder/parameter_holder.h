#pragma once

#include <vector>
#include "base_holder/base_holder.h"
#include "calculator/value_interfaces/parameter_interfaces/i_parameter.h"

namespace calc {

class ParameterHolder : public BaseHolder {
 public:
  explicit ParameterHolder(std::string name, std::string id);

  [[nodiscard]] price Cost() const override;

  void Update() override;

  void AddParameter(std::unique_ptr<IParameter> parameter);

  [[nodiscard]] const std::vector<std::unique_ptr<IParameter>>& Parameters() const;

  [[nodiscard]] const IParameter* GetParameter(const std::string_view& id) const;

  [[nodiscard]] IParameter* GetParameter(const std::string_view& id);

  [[nodiscard]] bool HasParameter(const std::string_view& id) const;
  void Accept(IBaseHolderVisitor& visitor) override;

 private:
  std::vector<std::unique_ptr<IParameter>> parameters_;
};

} // calc
