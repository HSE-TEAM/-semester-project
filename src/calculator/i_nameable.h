#pragma once

#include <string>

namespace calc {

class INameable {
 public:
  virtual ~INameable() = default;

  [[nodiscard]] virtual const std::string& Name() const = 0;
  [[nodiscard]] virtual const std::string& Id() const = 0;

};

} // calc

