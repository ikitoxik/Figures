////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief Реализация класса ViewPhantom
*/
//
////////////////////////////////////////////////////////////////////////////////


#include "ViewPhantom.h"
#include "../Utils/Last.h"

namespace view
{
  //------------------------------------------------------------------------------
  /**
     Получение данных из модели
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
     Получение контейнера объектов отрисовки
  */
  //---
  std::vector<DrawData> ViewPhantom::GetDrawData()
  {
    return m_data;
  }
}