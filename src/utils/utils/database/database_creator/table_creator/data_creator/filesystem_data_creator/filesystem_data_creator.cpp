#include <sstream>
#include <iostream>
#include <fstream>
#include "filesystem_data_creator.h"

namespace utils {

IDataCreator& FilesystemDataCreator::SetHeader(std::pair<std::string, std::string> header) {
  auto lines = ReadLines();

  std::ofstream file(db_name_ + "/" + table_name_ + ".csv");

  if (!file) {
    throw std::runtime_error("Table does not exist");
  }

  lines[0] = {header.first, header.second};

  for (auto const& kLine : lines) {
    file << kLine.first << "," << kLine.second << "\n";
  }

  return *this;
}

IDataCreator& FilesystemDataCreator::AddRow(std::pair<std::string, price> row) {
  std::ifstream ifile(db_name_ + "/" + table_name_ + ".csv");
  if (!ifile) {
    throw std::runtime_error("Table does not exist");
  }
  bool isEmpty = ifile.peek() == std::ifstream::traits_type::eof();
  ifile.close();

  std::ofstream file(db_name_ + "/" + table_name_ + ".csv", std::ios::app);
  if (!file) {
    throw std::runtime_error("Table does not exist");
  }

  if (isEmpty) {
    file << "Column1,Column2\n";
  }

  file << row.first << "," << row.second << "\n";
  file.close();

  return *this;
}

IDataCreator& FilesystemDataCreator::AddRows(std::vector<std::pair<std::string, price>> rows) {
  for (auto const& kRow : rows) {
    AddRow(kRow);
  }

  return *this;
}

IDataCreator& FilesystemDataCreator::SetOrAddRow(std::pair<std::string, price> new_row) {
  auto body = ReadLines();
  bool rowExists = false;

  for (auto& kRow : body) {
    if (kRow.first == new_row.first) {
      kRow.second = std::to_string(new_row.second);
      rowExists = true;
      break;
    }
  }

  if (!rowExists) {
    body.emplace_back(new_row.first, std::to_string(new_row.second));
  }

  std::ofstream file(db_name_ + "/" + table_name_ + ".csv");

  if (!file) {
    throw std::runtime_error("Table does not exist");
  }

  std::stringstream ss;
  for (auto const& kRow : body) {
    ss << kRow.first << "," << kRow.second << "\n";
  }

  file << ss.rdbuf();

  file.close();

  return *this;
}

IDataCreator& FilesystemDataCreator::SetOrAddRows(std::vector<std::pair<std::string, price>> new_rows) {
  for (auto const& kRow : new_rows) {
    SetOrAddRow(kRow);
  }

  return *this;
}

IDataCreator& FilesystemDataCreator::DeleteRow(std::string row_name) {
  auto body = ReadLines();
  bool rowExists = false;

  for (auto it = body.begin(); it != body.end(); ++it) {
    if (it->first == row_name) {
      body.erase(it);
      rowExists = true;
      break;
    }
  }

  if (!rowExists) {
    throw std::runtime_error("Row does not exist");
  }

  std::ofstream file(db_name_ + "/" + table_name_ + ".csv");

  if (!file) {
    throw std::runtime_error("Table does not exist");
  }

  std::stringstream ss;
  for (auto const& kRow : body) {
    ss << kRow.first << "," << kRow.second << "\n";
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
  db_name_ = db_name;
  table_name_ = table_name;
}

std::vector<std::pair<std::string, std::string>> FilesystemDataCreator::ReadLines() {
  std::vector<std::pair<std::string, std::string>> lines;
  std::ifstream file(db_name_ + "/" + table_name_ + ".csv");
  if (!file) {
    throw std::runtime_error("Table does not exist");
  }

  std::string line;

  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string firstWord, secondWord;
    std::getline(ss, firstWord, ',');
    std::getline(ss, secondWord, ',');
    lines.push_back(std::make_pair(firstWord, secondWord));
  }

  return lines;
}

} // utils
