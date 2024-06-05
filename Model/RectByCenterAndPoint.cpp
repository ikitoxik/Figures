////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ������ �������������� �� ������ � �����
*/
//
////////////////////////////////////////////////////////////////////////////////


#include "RectByCenterAndPoint.h"
#include "../Geometry/GeometryLineSegment.h"
#include "IFigure.h"
#include "../Utils/Last.h"

namespace model
{
  //------------------------------------------------------------------------------
  /**
    ��������� ���������� �� ������ � �����
    \return ��������� ����������, ������ ��� ���������� ��������������
  */
  //--- 
  PrimitiveContainer RectByCenterAndPoint::Build() const
  {
    PrimitiveContainer primitives;
    if (m_center.has_value() && m_firstPoint.has_value())
    {
      double dx = m_center.value().GetX() - m_firstPoint.value().GetX();
      double dy = m_center.value().GetY() - m_firstPoint.value().GetY();
      double secondX = m_center.value().GetX() + dx;
      double secondY = m_center.value().GetY() + dy;
      geometry::Point secondPoint(secondX, secondY);
      primitives = model::Build(m_firstPoint.value(), secondPoint);
    }
    return primitives;
  }

  //------------------------------------------------------------------------------
    /**
       ���������� �������������� ����� � �������������
       \param point �������������� �����, ����������� � �������������
    */
    //--- 
  void RectByCenterAndPoint::AddPoint(const geometry::Point& point)
  {
    if (!m_center.has_value())
    {
      m_center.emplace(point);
    }
    else
    {
      m_firstPoint.emplace(point);
    }
  }

  //------------------------------------------------------------------------------
  /**
     �����, ������ ����� � ���, ����� �� ������������� � ����������
     \return ������ �� ������ � ����������
  */
  //--- 
  /// 
  bool RectByCenterAndPoint::IsReady() const
  {
    return m_firstPoint.has_value();
  }

  //------------------------------------------------------------------------------
  /**
    �������� ��������� �����
    \param point �������������� �����, �� ������� ���������� ��������� ����� ��������������
  */
  //--- 
  void RectByCenterAndPoint::ChangeLastPoint(const geometry::Point& point)
  {
    if (m_center.has_value())
    {
      m_firstPoint.emplace(point);
    }
  }

  //------------------------------------------------------------------------------
  /**
    ������� ����� �������
    \return ��������� �� ����� �������������� �� ������ � �����
  */
  //--- 
  std::unique_ptr<IRectParams> RectByCenterAndPoint::Duplicate() const
  {
    return std::make_unique<RectByCenterAndPoint>(*this);
  }

} // namespace model