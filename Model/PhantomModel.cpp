////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief ���������� ������ PhantomModel
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
     ����������
  */
  //-
  PhantomModel::~PhantomModel()
  {
    CleanFigure();
  }

  //------------------------------------------------------------------------------
  /**
     ����� ���������� ������ � ��������� ������
  */
  //---
  void PhantomModel::SetTempFigure(FigureUPtr figure)
  {
    m_figure = std::move(figure);
    Notify();
  }

  //------------------------------------------------------------------------------
  /**
     ����� ��������� ������ �� ��������� ������
  */
  //---
  const IFigure* PhantomModel::GetTempFigure() const
  {
    return m_figure.get();
  }

  //------------------------------------------------------------------------------
  /**
     ����������� ������ �� ��������� ������ � �������
  */
  //---
  void PhantomModel::TransferPhantomFigure(IModel& model)
  {
    model.AddFigure(std::move(m_figure));
    Notify();
  }

  //------------------------------------------------------------------------------
  /**
     �������� ��������� ������
  */
  //---
  void PhantomModel::CleanFigure()
  {
    m_figure.reset();
    Notify();
  }

  //------------------------------------------------------------------------------
  /**
     �������� ��������� �� �����������
  */
  //--- 
  void PhantomModel::AddObserver(UpdateFunc callback)
  {
    m_callbacks.emplace_back(callback);
  }

  //------------------------------------------------------------------------------
  /**
     ��������� ����������� �� ���������
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
     �������� ������� PhantomModel
  */
  //--- 
  std::unique_ptr<PhantomModel> CreatePhantomModel()
  {
    return std::make_unique<PhantomModel>();
  }

} //namespace model