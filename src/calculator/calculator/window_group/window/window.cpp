#include <stdexcept>
#include "window.h"
#include "calculator/window_group/window/parameters/concrete_parameters/i_glassy_object_parentable.h"

namespace calc {
Window::Window(std::string name,
               std::string id,
               const bool is_counted,
               const int section_count,
               WindowGroup* const window_group = nullptr)
    : GlassyObject(std::move(name), std::move(id)),
      section_count_(section_count),
      is_counted_(is_counted),
      group_(window_group) {}

void Window::SetSectionCount(const int count) {
  section_count_ = count;
}

void Window::SetCount(const bool is_counted) {
  is_counted_ = is_counted;
}

int Window::SectionCount() const {
  return section_count_;
}

bool Window::IsCounted() const {
  return is_counted_;
}

length Window::Width() const {
  return width_;
}

void Window::SetWidth(const length width) {
  width_ = width;
}

WindowGroup* Window::Group() const {
  return group_;
}

void Window::SetGroup(WindowGroup* const group) {
  group_ = group;
}

void Window::Accept(IBaseHolderVisitor& visitor) {
  visitor.Visit(*this);
}

length Window::TopRowHeight() const {
  return group_->TopRowHeight();
}

length Window::BottomRowHeight() const {
  return group_->BottomRowHeight();
}

std::unique_ptr<ICloneable> Window::Clone() const {
  auto clone = std::make_unique<Window>(Name(), Id(), IsCounted(), SectionCount(), Group());
  clone->SetWidth(Width());
  for (const auto& kParameter : Parameters()) {
    std::unique_ptr<IParameter> param(dynamic_cast<IParameter*>(kParameter->Clone().release()));
    if (!param) {
      throw std::runtime_error("Failed to cast parameter to IParameter");
    }
    if (auto* const kParentableParam = dynamic_cast<IGlassyObjectParentable*>(param.get())) {
      kParentableParam->SetParent(clone.get());
    }
    clone->AddParameter(std::move(param));
  }
  return clone;
}

} // calc
