#pragma once

#include <string>
#include <memory>

#include <pqxx/pqxx>

#include "database/db_accessor/i_db_accessor.h"
#include "database/data_sheet_handler/i_data_sheet_handler.h"
#include "database/data_sheet_handler/postgres_data_sheet_handler/postgres_data_sheet_handler.h"

namespace db {

class PostgresDbAccessor : public IDbAccessor {
 public:
  ~PostgresDbAccessor() override = default;

  void Open(std::string path) override;

  void Close() override;

  [[nodiscard]] std::string Path() const override;

  [[nodiscard]] std::string Info() const override;

  [[nodiscard]] std::unique_ptr<IDataSheetHandler> DataSheetHandler(std::string table) const override;

  [[nodiscard]] std::unique_ptr<IDataSheetHandler> DataSheetHandlerWithSingleLine(std::string table, std::string line) const override;

 private:
  std::unique_ptr<pqxx::connection> connection_;
};

} // db