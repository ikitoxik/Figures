////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Объявление класса отрезка
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "../Geometry/Geometry_fwd.h"

#include "Figure.h"


namespace model
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// Объявление класса отрезка
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class Circle : public Figure
  {
  private:
    geometry::PointOpt m_centerPoint; /// < начальная точка отрезка
    geometry::PointOpt m_PointOnCircle; /// < конечная точка отрезка
  public:

    /// Получение типа фигуры
    virtual FigureType GetType() const override;
    /// Метод, дающий ответ о том, готова ли фигура к построению
    virtual bool IsReady() const override;
    /// Добавление геометрической точки в фигуру
    virtual void AddPoint(const geometry::Point&) override;
    /// Вспомогательная функция для перерасчета примитивов фигуры

    /// Метод, позволяющий создать копию объекта
    virtual FigureUPtr Duplicate() const override;
    /// Метод для изменения последней точки
    virtual void ChangeLastPoint(const geometry::Point&) override;
    /// Вспомогательная функция для перерасчета примитивов фигуры

    void CalcPrims();
  };

}   //namespace model