#include "taskmodel.h"

TaskModel::TaskModel(const QString &name) : _name(name) {}

int TaskModel::id() const { return _id; }

void TaskModel::setId(int id) { _id = id; }

QString TaskModel::name() const { return _name; }

void TaskModel::setName(const QString &name) { _name = name; }

TaskStatus TaskModel::status() const { return _status; }

void TaskModel::setStatus(const TaskStatus &status) { _status = status; }

void TaskModel::setStatus(int status) { setStatus(TaskStatus(status)); }
