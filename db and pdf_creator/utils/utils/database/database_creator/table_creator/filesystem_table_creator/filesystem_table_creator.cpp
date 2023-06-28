#include <fstream>
#include <filesystem>
#include <utility>
#include "filesystem_table_creator.h"
#include "utils/database/database_creator/table_creator/data_creator/filesystem_data_creator/filesystem_data_creator.h"

namespace utils {

FilesystemTableCreator::FilesystemTableCreator(std::string db_name) {
  db_name_ = std::move(db_name);
}

std::unique_ptr<IDataCreator> FilesystemTableCreator::CreateTable(std::string table_name) {
  current_table_name_ = std::move(table_name);
  if (std::ifstream(db_name_ + "/" + current_table_name_ + ".csv")) {
    throw std::runtime_error("Table already exists");
  }
  std::ofstream file(db_name_ + "/" + current_table_name_ + ".csv");
  return std::make_unique<FilesystemDataCreator>(db_name_, current_table_name_);
}

ITableCreator& FilesystemTableCreator::DeleteTable(const std::string& table_name) {
  if (!std::ifstream(db_name_ + "/" + table_name + ".csv")) {
    throw std::runtime_error("Table does not exist");
  }
  std::filesystem::remove(db_name_ + "/" + table_name + ".csv");
  return *this;
}

ITableCreator& FilesystemTableCreator::DeleteTable() {
  if (!std::ifstream(db_name_ + "/" + current_table_name_ + ".csv")) {
    throw std::runtime_error("Table does not exist");
  }
  std::filesystem::remove(db_name_ + "/" + current_table_name_ + ".csv");
  return *this;
}

std::unique_ptr<IDataCreator> FilesystemTableCreator::OpenTable(std::string table_name) {
  current_table_name_ = std::move(table_name);
  if (!std::ifstream(db_name_ + "/" + current_table_name_ + ".csv")) {
    throw std::runtime_error("Table does not exist");
  }
  return std::make_unique<FilesystemDataCreator>(db_name_, current_table_name_);
}

ITableCreator& FilesystemTableCreator::CloseTable() {
  current_table_name_ = "";
  return *this;
}

std::unique_ptr<IDataCreator> FilesystemTableCreator::DataCreator() {
  if (current_table_name_.empty()) {
    throw std::runtime_error("Table is not opened");
  }
  return std::make_unique<FilesystemDataCreator>(db_name_, current_table_name_);
}

} // utils