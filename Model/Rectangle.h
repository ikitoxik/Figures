////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Объявление класса прямоугольника
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "../Geometry/Geometry_fwd.h"
#include "Figure.h"

namespace model
{
  class IRectParams;
} // namespace model

namespace model
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// Объявление класса прямоугольника
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class Rectangle : public Figure
  {
  private:
    std::unique_ptr<IRectParams> m_params; /// < параметры прямоугольника
  public:
    /// Деструктор
    ~Rectangle() = default;
    /// Конструктор по умолчанию
    Rectangle() = default;
    /// Конструктор по параметрам
    Rectangle(std::unique_ptr<IRectParams> params);
    /// Конструктор копирования
    Rectangle(const Rectangle&);
    /// Оператор копирования
    Rectangle& operator=(const Rectangle&) = delete;
    /// Конструктор перемещения 
    Rectangle(Rectangle&&) = delete;
    /// Оператор перемещения
    Rectangle& operator=(Rectangle&&) = delete;
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
    /// Вспомогательная функция для перерасчета примитивов фигуры
    void CalcPrims();
  };

}   //namespace model