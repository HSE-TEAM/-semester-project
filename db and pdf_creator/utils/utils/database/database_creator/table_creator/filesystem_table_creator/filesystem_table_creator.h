#pragma once

#include "utils/database/database_creator/table_creator/i_table_creator.h"
#include "utils/database/database_creator/table_creator/data_creator/i_data_creator.h"

namespace utils {

class FilesystemTableCreator : public ITableCreator {
 public:
  explicit FilesystemTableCreator(std::string db_name);
  ~FilesystemTableCreator() override = default;

  std::unique_ptr<IDataCreator> CreateTable(std::string table_name) override;
  ITableCreator& DeleteTable(const std::string& table_name) override;
  ITableCreator& DeleteTable() override;
  std::unique_ptr<IDataCreator> OpenTable(std::string table_name) override;
  ITableCreator& CloseTable() override;
  std::unique_ptr<IDataCreator> DataCreator() override;

 private:
  std::string current_table_name_;
  std::string db_name_;
};

} // utils
