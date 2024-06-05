////////////////////////////////////////////////////////////////////////////////
//
/**
\file
\brief Объявление интерфейса параметров прямоугольника
*/
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Model_fwd.h"
#include "../Geometry/Geometry_fwd.h"


namespace model
{
  ////////////////////////////////////////////////////////////////////////////////
  //
  /// Объявление интерфейса параметров прямоугольника
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class IRectParams 
  {
  public:
    /// Деструктор
    virtual ~IRectParams() = default;
    /// Постройка примитивов по заданным точкам
    virtual PrimitiveContainer Build() const = 0;
    /// Добавление геометрической точки в прямоугольник
    virtual void AddPoint(const geometry::Point&) = 0;
    /// Метод, дающий ответ о том, готов ли прямоугольник к построению
    virtual bool IsReady() const = 0;

    /// Метод для изменения последней точки
    virtual void ChangeLastPoint(const geometry::Point&) = 0;
    /// Метод, позволяющий создать копию объекта
    virtual std::unique_ptr<IRectParams> Duplicate() const = 0;
  };

  /// Свободный метод для построения примитивов по двум противоположным точкам
  PrimitiveContainer Build(const geometry::Point&, const geometry::Point&);

}   //namespace model