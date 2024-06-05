////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief Объявление класса отрезка примитивов
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "GeometryPoint.h"

namespace geometry
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// Объявление класса отрезка примитивов
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class LineSegment : public IPrimitive
  {
  private:
    Point m_begPoint;    /// < начальная точка отрезка
    Point m_endPoint;    /// < конечная точка отрезка
  public:
    /// Конструктор
    LineSegment(const Point& begPoint = { 0.0, 0.0 }, const Point& endPoint = { 1.0, 1.0 });
    /// Метод, возвращающий тип примитива
    virtual PrimitiveType GetType() const override;
    /// Метод получения первой точки
    const Point& GetBeg() const;
    /// Метод получения второй точки
    const Point& GetEnd() const;
  };
} // namespace geometry