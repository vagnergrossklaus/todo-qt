#include "taskmodel.h"

TaskModel::TaskModel(const QString &name) : _name(name) {}

int TaskModel::id() const { return _id; }

void TaskModel::setId(int id) { _id = id; }

QString TaskModel::name() const { return _name; }

void TaskModel::setName(const QString &name) { _name = name; }

TaskState TaskModel::state() const { return _state; }

void TaskModel::setState(const TaskState &state) { _state = state; }
