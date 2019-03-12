#include "taskremotecontroller.h"

#include "repository/taskremoterepository.h"

TaskRemoteController::TaskRemoteController()
    : TaskController(TaskService(new TaskRemoteRepository())) {}

void TaskRemoteController::edit(QVector<TaskModel *> tasks) { Q_UNUSED(tasks); }
