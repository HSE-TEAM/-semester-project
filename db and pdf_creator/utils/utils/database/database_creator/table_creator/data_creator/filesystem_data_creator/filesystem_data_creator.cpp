#include <sstream>
#include <iostream>
#include <fstream>
#include <utility>
#include "filesystem_data_creator.h"

namespace utils {

IDataCreator& FilesystemDataCreator::SetHeader(const std::pair<std::string, std::string>& header) {
  auto lines = ReadLines();

  std::ofstream file(db_name_ + "/" + table_name_ + ".csv");

  if (!file) {
    throw std::runtime_error("Table does not exist");
  }

  lines[0] = {header.first, header.second};

  for (auto const& [kFirst, kSecond] : lines) {
    file << kFirst << "," << kSecond << "\n";
  }

  return *this;
}

IDataCreator& FilesystemDataCreator::AddRow(const std::pair<std::string, price>& row) {
  std::ifstream ifile(db_name_ + "/" + table_name_ + ".csv");
  if (!ifile) {
    throw std::runtime_error("Table does not exist");
  }
  const bool kIsEmpty = ifile.peek() == std::ifstream::traits_type::eof();
  ifile.close();

  std::ofstream file(db_name_ + "/" + table_name_ + ".csv", std::ios::app);
  if (!file) {
    throw std::runtime_error("Table does not exist");
  }

  if (kIsEmpty) {
    file << "Column1,Column2\n";
  }

  file << row.first << "," << row.second << "\n";
  file.close();

  return *this;
}

IDataCreator& FilesystemDataCreator::AddRows(const std::vector<std::pair<std::string, price>>& rows) {
  for (auto const& kRow : rows) {
    AddRow(kRow);
  }

  return *this;
}

IDataCreator& FilesystemDataCreator::SetOrAddRow(const std::pair<std::string, price>& new_row) {
  auto body = ReadLines();
  bool row_exists = false;

  for (auto& [row, price] : body) {
    if (row == new_row.first) {
      price = std::to_string(new_row.second);
      row_exists = true;
      break;
    }
  }

  if (!row_exists) {
    body.emplace_back(new_row.first, std::to_string(new_row.second));
  }

  std::ofstream file(db_name_ + "/" + table_name_ + ".csv");

  if (!file) {
    throw std::runtime_error("Table does not exist");
  }

  std::stringstream ss;
  for (auto const& [kRow, kPrice] : body) {
    ss << kRow << "," << kPrice << "\n";
  }

  file << ss.rdbuf();

  file.close();

  return *this;
}

IDataCreator& FilesystemDataCreator::SetOrAddRows(const std::vector<std::pair<std::string, price>>& new_rows) {
  for (auto const& kRow : new_rows) {
    SetOrAddRow(kRow);
  }

  return *this;
}

IDataCreator& FilesystemDataCreator::DeleteRow(const std::string& row_name) {
  auto body = ReadLines();
  bool row_exists = false;

  for (auto it = body.begin(); it != body.end(); ++it) {
    if (it->first == row_name) {
      body.erase(it);
      row_exists = true;
      break;
    }
  }

  if (!row_exists) {
    throw std::runtime_error("Row does not exist");
  }

  std::ofstream file(db_name_ + "/" + table_name_ + ".csv");

  if (!file) {
    throw std::runtime_error("Table does not exist");
  }

  std::stringstream ss;
  for (auto const& [kRow, kPrice] : body) {
    ss << kRow << "," << kPrice << "\n";
  }

  file << ss.rdbuf();
  file.close();

  return *this;
}

IDataCreator& FilesystemDataCreator::DeleteAllRows() {
  std::ifstream ifile(db_name_ + "/" + table_name_ + ".csv");

  if (!ifile) {
    throw std::runtime_error("Table does not exist");
  }

  // save header
  std::string header;
  std::getline(ifile, header);
  ifile.close();

  std::ofstream ofile(db_name_ + "/" + table_name_ + ".csv", std::ios::out | std::ios::trunc);
  ofile << header << "\n";
  ofile.close();

  return *this;
}

IDataCreator& FilesystemDataCreator::Clear() {
  std::ofstream file(db_name_ + "/" + table_name_ + ".csv", std::ios::trunc | std::ios::out);

  if (!file) {
    throw std::runtime_error("Table does not exist");
  }

  file.close();

  return *this;
}

FilesystemDataCreator::FilesystemDataCreator(std::string db_name, std::string table_name) {
  db_name_ = std::move(db_name);
  table_name_ = std::move(table_name);
}

std::vector<std::pair<std::string, std::string>> FilesystemDataCreator::ReadLines() const {
  std::vector<std::pair<std::string, std::string>> lines;
  std::ifstream file(db_name_ + "/" + table_name_ + ".csv");
  if (!file) {
    throw std::runtime_error("Table does not exist");
  }

  std::string line;

  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string first_word;
    std::string second_word;
    std::getline(ss, first_word, ',');
    std::getline(ss, second_word, ',');
    lines.emplace_back(first_word, second_word);
  }

  return lines;
}

} // utils
