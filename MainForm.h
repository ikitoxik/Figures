////////////////////////////////////////////////////////////////////////////////
//
/**
  \file
  \brief Реализация класса главного окна
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
/// Перечисления для типов представлений-подписчиков
/**
*/
////////////////////////////////////////////////////////////////////////////////
enum class ViewType
{
  Model, ///< представление модели
  Phantom, ///< представление фантома
  Select
};

////////////////////////////////////////////////////////////////////////////////
//
/// Класс представления главного окна
/**

*/
////////////////////////////////////////////////////////////////////////////////
class MainForm : public QMainWindow {
  Q_OBJECT

private:
  std::vector<std::unique_ptr<view::ViewBase>> m_views; ///< представления-подписчики на изменения моделей
  controller::ControllerSPtr m_controller; ///< контроллер
  model::ModelUPtr m_model; ///< модель
public:
  /// Конуструктор
  explicit MainForm(QWidget* parent = nullptr);
  /// Деструктор
  virtual ~MainForm();
  //Получение точки по положению курсора
  geometry::Point GetPoint(QPointF) const;

  // Закрытые функции-члены – слоты для обработки команд меню
private slots:
  // Метод обработки нажатия "Точка"
  void drawPoint();
  // Метод обработки нажатия "Отрезок"
  void drawLineSegment();
  // Метод обработки нажатия "Прямоугольник по двум точкам"
  void drawRectByTwoPoints();
  // Метод обработки нажатия "Прямоугольник по центру и точке"
  void drawRectByCenterAndPoint();
  // Метод обработки нажатия "Окружность"
  void drawCirclet();

  // Закрытые функции-члены, реализующие функциональность главного окна.
  // Вызываются из конструктора и из слотов.
private:
  void createActions();       // Создание объектов-действий
  ///Функция для обработки события нажатия на кнопку создания фигуры
  void OnNewFigure(controller::ProcessId procId);
  //Лямбда функция
  model::UpdateFunc Observer(ViewType type);
  /// Вспомогательная функция
  void OnCreate(model::UpdateFunc callback);

protected:
  /// Метод для обработки движения курсора
  void mouseMoveEvent(QMouseEvent* event) override;
  /// Метод для обработки клика в рабочую область
  void mousePressEvent(QMouseEvent* event) override;
  //Отрисовка данных
  void paintEvent(QPaintEvent* event) override;

private:
  FiguresView* m_figuresView{}; 
  
  QAction* m_drawPoint{};
  QAction* m_drawLineSegment{};
  QAction* m_drawRectByTwoPoints{};
  QAction* m_drawRectByCenterAndPoint{};
  QAction* m_drawCircle{};


};