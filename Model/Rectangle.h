////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ������ ��������������
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "../Geometry/Geometry_fwd.h"
#include "Figure.h"

namespace model
{
  class IRectParams;
} // namespace model

namespace model
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// ���������� ������ ��������������
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class Rectangle : public Figure
  {
  private:
    std::unique_ptr<IRectParams> m_params; /// < ��������� ��������������
  public:
    /// ����������
    ~Rectangle() = default;
    /// ����������� �� ���������
    Rectangle() = default;
    /// ����������� �� ����������
    Rectangle(std::unique_ptr<IRectParams> params);
    /// ����������� �����������
    Rectangle(const Rectangle&);
    /// �������� �����������
    Rectangle& operator=(const Rectangle&) = delete;
    /// ����������� ����������� 
    Rectangle(Rectangle&&) = delete;
    /// �������� �����������
    Rectangle& operator=(Rectangle&&) = delete;
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