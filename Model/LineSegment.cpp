////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ������ �������
*/
//
////////////////////////////////////////////////////////////////////////////////


#include "LineSegment.h"
#include "../Geometry/GeometryLineSegment.h"
#include "../Utils/Last.h"


namespace model
{
  //------------------------------------------------------------------------------
  /**
     ��������� ���� ������
  */
  //--- 
  FigureType LineSegment::GetType() const
  {
    return FigureType::LineSegment;
  }

  //------------------------------------------------------------------------------
  /**
     �����, ������ ����� � ���, ������ �� ������ � ����������
     \return ������ �� ������ � ����������
  */
  //--- 
  bool LineSegment::IsReady() const
  {
    return m_endPoint.has_value();
  }

  //------------------------------------------------------------------------------
  /**
     ���������� �������������� ����� � ������
     \param point �������������� �����, ����������� � ������
  */
  //--- 
  void LineSegment::AddPoint(const geometry::Point& point)
  {
    if (!m_begPoint.has_value())
    {
      m_begPoint.emplace(point);
    }
    else
    {
      m_endPoint.emplace(point);
      CalcPrims();
    }
  }

  //------------------------------------------------------------------------------
  /**
    ������� ����� �������
  */
  //--- 
  FigureUPtr LineSegment::Duplicate() const
  {
    return std::make_unique<LineSegment>(*this);
  }

  //------------------------------------------------------------------------------
  /**
    �������� ��������� �����
  */
  //--- 
  void LineSegment::ChangeLastPoint(const geometry::Point& point)
  {
    if (m_begPoint.has_value())
    {
      m_endPoint.emplace(point);
      CalcPrims();
    }
  }

  //------------------------------------------------------------------------------
  /**
    ��������������� ������� ��� ����������� ���������� ������
  */
  //--- 
  void LineSegment::CalcPrims()
  {
    if (m_begPoint.has_value() && m_endPoint.has_value())
      m_primitives = { std::make_shared<geometry::LineSegment>(m_begPoint.value(), m_endPoint.value()) };
    else
      m_primitives.clear();
  }
} // namespace model