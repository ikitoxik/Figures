////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief ���������� ������ ������� ����������
*/
//
////////////////////////////////////////////////////////////////////////////////


#include "GeometryLineSegment.h"
#include "../Utils/Last.h"

namespace geometry
{
  //------------------------------------------------------------------------------
  /**
     �����������
     \param begPoint ��������� ����� �������
     \param endPoint �������� ����� �������
  */
  //--- 
  LineSegment::LineSegment(const Point& begPoint, const Point& endPoint)
    : m_begPoint(begPoint)
    , m_endPoint(endPoint)
  {
  }

  //------------------------------------------------------------------------------
  /**
     �����, ������������ ��� ���������
  */
  //--- 
  PrimitiveType LineSegment::GetType() const
  {
    return PrimitiveType::LineSegment;
  }

  //------------------------------------------------------------------------------
  /**
    ����� ��������� ��������� ����� �������
  */
  //--- 
  const Point& LineSegment::GetBeg() const
  {
    return m_begPoint;
  }

  //------------------------------------------------------------------------------
  /**
     ����� ��������� �������� ����� �������
  */
  //--- 
  const Point& LineSegment::GetEnd() const
  {
    return m_endPoint;
  }

} // namespace geometry