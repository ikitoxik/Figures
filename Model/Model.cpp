////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief ���������� � ���������� ������ Model
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
  /// ���������� ������ Model
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class Model : public IModel, public IObservable
  {
  private:
    std::vector<UpdateFunc> m_callbacks; /// < �����������, ������� ���� ���������� �� ���������
    std::vector<FigureUPtr> m_figures; /// < ������
    IdType m_counter; /// < ������� �����
  public:
    /// �����������
    Model();
    /// �������� ������ � ������
    virtual void AddFigure(FigureUPtr figure) override;
    /// �������� ��������� �� �����������
    virtual void AddObserver(UpdateFunc) override;
    /// ��������� ����������� �� ���������
    virtual void Notify() const override;

    /// �������� ��� ��������� ������
    virtual PrimitiveContainer GetAllPrimitives() const override;
  };


  //------------------------------------------------------------------------------
  /**
    ����������
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
     �������� ������ � ������
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
   �������� ��� ��������� ������
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
      �������� ��������� �� �����������
  */
  //--- 
  void Model::AddObserver(UpdateFunc callback)
  {
    m_callbacks.emplace_back(callback);
  }

  //------------------------------------------------------------------------------
  /**
     ��������� ����������� �� ���������
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
    ������� ������ Model
  */
  //--- 
  std::unique_ptr<IModel> CreateModel()
  {
    return std::make_unique<Model>();
  }

} //namespace model