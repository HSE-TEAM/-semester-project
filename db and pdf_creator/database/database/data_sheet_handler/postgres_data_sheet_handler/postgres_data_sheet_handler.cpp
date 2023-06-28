#include "postgres_data_sheet_handler.h"

#include <utility>

namespace db {
std::map<std::string, price, std::less<>> PostgresDataSheetHandler::BodyPairs() const {
  std::map<std::string, price, std::less<>> result;
  pqxx::work txn(*connection_);
  std::string query = "SELECT value, cost FROM " + table_;
  if (single_line_) {
    query += " WHERE value = " + txn.quote(line_);
  }
  pqxx::result rows = txn.exec(query);
  for (const auto& kRow : rows) {
    result[kRow["value"].as<std::string>()] = kRow["cost"].as<double>();
  }
  return result;
}

PostgresDataSheetHandler::PostgresDataSheetHandler(const std::unique_ptr<pqxx::connection>& connection,
                                                   std::string table)
    : connection_(connection), table_(std::move(table)) {}

PostgresDataSheetHandler::PostgresDataSheetHandler(const std::unique_ptr<pqxx::connection>& connection,
                                                   std::string table,
                                                   std::string line)
    : connection_(connection), table_(std::move(table)), line_(std::move(line)), single_line_(true) {}

std::vector<std::vector<std::string>> PostgresDataSheetHandler::BodyLines() const {
  std::vector<std::vector<std::string>> result;
  pqxx::work txn(*connection_);
  std::string query = "SELECT * FROM " + table_;
  if (single_line_) {
    query += " WHERE value = " + txn.quote(line_);
  }
  pqxx::result rows = txn.exec(query);
  for (const auto& kRow : rows) {
    std::vector<std::string> cells;
    for (const auto& field : kRow) {
      cells.emplace_back(field.c_str());
    }
    result.push_back(std::move(cells));
  }
  return result;
}

} // db