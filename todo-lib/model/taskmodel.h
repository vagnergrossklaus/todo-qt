#ifndef TASKMODEL_H
#define TASKMODEL_H

#include "todo-lib_global.h"

#include <QString>

enum class TaskState : int {
  DONE = Qt::CheckState::Checked,
  TODO = Qt::CheckState::Unchecked
};

class TODOLIBSHARED_EXPORT TaskModel {
public:
  TaskModel(const QString &name);

  int id() const;
  void setId(int id);

  QString name() const;
  void setName(const QString &name);

  TaskState state() const;
  void setState(const TaskState &state);

private:
  int _id = 0;
  QString _name = "";
  TaskState _state = TaskState::TODO;
};

#endif // TASKMODEL_H
