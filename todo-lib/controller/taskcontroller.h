#ifndef TASKCONTROLLER_H
#define TASKCONTROLLER_H

#include "service/taskservice.h"

class TODOLIBSHARED_EXPORT TaskController {
public:
  virtual QVector<TaskModel *> find();
  virtual void add(TaskModel *task);
  virtual void remove(const int &id);
  virtual void edit(TaskModel *task);
  virtual void edit(QVector<TaskModel *> tasks) = 0;

protected:
  TaskController(TaskService taskService);

  TaskService taskService() const;

private:
  TaskService _taskService;
};

#endif // TASKCONTROLLER_H
