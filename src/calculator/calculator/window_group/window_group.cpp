#include <stdexcept>
#include "window_group.h"
#include "calculator/window_group/window/parameters/concrete_parameters/i_glassy_object_parentable.h"

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

void WindowGroup::Accept(IBaseHolderVisitor& visitor) {
  visitor.Visit(*this);
}

length WindowGroup::TopRowHeight() const {
  return top_row_height_;
}

length WindowGroup::BottomRowHeight() const {
  return bottom_row_height_;
}

void WindowGroup::SetTopRowHeight(const length height) {
  top_row_height_ = height;
}

void WindowGroup::SetBottomRowHeight(const length height) {
  bottom_row_height_ = height;
}

std::unique_ptr<ICloneable> WindowGroup::Clone() const {
  auto clone = std::make_unique<WindowGroup>(Name(), Id());
  clone->SetTopRowHeight(TopRowHeight());
  clone->SetBottomRowHeight(BottomRowHeight());
  for (const auto& kWindow : windows_) {
    std::unique_ptr<Window> window(dynamic_cast<Window*>(kWindow->Clone().release()));
    window->SetGroup(clone.get());
    if (window == nullptr) {
      throw std::runtime_error("WindowGroup::Clone() - dynamic_cast<Window*> failed");
    }
    clone->AddWindow(std::move(window));
  }

  for (const auto& kParameter : Parameters()) {
    std::unique_ptr<IParameter> parameter(dynamic_cast<IParameter*>(kParameter->Clone().release()));
    if (parameter == nullptr) {
      throw std::runtime_error("WindowGroup::Clone() - dynamic_cast<Parameter*> failed");
    }
    if (auto* const kParentableParam = dynamic_cast<IGlassyObjectParentable*>(parameter.get())) {
      kParentableParam->SetParent(clone.get());
    }
    clone->AddParameter(std::move(parameter));
  }

  return clone;
}

} // calc
