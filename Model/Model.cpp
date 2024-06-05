////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief Объявление и реализация класса Model
*/
//
////////////////////////////////////////////////////////////////////////////////

#include "Model.h"
#include "IFigure.h"
#include "../Utils/Last.h"


namespace model
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// Объявление класса Model
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class Model : public IModel, public IObservable
  {
  private:
    std::vector<UpdateFunc> m_callbacks; /// < наблюдатели, которых надо оповестить об изменении
    std::vector<FigureUPtr> m_figures; /// < фигуры
    IdType m_counter; /// < счетчик фигур
  public:
    /// Конструктор
    Model();
    /// Добавить фигуры в модель
    virtual void AddFigure(FigureUPtr figure) override;
    /// Добавить указатель на наблюдатель
    virtual void AddObserver(UpdateFunc) override;
    /// Уведомить наблюдателя об изменении
    virtual void Notify() const override;

    /// Получить все примитивы модели
    virtual PrimitiveContainer GetAllPrimitives() const override;
  };


  //------------------------------------------------------------------------------
  /**
    Конструтор
  */
  //--- 
  Model::Model()
    : m_callbacks{}
    , m_figures{}
    , m_counter{ 1 }
  {
  }

  //------------------------------------------------------------------------------
  /**
     Добавить фигуры в модель
  */
  //--- 
  void Model::AddFigure(FigureUPtr figure)
  {
    figure->SetId(m_counter++);
    m_figures.push_back(std::move(figure));
    Notify();
  }

  //------------------------------------------------------------------------------
/**
   Получить все примитивы модели
*/
//--- 
  PrimitiveContainer Model::GetAllPrimitives() const
  {
    PrimitiveContainer primitives;
    for (const auto& figure : m_figures)
    {
      auto temp = figure.get()->GetPrimitives();
      primitives.insert(primitives.end(), temp.begin(), temp.end());
    }

    return primitives;
  }


  //------------------------------------------------------------------------------
  /**
      Добавить указатель на наблюдатель
  */
  //--- 
  void Model::AddObserver(UpdateFunc callback)
  {
    m_callbacks.emplace_back(callback);
  }

  //------------------------------------------------------------------------------
  /**
     Уведомить наблюдатели об изменении
  */
  //--- 
  void Model::Notify() const
  {
    auto prims = GetAllPrimitives();
    for (const auto& callback : m_callbacks)
    {
      callback(prims);
    }
  }

  //------------------------------------------------------------------------------
  /**
    Создать объект Model
  */
  //--- 
  std::unique_ptr<IModel> CreateModel()
  {
    return std::make_unique<Model>();
  }

} //namespace model