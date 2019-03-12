#ifndef TASKREMOTECONTROLLER_H
#define TASKREMOTECONTROLLER_H

#include "taskcontroller.h"

class TODOLIBSHARED_EXPORT TaskRemoteController : public TaskController {
public:
  TaskRemoteController();

  void edit(QVector<TaskModel *> tasks);
};

#endif // TASKREMOTECONTROLLER_H
