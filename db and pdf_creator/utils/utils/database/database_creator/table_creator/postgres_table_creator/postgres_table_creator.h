#pragma once

#include "utils/database/database_creator/table_creator/i_table_creator.h"

namespace utils {

class PostgresTableCreator : public ITableCreator {
 public:
  PostgresTableCreator(std::string host,
                       std::string port,
                       std::string user,
                       std::string password,
                       std::string db_name);
  ~PostgresTableCreator() override = default;

  std::unique_ptr<IDataCreator> CreateTable(std::string table_name) override;

  ITableCreator& DeleteTable(const std::string& table_name) override;

  ITableCreator& DeleteTable() override;

  std::unique_ptr<IDataCreator> OpenTable(std::string table_name) override;

  ITableCreator& CloseTable() override;

  std::unique_ptr<IDataCreator> DataCreator() override;

 private:
  std::string current_table_name_;
  std::string db_name_;
  std::string host_;
  std::string port_;
  std::string user_;
  std::string password_;

};

} // utils