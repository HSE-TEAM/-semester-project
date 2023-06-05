#pragma once

#include <string>
#include <map>
#include <filesystem>

#include "database/data_sheet_handler/i_data_sheet_handler.h"

namespace db {

class FilesystemDataSheetHandler : public IDataSheetHandler {
 public:
  explicit FilesystemDataSheetHandler(std::filesystem::path path) : path_(path) {}

  ~FilesystemDataSheetHandler() override = default;

  [[nodiscard]] std::map<std::string, price> BodyPairs() const override;

  [[nodiscard]] std::vector<std::vector<std::string>> BodyLines() const;

 private:
  std::filesystem::path path_;
};

} // db

