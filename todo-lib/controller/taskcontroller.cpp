#include "taskcontroller.h"

TaskController::TaskController(TaskService taskService)
    : _taskService(taskService) {}

TaskService TaskController::taskService() const { return _taskService; }

QVector<TaskModel *> TaskController::find() { return _taskService.findAll(); }

void TaskController::add(TaskModel *task) { _taskService.add(task); }

void TaskController::remove(const int &id) { _taskService.remove(id); }

void TaskController::edit(TaskModel *task) { _taskService.edit(task); }
