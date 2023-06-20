#pragma once

#include <memory>
#include "calculator/common_interfaces/i_costable.h"
#include "calculator/common_interfaces/i_updatable.h"
#include "calculator/window_group/window/window.h"
#include "calculator/window_group/window/glassy_object/glassy_object.h"

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

  void Accept(IBaseHolderVisitor& visitor) override;

  [[nodiscard]] std::unique_ptr<ICloneable> Clone() const override;

 private:
  std::vector<std::unique_ptr<Window>> windows_;
  length top_row_height_ = 0;
  length bottom_row_height_ = 0;
};

} // calc
