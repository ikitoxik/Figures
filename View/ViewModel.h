////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ������ ViewModel
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ViewBase.h"

namespace view
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// ����� ��� �������� �������
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class ViewModel : public ViewBase
  {
    std::vector<DrawData> m_data;	/// < ��������� �������� ���������
  public:
    /// ����� ��������� ������ �� ������
    virtual void Update(const PrimitiveContainer& prim_container) override;
    /// ����� ��������� ������� �������� ���������
    virtual std::vector<DrawData> GetDrawData() override;
  };
}   //namespace view