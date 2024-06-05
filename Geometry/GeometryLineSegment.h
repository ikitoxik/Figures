////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief ���������� ������ ������� ����������
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "GeometryPoint.h"

namespace geometry
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// ���������� ������ ������� ����������
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class LineSegment : public IPrimitive
  {
  private:
    Point m_begPoint;    /// < ��������� ����� �������
    Point m_endPoint;    /// < �������� ����� �������
  public:
    /// �����������
    LineSegment(const Point& begPoint = { 0.0, 0.0 }, const Point& endPoint = { 1.0, 1.0 });
    /// �����, ������������ ��� ���������
    virtual PrimitiveType GetType() const override;
    /// ����� ��������� ������ �����
    const Point& GetBeg() const;
    /// ����� ��������� ������ �����
    const Point& GetEnd() const;
  };
} // namespace geometry