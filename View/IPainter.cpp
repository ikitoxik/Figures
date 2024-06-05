#include "IPainter.h"
#include "../Geometry/GeometryPoint.h"
#include "../Geometry/GeometryLineSegment.h"
#include "../Geometry/GeometryCircle.h"
#include "../View/ViewBase.h"
#include "FiguresView.h"

namespace view
{

  ////////////////////////////////////////////////////////////////////////////////
  //
  /// Объявление класса Painter
  /**
  */
  ////////////////////////////////////////////////////////////////////////////////
  class Painter :public IPainter
  {
  private:
    QPainter* pWidget; ///< указатель на контекст отображения
  public:
    /// Конструктор
    Painter() = default;
    /// Конструктор от параметра
    Painter(QPainter* pWidget);
    /// Деструктор
    ~Painter() = default;
    /// Метод для отрисовки
    virtual void Draw(const view::DrawData&) override;
  };
  //------------------------------------------------------------------------------
  /**
    Конструктор от параметра
    \param pWidget указатель на контекст отображения
  */
  //---
  Painter::Painter(QPainter* pWidget) : pWidget(pWidget)
  {
  }

  //------------------------------------------------------------------------------
  /**
    Метод отрисовки
    \param data данные для отрисовки
  */
  //---
  void Painter::Draw(const view::DrawData& data)
  {

    switch (data.prim->GetType())
    {
    case geometry::PrimitiveType::Point:
    {
      auto point = static_cast<geometry::Point*>(data.prim.get());
      geometry::Point pnt = *point;
      

      QPen pen;
      pen.setColor(data.color);         
      pen.setStyle(Qt::SolidLine);      
      pen.setCapStyle(Qt::SquareCap); 
      pen.setWidth(data.width);         

      pWidget->setPen(pen);
      
      pWidget->drawPoint(pnt.GetX(), pnt.GetY());
      pWidget->drawPoint(pnt.GetX() + 1, pnt.GetY());
      pWidget->drawPoint(pnt.GetX() - 1, pnt.GetY());
      pWidget->drawPoint(pnt.GetX(), pnt.GetY() + 1);
      pWidget->drawPoint(pnt.GetX(), pnt.GetY() - 1);
      break;
    }
    case geometry::PrimitiveType::LineSegment:
    {
      auto lineSegment = static_cast<const geometry::LineSegment*>(data.prim.get());
      auto&& begPoint = const_cast<geometry::Point&>(lineSegment->GetBeg());
      auto&& endPoint = const_cast<geometry::Point&>(lineSegment->GetEnd());

      QPen pen;
      pen.setColor(data.color);        
      pen.setStyle(Qt::SolidLine);      
      pen.setCapStyle(Qt::SquareCap); 
      pen.setWidth(data.width);         

      pWidget->setPen(pen);
      
      pWidget->drawLine(begPoint.GetX(), begPoint.GetY(), endPoint.GetX(), endPoint.GetY());
      break;
    }
    case geometry::PrimitiveType::Circle:
    {
      auto circle = static_cast<const geometry::Circle*>(data.prim.get());
      auto&& center = const_cast<geometry::Point&>(circle->GetCenter());
      auto&& onCircle = const_cast<geometry::Point&>(circle->GetOnCircle());

      QPen pen;
      pen.setColor(data.color);        
      pen.setStyle(Qt::SolidLine);      
      pen.setCapStyle(Qt::SquareCap); 
      pen.setWidth(data.width);         

      pWidget->setPen(pen);
      QPoint temp(center.GetX(), center.GetY());
      int radius = static_cast<int>(abs(sqrt(pow(center.GetX() - onCircle.GetX(), 2) + sqrt(pow(center.GetY() - onCircle.GetY(), 2)))));
      pWidget->drawEllipse(temp, radius, radius);
      break;
    }
    }
  }

  //------------------------------------------------------------------------------
  /**
   Создать объект Model
  */
  //--- 
  std::unique_ptr<IPainter> CreatePainter(QPainter* pWidget)
  {
    return std::make_unique<Painter>(pWidget);
  }
}