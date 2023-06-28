#include "postgres_db_accessor.h"
#include "database/data_sheet_handler/i_data_sheet_handler.h"

namespace db {
void PostgresDbAccessor::Open(std::string path) {
  connection_ = std::make_unique<pqxx::connection>(path);
}
void PostgresDbAccessor::Close() {
  if (connection_) {
    connection_->close();
    connection_.reset();
  }
}
std::string PostgresDbAccessor::Path() const {
  return connection_ ? connection_->dbname() : "";
}
std::string db::PostgresDbAccessor::Info() const {
  std::string info;
  info += "Name: " + Path() + "\n";
  info += "Status: " + (connection_ && connection_->is_open() ? std::string("connected") : "disconnected") + "\n";
  return info;
}
std::unique_ptr<IDataSheetHandler> PostgresDbAccessor::DataSheetHandler(std::string table) const {
  return std::make_unique<PostgresDataSheetHandler>(connection_, table);
}
std::unique_ptr<IDataSheetHandler> PostgresDbAccessor::DataSheetHandlerWithSingleLine(std::string table,
                                                                                          std::string line) const {
  return std::make_unique<PostgresDataSheetHandler>(connection_, table, line);
}
} // db