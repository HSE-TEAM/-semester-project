#pragma once

#include <memory>
#include <vector>
#include "i_costable.h"
#include "i_updateable.h"
#include "value_interfaces/parameter_interfaces/i_parameter.h"
#include "window_group/window_group.h"
#include "glassy_object.h"

namespace calc {

class WindowGroup;

class Window : public GlassyObject {
 public:
  Window(std::string name, std::string id, bool is_counted, int section_count, WindowGroup* window_group);

  ~Window() override = default;

  void SetSectionCount(int count);

  void SetCount(bool is_counted);

  void SetGroup(WindowGroup* group);

  [[nodiscard]] int SectionCount() const;

  [[nodiscard]] bool IsCounted() const;

  [[nodiscard]] WindowGroup* Group() const;

  [[nodiscard]] length Width() const override;

  [[nodiscard]] length TopRowHeight() const override;

  [[nodiscard]] length BottomRowHeight() const override;

  void SetWidth(length width);

  void Accept(IGlassyObjectVisitor& visitor) override;

 private:
  int section_count_;
  bool is_counted_;
  length width_ = 0;
  WindowGroup* group_ = nullptr;
};

} // calc

