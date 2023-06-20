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
  explicit PostgresDataSheetHandler(std::unique_ptr<pqxx::connection>& connection, const std::string& table);

  explicit PostgresDataSheetHandler(std::unique_ptr<pqxx::connection>& connection, const std::string& table, const std::string& line);

  std::map<std::string, double> BodyPairs() const override;

  std::vector<std::vector<std::string>> BodyLines() const override;

 private:
  std::unique_ptr<pqxx::connection>& connection_;
  std::string table_;
  std::string line_;
  bool single_line_ = false;
};

} // db