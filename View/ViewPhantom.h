////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Объявление класса ViewPhantom
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ViewBase.h"

namespace view
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// Класс для хранения фантомов
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class ViewPhantom : public ViewBase
  {
    std::vector<DrawData> m_data;	/// < контейнер объектов отрисовки
  public:
    /// Метод получения данных из модели
    virtual void Update(const PrimitiveContainer& prim_container) override;
    /// Метод получения вектора объектов отрисовки
    virtual std::vector<DrawData> GetDrawData() override;
  };
}