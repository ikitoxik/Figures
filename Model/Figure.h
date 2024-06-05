////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ������ Figure
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "IFigure.h"

namespace model
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// ���������� ������ Figure
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class Figure : public IFigure
  {
  protected:
    PrimitiveContainer m_primitives; ///< ���������, ���������� � ������
    IdType m_id; ///< id ������
  public:
    /// �����������
    Figure() = default;
    /// ����������
    ~Figure() = default;
    /// ����������� �����������
    Figure(const Figure&) = default;
    /// ����������� �����������
    Figure(Figure&&) = delete;
    /// �������� �����������
    Figure& operator=(const Figure&) = delete;
    /// �������� �����������
    Figure& operator=(Figure&&) = delete;
    /// ���������� Id ������
    virtual void SetId(IdType) override;
    /// �������� id ������
    virtual IdType GetId() const override;
    /// ����� ��������� ���������� ������
    virtual PrimitiveContainer GetPrimitives() const override;
  };
}