////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief Реализация класса Controller
*/
//
////////////////////////////////////////////////////////////////////////////////


#include <assert.h>
#include "Controller.h"
#include "../Model/Model.h"
#include "../Model/PhantomModel.h"
#include "../Model/Point.h"
#include "../Model/LineSegment.h"
#include "../Model/Rectangle.h"
#include "../Model/RectByTwoPoints.h"
#include "../Model/RectByCenterAndPoint.h"
#include "../Model/Circle.h"
#include "../Utils/Last.h"


namespace controller
{
  //------------------------------------------------------------------------------
  /**
    Конструктор от параметра
    \param model ссылка на текущюю модель
  */
  //--- 
  Controller::Controller(model::IModel& model)
    : m_model(model)
  {
    m_process = ProcessId::Select;
  }

  //------------------------------------------------------------------------------
  /**
    Деструктор
  */
  //--- 
  Controller::~Controller() = default;

  //------------------------------------------------------------------------------
  /**
    Установка текущего процесса
    \param proc текущий процесс
  */
  //--- 
  void Controller::SetActiveProcess(ProcessId proc, model::UpdateFunc update)
  {
    m_process = proc;

    if (proc == ProcessId::Select)
    {
      if (m_phantomModel && m_phantomModel->GetTempFigure())
      {
        m_phantomModel->CleanFigure();
      }
    }
    else
    {
      m_phantomModel = std::make_unique<model::PhantomModel>();
      m_phantomModel->AddObserver(update);
      m_phantomModel->Notify();
    }
  }

  //------------------------------------------------------------------------------
  /**
    Фабричный метод создания фигуры
    \param proc текущий процесс
  */
  //--- 
  model::FigureUPtr Create(ProcessId proc)
  {
    switch (proc)
    {
    case ProcessId::Point:
    {
      return std::make_unique<model::Point>();
    }
    case ProcessId::LineSegment:
    {
      return std::make_unique<model::LineSegment>();
    }
    case ProcessId::RectByTwoPoints:
    {
      auto temp = std::make_unique<model::RectByTwoPoints>();
      return std::make_unique<model::Rectangle>(std::move(temp));
    }
    case ProcessId::RectByCenterAndPoint:
    {
      auto temp = std::make_unique<model::RectByCenterAndPoint>();
      return std::make_unique<model::Rectangle>(std::move(temp));
    }
    case ProcessId::Circle:
    {
      return std::make_unique<model::Circle>();
    }
    default:
      assert(false, "Добавьте новый тип фигуры");
      break;
    }
  }
  //------------------------------------------------------------------------------
  /**
    Обработка события
    \param event действие пользователя
  */
  //--- 
  void Controller::HandleEvent(const Event& event)
  {
    if (m_process == ProcessId::Select)
    {
      return;
    }
    else
      CreateFigureEvent(event);
  }

  //------------------------------------------------------------------------------
  /**
    Обработка события перемещения мыши
    \param event действие пользователя
  */
  //--- 
  void Controller::OnMouseMoveEvent(const Event& event)
  {
    model::FigureUPtr tempFigure;
    if (auto&& phantomFigure = m_phantomModel->GetTempFigure())
      tempFigure = phantomFigure->Duplicate();
    else
      tempFigure = Create(m_process);

    tempFigure->ChangeLastPoint(event.point);
    m_phantomModel->SetTempFigure(std::move(tempFigure));
  }

  //------------------------------------------------------------------------------
  /**
    Обработка события нажатия левой кнопки мыши
    \param event действие пользователя
  */
  //--- 
  void Controller::OnMouseLButtonEvent(const Event& event)
  {
    model::FigureUPtr tempFigure;
    if (auto&& phantomFigure = m_phantomModel->GetTempFigure())
      tempFigure = phantomFigure->Duplicate();
    else
      tempFigure = Create(m_process);
    tempFigure->AddPoint(event.point);
    m_phantomModel->SetTempFigure(std::move(tempFigure));

    if (m_phantomModel->GetTempFigure()->IsReady())
      m_phantomModel->TransferPhantomFigure(m_model);
  }

  //------------------------------------------------------------------------------
  /**
    Метод, возвращающий текущий процесс
  */
  //---
  ProcessId Controller::GetProcess() const
  {
    return m_process;
  }

  

  //------------------------------------------------------------------------------
  /**
    Обработка события при создании фигур
  */
  //---
  void Controller::CreateFigureEvent(const Event& event)
  {
    switch (event.type)
    {
    case EventType::MouseMove:
    {
      OnMouseMoveEvent(event);
      break;
    }
    case EventType::LeftMouseButton:
    {
      OnMouseLButtonEvent(event);
      break;
    }
    }
  }

} // namespace controller
