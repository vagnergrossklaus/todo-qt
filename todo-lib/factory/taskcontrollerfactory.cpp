#include "taskcontrollerfactory.h"

#include "controller/tasklocalcontroller.h"
#include "controller/taskremotecontroller.h"

TaskController *
TaskControllerFactory::create(const TaskRepository &taskRepository) {

  TaskController *taskController = nullptr;

  switch (taskRepository) {
  case TaskRepository::LOCAL:
    taskController = new TaskLocalController();
    break;
  case TaskRepository::REMOTE:
    taskController = new TaskRemoteController();
    break;
  }

  return taskController;
}
