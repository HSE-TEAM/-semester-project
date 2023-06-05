#include "window.h"

namespace calc {
Window::Window(std::string name,
               std::string id,
               const bool is_counted,
               const int section_count,
               WindowGroup* window_group = nullptr)
    : GlassyObject(std::move(name), std::move(id)),
      is_counted_(is_counted),
      section_count_(section_count),
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

void Window::SetGroup(WindowGroup* group) {
  group_ = group;
}

void Window::Accept(IGlassyObjectVisitor& visitor) {
  visitor.Visit(*this);
}

length Window::TopRowHeight() const {
  return group_->TopRowHeight();
}

length Window::BottomRowHeight() const {
  return group_->BottomRowHeight();
}

} // calc