////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Объявление класса точки Point
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Figure.h"


namespace model
{

  ////////////////////////////////////////////////////////////////////////////////
  //
  /// Объявление класса точки Point
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class Point : public Figure
  {
  public:
    /// Получение типа фигуры
    virtual FigureType GetType() const override;
    /// Метод, дающий ответ о том, готова ли фигура к построению
    virtual bool IsReady() const override;
    /// Добавление геометрической точки в фигуру
    virtual void AddPoint(const geometry::Point&) override;

    /// Метод, позволяющий создать копию объекта
    virtual FigureUPtr Duplicate() const override;
    /// Метод для изменения последней точки
    virtual void ChangeLastPoint(const geometry::Point&) override;
  };

} //namespace model