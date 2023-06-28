#include <pqxx/pqxx>
#include "postgres_table_creator.h"
#include "utils/database/database_creator/table_creator/data_creator/postgres_data_creator/postgres_data_creator.h"

namespace utils {
PostgresTableCreator::PostgresTableCreator(std::string host,
                                           std::string port,
                                           std::string user,
                                           std::string password,
                                           std::string db_name) :
    db_name_(std::move(db_name)),
    host_(std::move(host)),
    port_(std::move(port)),
    user_(std::move(user)),
    password_(std::move(password)) {

}
std::unique_ptr<IDataCreator> PostgresTableCreator::CreateTable(std::string table_name) {
  current_table_name_ = std::move(table_name);
  try {
    pqxx::connection conn
        ("dbname = " + db_name_ + " user = " + user_ + " password = " + password_ + " host = " + host_ + " port = "
             + port_);
    pqxx::work txn(conn);
    txn.exec("CREATE TABLE IF NOT EXISTS " + current_table_name_ + "(value VARCHAR(255), cost DOUBLE PRECISION)");
    txn.commit();
  } catch (const std::exception& e) {
    throw std::runtime_error("Failed to create table: " + std::string(e.what()));
  }
  return std::make_unique<PostgresDataCreator>(host_, port_, user_, password_, db_name_, current_table_name_);
}
ITableCreator& PostgresTableCreator::DeleteTable(const std::string& table_name) {
  try {
    pqxx::connection conn
        ("dbname = " + db_name_ + " user = " + user_ + " password = " + password_ + " host = " + host_ + " port = "
             + port_);
    pqxx::work txn(conn);
    txn.exec("DROP TABLE IF EXISTS " + table_name + ";");
    txn.commit();
  } catch (const std::exception& e) {
    throw std::runtime_error("Failed to delete table: " + std::string(e.what()));
  }
  return *this;
}
ITableCreator& PostgresTableCreator::DeleteTable() {
  if (current_table_name_.empty()) {
    throw std::runtime_error("No current table is set");
  }
  return DeleteTable(current_table_name_);
}
std::unique_ptr<IDataCreator> PostgresTableCreator::OpenTable(std::string table_name) {
  current_table_name_ = std::move(table_name);
  return std::make_unique<PostgresDataCreator>(host_, port_, user_, password_, db_name_, current_table_name_);
}
ITableCreator& PostgresTableCreator::CloseTable() {
  current_table_name_.clear();
  return *this;
}
std::unique_ptr<IDataCreator> PostgresTableCreator::DataCreator() {
  if (current_table_name_.empty()) {
    throw std::runtime_error("No current table is set");
  }
  return std::make_unique<PostgresDataCreator>(host_, port_, user_, password_, db_name_, current_table_name_);
}
} // utils