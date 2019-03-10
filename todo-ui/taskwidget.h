#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QWidget>

#include "model/taskmodel.h"

namespace Ui {
class TaskWidget;
}

class TaskWidget : public QWidget {
  Q_OBJECT

public:
  explicit TaskWidget(TaskModel *task, QWidget *parent = nullptr);
  ~TaskWidget();

private:
  Ui::TaskWidget *ui;

  TaskModel *_task;

private slots:
  void onStateChanged(int state);
  void onEditClicked();
  void onRemoveClicked();

signals:
  void removed(TaskWidget *widget);
};

#endif // TASKWIDGET_H
