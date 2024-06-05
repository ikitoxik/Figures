////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Объявление интерфейса модельной части IModel
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Model_fwd.h"
#include "IObservable.h"

////////////////////////////////////////////////////////////////////////////////
//
/// Интерфейс модельной части IModel
/**
*/
////////////////////////////////////////////////////////////////////////////////
namespace model
{
  class IModel
  {
  public:
    /// Деструктор
    virtual ~IModel() = default;
    /// Метод добавления фигуры в модель
    virtual void AddFigure(FigureUPtr) = 0;
    /// Метод получения всех примитивов модели
    virtual PrimitiveContainer GetAllPrimitives() const = 0;
  };

  /// Метод создания объекта Model
  std::unique_ptr<IModel> CreateModel();

}   //namespace model