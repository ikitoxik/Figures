////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ���������� ��������� ����� IModel
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Model_fwd.h"
#include "IObservable.h"

////////////////////////////////////////////////////////////////////////////////
//
/// ��������� ��������� ����� IModel
/**
*/
////////////////////////////////////////////////////////////////////////////////
namespace model
{
  class IModel
  {
  public:
    /// ����������
    virtual ~IModel() = default;
    /// ����� ���������� ������ � ������
    virtual void AddFigure(FigureUPtr) = 0;
    /// ����� ��������� ���� ���������� ������
    virtual PrimitiveContainer GetAllPrimitives() const = 0;
  };

  /// ����� �������� ������� Model
  std::unique_ptr<IModel> CreateModel();

}   //namespace model