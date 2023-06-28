#pragma once

#include <pqxx/pqxx>
#include "utils/database/database_creator/i_database_creator.h"

namespace utils {

class PostgresDatabaseCreator : public IDatabaseCreator {
 public:
  PostgresDatabaseCreator(std::string host,
                          std::string port,
                          std::string user,
                          std::string password,
                          std::string db_name);
  PostgresDatabaseCreator(std::string host, std::string port, std::string user, std::string password);

  std::unique_ptr<ITableCreator> CreateDatabase(std::string db_name) override;

  IDatabaseCreator& DeleteDatabase(const std::string& db_name) override;

  IDatabaseCreator& DeleteDatabase() override;

  std::unique_ptr<ITableCreator> OpenDatabase(std::string db_name) override;

  IDatabaseCreator& CloseDatabase() override;

  std::unique_ptr<ITableCreator> TableCreator() override;

  bool Exists(const std::string& db_name);

 private:
  std::string current_db_name_;
  std::string host_;
  std::string port_;
  std::string user_;
  std::string password_;
};

} // utils