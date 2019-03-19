#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>

class DatabaseManager {
public:
  static DatabaseManager &instance();

  QSqlDatabase database();

private:
  static constexpr const char *CONNECTION_NAME = "TODO";

  DatabaseManager();

  void init();
};

#endif // DATABASEMANAGER_H
