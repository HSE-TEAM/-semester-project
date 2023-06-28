#pragma once

#include <string>
#include <memory>

#include "utils/database/database_creator/table_creator/i_table_creator.h"

namespace utils {

class IDatabaseCreator {
 public:
  virtual ~IDatabaseCreator() = default;

  virtual std::unique_ptr<ITableCreator> CreateDatabase(std::string db_name) = 0;
  virtual IDatabaseCreator& DeleteDatabase(const std::string& db_name) = 0;
  virtual IDatabaseCreator& DeleteDatabase() = 0;
  virtual std::unique_ptr<ITableCreator> OpenDatabase(std::string db_name) = 0;
  virtual IDatabaseCreator& CloseDatabase() = 0;
  virtual std::unique_ptr<ITableCreator> TableCreator() = 0;

};

} // utils