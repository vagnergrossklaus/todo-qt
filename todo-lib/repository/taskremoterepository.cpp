#include "taskremoterepository.h"

TaskRemoteRepository::TaskRemoteRepository() {}

QVector<TaskModel *> TaskRemoteRepository::findAll() { return {}; }

void TaskRemoteRepository::add(TaskModel *task) { Q_UNUSED(task); }

void TaskRemoteRepository::remove(const int &id) { Q_UNUSED(id); }

void TaskRemoteRepository::update(TaskModel *task) { Q_UNUSED(task); }
