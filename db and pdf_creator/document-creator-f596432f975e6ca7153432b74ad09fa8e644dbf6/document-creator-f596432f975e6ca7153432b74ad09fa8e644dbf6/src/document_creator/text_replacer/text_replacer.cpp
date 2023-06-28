#include "text_replacer.h"

namespace document_creator {
TextReplacer& TextReplacer::SetExecutablePath(std::filesystem::path executable_path) {
  executable_path_ = std::move(executable_path);
  return *this;
}

TextReplacer& TextReplacer::AddTemplatesPath(std::filesystem::path templates_path) {
  templates_path_.push_back(std::move(templates_path));
  return *this;
}

TextReplacer& TextReplacer::AddTemplatesPaths(std::vector<std::filesystem::path> templates_path) {
  templates_path_.insert(templates_path_.end(), templates_path.begin(), templates_path.end());
  return *this;
}

TextReplacer& TextReplacer::AddTemplateDirsPath(std::filesystem::path template_dirs_path) {
  template_dirs_path_.push_back(std::move(template_dirs_path));
  return *this;
}

TextReplacer& TextReplacer::AddTemplateDirsPaths(std::vector<std::filesystem::path> template_dirs_path) {
  template_dirs_path_.insert(template_dirs_path_.end(), template_dirs_path.begin(), template_dirs_path.end());
  return *this;
}

TextReplacer& TextReplacer::SetOutputDirPath(std::filesystem::path output_dir_path) {
  output_dir_path_ = std::move(output_dir_path);
  return *this;
}

TextReplacer& TextReplacer::SetParameterHolder(std::unique_ptr<ParameterHolder> parameter_holder) {
  parameter_holder_ = std::move(parameter_holder);
  return *this;
}

TextReplacer& TextReplacer::SetId(std::string id) {
  id_ = std::move(id);
  return *this;
}

void TextReplacer::Replace() {
  for (auto& template_path : templates_path_) {
    ReplaceText(template_path);
  }
  for (auto& template_dirs_path : template_dirs_path_) {
    ReplaceText(template_dirs_path);
  }
}

void TextReplacer::ReplaceText(const std::filesystem::path& template_path) {
  if (executable_path_.empty()) {
    throw std::runtime_error("TextReplacer::ReplaceText() failed to replace text because executable path is empty");
  }
  if (template_path.empty()) {
    throw std::runtime_error("TextReplacer::ReplaceText() failed to replace text because template path is empty");
  }
  if (output_dir_path_.empty()) {
    throw std::runtime_error("TextReplacer::ReplaceText() failed to replace text because output path is empty");
  }
  if (!parameter_holder_) {
    throw std::runtime_error("TextReplacer::ReplaceText() failed to replace text because parameter holder is empty");
  }
  if (id_.empty()) {
    throw std::runtime_error("TextReplacer::ReplaceText() failed to replace text because id is empty");
  }
  if (std::filesystem::is_directory(template_path)) {
    for (auto& kFile : std::filesystem::directory_iterator(template_path)) {
      ReplaceText(kFile.path());
    }
    return;
  }

  std::string output_file_name = id_ + "_" + template_path.filename().string();
  std::filesystem::path output_file_path = output_dir_path_ / output_file_name;
  std::string command = executable_path_.string() + " ";
  command += "--input_file " + template_path.string() + " ";
  command += "--output_file " + output_file_path.string() + " ";
  for (auto& parameter : parameter_holder_->Parameters()) {
    command += " " + parameter->Id() + "=" + parameter->Value() + " ";
  }
  std::system(command.c_str());
}
}
// document_creator