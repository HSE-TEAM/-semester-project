#pragma once

#include <pqxx/pqxx>
#include "utils/database/database_creator/table_creator/data_creator/i_data_creator.h"

namespace utils {

class PostgresDataCreator : public IDataCreator {
 public:
  PostgresDataCreator(std::string host,
                      std::string port,
                      std::string user,
                      std::string password,
                      std::string db_name,
                      std::string table_name);
  ~PostgresDataCreator() override = default;
  IDataCreator& SetHeader(const std::pair<std::string, std::string>& header) override;
  IDataCreator& AddRow(const std::pair<std::string, price>& row) override;
  IDataCreator& AddRows(const std::vector<std::pair<std::string, price>>& rows) override;
  IDataCreator& SetOrAddRow(const std::pair<std::string, price>& new_row) override;
  IDataCreator& SetOrAddRows(const std::vector<std::pair<std::string, price>>& new_rows) override;
  IDataCreator& DeleteRow(const std::string& row_name) override;
  IDataCreator& DeleteAllRows() override;
  IDataCreator& Clear() override;

 private:
  static std::pair<std::string, std::string> GetHeaderPair(const std::string& table_name, pqxx::connection& connection);

  std::string db_name_;
  std::string table_name_;
  std::string host_;
  std::string port_;
  std::string user_;
  std::string password_;

};

} // utils