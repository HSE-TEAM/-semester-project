#include <fstream>
#include "filesystem_data_sheet_handler.h"

namespace db {

std::map<std::string, price, std::less<>> FilesystemDataSheetHandler::BodyPairs() const {
  std::map<std::string, price, std::less<>> result;
  std::ifstream file(path_);
  if (!file.is_open()) {
    throw std::runtime_error("File " + path_.string() + " not found");
  }
  std::string line;
  std::getline(file, line); // skip header
  while (std::getline(file, line)) {
    const auto kPos = line.find(',');
    if (kPos == std::string::npos) {
      throw std::runtime_error("Invalid file format " + path_.string());
    }
    const auto kName = line.substr(0, kPos);
    const auto kCost = std::stod(line.substr(kPos + 1));
    if (single_line_ && kName != line_) {
      continue;
    }
    result[kName] = kCost;
  }
  return result;
}

std::vector<std::vector<std::string>> FilesystemDataSheetHandler::BodyLines() const {
  std::vector<std::vector<std::string>> result;
  std::ifstream file(path_);
  if (!file.is_open()) {
    throw std::runtime_error("File" + path_.string() + " not found");
  }
  std::string line;
  std::istringstream iss;
  std::getline(file, line); // skip header
  while (std::getline(file, line)) {
    std::vector<std::string> row;
    iss.str(line);
    std::string cell;
    while (std::getline(iss, cell, ',')) {
      row.push_back(cell);
    }
    if (single_line_ && row[0] != line_) {
      continue;
    }
    result.push_back(std::move(row));
  }
  return result;
}

} // db
