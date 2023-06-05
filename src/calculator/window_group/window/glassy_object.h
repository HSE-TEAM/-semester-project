#pragma once

#include <memory>
#include <vector>
#include "i_costable.h"
#include "i_updateable.h"
#include "value_interfaces/parameter_interfaces/i_parameter.h"
#include "window_group/window/glassy_object_visitor/i_glassy_object_visitor.h"

namespace calc {

class GlassyObject : public ICostable, public IUpdateable, public INameable {
 public:
  explicit GlassyObject(std::string name, std::string id);
  ~GlassyObject() override = default;

  [[nodiscard]] price Cost() const override;

  [[nodiscard]] const std::string& Name() const override;

  [[nodiscard]] const std::string& Id() const override;

  void Update() override;

  void AddParameter(std::unique_ptr<IParameter> parameter);

  [[nodiscard]] const std::vector<std::unique_ptr<IParameter>>& Parameters() const;

  [[nodiscard]] square Square() const;

  [[nodiscard]] virtual length Height() const;

  [[nodiscard]] virtual length Width() const = 0;

  [[nodiscard]] virtual length TopRowHeight() const = 0;

  [[nodiscard]] virtual length BottomRowHeight() const = 0;

  virtual void Accept(IGlassyObjectVisitor& visitor) = 0;

 private:
  std::vector<std::unique_ptr<IParameter>> parameters_;
  std::string name_;
  std::string id_;
};

} // calc