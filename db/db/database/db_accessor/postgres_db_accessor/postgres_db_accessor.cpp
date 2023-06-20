#include "postgres_db_accessor.h"

namespace db {
void db::PostgresDbAccessor::Open(const std::string& connection_string) {
  connection_ = std::make_unique<pqxx::connection>(connection_string);
}
void db::PostgresDbAccessor::Close() {
  if (connection_) {
    connection_->disconnect();
    connection_.reset();
  }
}
std::string db::PostgresDbAccessor::Path() const {
  return connection_ ? connection_->dbname() : "";
}
std::string db::PostgresDbAccessor::Info() const {
  std::string info;
  info += "Name: " + Path() + "\n";
  info += "Status: " + (connection_ && connection_->is_open() ? "connected" : "disconnected") + "\n";
  return info;
}
std::unique_ptr<IDataSheetHandler> db::PostgresDbAccessor::DataSheetHandler(const std::string& table) const {
  return std::make_unique<PostgresDataSheetHandler>(connection_, table);
}
std::unique_ptr<IDataSheetHandler> db::PostgresDbAccessor::DataSheetHandlerWithSingleLine(const std::string& table,
                                                                                          const std::string& line) const {
  return std::make_unique<PostgresDataSheetHandler>(connection_, table, line);
}
} // db