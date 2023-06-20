#pragma once

#include "utils/database/database_creator/table_creator/data_creator/i_data_creator.h"

namespace utils {

/// TODO: Needs some refactoring
class FilesystemDataCreator : public IDataCreator {
 public:
  FilesystemDataCreator(std::string db_name, std::string table_name);
  ~FilesystemDataCreator() override = default;
  IDataCreator& SetHeader(const std::pair<std::string, std::string>& header) override;
  IDataCreator& AddRow(const std::pair<std::string, price>& row) override;
  IDataCreator& AddRows(const std::vector<std::pair<std::string, price>>& rows) override;
  IDataCreator& SetOrAddRow(const std::pair<std::string, price>& new_row) override;
  IDataCreator& SetOrAddRows(const std::vector<std::pair<std::string, price>>& new_rows) override;
  IDataCreator& DeleteRow(const std::string& row_name) override;
  IDataCreator& DeleteAllRows() override;
  IDataCreator& Clear() override;

 private:
  std::string db_name_;
  std::string table_name_;

  std::vector<std::pair<std::string, std::string>> ReadLines() const;
};

} // utils
