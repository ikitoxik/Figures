////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Объявление класса ViewModel
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ViewBase.h"

namespace view
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// класс для хранения моделей
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class ViewModel : public ViewBase
  {
    std::vector<DrawData> m_data;	/// < контейнер объектов отрисовки
  public:
    /// Метод получения данных из модели
    virtual void Update(const PrimitiveContainer& prim_container) override;
    /// Метод получения вектора объектов отрисовки
    virtual std::vector<DrawData> GetDrawData() override;
  };
}   //namespace view