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

  TaskModel *task() const;

private:
  Ui::TaskWidget *ui;

  TaskModel *_task;

  void strikeOut(Qt::CheckState state);

private slots:
  void onStateChanged(int state);
  void onEditClicked();
  void onRemoveClicked();

signals:
  void edited(TaskWidget *widget);
  void removed(TaskWidget *widget);
};

#endif // TASKWIDGET_H
