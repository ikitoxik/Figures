////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Реализация класса прямоугольника
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
     Конструктор по параметрам
     \param params прямоугольник по двум точкам, нужный для инициализации поля параметров
  */
  //---
  Rectangle::Rectangle(std::unique_ptr<IRectParams> params)
    : m_params(std::move(params))
  {
  }

  //------------------------------------------------------------------------------
  /**
     Конструктор копирования
     \param other прямоугольник для копирования
  */
  //---
  Rectangle::Rectangle(const Rectangle& other)
  {
    m_params = std::move(other.m_params->Duplicate());
  }

  //------------------------------------------------------------------------------
  /**
     Получение типа фигуры
  */
  //--- 
  FigureType Rectangle::GetType() const
  {
    return FigureType::Rectangle;
  }

  //------------------------------------------------------------------------------
  /**
     Добавление геометрической точки в фигуру
     \param point геометрическая точка, добавляемая в фигуру
  */
  //--- 
  void Rectangle::AddPoint(const geometry::Point& point)
  {
    m_params->AddPoint(point);
    CalcPrims();
  }

  //------------------------------------------------------------------------------
  /**
     Метод, дающий ответ о том, готова ли фигура к построению
     \return готова ли фигура к построению
  */
  //--- 
  bool Rectangle::IsReady() const
  {
    return m_params->IsReady();
  }

  //------------------------------------------------------------------------------
  /**
    Изменить последнюю точку
    \param point геометрическая точка, на которую заменяется последняя точка фигуры
  */
  //--- 
  void Rectangle::ChangeLastPoint(const geometry::Point& point)
  {
    m_params->ChangeLastPoint(point);
    CalcPrims();
  }

  //------------------------------------------------------------------------------
  /**
    Создать копию прямоугольника
  */
  //--- 
  FigureUPtr Rectangle::Duplicate() const
  {
    return std::make_unique<Rectangle>(*this);
  }

  //------------------------------------------------------------------------------
  /**
    Вспомогательная функция для перерасчета примитивов фигуры
  */
  //--- 
  void Rectangle::CalcPrims()
  {
    m_primitives = m_params->Build();
  }

} // namespace model