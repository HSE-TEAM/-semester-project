#include <iostream>
#include "postgres_data_creator.h"

namespace utils {

IDataCreator& PostgresDataCreator::SetHeader(const std::pair<std::string, std::string>& header) {
  pqxx::connection connection("host=" + host_ + " port=" + port_ + " user=" + user_ + " password=" + password_ +
      " dbname=" + db_name_);

  if (!connection.is_open()) {
    throw std::runtime_error("Failed to connect to the database");
  }

  try {
    auto current_header = GetHeaderPair(table_name_, connection);

    std::string query = "ALTER TABLE " + table_name_ + " RENAME COLUMN " + current_header.first + " TO " +
        header.first + ", RENAME COLUMN " + current_header.second + " TO " + header.second + ";";
    pqxx::work transaction(connection);
    transaction.exec(query);
    transaction.commit();
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    throw;
  }

  return *this;
}

IDataCreator& PostgresDataCreator::AddRow(const std::pair<std::string, price>& row) {
  pqxx::connection connection("host=" + host_ + " port=" + port_ + " user=" + user_ + " password=" + password_ +
      " dbname=" + db_name_);
  auto current_header = GetHeaderPair(table_name_, connection);

  if (!connection.is_open()) {
    throw std::runtime_error("Failed to connect to the database");
  }

  try {
    std::string
        query = "INSERT INTO " + table_name_ + " (" + current_header.first + ", " + current_header.second +
        ") VALUES ('" + row.first + "', " + std::to_string(row.second) + ");";
    pqxx::work transaction(connection);
    transaction.exec(query);
    transaction.commit();
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    throw;
  }
  return *this;
}

IDataCreator& PostgresDataCreator::AddRows(const std::vector<std::pair<std::string, price>>& rows) {
  for (const auto& kRow : rows) {
    AddRow(kRow);
  }

  return *this;
}

IDataCreator& PostgresDataCreator::SetOrAddRow(const std::pair<std::string, price>& new_row) {
  pqxx::connection connection("host=" + host_ + " port=" + port_ + " user=" + user_ + " password=" + password_ +
      " dbname=" + db_name_);

  if (!connection.is_open()) {
    throw std::runtime_error("Failed to connect to the database");
  }

  try {
    std::string query =
        "SELECT * FROM " + table_name_ + " WHERE " + GetHeaderPair(table_name_, connection).first + " = '"
            + new_row.first + "';";
    pqxx::work transaction(connection);
    pqxx::result result = transaction.exec(query);

    if (result.empty()) {
      AddRow(new_row);
    } else {
      std::string update_query =
          "UPDATE " + table_name_ + " SET " + GetHeaderPair(table_name_, connection).second + " = "
              + std::to_string(new_row.second) + " WHERE " + GetHeaderPair(table_name_, connection).first + " = '"
              + new_row.first + "';";
      transaction.exec(update_query);
    }

    transaction.commit();
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    throw;
  }

  return *this;
}

IDataCreator& PostgresDataCreator::SetOrAddRows(const std::vector<std::pair<std::string, price>>& new_rows) {
  for (const auto& kRow : new_rows) {
    SetOrAddRow(kRow);
  }

  return *this;
}

IDataCreator& PostgresDataCreator::DeleteRow(const std::string& row_name) {
  pqxx::connection connection("host=" + host_ + " port=" + port_ + " user=" + user_ + " password=" + password_ +
      " dbname=" + db_name_);

  if (!connection.is_open()) {
    throw std::runtime_error("Failed to connect to the database");
  }

  try {
    std::string query =
        "DELETE FROM " + table_name_ + " WHERE " + GetHeaderPair(table_name_, connection).first + " = '" + row_name
            + "';";
    pqxx::work transaction(connection);
    transaction.exec(query);
    transaction.commit();
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    throw;
  }

  return *this;
}

IDataCreator& PostgresDataCreator::DeleteAllRows() {
  pqxx::connection connection("host=" + host_ + " port=" + port_ + " user=" + user_ + " password=" + password_ +
      " dbname=" + db_name_);

  if (!connection.is_open()) {
    throw std::runtime_error("Failed to connect to the database");
  }

  try {
    std::string query = "DELETE FROM " + table_name_ + ";";
    pqxx::work transaction(connection);
    transaction.exec(query);
    transaction.commit();
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    throw;
  }

  return *this;
}

IDataCreator& PostgresDataCreator::Clear() {
  DeleteAllRows();
  SetHeader({"", ""});

  return *this;
}

PostgresDataCreator::PostgresDataCreator(std::string host,
                                         std::string port,
                                         std::string user,
                                         std::string password,
                                         std::string db_name,
                                         std::string table_name) :
    db_name_(std::move(db_name)),
    table_name_(std::move(table_name)),
    host_(std::move(host)),
    port_(std::move(port)),
    user_(std::move(user)),
    password_(std::move(password)) {}

std::pair<std::string, std::string> PostgresDataCreator::GetHeaderPair(const std::string& table_name,
                                                                       pqxx::connection& connection) {
  std::pair<std::string, std::string> header_pair;

  pqxx::work transaction(connection);

  std::string query = "SELECT column_name FROM information_schema.columns WHERE table_name = '" + table_name + "'";
  pqxx::result result = transaction.exec(query);

  if (result.empty()) {
    throw std::runtime_error("Table does not exist or has no columns");
  }

  if (result.size() != 2) {
    throw std::runtime_error("Table has more than 2 columns");
  }

  header_pair.first = result[0][0].as<std::string>();
  header_pair.second = result[1][0].as<std::string>();
  transaction.commit();

  return header_pair;
}

} // utils
