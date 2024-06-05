////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Реализация класса окружность
*/
//
////////////////////////////////////////////////////////////////////////////////

#include "Circle.h"
#include "../Geometry/GeometryCircle.h"
#include "../Utils/Last.h"


namespace model
{
  //------------------------------------------------------------------------------
    /**
       Добавление геометрической точки в окружность
       \param point геометрическая точка, добавляемая в окружность
    */
    //--- 
  void Circle::AddPoint(const geometry::Point& point)
  {
    if (!m_centerPoint.has_value())
    {
      m_centerPoint.emplace(point);
    }
    else
    {
      m_PointOnCircle.emplace(point);
    }
  }

  //------------------------------------------------------------------------------
  /**
     Метод, дающий ответ о том, готова ли окружность к построению
     \return готова ли фигура к построению
  */
  //--- 
  /// 
  bool Circle::IsReady() const
  {
    return m_PointOnCircle.has_value();
  }

  //------------------------------------------------------------------------------
  /**
    Изменить последнюю точку
    \param point геометрическая точка, на которую заменяется последняя точка окружности
  */
  //--- 
  void Circle::ChangeLastPoint(const geometry::Point& point)
  {
    if (m_centerPoint.has_value())
    {
      m_PointOnCircle.emplace(point);
      CalcPrims();
    }
  }

  //------------------------------------------------------------------------------
  /**
    Создать копию объекта
    \return указатель на копию окружности по двум точкам
  */
  //--- 
  FigureUPtr Circle::Duplicate() const
  {
    return std::make_unique<Circle>(*this);
  }

  //------------------------------------------------------------------------------
/**
   Получение типа фигуры
*/
//--- 
  FigureType Circle::GetType() const
  {
    return FigureType::Circle;
  }

  //------------------------------------------------------------------------------
/**
  Вспомогательная функция для перерасчета примитивов фигуры
*/
//--- 
  void Circle::CalcPrims()
  {
    if (m_centerPoint.has_value() && m_PointOnCircle.has_value())
      m_primitives = { std::make_shared<geometry::Circle>(m_centerPoint.value(), m_PointOnCircle.value()) };
    else
      m_primitives.clear();
  }

} // namespace model