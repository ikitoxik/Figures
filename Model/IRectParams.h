////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ���������� ���������� ��������������
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Model_fwd.h"
#include "../Geometry/Geometry_fwd.h"


namespace model
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// ���������� ���������� ���������� ��������������
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class IRectParams 
  {
  public:
    /// ����������
    virtual ~IRectParams() = default;
    /// ��������� ���������� �� �������� ������
    virtual PrimitiveContainer Build() const = 0;
    /// ���������� �������������� ����� � �������������
    virtual void AddPoint(const geometry::Point&) = 0;
    /// �����, ������ ����� � ���, ����� �� ������������� � ����������
    virtual bool IsReady() const = 0;

    /// ����� ��� ��������� ��������� �����
    virtual void ChangeLastPoint(const geometry::Point&) = 0;
    /// �����, ����������� ������� ����� �������
    virtual std::unique_ptr<IRectParams> Duplicate() const = 0;
  };

  /// ��������� ����� ��� ���������� ���������� �� ���� ��������������� ������
  PrimitiveContainer Build(const geometry::Point&, const geometry::Point&);

}   //namespace model