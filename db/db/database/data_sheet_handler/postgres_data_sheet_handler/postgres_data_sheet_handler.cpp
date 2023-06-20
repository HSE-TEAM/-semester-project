#include "postgres_data_sheet_handler.h"

namespace db {
std::map<std::string, double> PostgresDataSheetHandler::BodyPairs() const {
  std::map<std::string, double> result;
  pqxx::work txn(*connection_);
  std::string query = "SELECT name, cost FROM " + table_;
  if (single_line_) {
    query += " WHERE name = " + txn.quote(line_);
  }
  pqxx::result rows = txn.exec(query);
  for (const auto& row : rows) {
    result[row["name"].as<std::string>()] = row["cost"].as<double>();
  }
  return result;
}

PostgresDataSheetHandler::PostgresDataSheetHandler(std::unique_ptr<pqxx::connection>& connection,
                                                   const std::string& table)
    : connection_(connection), table_(table) {}

PostgresDataSheetHandler::PostgresDataSheetHandler(std::unique_ptr<pqxx::connection>& connection,
                                                   const std::string& table,
                                                   const std::string& line)
    : connection_(connection), table_(table), line_(line), single_line_(true) {}

std::vector<std::vector<std::string>> PostgresDataSheetHandler::BodyLines() const {
  std::vector<std::vector<std::string>> result;
  pqxx::work txn(*connection_);
  std::string query = "SELECT * FROM " + table_;
  if (single_line_) {
    query += " WHERE name = " + txn.quote(line_);
  }
  pqxx::result rows = txn.exec(query);
  for (const auto& row : rows) {
    std::vector<std::string> cells;
    for (const auto& field : row) {
      cells.push_back(field.c_str());
    }
    result.push_back(std::move(cells));
  }
  return result;
}

} // db