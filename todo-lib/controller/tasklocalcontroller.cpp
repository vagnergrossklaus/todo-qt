#include "tasklocalcontroller.h"

#include "repository/tasklocalrepository.h"

TaskLocalController::TaskLocalController()
    : TaskController(TaskService(new TaskLocalRepository())) {}
