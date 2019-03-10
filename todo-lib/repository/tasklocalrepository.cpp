#include "tasklocalrepository.h"

TaskLocalRepository::TaskLocalRepository() {}

QVector<TaskModel *> TaskLocalRepository::findAll() { return {}; }

void TaskLocalRepository::add(TaskModel *task) { Q_UNUSED(task); }

void TaskLocalRepository::remove(const int &id) { Q_UNUSED(id); }

void TaskLocalRepository::update(TaskModel *task) { Q_UNUSED(task); }
