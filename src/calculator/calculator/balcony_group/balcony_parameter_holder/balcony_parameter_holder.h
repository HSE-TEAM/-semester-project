#pragma once

#include "calculator/sized_parameter_holder/sized_parameter_holder.h"
namespace calc {

class BalconyParameterHolder : public SizedParameterHolder {
 public:
  BalconyParameterHolder(std::string name, std::string id);
  void SetHeight(length height);
  void SetWidth(length width);
  [[nodiscard]] length Height() const override;
  [[nodiscard]] length Width() const override;
  void Accept(IBaseHolderVisitor& visitor) override;
  [[nodiscard]] std::unique_ptr<ICloneable> Clone() const override;

 private:
  length height_{};
  length width_{};

};

} // calc
