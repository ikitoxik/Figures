////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief ���������� ������ ���������� ����������
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "GeometryPoint.h"

namespace geometry
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// ���������� ������ ���������� ����������
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class Circle : public IPrimitive
  {
  private:
    Point m_center;    /// < ����������� ����� ����������
    Point m_onCircle;    /// < ����� �� ����������
  public:
    /// �����������
    Circle(const Point& m_center = { 0.0, 0.0 }, const Point& m_onCircle = { 1.0, 1.0 });
    /// �����, ������������ ��� ���������
    virtual PrimitiveType GetType() const override;
    /// ����� ��������� ������ �����
    const Point& GetCenter() const;
    /// ����� ��������� ������ �����
    const Point& GetOnCircle() const;
  };
} // namespace geometry