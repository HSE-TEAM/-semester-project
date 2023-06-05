#include <stdexcept>
#include <filesystem>
#include "filesystem_database_creator.h"
#include "utils/database/database_creator/table_creator/filesystem_table_creator/filesystem_table_creator.h"

namespace utils {

std::unique_ptr<ITableCreator> FilesystemDatabaseCreator::CreateDatabase(std::string db_name) {
  if (Exists(db_name)) {
    throw std::runtime_error("Database " + db_name + " already exists");
  }

  current_db_name_ = db_name;
  std::filesystem::create_directory(db_name);

  return std::make_unique<FilesystemTableCreator>(db_name);
}

IDatabaseCreator& FilesystemDatabaseCreator::DeleteDatabase(std::string db_name) {
  if (!Exists(db_name)) {
    throw std::runtime_error("Database " + db_name + " does not exist");
  }

  std::filesystem::remove_all(db_name);

  return *this;
}

std::unique_ptr<ITableCreator> FilesystemDatabaseCreator::OpenDatabase(std::string db_name) {
  if (!Exists(db_name)) {
    throw std::runtime_error("Database " + db_name + " does not exist");
  }

  current_db_name_ = db_name;
  return std::make_unique<FilesystemTableCreator>(db_name);
}

IDatabaseCreator& FilesystemDatabaseCreator::CloseDatabase() {
  current_db_name_ = "";

  return *this;
}

std::unique_ptr<ITableCreator> FilesystemDatabaseCreator::TableCreator() {
  return std::make_unique<FilesystemTableCreator>(current_db_name_);
}

FilesystemDatabaseCreator::FilesystemDatabaseCreator(std::string db_name) {
  current_db_name_ = db_name;
  if (!Exists(db_name)) {
    CreateDatabase(db_name);
  }
  OpenDatabase(db_name);
}

IDatabaseCreator& FilesystemDatabaseCreator::DeleteDatabase() {
  if (!Exists(current_db_name_)) {
    throw std::runtime_error("Database " + current_db_name_ + " does not exist");
  }

  current_db_name_ = "";
  std::filesystem::remove_all(current_db_name_);

  return *this;
}

bool FilesystemDatabaseCreator::Exists(std::string db_name) {
  return std::filesystem::exists(db_name);
}

} // utils
