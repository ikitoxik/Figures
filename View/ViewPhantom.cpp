////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief ���������� ������ ViewPhantom
*/
//
////////////////////////////////////////////////////////////////////////////////


#include "ViewPhantom.h"
#include "../Utils/Last.h"

namespace view
{
  //------------------------------------------------------------------------------
  /**
     ��������� ������ �� ������
  */
  //---
  void ViewPhantom::Update(const PrimitiveContainer& prim_container)
  {
    QColor color = Qt::black;
    constexpr unsigned int width = 1;
    m_data.clear();
    for (auto& i : prim_container)
    {
      DrawData temp{ i, color, width };
      m_data.emplace_back(temp);
    }
  }

  //------------------------------------------------------------------------------
  /**
     ��������� ���������� �������� ���������
  */
  //---
  std::vector<DrawData> ViewPhantom::GetDrawData()
  {
    return m_data;
  }
}