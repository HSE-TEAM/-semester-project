#pragma once

#include <string>
#include <memory>
#include "database/data_sheet_handler/i_data_sheet_handler.h"

namespace db {

class IDbAccessor {
 public:
  virtual ~IDbAccessor() = default;

  virtual void Open(std::string path) = 0;
  virtual void Close() = 0;
  [[nodiscard]] virtual std::string Path() const = 0;
  [[nodiscard]] virtual std::string Info() const = 0;
  [[nodiscard]] virtual std::unique_ptr<IDataSheetHandler> DataSheetHandler(std::string table) const = 0;
  [[nodiscard]] virtual std::unique_ptr<IDataSheetHandler> DataSheetHandlerWithSingleLine(std::string table,
                                                                                          std::string line) const = 0;
};

}

