////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Объявление класса прямоугольника по двум точкам
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "IRectParams.h"
#include "Model_fwd.h"
#include "../Geometry/Geometry_fwd.h"
#include "../Geometry/GeometryPoint.h"

namespace model
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// Объявление класса прямоугольника по двум точкам
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class RectByTwoPoints : public IRectParams
  {
  private:
    geometry::PointOpt m_firstPoint;  /// < первая вершина прямоугольника
    geometry::PointOpt m_secondPoint; /// < вторая вершина прямоугольника
  public:
    /// Постройка примитивов по заданным точкам
    virtual PrimitiveContainer Build() const override;
    /// Добавление геометрической точки в прямоугольник
    virtual void AddPoint(const geometry::Point&) override;
    /// Метод, дающий ответ о том, готов ли прямоугольник к построению
    virtual bool IsReady() const override;
    /// Метод для изменения последней точки
    virtual void ChangeLastPoint(const geometry::Point&) override;
    /// Создать копию объекта
    virtual std::unique_ptr<IRectParams> Duplicate() const override;
  };

}   //namespace model