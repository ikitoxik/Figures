////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ������ ViewPhantom
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ViewBase.h"

namespace view
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// ����� ��� �������� ��������
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class ViewPhantom : public ViewBase
  {
    std::vector<DrawData> m_data;	/// < ��������� �������� ���������
  public:
    /// ����� ��������� ������ �� ������
    virtual void Update(const PrimitiveContainer& prim_container) override;
    /// ����� ��������� ������� �������� ���������
    virtual std::vector<DrawData> GetDrawData() override;
  };
}