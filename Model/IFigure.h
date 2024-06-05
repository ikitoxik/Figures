////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ���������� �����
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Model_fwd.h"

#include "../Geometry/GeometryPoint.h"

namespace model
{
  /// ���� �����
  enum class FigureType
  {
    Point,       ///< �����
    LineSegment, ///< �������
    Rectangle,   ///< �������������
    Circle  ///< ����������
  };

  ////////////////////////////////////////////////////////////////////////////////
  //
  /// ��������� �����
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class IFigure 
  {
  public:
    /// ����������
    virtual ~IFigure() = default;
    /// ����� ��������� ���� ������
    virtual FigureType GetType() const = 0;
    /// ����� ��������� ���������� ������
    virtual PrimitiveContainer GetPrimitives() const = 0;
    /// ����� ���������� ����� ���������� � ������
    virtual void AddPoint(const geometry::Point&) = 0;
    /// �����, ������ ����� � ���, ������ �� ������ � ����������
    virtual bool IsReady() const = 0;
    /// ��������� Id ������
    virtual void SetId(IdType) = 0;
    /// ��������� id ������
    virtual IdType GetId() const = 0;
    /// �����, ����������� ������� ����� �������
    virtual FigureUPtr Duplicate() const = 0;
    /// ����� ��� ��������� ��������� �����
    virtual void ChangeLastPoint(const geometry::Point&) = 0;
  };

} // namespace model