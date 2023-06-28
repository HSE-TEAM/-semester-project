#include "postgres_database_creator.h"
#include "utils/database/database_creator/table_creator/postgres_table_creator/postgres_table_creator.h"

namespace utils {

std::unique_ptr<ITableCreator> PostgresDatabaseCreator::CreateDatabase(std::string db_name) {
  current_db_name_ = std::move(db_name);

  pqxx::connection conn("host=" + host_ + " port=" + port_ + " user=" + user_ + " password=" + password_);
  pqxx::work txn(conn);

  std::string createDbQuery = "CREATE DATABASE " + current_db_name_;

  try {
    txn.exec(createDbQuery);
    txn.commit();
  } catch (const pqxx::sql_error& e) {
    throw std::runtime_error("Failed to create database: " + std::string(e.what()));
  }

  return std::make_unique<PostgresTableCreator>(host_, port_, user_, password_, current_db_name_);
}

IDatabaseCreator& PostgresDatabaseCreator::DeleteDatabase(const std::string& db_name) {
  pqxx::connection conn("host=" + host_ + " port=" + port_ + " user=" + user_ + " password=" + password_);
  pqxx::work txn(conn);

  std::string dropDbQuery = "DROP DATABASE IF EXISTS " + db_name;

  try {
    txn.exec(dropDbQuery);
    txn.commit();
  } catch (const pqxx::sql_error& e) {
    throw std::runtime_error("Failed to delete database: " + std::string(e.what()));
  }

  return *this;
}

IDatabaseCreator& PostgresDatabaseCreator::DeleteDatabase() {
  if (current_db_name_.empty()) {
    throw std::runtime_error("No current database is set");
  }

  return DeleteDatabase(current_db_name_);
}

std::unique_ptr<ITableCreator> PostgresDatabaseCreator::OpenDatabase(std::string db_name) {
  current_db_name_ = std::move(db_name);

  return std::make_unique<PostgresTableCreator>(host_, port_, user_, password_, current_db_name_);
}

IDatabaseCreator& PostgresDatabaseCreator::CloseDatabase() {
  current_db_name_ = "";

  return *this;
}
PostgresDatabaseCreator::PostgresDatabaseCreator(std::string host,
                                                 std::string port,
                                                 std::string user,
                                                 std::string password,
                                                 std::string db_name)
    : host_(std::move(host)),
      port_(std::move(port)),
      user_(std::move(user)),
      password_(std::move(password)),
      current_db_name_(std::move(db_name)) {}

PostgresDatabaseCreator::PostgresDatabaseCreator(std::string host,
                                                 std::string port,
                                                 std::string user,
                                                 std::string password)
    : host_(std::move(host)),
      port_(std::move(port)),
      user_(std::move(user)),
      password_(std::move(password)) {}

std::unique_ptr<ITableCreator> PostgresDatabaseCreator::TableCreator() {
  return std::make_unique<PostgresTableCreator>(host_, port_, user_, password_, current_db_name_);
}

bool PostgresDatabaseCreator::Exists(const std::string& db_name) {
  pqxx::connection conn("host=" + host_ + " port=" + port_ + " user=" + user_ + " password=" + password_);
  pqxx::work txn(conn);

  std::string existsDbQuery = "SELECT 1 FROM pg_database WHERE datname = '" + db_name + "'";

  try {
    pqxx::result result = txn.exec(existsDbQuery);
    txn.commit();

    return !result.empty();
  } catch (const pqxx::sql_error& e) {
    throw std::runtime_error("Failed to check if database exists: " + std::string(e.what()));
  }
}

} // utils