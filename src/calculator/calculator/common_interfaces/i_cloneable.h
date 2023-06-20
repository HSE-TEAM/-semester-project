#pragma once

#include <memory>
namespace calc {

class ICloneable {
 public:
  virtual ~ICloneable() = default;

  [[nodiscard]] virtual std::unique_ptr<ICloneable> Clone() const = 0;
};

} // calc
