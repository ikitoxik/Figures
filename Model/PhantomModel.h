////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief Объявление класса PhantomModel
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once 

#include "IObservable.h"
#include "Model_fwd.h"
#include "../Geometry/GeometryPoint.h"

namespace model
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// Объявление класса PhantomModel
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class PhantomModel : public IObservable
  {
  private:
    std::vector<UpdateFunc> m_callbacks; ///< наблюдатели, которых надо оповестить об изменении
    FigureUPtr m_figure; ///< фигура
  public:
    /// Деструктор
    ~PhantomModel();
    /// Метод добавления фигуры в фантомную модель
    void SetTempFigure(FigureUPtr);
    /// Метод получения фигуры из фантомной модели
    const IFigure* GetTempFigure() const;
    /// Переместить фигуру из фантомной модели в обычную
    void TransferPhantomFigure(IModel&);
    /// Очистить фантомную фигуру
    void CleanFigure();
    /// Добавить указатель на наблюдатель
    virtual void AddObserver(UpdateFunc) override;
    /// Уведомить наблюдатели об изменении 
    virtual void Notify() const override;
  };

  /// Создать объекта фантомной модели
  std::unique_ptr<PhantomModel> CreatePhantomModel();
} // namespace model