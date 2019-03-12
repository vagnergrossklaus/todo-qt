#ifndef TASKLOCALCONTROLLER_H
#define TASKLOCALCONTROLLER_H

#include "taskcontroller.h"

class TODOLIBSHARED_EXPORT TaskLocalController : public TaskController {
public:
  TaskLocalController();

  void edit(QVector<TaskModel *> tasks);
};

#endif // TASKLOCALCONTROLLER_H
