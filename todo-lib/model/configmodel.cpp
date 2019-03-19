#include "configmodel.h"

ConfigModel::ConfigModel() {}

TaskRepository ConfigModel::repository() const { return _repository; }

void ConfigModel::setRepository(const TaskRepository &repository) {
  _repository = repository;
}

void ConfigModel::setRepository(const int &repository) {
  setRepository(TaskRepository(repository));
}

QString ConfigModel::user() const { return _user; }

void ConfigModel::setUser(const QString &user) { _user = user; }

QString ConfigModel::host() const { return _host; }

void ConfigModel::setHost(const QString &host) { _host = host; }

int ConfigModel::port() const { return _port; }

void ConfigModel::setPort(int port) { _port = port; }
