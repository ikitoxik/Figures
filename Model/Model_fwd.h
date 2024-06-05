////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Содержит компоненты, необходимые для класса Model
*/
//
////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <vector>
#include <set>
#include <memory>
#include <functional>

#include "../Geometry/Primitive.h"


namespace model
{
  class IModel;
  class IFigure;
  using ModelUPtr = std::unique_ptr<IModel>;
  using FigureUPtr = std::unique_ptr<IFigure>;
  using PrimitiveSPtr = std::shared_ptr<geometry::IPrimitive>;
  using PrimitiveContainer = std::vector<PrimitiveSPtr>;
  using UpdateFunc = std::function<void(const PrimitiveContainer&)>;
  using IdType = size_t;
  using IdContainer = std::set<IdType>;
  const IdType InvalidId = 0;
  using HotPointsContainer = std::vector<geometry::Point>;
} // namespace model