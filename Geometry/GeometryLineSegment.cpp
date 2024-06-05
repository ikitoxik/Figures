////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief Реализация класса отрезка примитивов
*/
//
////////////////////////////////////////////////////////////////////////////////


#include "GeometryLineSegment.h"
#include "../Utils/Last.h"

namespace geometry
{
  //------------------------------------------------------------------------------
  /**
     Конструктор
     \param begPoint начальная точка отрезка
     \param endPoint конечная точка отрезка
  */
  //--- 
  LineSegment::LineSegment(const Point& begPoint, const Point& endPoint)
    : m_begPoint(begPoint)
    , m_endPoint(endPoint)
  {
  }

  //------------------------------------------------------------------------------
  /**
     Метод, возвращающий тип примитива
  */
  //--- 
  PrimitiveType LineSegment::GetType() const
  {
    return PrimitiveType::LineSegment;
  }

  //------------------------------------------------------------------------------
  /**
    Метод получения начальной точки отрезка
  */
  //--- 
  const Point& LineSegment::GetBeg() const
  {
    return m_begPoint;
  }

  //------------------------------------------------------------------------------
  /**
     Метод получения конечной точки отрезка
  */
  //--- 
  const Point& LineSegment::GetEnd() const
  {
    return m_endPoint;
  }

} // namespace geometry