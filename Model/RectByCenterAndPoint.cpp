////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Реализация класса прямоугольника по центру и точке
*/
//
////////////////////////////////////////////////////////////////////////////////


#include "RectByCenterAndPoint.h"
#include "../Geometry/GeometryLineSegment.h"
#include "IFigure.h"
#include "../Utils/Last.h"

namespace model
{
  //------------------------------------------------------------------------------
  /**
    Постройка примитивов по центру и точке
    \return контейнер примитивов, нужных для построения прямоугольника
  */
  //--- 
  PrimitiveContainer RectByCenterAndPoint::Build() const
  {
    PrimitiveContainer primitives;
    if (m_center.has_value() && m_firstPoint.has_value())
    {
      double dx = m_center.value().GetX() - m_firstPoint.value().GetX();
      double dy = m_center.value().GetY() - m_firstPoint.value().GetY();
      double secondX = m_center.value().GetX() + dx;
      double secondY = m_center.value().GetY() + dy;
      geometry::Point secondPoint(secondX, secondY);
      primitives = model::Build(m_firstPoint.value(), secondPoint);
    }
    return primitives;
  }

  //------------------------------------------------------------------------------
    /**
       Добавление геометрической точки в прямоугольник
       \param point геометрическая точка, добавляемая в прямоугольник
    */
    //--- 
  void RectByCenterAndPoint::AddPoint(const geometry::Point& point)
  {
    if (!m_center.has_value())
    {
      m_center.emplace(point);
    }
    else
    {
      m_firstPoint.emplace(point);
    }
  }

  //------------------------------------------------------------------------------
  /**
     Метод, дающий ответ о том, готов ли прямоугольник к построению
     \return готова ли фигура к построению
  */
  //--- 
  /// 
  bool RectByCenterAndPoint::IsReady() const
  {
    return m_firstPoint.has_value();
  }

  //------------------------------------------------------------------------------
  /**
    Изменить последнюю точку
    \param point геометрическая точка, на которую заменяется последняя точка прямоугольника
  */
  //--- 
  void RectByCenterAndPoint::ChangeLastPoint(const geometry::Point& point)
  {
    if (m_center.has_value())
    {
      m_firstPoint.emplace(point);
    }
  }

  //------------------------------------------------------------------------------
  /**
    Создать копию объекта
    \return указатель на копию прямоугольника по центру и точке
  */
  //--- 
  std::unique_ptr<IRectParams> RectByCenterAndPoint::Duplicate() const
  {
    return std::make_unique<RectByCenterAndPoint>(*this);
  }

} // namespace model