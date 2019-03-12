#include "taskservice.h"

TaskService::TaskService(Repository<TaskModel> *taskRepository)
    : _taskRepository(taskRepository) {}

QVector<TaskModel *> TaskService::findAll() {
  return _taskRepository->findAll();
}

void TaskService::add(TaskModel *task) { _taskRepository->add(task); }

void TaskService::remove(const int &id) { _taskRepository->remove(id); }

void TaskService::edit(TaskModel *task) { _taskRepository->edit(task); }

void TaskService::edit(QVector<TaskModel *> tasks) {
  for (auto task : tasks) {
    _taskRepository->edit(task);
  }
}
