#pragma once

#include "calculator/common_interfaces/i_costable.h"
#include "calculator/common_interfaces/i_updatable.h"
#include "calculator/common_interfaces/i_nameable.h"
#include "calculator/common_interfaces/i_cloneable.h"
#include "calculator/sized_parameter_holder/parameter_holder/base_holder/base_holder_visitor/i_base_holder_visitor.h"

namespace calc {

class BaseHolder : public ICostable, public IUpdatable, public INameable, public ICloneable {
 public:
  explicit BaseHolder(std::string name, std::string id);
  ~BaseHolder() override = default;

  void SetName(std::string name);

  void SetId(std::string id);

  [[nodiscard]] const std::string& Name() const override;

  [[nodiscard]] const std::string& Id() const override;

  virtual void Accept(IBaseHolderVisitor& visitor) = 0;

 private:
  std::string name_;
  std::string id_;
};

} // calc
