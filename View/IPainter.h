////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief ���������� ������ IPainter
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
  /// ���������� ������ IPainter
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class IPainter
  {
  public:
    /// ����������
    virtual ~IPainter() = default;
    /// ����� ��� ���������
    virtual void Draw(const view::DrawData&) = 0;
  };


  using IPainterUPtr = std::unique_ptr<view::IPainter>;

  /// ����� �������� ������� Model
  std::unique_ptr<IPainter> CreatePainter(QPainter*);

} // namespace view

