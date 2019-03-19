#ifndef CONFIGMODEL_H
#define CONFIGMODEL_H

#include <QString>

enum class TaskRepository { LOCAL, REMOTE };

class ConfigModel {
public:
  ConfigModel();

  TaskRepository repository() const;
  void setRepository(const TaskRepository &repository);
  void setRepository(const int &repository);

  QString user() const;
  void setUser(const QString &user);

  QString host() const;
  void setHost(const QString &host);

  int port() const;
  void setPort(int port);

private:
  TaskRepository _repository = TaskRepository::LOCAL;
  QString _user = "";
  QString _host = "";
  int _port = 0;
};

#endif // CONFIGMODEL_H
