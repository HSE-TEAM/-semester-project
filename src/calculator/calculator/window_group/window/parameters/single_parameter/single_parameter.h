#pragma once

#include <memory>
#include "calculator/value_interfaces/parameter_interfaces/i_parameter.h"

namespace calc {

class SingleParameter : public IParameter {
 public:
  explicit SingleParameter(
      std::string name,
      std::string id,
      std::unique_ptr<IValue> value,
      std::string default_value = ""
  );

  SingleParameter(SingleParameter&& other) noexcept = default;

  ~SingleParameter() override = default;

  [[nodiscard]] const std::string& Value() const override;

  void SetValue(std::string value) override;

  [[nodiscard]] price Cost() const override;

  void Update() override;

  [[nodiscard]] const std::string& Name() const override;

  [[nodiscard]] const std::string& Id() const override;

  void Accept(IValueVisitor& visitor) override;

  [[nodiscard]] std::unique_ptr<ICloneable> Clone() const override;

 private:
  std::string name_;
  std::string id_;
  std::unique_ptr<IValue> value_;
};

} // calc
