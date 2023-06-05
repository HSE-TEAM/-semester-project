#pragma once

#include "utils/database/database_creator/i_database_creator.h"

namespace utils {

class FilesystemDatabaseCreator : public IDatabaseCreator {
 public:
  FilesystemDatabaseCreator() = default;
  explicit FilesystemDatabaseCreator(std::string db_name);
  ~FilesystemDatabaseCreator() = default;

  std::unique_ptr<ITableCreator> CreateDatabase(std::string db_name) override;
  IDatabaseCreator& DeleteDatabase(std::string db_name) override;
  IDatabaseCreator& DeleteDatabase() override;
  std::unique_ptr<ITableCreator> OpenDatabase(std::string db_name) override;
  IDatabaseCreator& CloseDatabase() override;
  std::unique_ptr<ITableCreator> TableCreator() override;

  static bool Exists(std::string db_name);

 private:
  std::string current_db_name_;
};

} // utils