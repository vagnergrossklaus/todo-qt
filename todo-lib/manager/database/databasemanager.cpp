#include "databasemanager.h"

#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

DatabaseManager::DatabaseManager() {
  QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", CONNECTION_NAME);
  database.setDatabaseName("todo.db");

  if (database.open()) {
    init();
  }
}

void DatabaseManager::init() {
  QSqlQuery query("CREATE TABLE IF NOT EXISTS task ("
                  " id INTEGER PRIMARY KEY,"
                  " name TEXT NOT NULL,"
                  " status INTEGER NOT NULL"
                  ")",
                  database());
  qDebug() << query.lastError().text();
}

DatabaseManager DatabaseManager::instance() {
  static DatabaseManager manager;
  return manager;
}

QSqlDatabase DatabaseManager::database() {
  return QSqlDatabase::database(CONNECTION_NAME);
}
