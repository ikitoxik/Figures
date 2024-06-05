////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ������ �������
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "../Geometry/Geometry_fwd.h"

#include "Figure.h"


namespace model
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// ���������� ������ �������
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class Circle : public Figure
  {
  private:
    geometry::PointOpt m_centerPoint; /// < ��������� ����� �������
    geometry::PointOpt m_PointOnCircle; /// < �������� ����� �������
  public:

    /// ��������� ���� ������
    virtual FigureType GetType() const override;
    /// �����, ������ ����� � ���, ������ �� ������ � ����������
    virtual bool IsReady() const override;
    /// ���������� �������������� ����� � ������
    virtual void AddPoint(const geometry::Point&) override;
    /// ��������������� ������� ��� ����������� ���������� ������

    /// �����, ����������� ������� ����� �������
    virtual FigureUPtr Duplicate() const override;
    /// ����� ��� ��������� ��������� �����
    virtual void ChangeLastPoint(const geometry::Point&) override;
    /// ��������������� ������� ��� ����������� ���������� ������

    void CalcPrims();
  };

}   //namespace model