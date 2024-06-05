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
  class LineSegment : public Figure
  {
  private:
    geometry::PointOpt m_begPoint; /// < ��������� ����� �������
    geometry::PointOpt m_endPoint; /// < �������� ����� �������
  public:
    /// ��������� ���� ������
    virtual FigureType GetType() const override;
    /// �����, ������ ����� � ���, ������ �� ������ � ����������
    virtual bool IsReady() const override;
    /// ���������� �������������� ����� � ������
    virtual void AddPoint(const geometry::Point&) override;
    /// �����, ����������� ������� ����� �������
    virtual FigureUPtr Duplicate() const override;
    /// ����� ��� ��������� ��������� �����
    virtual void ChangeLastPoint(const geometry::Point&) override;
    /// ��������������� ������� ��� ����������� ���������� ������
    void CalcPrims();
  };

}   //namespace model