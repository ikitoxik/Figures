#pragma once
#include <QWidget>

class FiguresView : public QWidget {
  Q_OBJECT

private:
  int temp{ 0 };

public:
  explicit FiguresView(QWidget* parent = nullptr) : QWidget(parent) { this->setMouseTracking(true); }


protected:

};