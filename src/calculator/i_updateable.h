#pragma once

namespace calc {

class IUpdateable {
 public:
  virtual ~IUpdateable() = default;

  virtual void Update() = 0;
};

} // calc

