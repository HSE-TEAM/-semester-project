#pragma once

#include <string>
#include <map>
#include <filesystem>
#include <utility>

#include "database/data_sheet_handler/i_data_sheet_handler.h"

namespace db {

class FilesystemDataSheetHandler : public IDataSheetHandler {
 public:
  explicit FilesystemDataSheetHandler(std::filesystem::path path) : path_(std::move(path)) {}
  FilesystemDataSheetHandler(std::filesystem::path path, std::string line) : path_(std::move(path)),
                                                                             line_(std::move(line)),
                                                                             single_line_(true) {}

  ~FilesystemDataSheetHandler() override = default;

  [[nodiscard]] std::map<std::string, price, std::less<>> BodyPairs() const override;

  [[nodiscard]] std::vector<std::vector<std::string>> BodyLines() const override;

 private:
  std::filesystem::path path_;
  std::string line_;
  bool single_line_ = false;
};

} // db
