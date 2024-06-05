////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ������ ����������
*/
//
////////////////////////////////////////////////////////////////////////////////

#include "Circle.h"
#include "../Geometry/GeometryCircle.h"
#include "../Utils/Last.h"


namespace model
{
  //------------------------------------------------------------------------------
    /**
       ���������� �������������� ����� � ����������
       \param point �������������� �����, ����������� � ����������
    */
    //--- 
  void Circle::AddPoint(const geometry::Point& point)
  {
    if (!m_centerPoint.has_value())
    {
      m_centerPoint.emplace(point);
    }
    else
    {
      m_PointOnCircle.emplace(point);
    }
  }

  //------------------------------------------------------------------------------
  /**
     �����, ������ ����� � ���, ������ �� ���������� � ����������
     \return ������ �� ������ � ����������
  */
  //--- 
  /// 
  bool Circle::IsReady() const
  {
    return m_PointOnCircle.has_value();
  }

  //------------------------------------------------------------------------------
  /**
    �������� ��������� �����
    \param point �������������� �����, �� ������� ���������� ��������� ����� ����������
  */
  //--- 
  void Circle::ChangeLastPoint(const geometry::Point& point)
  {
    if (m_centerPoint.has_value())
    {
      m_PointOnCircle.emplace(point);
      CalcPrims();
    }
  }

  //------------------------------------------------------------------------------
  /**
    ������� ����� �������
    \return ��������� �� ����� ���������� �� ���� ������
  */
  //--- 
  FigureUPtr Circle::Duplicate() const
  {
    return std::make_unique<Circle>(*this);
  }

  //------------------------------------------------------------------------------
/**
   ��������� ���� ������
*/
//--- 
  FigureType Circle::GetType() const
  {
    return FigureType::Circle;
  }

  //------------------------------------------------------------------------------
/**
  ��������������� ������� ��� ����������� ���������� ������
*/
//--- 
  void Circle::CalcPrims()
  {
    if (m_centerPoint.has_value() && m_PointOnCircle.has_value())
      m_primitives = { std::make_shared<geometry::Circle>(m_centerPoint.value(), m_PointOnCircle.value()) };
    else
      m_primitives.clear();
  }

} // namespace model