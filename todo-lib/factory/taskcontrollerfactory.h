#ifndef TASKCONTROLLERFACTORY_H
#define TASKCONTROLLERFACTORY_H

#include "controller/taskcontroller.h"
#include "model/configmodel.h"

class TaskControllerFactory {
public:
  static TaskController *create(const TaskRepository &taskRepository);

private:
  TaskControllerFactory();
};

#endif // TASKCONTROLLERFACTORY_H
