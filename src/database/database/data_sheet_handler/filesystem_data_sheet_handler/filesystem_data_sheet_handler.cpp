#include <fstream>
#include "filesystem_data_sheet_handler.h"

namespace db {

std::map<std::string, price> FilesystemDataSheetHandler::BodyPairs() const {
  std::map<std::string, price> result;
  std::ifstream file(path_);
  if (!file.is_open()) {
    throw std::runtime_error("File " + path_.string() + " not found");
  }
  std::string line;
  std::getline(file, line); // skip header
  while (std::getline(file, line)) {
    auto pos = line.find(',');
    if (pos == std::string::npos) {
      throw std::runtime_error("Invalid file format " + path_.string());
    }
    auto name = line.substr(0, pos);
    auto cost = std::stod(line.substr(pos + 1));
    result[name] = cost;
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
    result.push_back(std::move(row));
  }
  return result;
}

} // db
