#include "taskservice.h"

TaskService::TaskService(Repository<TaskModel> *taskRepository)
    : _taskRepository(taskRepository) {}

QVector<TaskModel *> TaskService::findAll() {
  return _taskRepository->findAll();
}

void TaskService::add(TaskModel *task) { _taskRepository->add(task); }

void TaskService::remove(const int &id) { _taskRepository->remove(id); }

void TaskService::update(TaskModel *task) { _taskRepository->update(task); }
