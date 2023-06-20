#pragma once

#include "calculator/value_interfaces/i_value_enumerable.h"
#include "database/data_sheet_handler/i_data_sheet_handler.h"

namespace calc {

class EnumerableValue : public IValueEnumerable {
 public:
  explicit EnumerableValue(std::shared_ptr<db::IDataSheetHandler> handler);

  ~EnumerableValue() override = default;

  [[nodiscard]] const std::map<std::string, price, std::less<>>& Enumeration() const override;

  void SetValue(std::string value) override;

  [[nodiscard]] const std::string& Value() const override;

  [[nodiscard]] price Cost() const override;

  void Update() override;

  void Accept(IValueVisitor& visitor) override;

  [[nodiscard]] std::unique_ptr<ICloneable> Clone() const override;

 private:
  std::shared_ptr<db::IDataSheetHandler> handler_;
  std::map<std::string, price, std::less<>> body_;
  std::string current_;
};

} // calc
