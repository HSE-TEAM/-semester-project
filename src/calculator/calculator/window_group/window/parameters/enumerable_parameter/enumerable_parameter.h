
#pragma once

#include <memory>
#include "calculator/value_interfaces/parameter_interfaces/i_parameter_enumerable.h"

namespace calc {

class EnumerableParameter : public IParameterEnumerable {
 public:
  explicit EnumerableParameter(
      std::string name,
      std::string id,
      std::unique_ptr<IValueEnumerable> value,
      std::string default_value = ""
  );

  EnumerableParameter(EnumerableParameter&& other) noexcept = default;

  ~EnumerableParameter() override = default;

  [[nodiscard]] const std::map<std::string, price, std::less<>>& Enumeration() const override;

  void SetValue(std::string value) override;

  [[nodiscard]] const std::string& Value() const override;

  [[nodiscard]] price Cost() const override;

  void Update() override;

  [[nodiscard]] const std::string& Name() const override;

  [[nodiscard]] const std::string& Id() const override;

  void Accept(IValueVisitor& visitor) override;

  [[nodiscard]] std::unique_ptr<ICloneable> Clone() const override;

 private:
  std::string name_;
  std::string id_;
  std::unique_ptr<IValueEnumerable> value_;
};

} // calc
