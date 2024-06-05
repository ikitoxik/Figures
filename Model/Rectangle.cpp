////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ������ ��������������
*/
//
////////////////////////////////////////////////////////////////////////////////

#include "Rectangle.h"
#include "IRectParams.h"
#include "../Utils/Last.h"
#include "RectByCenterAndPoint.h"
#include "RectByTwoPoints.h"
#include "../Geometry/GeometryLineSegment.h"
#include "Model.h"

namespace model
{
  //------------------------------------------------------------------------------
  /**
     ����������� �� ����������
     \param params ������������� �� ���� ������, ������ ��� ������������� ���� ����������
  */
  //---
  Rectangle::Rectangle(std::unique_ptr<IRectParams> params)
    : m_params(std::move(params))
  {
  }

  //------------------------------------------------------------------------------
  /**
     ����������� �����������
     \param other ������������� ��� �����������
  */
  //---
  Rectangle::Rectangle(const Rectangle& other)
  {
    m_params = std::move(other.m_params->Duplicate());
  }

  //------------------------------------------------------------------------------
  /**
     ��������� ���� ������
  */
  //--- 
  FigureType Rectangle::GetType() const
  {
    return FigureType::Rectangle;
  }

  //------------------------------------------------------------------------------
  /**
     ���������� �������������� ����� � ������
     \param point �������������� �����, ����������� � ������
  */
  //--- 
  void Rectangle::AddPoint(const geometry::Point& point)
  {
    m_params->AddPoint(point);
    CalcPrims();
  }

  //------------------------------------------------------------------------------
  /**
     �����, ������ ����� � ���, ������ �� ������ � ����������
     \return ������ �� ������ � ����������
  */
  //--- 
  bool Rectangle::IsReady() const
  {
    return m_params->IsReady();
  }

  //------------------------------------------------------------------------------
  /**
    �������� ��������� �����
    \param point �������������� �����, �� ������� ���������� ��������� ����� ������
  */
  //--- 
  void Rectangle::ChangeLastPoint(const geometry::Point& point)
  {
    m_params->ChangeLastPoint(point);
    CalcPrims();
  }

  //------------------------------------------------------------------------------
  /**
    ������� ����� ��������������
  */
  //--- 
  FigureUPtr Rectangle::Duplicate() const
  {
    return std::make_unique<Rectangle>(*this);
  }

  //------------------------------------------------------------------------------
  /**
    ��������������� ������� ��� ����������� ���������� ������
  */
  //--- 
  void Rectangle::CalcPrims()
  {
    m_primitives = m_params->Build();
  }

} // namespace model