////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ������ ����� Point
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Figure.h"


namespace model
{

  ////////////////////////////////////////////////////////////////////////////////
  //
  /// ���������� ������ ����� Point
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class Point : public Figure
  {
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
  };

} //namespace model