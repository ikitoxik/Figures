////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief ���������� ������ Controller
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "../Model/Model_fwd.h"
#include "../Geometry/GeometryPoint.h"

namespace model
{
  class PhantomModel;
} // namespace model


namespace controller
{

  ////////////////////////////////////////////////////////////////////////////////
  //
  /// ������������ ��� �������� ����� ���������
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  enum class ProcessId
  {
    Point, /// < �����
    LineSegment,  /// < �������
    Select, /// < ����� ������ ������ 
    RectByCenterAndPoint, /// < ������������� �� ������ � �����
    RectByTwoPoints, /// < ������������� �� ���� ������
    Circle  ///<����������
  };

  ////////////////////////////////////////////////////////////////////////////////
  //
  /// ������������ ��� ����� �������
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  enum class EventType
  {
    LeftMouseButton, /// < ���� ���
    MouseMove /// < �������� �����
  };

  ////////////////////////////////////////////////////////////////////////////////
  //
  // ��������� ��� �������� ������� Event
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  struct Event
  {
    EventType type; /// < ��� ������
    geometry::Point point; /// < �����
  };
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// ����������: ������������ ����� ����� ������������� � ��������
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class Controller
  {
  private:
    model::IModel& m_model;	///< ������ � ��������
    std::unique_ptr<model::PhantomModel> m_phantomModel; ///< ������ � �������������� ��������
    ProcessId m_process; ///< ������� �������
    geometry::Point pnt;  ///< ���������� ��������� �������
  public:
    /// ����������� �� ���������
    Controller() = delete;
    /// ����������� �� ���������
    Controller(model::IModel& model);
    /// ����������
    ~Controller();
    /// ����� ��������� �������� ��������
    void SetActiveProcess(ProcessId, model::UpdateFunc);
    /// ����� ��������� �������
    void HandleEvent(const Event& event);
    /// ����� ��������� �������� ��������
    ProcessId GetProcess() const;

  private:
    /// ��������� ������� �������� ����
    void OnMouseMoveEvent(const Event& event);
    /// ��������� ������� ������� ����� ������ ����
    void OnMouseLButtonEvent(const Event& event);
    /// ��������� ������� ��� �������� �����
    void CreateFigureEvent(const Event& event);

  };

  using ControllerSPtr = std::shared_ptr<controller::Controller>;

} // namespace controller