#pragma once

#include <string>
#include <memory>
#include <vector>
#include "common/dimensions.h"

namespace utils {

class IDataCreator {
 public:
  virtual ~IDataCreator() = default;
  virtual IDataCreator& SetHeader(const std::pair<std::string, std::string>& header) = 0;
  virtual IDataCreator& AddRow(const std::pair<std::string, price>& row) = 0;
  virtual IDataCreator& AddRows(const std::vector<std::pair<std::string, price>>& rows) = 0;
  virtual IDataCreator& SetOrAddRow(const std::pair<std::string, price>& new_row) = 0;
  virtual IDataCreator& SetOrAddRows(const std::vector<std::pair<std::string, price>>& new_rows) = 0;
  virtual IDataCreator& DeleteRow(const std::string& row_name) = 0;
  virtual IDataCreator& DeleteAllRows() = 0;
  virtual IDataCreator& Clear() = 0;
};

} // utils