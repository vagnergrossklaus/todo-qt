#ifndef TASKLOCALREPOSITORY_H
#define TASKLOCALREPOSITORY_H

#include "model/taskmodel.h"
#include "repository.h"

class TaskLocalRepository : public Repository<TaskModel> {
public:
  TaskLocalRepository();

  QVector<TaskModel *> findAll() override;
  void add(TaskModel *task) override;
  void remove(const int &id) override;
  void update(TaskModel *task) override;
};

#endif // TASKLOCALREPOSITORY_H
