#ifndef TASKREMOTEREPOSITORY_H
#define TASKREMOTEREPOSITORY_H

#include "model/taskmodel.h"
#include "repository.h"

class TaskRemoteRepository : public Repository<TaskModel> {
public:
  TaskRemoteRepository();

  QVector<TaskModel *> findAll() override;
  void add(TaskModel *task) override;
  void remove(const int &id) override;
  void edit(TaskModel *task) override;
};

#endif // TASKREMOTEREPOSITORY_H
