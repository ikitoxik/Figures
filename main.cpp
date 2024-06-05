#include <QApplication>
#include "MainForm.h"

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  app.setApplicationDisplayName("Figures Viewer");

  MainForm formWnd;
  formWnd.show();
  
  return app.exec();
}
