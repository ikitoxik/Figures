////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ���������� ����������
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace geometry
{
  class Point;
  struct Vector;
} // namepsace geometry

namespace geometry
{
  /// ���� ���������� 
  enum class PrimitiveType
  {
    Point,       /// < �����
    LineSegment, /// < �������
    Circle ///< ����������
  };

  ////////////////////////////////////////////////////////////////////////////////
  //
  /// ��������� ���������
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class IPrimitive
  {
  public:
    /// ����������
    virtual ~IPrimitive() = default;
    /// �����, ������������ ��� ���������
    virtual PrimitiveType GetType() const = 0;
  };
} //namespace geometry