#ifndef TASKMODEL_H
#define TASKMODEL_H

#include "todo-lib_global.h"

#include <QString>

enum class TaskStatus : int {
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

  TaskStatus status() const;
  void setStatus(const TaskStatus &status);
  void setStatus(int status);

private:
  int _id = 0;
  QString _name = "";
  TaskStatus _status = TaskStatus::TODO;
};

#endif // TASKMODEL_H
