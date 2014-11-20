#include "bluebox.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  BlueBox w;
  w.show();

  return a.exec();
}
