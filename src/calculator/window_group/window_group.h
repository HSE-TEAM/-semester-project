#pragma once

#include <memory>
#include "i_costable.h"
#include "i_updateable.h"
#include "window_group/window/window.h"
#include "window_group/window/glassy_object.h"

namespace calc {

class Window;

class WindowGroup : public GlassyObject {
 public:
  WindowGroup(std::string name, std::string id);

  ~WindowGroup() override = default;

  [[nodiscard]] price Cost() const override;

  void Update() override;

  void AddWindow(std::unique_ptr<Window> window);

  [[nodiscard]] const std::vector<std::unique_ptr<Window>>& Windows() const;

  [[nodiscard]] length Width() const override;

  [[nodiscard]] length TopRowHeight() const override;

  [[nodiscard]] length BottomRowHeight() const override;

  void SetTopRowHeight(length height);

  void SetBottomRowHeight(length height);

  void Accept(IGlassyObjectVisitor& visitor) override;

 private:
  std::vector<std::unique_ptr<Window>> windows_;
  length top_row_height_ = 0;
  length bottom_row_height_ = 0;
};

} // calc