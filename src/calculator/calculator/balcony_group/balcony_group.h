#pragma once

#include <vector>
#include "calculator/sized_parameter_holder/parameter_holder/base_holder/base_holder.h"
#include "calculator/balcony_group/balcony_parameter_holder/balcony_parameter_holder.h"

namespace calc {

class BalconyGroup : public BaseHolder {
 public:
  BalconyGroup(std::string name, std::string id);

  [[nodiscard]] price Cost() const override;

  void Update() override;

  void AddParameterHolder(std::unique_ptr<BalconyParameterHolder> parameter);

  [[nodiscard]] const std::vector<std::unique_ptr<BalconyParameterHolder>>& ParameterHolders() const;

  [[nodiscard]] const BalconyParameterHolder* GetParameterHolder(const std::string_view& id) const;

  [[nodiscard]] BalconyParameterHolder* GetParameterHolder(const std::string_view& id);

  [[nodiscard]] bool HasParameterHolder(const std::string_view& id) const;

  [[nodiscard]] std::unique_ptr<ICloneable> Clone() const override;

  void Accept(IBaseHolderVisitor& visitor) override;

 private:
  std::vector<std::unique_ptr<BalconyParameterHolder>> parameter_holders_;
};

} // calc
