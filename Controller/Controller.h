////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Объявление класса Controller
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
  /// Перечисление для хранения видов процессов
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  enum class ProcessId
  {
    Point, /// < точка
    LineSegment,  /// < отрезок
    Select, /// < режим выбора фигуры 
    RectByCenterAndPoint, /// < прямоугольник по центру и точке
    RectByTwoPoints, /// < прямоугольник по двум точкам
    Circle  ///<окружность
  };

  ////////////////////////////////////////////////////////////////////////////////
  //
  /// Перечисления для видов событий
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  enum class EventType
  {
    LeftMouseButton, /// < клик ЛКМ
    MouseMove /// < движение мышью
  };

  ////////////////////////////////////////////////////////////////////////////////
  //
  // Структура для хранения объекта Event
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  struct Event
  {
    EventType type; /// < тип ивента
    geometry::Point point; /// < точка
  };
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// Контроллер: обеспечивает связь между пользователем и системой
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class Controller
  {
  private:
    model::IModel& m_model;	///< модель с фигурами
    std::unique_ptr<model::PhantomModel> m_phantomModel; ///< модель с редактируемыми фигурами
    ProcessId m_process; ///< текущий процесс
    geometry::Point pnt;  ///< предыдущее положение курсора
  public:
    /// Конструктор по умолчанию
    Controller() = delete;
    /// Конструктор от параметра
    Controller(model::IModel& model);
    /// Деструктор
    ~Controller();
    /// Метод установки текущего процесса
    void SetActiveProcess(ProcessId, model::UpdateFunc);
    /// Метод обработки события
    void HandleEvent(const Event& event);
    /// Метод получения текущего процесса
    ProcessId GetProcess() const;

  private:
    /// Обработка события движения мыши
    void OnMouseMoveEvent(const Event& event);
    /// Обработка события нажатия левой кнопки мыши
    void OnMouseLButtonEvent(const Event& event);
    /// Обработка события при создании фигур
    void CreateFigureEvent(const Event& event);

  };

  using ControllerSPtr = std::shared_ptr<controller::Controller>;

} // namespace controller