#include "tasklocalcontroller.h"

#include "manager/database/databasemanager.h"
#include "repository/tasklocalrepository.h"

TaskLocalController::TaskLocalController()
    : TaskController(TaskService(new TaskLocalRepository())) {}

void TaskLocalController::edit(QVector<TaskModel *> tasks) {
  try {
    DatabaseManager::instance().database().transaction();
    taskService().edit(tasks);
    DatabaseManager::instance().database().commit();
  } catch (...) {
    DatabaseManager::instance().database().rollback();
  }
}
