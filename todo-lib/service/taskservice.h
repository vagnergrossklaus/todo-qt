#ifndef TASKSERVICE_H
#define TASKSERVICE_H

#include "model/taskmodel.h"
#include "repository/repository.h"

class TaskService {
public:
  TaskService(Repository<TaskModel> *taskRepository);

  QVector<TaskModel *> findAll();
  void add(TaskModel *task);
  void remove(const int &id);
  void update(TaskModel *task);

private:
  Repository<TaskModel> *_taskRepository = nullptr;
};

#endif // TASKSERVICE_H
