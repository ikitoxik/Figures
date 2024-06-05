////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ������ �������������� �� ���� ������
*/
//
////////////////////////////////////////////////////////////////////////////////

#include "RectByTwoPoints.h"
#include "../Geometry/GeometryLineSegment.h"
#include "IFigure.h"
#include "../Utils/Last.h"


namespace model
{
  //------------------------------------------------------------------------------
  /**
    ��������� ���������� �� ���� ��������������� ������
    \param firstPoint ������ �����
    \param secondPoint ������ �����
    \return ��������� ����������, ������ ��� ���������� ��������������
  */
  //--- 
  PrimitiveContainer Build(const geometry::Point& firstPoint, const geometry::Point& secondPoint)
  {
    PrimitiveContainer primitives;
    constexpr size_t numberOfPrims = 4;
    primitives.reserve(numberOfPrims);
    geometry::Point thirdPoint(firstPoint.GetX(), secondPoint.GetY());
    geometry::Point fourthPoint(secondPoint.GetX(), firstPoint.GetY());
    primitives.push_back(std::make_shared<geometry::LineSegment>(firstPoint, fourthPoint));
    primitives.push_back(std::make_shared<geometry::LineSegment>(firstPoint, thirdPoint));
    primitives.push_back(std::make_shared<geometry::LineSegment>(secondPoint, fourthPoint));
    primitives.push_back(std::make_shared<geometry::LineSegment>(secondPoint, thirdPoint));

    return primitives;
  }
  //------------------------------------------------------------------------------
  /**
    ��������� ���������� �� ���� ������
    \return ��������� ����������, ������ ��� ���������� ��������������
  */
  //--- 
  PrimitiveContainer RectByTwoPoints::Build() const
  {
    PrimitiveContainer primitives;
    if (m_firstPoint.has_value() && m_secondPoint.has_value())
      primitives = model::Build(m_firstPoint.value(), m_secondPoint.value());

    return primitives;
  }

  //------------------------------------------------------------------------------
    /**
       ���������� �������������� ����� � �������������
       \param point �������������� �����, ����������� � �������������
    */
    //--- 
  void RectByTwoPoints::AddPoint(const geometry::Point& point)
  {
    if (!m_firstPoint.has_value())
    {
      m_firstPoint.emplace(point);
    }
    else
    {
      m_secondPoint.emplace(point);
    }
  }

  //------------------------------------------------------------------------------
  /**
     �����, ������ ����� � ���, ����� �� ������������� � ����������
     \return ������ �� ������ � ����������
  */
  //--- 
  /// 
  bool RectByTwoPoints::IsReady() const
  {
    return m_secondPoint.has_value();
  }

  //------------------------------------------------------------------------------
  /**
    �������� ��������� �����
    \param point �������������� �����, �� ������� ���������� ��������� ����� ��������������
  */
  //--- 
  void RectByTwoPoints::ChangeLastPoint(const geometry::Point& point)
  {
    if (m_firstPoint.has_value())
    {
      m_secondPoint.emplace(point);
    }
  }

  //------------------------------------------------------------------------------
  /**
    ������� ����� �������
    \return ��������� �� ����� �������������� �� ���� ������
  */
  //--- 
  std::unique_ptr<IRectParams> RectByTwoPoints::Duplicate() const
  {
    return std::make_unique<RectByTwoPoints>(*this);
  }

} // namespace model