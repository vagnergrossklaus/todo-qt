#include "mainwindow.h"
#include <QApplication>
#include <QResource>

int main(int argc, char *argv[]) {

  QApplication a(argc, argv);

  QResource::registerResource(a.applicationDirPath() + "sql.rcc");

  MainWindow w;
  w.show();

  return a.exec();
}
