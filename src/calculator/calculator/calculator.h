#pragma once

#include <vector>
#include "calculator/sized_parameter_holder/parameter_holder/base_holder/base_holder.h"
namespace calc {

class Calculator : public BaseHolder {

 public:
  Calculator(std::string name, std::string id);
  [[nodiscard]] price Cost() const override;
  void Update() override;
  void AddBaseHolder(std::unique_ptr<BaseHolder> base_holder);
  [[nodiscard]] const std::vector<std::unique_ptr<BaseHolder>>& BaseHolders() const;
  [[nodiscard]] const BaseHolder* GetBaseHolder(const std::string_view& id) const;
  [[nodiscard]] BaseHolder* GetBaseHolder(const std::string_view& id);
  [[nodiscard]] bool HasBaseHolder(const std::string_view& id) const;
  [[nodiscard]] std::unique_ptr<ICloneable> Clone() const override;
  void Accept(IBaseHolderVisitor& visitor) override;
 private:
  std::vector<std::unique_ptr<BaseHolder>> base_holders_;
};

} // calc
