////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief Реализация класса PhantomModel
*/
//
////////////////////////////////////////////////////////////////////////////////

#include "PhantomModel.h"

#include "Model.h"
#include "IObservable.h"
#include "../View/IObserver.h"
#include "IFigure.h"
#include "../Utils/Last.h"


namespace model
{
  //------------------------------------------------------------------------------
  /**
     Деструктор
  */
  //-
  PhantomModel::~PhantomModel()
  {
    CleanFigure();
  }

  //------------------------------------------------------------------------------
  /**
     Метод добавления фигуры в фантомную модель
  */
  //---
  void PhantomModel::SetTempFigure(FigureUPtr figure)
  {
    m_figure = std::move(figure);
    Notify();
  }

  //------------------------------------------------------------------------------
  /**
     Метод получения фигуры из фантомной модели
  */
  //---
  const IFigure* PhantomModel::GetTempFigure() const
  {
    return m_figure.get();
  }

  //------------------------------------------------------------------------------
  /**
     Переместить фигуру из фантомной модели в обычную
  */
  //---
  void PhantomModel::TransferPhantomFigure(IModel& model)
  {
    model.AddFigure(std::move(m_figure));
    Notify();
  }

  //------------------------------------------------------------------------------
  /**
     Очистить фантомную фигуру
  */
  //---
  void PhantomModel::CleanFigure()
  {
    m_figure.reset();
    Notify();
  }

  //------------------------------------------------------------------------------
  /**
     Добавить указатель на наблюдатель
  */
  //--- 
  void PhantomModel::AddObserver(UpdateFunc callback)
  {
    m_callbacks.emplace_back(callback);
  }

  //------------------------------------------------------------------------------
  /**
     Уведомить наблюдатели об изменении
  */
  //--- 
  void PhantomModel::Notify() const
  {
    PrimitiveContainer primitives;
    if (m_figure)
      primitives = m_figure->GetPrimitives();

    for (const auto& callback : m_callbacks)
    {
      callback(primitives);
    }
  }

  //------------------------------------------------------------------------------
  /**
     Создание объекта PhantomModel
  */
  //--- 
  std::unique_ptr<PhantomModel> CreatePhantomModel()
  {
    return std::make_unique<PhantomModel>();
  }

} //namespace model