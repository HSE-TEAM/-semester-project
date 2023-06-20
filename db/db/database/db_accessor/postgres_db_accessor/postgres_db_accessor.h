#pragma once

namespace db {

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

  void Open(const std::string& connection_string) override;

  void Close() override;

  std::string Path() const override;

  std::string Info() const override;

  std::unique_ptr<IDataSheetHandler> DataSheetHandler(const std::string& table) const override;

  std::unique_ptr<IDataSheetHandler> DataSheetHandlerWithSingleLine(const std::string& table, const std::string& line) const override;

 private:
  std::unique_ptr<pqxx::connection> connection_;
};

} // db

} // db