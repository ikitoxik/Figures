////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Реализация класса отрезка
*/
//
////////////////////////////////////////////////////////////////////////////////


#include "LineSegment.h"
#include "../Geometry/GeometryLineSegment.h"
#include "../Utils/Last.h"


namespace model
{
  //------------------------------------------------------------------------------
  /**
     Получение типа фигуры
  */
  //--- 
  FigureType LineSegment::GetType() const
  {
    return FigureType::LineSegment;
  }

  //------------------------------------------------------------------------------
  /**
     Метод, дающий ответ о том, готова ли фигура к построению
     \return готова ли фигура к построению
  */
  //--- 
  bool LineSegment::IsReady() const
  {
    return m_endPoint.has_value();
  }

  //------------------------------------------------------------------------------
  /**
     Добавление геометрической точки в фигуру
     \param point геометрическая точка, добавляемая в фигуру
  */
  //--- 
  void LineSegment::AddPoint(const geometry::Point& point)
  {
    if (!m_begPoint.has_value())
    {
      m_begPoint.emplace(point);
    }
    else
    {
      m_endPoint.emplace(point);
      CalcPrims();
    }
  }

  //------------------------------------------------------------------------------
  /**
    Создать копию отрезка
  */
  //--- 
  FigureUPtr LineSegment::Duplicate() const
  {
    return std::make_unique<LineSegment>(*this);
  }

  //------------------------------------------------------------------------------
  /**
    Изменить последнюю точку
  */
  //--- 
  void LineSegment::ChangeLastPoint(const geometry::Point& point)
  {
    if (m_begPoint.has_value())
    {
      m_endPoint.emplace(point);
      CalcPrims();
    }
  }

  //------------------------------------------------------------------------------
  /**
    Вспомогательная функция для перерасчета примитивов фигуры
  */
  //--- 
  void LineSegment::CalcPrims()
  {
    if (m_begPoint.has_value() && m_endPoint.has_value())
      m_primitives = { std::make_shared<geometry::LineSegment>(m_begPoint.value(), m_endPoint.value()) };
    else
      m_primitives.clear();
  }
} // namespace model