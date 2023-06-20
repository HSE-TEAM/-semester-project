#include "filesystem_db_accessor.h"
#include "database/data_sheet_handler/filesystem_data_sheet_handler/filesystem_data_sheet_handler.h"

namespace db {

void FilesystemDbAccessor::Open(const std::string path) {
  path_ = path;
}

void FilesystemDbAccessor::Close() {
  path_.clear();
}

std::unique_ptr<IDataSheetHandler> FilesystemDbAccessor::DataSheetHandler(std::string table) const {
  table += ".csv";
  return std::make_unique<FilesystemDataSheetHandler>(path_ / table);
}

std::string FilesystemDbAccessor::Path() const {
  return path_.string();
}

std::string FilesystemDbAccessor::Info() const {
  std::string info;
  const bool kIsPathExist = std::filesystem::directory_entry(path_).exists();

  const std::string kNameInfo = kIsPathExist ? path_.filename().string() : "No name";
  info += "Name: " + kNameInfo + "\n";
  info += "Path: " + (Path().empty() ? "No path" : Path()) + "\n";
  info += "Tables:\n";
  if (!kIsPathExist) {
    info += "    No tables\n";
  } else {
    for (const auto& kEntry : std::filesystem::directory_iterator(path_)) {
      if (kEntry.path().extension() != ".csv") {
        continue;
      }
      std::string table_info = kEntry.path().filename().string();
      table_info.erase(table_info.end() - 4, table_info.end());
      info += "    " + table_info + "\n";
    }
  }

  const std::string kStatusInfo = kIsPathExist ? "connected" : "disconnected";
  info += "Status: " + kStatusInfo + "\n";

  return info;
}
std::unique_ptr<IDataSheetHandler> FilesystemDbAccessor::DataSheetHandlerWithSingleLine(std::string table,
                                                                                        std::string line) const {
  table += ".csv";
  return std::make_unique<FilesystemDataSheetHandler>(path_ / table, line);
}

} // db
