////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief Объявление класса IPainter
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "../View/View_fwd.h"
#include <QtWidgets>

namespace view
{
  struct DrawData;
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// Объявление класса IPainter
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class IPainter
  {
  public:
    /// Деструктор
    virtual ~IPainter() = default;
    /// Метод для отрисовки
    virtual void Draw(const view::DrawData&) = 0;
  };


  using IPainterUPtr = std::unique_ptr<view::IPainter>;

  /// Метод создания объекта Model
  std::unique_ptr<IPainter> CreatePainter(QPainter*);

} // namespace view

