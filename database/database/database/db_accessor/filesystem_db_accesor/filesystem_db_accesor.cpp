#include "filesystem_db_accesor.h"
#include "database/data_sheet_handler/filesystem_data_sheet_handler/filesystem_data_sheet_handler.h"

namespace db {

void FilesystemDBAccessor::Open(std::string path) {
  path_ = path;
}

void FilesystemDBAccessor::Close() {
  path_.clear();
}

std::unique_ptr<IDataSheetHandler> FilesystemDBAccessor::DataSheetHandler(std::string table) const {
  table += ".csv";
  return std::make_unique<FilesystemDataSheetHandler>(path_ / table);
}

std::string FilesystemDBAccessor::Path() const {
  return path_.string();
}

std::string FilesystemDBAccessor::Info() const {
  std::string info;
  const bool kIsPathExist = std::filesystem::directory_entry(path_).exists();

  std::string name_info = kIsPathExist ? path_.filename().string() : "No name";
  info += "Name: " + name_info + "\n";
  info += "Path: " + (Path() == "" ? "No path" : Path()) + "\n";
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

  std::string status_info = kIsPathExist ? "connected" : "disconnected";
  info += "Status: " + status_info + "\n";

  return info;
}

} // db