////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief ���������� ������ �������� ����
*/
//
////////////////////////////////////////////////////////////////////////////////
#pragma once 

#include <QMainWindow>
#include "View/FiguresView.h"
#include "View/ViewBase.h"
#include "Controller/Controller.h"
#include "Model/Model.h"

class QAction;
class QMenu;

////////////////////////////////////////////////////////////////////////////////
//
/// ������������ ��� ����� �������������-�����������
/**
*/
////////////////////////////////////////////////////////////////////////////////
enum class ViewType
{
  Model, ///< ������������� ������
  Phantom, ///< ������������� �������
  Select
};

////////////////////////////////////////////////////////////////////////////////
//
/// ����� ������������� �������� ����
/**

*/
////////////////////////////////////////////////////////////////////////////////
class MainForm : public QMainWindow {
  Q_OBJECT

private:
  std::vector<std::unique_ptr<view::ViewBase>> m_views; ///< �������������-���������� �� ��������� �������
  controller::ControllerSPtr m_controller; ///< ����������
  model::ModelUPtr m_model; ///< ������
public:
  /// ������������
  explicit MainForm(QWidget* parent = nullptr);
  /// ����������
  virtual ~MainForm();
  //��������� ����� �� ��������� �������
  geometry::Point GetPoint(QPointF) const;

  // �������� �������-����� � ����� ��� ��������� ������ ����
private slots:
  // ����� ��������� ������� "�����"
  void drawPoint();
  // ����� ��������� ������� "�������"
  void drawLineSegment();
  // ����� ��������� ������� "������������� �� ���� ������"
  void drawRectByTwoPoints();
  // ����� ��������� ������� "������������� �� ������ � �����"
  void drawRectByCenterAndPoint();
  // ����� ��������� ������� "����������"
  void drawCirclet();

  // �������� �������-�����, ����������� ���������������� �������� ����.
  // ���������� �� ������������ � �� ������.
private:
  void createActions();       // �������� ��������-��������
  ///������� ��� ��������� ������� ������� �� ������ �������� ������
  void OnNewFigure(controller::ProcessId procId);
  //������ �������
  model::UpdateFunc Observer(ViewType type);
  /// ��������������� �������
  void OnCreate(model::UpdateFunc callback);

protected:
  /// ����� ��� ��������� �������� �������
  void mouseMoveEvent(QMouseEvent* event) override;
  /// ����� ��� ��������� ����� � ������� �������
  void mousePressEvent(QMouseEvent* event) override;
  //��������� ������
  void paintEvent(QPaintEvent* event) override;

private:
  FiguresView* m_figuresView{}; 
  
  QAction* m_drawPoint{};
  QAction* m_drawLineSegment{};
  QAction* m_drawRectByTwoPoints{};
  QAction* m_drawRectByCenterAndPoint{};
  QAction* m_drawCircle{};


};