#include "window_group.h"

namespace calc {

WindowGroup::WindowGroup(std::string name, std::string id) : GlassyObject(std::move(name), std::move(id)) {}

price WindowGroup::Cost() const {
  price result = 0;
  for (const auto& kWindow : windows_) {
    result += kWindow->Cost();
  }
  result += GlassyObject::Cost();
  return result;
}

void WindowGroup::Update() {
  for (const auto& kWindow : windows_) {
    kWindow->Update();
  }
  GlassyObject::Update();
}

void WindowGroup::AddWindow(std::unique_ptr<Window> window) {
  window->SetGroup(this);
  windows_.push_back(std::move(window));
}

const std::vector<std::unique_ptr<Window>>& WindowGroup::Windows() const {
  return windows_;
}

length WindowGroup::Width() const {
  length result = 0;
  for (const auto& kWindow : windows_) {
    result += kWindow->Width();
  }
  return result;
}

void WindowGroup::Accept(IGlassyObjectVisitor& visitor) {
  visitor.Visit(*this);
}

length WindowGroup::TopRowHeight() const {
  return top_row_height_;
}

length WindowGroup::BottomRowHeight() const {
  return bottom_row_height_;
}

void WindowGroup::SetTopRowHeight(length height) {
  top_row_height_ = height;
}

void WindowGroup::SetBottomRowHeight(length height) {
  bottom_row_height_ = height;
}

} // calc
