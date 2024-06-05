////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Объявление класса Figure
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "IFigure.h"

namespace model
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// Объявление класса Figure
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class Figure : public IFigure
  {
  protected:
    PrimitiveContainer m_primitives; ///< примитивы, хранящиеся в фигуре
    IdType m_id; ///< id фигуры
  public:
    /// Конструктор
    Figure() = default;
    /// Деструктор
    ~Figure() = default;
    /// Конструктор копирования
    Figure(const Figure&) = default;
    /// Конструктор перемещения
    Figure(Figure&&) = delete;
    /// Оператор копирования
    Figure& operator=(const Figure&) = delete;
    /// Оператор перемещения
    Figure& operator=(Figure&&) = delete;
    /// Установить Id фигуры
    virtual void SetId(IdType) override;
    /// Получить id фигуры
    virtual IdType GetId() const override;
    /// Метод получения примитивов фигуры
    virtual PrimitiveContainer GetPrimitives() const override;
  };
}