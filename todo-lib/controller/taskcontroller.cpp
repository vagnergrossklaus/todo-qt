#include "taskcontroller.h"

TaskController::TaskController(TaskService taskService)
    : _taskService(taskService) {}

QVector<TaskModel *> TaskController::find() { return _taskService.findAll(); }

void TaskController::add(TaskModel *task) { _taskService.add(task); }

void TaskController::remove(const int &id) { _taskService.remove(id); }

void TaskController::update(TaskModel *task) { _taskService.update(task); }
