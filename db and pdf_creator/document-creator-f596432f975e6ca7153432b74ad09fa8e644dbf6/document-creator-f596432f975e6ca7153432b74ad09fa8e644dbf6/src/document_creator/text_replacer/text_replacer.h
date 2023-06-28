#pragma once

#include <filesystem>
#include "document_creator/parameter_holder/parameter_holder.h"
namespace document_creator {

class TextReplacer {
 public:
  TextReplacer() = default;
  ~TextReplacer() = default;

  TextReplacer& SetExecutablePath(std::filesystem::path executable_path);
  TextReplacer& AddTemplatesPath(std::filesystem::path templates_path);
  TextReplacer& AddTemplatesPaths(std::vector<std::filesystem::path> templates_path);
  TextReplacer& AddTemplateDirsPath(std::filesystem::path template_dirs_path);
  TextReplacer& AddTemplateDirsPaths(std::vector<std::filesystem::path> template_dirs_path);
  TextReplacer& SetOutputDirPath(std::filesystem::path output_dir_path);
  TextReplacer& SetParameterHolder(std::unique_ptr<ParameterHolder> parameter_holder);
  TextReplacer& SetId(std::string id);


  void Replace();

 private:
  void ReplaceText(const std::filesystem::path& template_path);

  std::filesystem::path executable_path_;
  std::vector<std::filesystem::path> templates_path_;
  std::vector<std::filesystem::path> template_dirs_path_;
  std::filesystem::path output_dir_path_;
  std::unique_ptr<ParameterHolder> parameter_holder_;
  std::string id_;
};

} // document_creator