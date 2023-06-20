#pragma once

#include <memory>
#include "calculator/value_interfaces/i_value.h"
#include "database/data_sheet_handler/i_data_sheet_handler.h"

namespace calc {

class SingleValue : public IValue {
 public:
  explicit SingleValue(
      std::shared_ptr<db::IDataSheetHandler> handler
  );

  ~SingleValue() override = default;

  [[nodiscard]] price Cost() const override;

  void Update() override;

  [[nodiscard]] const std::string& Value() const override;

  void SetValue(std::string value) override;

  void Accept(IValueVisitor& visitor) override;

  [[nodiscard]] std::unique_ptr<ICloneable> Clone() const override;

 private:
  std::shared_ptr<db::IDataSheetHandler> handler_;
  std::string value_;
//  double count_;
  price cost_;
};

} // calc
