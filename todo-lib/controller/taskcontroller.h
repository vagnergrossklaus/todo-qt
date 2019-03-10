#ifndef TASKCONTROLLER_H
#define TASKCONTROLLER_H

#include "service/taskservice.h"

class TODOLIBSHARED_EXPORT TaskController {
public:
  virtual QVector<TaskModel *> find();
  virtual void add(TaskModel *task);
  virtual void remove(const int &id);
  virtual void update(TaskModel *task);

protected:
  TaskController(TaskService taskService);

private:
  TaskService _taskService;
};

#endif // TASKCONTROLLER_H
