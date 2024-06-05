////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief Реализация класса MainForm
  Данный класс отвечает за отображение данных и работу с пользователем
*/
//
////////////////////////////////////////////////////////////////////////////////
#include "MainForm.h"

#include "View/FiguresView.h"
#include "View/ViewModel.h"
#include "View/ViewPhantom.h"
#include "View/IObserver.h"

#include <QtWidgets>

//------------------------------------------------------------------------------
/**
  Конструктор
*/
//--- 
MainForm::MainForm(QWidget* parent) :
  QMainWindow(parent)
{
  // Создание виджетов 
  FiguresView* m_figuresView = new FiguresView(this);
  setCentralWidget(m_figuresView);
  createActions();

  resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);

  m_views.push_back(std::make_unique<view::ViewModel>());
  m_views.push_back(std::make_unique<view::ViewPhantom>());

  this->setMouseTracking(true);

  m_model = model::CreateModel();
  OnCreate(Observer(ViewType::Model));
  m_controller->SetActiveProcess(controller::ProcessId::Select, Observer(ViewType::Select));
}

//------------------------------------------------------------------------------
/**
  Обработка движения курсора
*/
//---
void MainForm::mouseMoveEvent(QMouseEvent* event)
{
  if (!m_controller)
    return;

  controller::Event _event{controller::EventType::MouseMove, GetPoint(event->position())};
  m_controller->HandleEvent(_event);
}

//------------------------------------------------------------------------------
/**
  Обработка клика в рабочую область
*/
//---
void MainForm::mousePressEvent(QMouseEvent* event)
{
  if (!m_controller)
    return;

  controller::Event _event{controller::EventType::LeftMouseButton, GetPoint(event->position())};
  m_controller->HandleEvent(_event);
}

//------------------------------------------------------------------------------
/**
  Деструктор
*/
//--- 
MainForm::~MainForm() = default;

//------------------------------------------------------------------------------
/**
  Получение точки из курсора
*/
//---
geometry::Point MainForm::GetPoint(QPointF point) const
{
  return geometry::Point(point.x(), point.y());
}

//------------------------------------------------------------------------------
/**
  Лямбда функция
*/
//---
model::UpdateFunc MainForm::Observer(ViewType type)
{
  return [this, type](const model::PrimitiveContainer& prims)
  {
    m_views[static_cast<size_t>(type)]->Update(prims);
    update();
  };
}

//------------------------------------------------------------------------------
/**
  Обработка события нажатия на кнопку создания фигуры
*/
//---
void MainForm::OnNewFigure(controller::ProcessId procId)
{
  bool isCurrentProc = m_controller->GetProcess() == procId;
  ViewType viewType = isCurrentProc ? ViewType::Select : ViewType::Phantom;
  procId = isCurrentProc ? controller::ProcessId::Select : procId;

  m_controller->SetActiveProcess(procId, Observer(viewType));
}

//------------------------------------------------------------------------------
/**
  Вспомогательный метод добавления наблюдателей в модель
*/
//--- 
void MainForm::OnCreate(model::UpdateFunc callback)
{
  auto observable = dynamic_cast<IObservable*>(m_model.get());
  observable->AddObserver(callback);
  observable->Notify();
  m_controller = std::make_shared<controller::Controller>(*m_model);
}

//------------------------------------------------------------------------------
/**
  Отрисовка данных
*/
//--- 
void MainForm::paintEvent(QPaintEvent* event)
{
  QPainter _painter(this);
  QPainter* paint = &_painter;

  view::IPainterUPtr painter = view::CreatePainter(paint);
  for (auto&& view : m_views)
    view->Draw(*painter);
}

//------------------------------------------------------------------------------
/**
  Обработка нажатия на кнопку "Точка"
*/
//---
void MainForm::drawPoint()
{
  OnNewFigure(controller::ProcessId::Point);
}

//------------------------------------------------------------------------------
/**
  Обработка нажатия на кнопку "Отрезок"
*/
//---
void MainForm::drawLineSegment()
{
  OnNewFigure(controller::ProcessId::LineSegment);
}

//------------------------------------------------------------------------------
/**
  Обработка нажатия на кнопку "Прямоугольник по двум точкам"
*/
//---
void MainForm::drawRectByTwoPoints()
{
  OnNewFigure(controller::ProcessId::RectByTwoPoints);
}

//------------------------------------------------------------------------------
/**
  Обработка нажатия на кнопку "Прямоугольник по центру и точке"
*/
//---
void MainForm::drawRectByCenterAndPoint()
{
  OnNewFigure(controller::ProcessId::RectByCenterAndPoint);
}

//------------------------------------------------------------------------------
/**
  Обработка нажатия на кнопку "Окружность"
*/
//---
void MainForm::drawCirclet()
{
  OnNewFigure(controller::ProcessId::Circle);
}

//------------------------------------------------------------------------------
/**
  Создание меню
*/
//---
void MainForm::MainForm::createActions()
{
  QMenu* drawMenu = menuBar()->addMenu(tr("Фигуры"));

  m_drawPoint = drawMenu->addAction(tr("Точка"), this, &MainForm::drawPoint);

  m_drawLineSegment = drawMenu->addAction(tr("Отрезок"), this, &MainForm::drawLineSegment);

  QMenu* m_drawRect = drawMenu->addMenu(tr("Прямоугольник"));
  m_drawRectByTwoPoints = m_drawRect->addAction(tr("По двум точкам"), this, &MainForm::drawRectByTwoPoints);
  m_drawRectByCenterAndPoint = m_drawRect->addAction(tr("По центру и точке"), this, &MainForm::drawRectByCenterAndPoint);

  m_drawCircle = drawMenu->addAction(tr("Окружность"), this, &MainForm::drawCirclet);
}
