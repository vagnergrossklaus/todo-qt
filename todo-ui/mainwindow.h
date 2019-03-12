#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <controller/taskcontroller.h>

#include "taskwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;

  TaskController *_taskcontroller;

  void addTask(TaskModel *task);

private slots:
  void onAddClicked();
  void onDoneUndoneStateChanged(int state);
  void onEdited(TaskWidget *widget);
  void onRemoved(TaskWidget *widget);
};

#endif // MAINWINDOW_H
