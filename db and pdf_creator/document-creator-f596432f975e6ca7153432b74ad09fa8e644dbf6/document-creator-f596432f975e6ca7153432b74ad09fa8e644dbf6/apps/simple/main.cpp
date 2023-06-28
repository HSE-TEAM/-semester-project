#include <iostream>
#include "document_creator/text_replacer/text_replacer.h"

int main() {
  auto parameter_holder = std::make_unique<document_creator::ParameterHolder>();
  parameter_holder->AddParameter("h", "p");
  parameter_holder->AddParameter("p", "h");
  document_creator::TextReplacer text_replacer;
  text_replacer
      .SetExecutablePath("libs\\document_filler\\executable\\main.exe")
      .AddTemplateDirsPath("data/input_files")
      .SetOutputDirPath("data/output_files")
      .SetParameterHolder(std::move(parameter_holder))
      .SetId("user_1")
      .Replace();
  return 0;
}