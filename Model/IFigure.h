////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Объявление интерфейса фигур
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Model_fwd.h"

#include "../Geometry/GeometryPoint.h"

namespace model
{
  /// Типы фигур
  enum class FigureType
  {
    Point,       ///< точка
    LineSegment, ///< отрезок
    Rectangle,   ///< прямоуголньик
    Circle  ///< окружность
  };

  ////////////////////////////////////////////////////////////////////////////////
  //
  /// Интерфейс фигур
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class IFigure 
  {
  public:
    /// Деструктор
    virtual ~IFigure() = default;
    /// Метод получения типа фигуры
    virtual FigureType GetType() const = 0;
    /// Метод получения примитивов фигуры
    virtual PrimitiveContainer GetPrimitives() const = 0;
    /// Метод добавления точки примитивов в фигуру
    virtual void AddPoint(const geometry::Point&) = 0;
    /// Метод, дающий ответ о том, готова ли фигура к построению
    virtual bool IsReady() const = 0;
    /// Установка Id фигуры
    virtual void SetId(IdType) = 0;
    /// Получение id фигуры
    virtual IdType GetId() const = 0;
    /// Метод, позволяющий создать копию объекта
    virtual FigureUPtr Duplicate() const = 0;
    /// Метод для изменения последней точки
    virtual void ChangeLastPoint(const geometry::Point&) = 0;
  };

} // namespace model