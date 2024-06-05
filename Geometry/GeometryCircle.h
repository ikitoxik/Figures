////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief Объявление класса окружность примитивов
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "GeometryPoint.h"

namespace geometry
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// Объявление класса окружность примитивов
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class Circle : public IPrimitive
  {
  private:
    Point m_center;    /// < центральная точка окружности
    Point m_onCircle;    /// < точка на окружности
  public:
    /// Конструктор
    Circle(const Point& m_center = { 0.0, 0.0 }, const Point& m_onCircle = { 1.0, 1.0 });
    /// Метод, возвращающий тип примитива
    virtual PrimitiveType GetType() const override;
    /// Метод получения первой точки
    const Point& GetCenter() const;
    /// Метод получения второй точки
    const Point& GetOnCircle() const;
  };
} // namespace geometry