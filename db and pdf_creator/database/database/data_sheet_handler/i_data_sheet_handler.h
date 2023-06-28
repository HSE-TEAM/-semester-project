#pragma once

#include <string>
#include <map>
#include <vector>

#include "common/dimensions.h"

namespace db {

class IDataSheetHandler {
 public:
  virtual ~IDataSheetHandler() = default;

  [[nodiscard]] virtual std::map<std::string, price, std::less<>> BodyPairs() const = 0;

  [[nodiscard]] virtual std::vector<std::vector<std::string>> BodyLines() const = 0;

};

}

