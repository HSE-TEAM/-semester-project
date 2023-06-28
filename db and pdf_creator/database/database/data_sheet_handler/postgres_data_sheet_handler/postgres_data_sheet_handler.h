#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>

#include <pqxx/pqxx>

#include "database/data_sheet_handler/i_data_sheet_handler.h"

namespace db {

class PostgresDataSheetHandler : public IDataSheetHandler {
 public:
  explicit PostgresDataSheetHandler(const  std::unique_ptr<pqxx::connection>& connection, std::string table);

  explicit PostgresDataSheetHandler(const std::unique_ptr<pqxx::connection>& connection, std::string table, std::string line);

  [[nodiscard]] std::map<std::string, price, std::less<>> BodyPairs() const override;

  [[nodiscard]] std::vector<std::vector<std::string>> BodyLines() const override;

 private:
  const std::unique_ptr<pqxx::connection>& connection_;
  std::string table_;
  std::string line_;
  bool single_line_ = false;
};

} // db