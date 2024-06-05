////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Объявление интерфейса примитивов
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace geometry
{
  class Point;
  struct Vector;
} // namepsace geometry

namespace geometry
{
  /// Типы примитивов 
  enum class PrimitiveType
  {
    Point,       /// < точка
    LineSegment, /// < отрезок
    Circle ///< окружность
  };

  ////////////////////////////////////////////////////////////////////////////////
  //
  /// Интерфейс примтивов
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class IPrimitive
  {
  public:
    /// Деструктор
    virtual ~IPrimitive() = default;
    /// Метод, возвращающий тип примитива
    virtual PrimitiveType GetType() const = 0;
  };
} //namespace geometry