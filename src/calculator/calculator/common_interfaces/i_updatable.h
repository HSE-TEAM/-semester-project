#pragma once

namespace calc {

class IUpdatable {
 public:
  virtual ~IUpdatable() = default;

  virtual void Update() = 0;
};

} // calc

