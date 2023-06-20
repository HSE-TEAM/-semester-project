#pragma once

#include <string>
#include <memory>

#include "utils/database/database_creator/table_creator/data_creator/i_data_creator.h"

namespace utils {

class ITableCreator {
 public:
  virtual ~ITableCreator() = default;

  virtual std::unique_ptr<IDataCreator> CreateTable(std::string table_name) = 0;
  virtual ITableCreator& DeleteTable(const std::string& table_name) = 0;
  virtual ITableCreator& DeleteTable() = 0;
  virtual std::unique_ptr<IDataCreator> OpenTable(std::string table_name) = 0;
  virtual ITableCreator& CloseTable() = 0;
  virtual std::unique_ptr<IDataCreator> DataCreator() = 0;
};

} // utils