#include "taskremotecontroller.h"

#include "repository/taskremoterepository.h"

TaskRemoteController::TaskRemoteController()
    : TaskController(TaskService(new TaskRemoteRepository())) {}
