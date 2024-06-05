////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Реализация класса прямоугольника по двум точкам
*/
//
////////////////////////////////////////////////////////////////////////////////

#include "RectByTwoPoints.h"
#include "../Geometry/GeometryLineSegment.h"
#include "IFigure.h"
#include "../Utils/Last.h"


namespace model
{
  //------------------------------------------------------------------------------
  /**
    Постройка примитивов по двум противоположным точкам
    \param firstPoint первая точка
    \param secondPoint вторая точка
    \return контейнер примитивов, нужных для построения прямоугольника
  */
  //--- 
  PrimitiveContainer Build(const geometry::Point& firstPoint, const geometry::Point& secondPoint)
  {
    PrimitiveContainer primitives;
    constexpr size_t numberOfPrims = 4;
    primitives.reserve(numberOfPrims);
    geometry::Point thirdPoint(firstPoint.GetX(), secondPoint.GetY());
    geometry::Point fourthPoint(secondPoint.GetX(), firstPoint.GetY());
    primitives.push_back(std::make_shared<geometry::LineSegment>(firstPoint, fourthPoint));
    primitives.push_back(std::make_shared<geometry::LineSegment>(firstPoint, thirdPoint));
    primitives.push_back(std::make_shared<geometry::LineSegment>(secondPoint, fourthPoint));
    primitives.push_back(std::make_shared<geometry::LineSegment>(secondPoint, thirdPoint));

    return primitives;
  }
  //------------------------------------------------------------------------------
  /**
    Постройка примитивов по двум точкам
    \return контейнер примитивов, нужных для построения прямоугольника
  */
  //--- 
  PrimitiveContainer RectByTwoPoints::Build() const
  {
    PrimitiveContainer primitives;
    if (m_firstPoint.has_value() && m_secondPoint.has_value())
      primitives = model::Build(m_firstPoint.value(), m_secondPoint.value());

    return primitives;
  }

  //------------------------------------------------------------------------------
    /**
       Добавление геометрической точки в прямоугольник
       \param point геометрическая точка, добавляемая в прямоугольник
    */
    //--- 
  void RectByTwoPoints::AddPoint(const geometry::Point& point)
  {
    if (!m_firstPoint.has_value())
    {
      m_firstPoint.emplace(point);
    }
    else
    {
      m_secondPoint.emplace(point);
    }
  }

  //------------------------------------------------------------------------------
  /**
     Метод, дающий ответ о том, готов ли прямоугольник к построению
     \return готова ли фигура к построению
  */
  //--- 
  /// 
  bool RectByTwoPoints::IsReady() const
  {
    return m_secondPoint.has_value();
  }

  //------------------------------------------------------------------------------
  /**
    Изменить последнюю точку
    \param point геометрическая точка, на которую заменяется последняя точка прямоугольника
  */
  //--- 
  void RectByTwoPoints::ChangeLastPoint(const geometry::Point& point)
  {
    if (m_firstPoint.has_value())
    {
      m_secondPoint.emplace(point);
    }
  }

  //------------------------------------------------------------------------------
  /**
    Создать копию объекта
    \return указатель на копию прямоугольника по двум точкам
  */
  //--- 
  std::unique_ptr<IRectParams> RectByTwoPoints::Duplicate() const
  {
    return std::make_unique<RectByTwoPoints>(*this);
  }

} // namespace model