////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ������ �������������� �� ������ � �����
*/
//
////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "IRectParams.h"
#include "Model_fwd.h"
#include "../Geometry/Geometry_fwd.h"
#include "../Geometry/GeometryPoint.h"

namespace model
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// ���������� ������ �������������� �� ������ � �����
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class RectByCenterAndPoint : public IRectParams
  {
  private:
    geometry::PointOpt m_center;  /// < ����� ��������������
    geometry::PointOpt m_firstPoint; /// < ������ ������� ��������������
  public:
    /// ��������� ���������� �� �������� ������
    virtual PrimitiveContainer Build() const override;
    /// ���������� �������������� ����� � �������������
    virtual void AddPoint(const geometry::Point&) override;
    /// �����, ������ ����� � ���, ����� �� ������������� � ����������
    virtual bool IsReady() const override;
    /// ����� ��� ��������� ��������� �����
    virtual void ChangeLastPoint(const geometry::Point&) override;
    /// ������� ����� �������
    virtual std::unique_ptr<IRectParams> Duplicate() const override;
  };

}   //namespace model