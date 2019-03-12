#include "tasklocalrepository.h"

#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

#include "manager/database/databasemanager.h"

TaskLocalRepository::TaskLocalRepository() {
  DatabaseManager::instance().database();
}

QVector<TaskModel *> TaskLocalRepository::findAll() {

  QVector<TaskModel *> tasks = {};

  QSqlQuery query(DatabaseManager::instance().database());
  if (query.exec("SELECT id, name, status FROM task")) {
    TaskModel *task = nullptr;
    QSqlRecord record;
    while (query.next()) {

      record = query.record();

      task = new TaskModel(record.value("name").toString());
      task->setId(record.value("id").toInt());
      task->setStatus(record.value("status").toInt());

      tasks.append(task);
    }
  } else {
    qDebug() << query.lastError().text();
  }

  return tasks;
}

void TaskLocalRepository::add(TaskModel *task) {
  QSqlQuery query(DatabaseManager::instance().database());

  query.prepare("INSERT INTO task (name, status) VALUES (:name, :status)");
  query.bindValue(":name", task->name());
  query.bindValue(":status", static_cast<int>(task->status()));

  if (query.exec()) {
    task->setId(query.lastInsertId().toInt());
  } else {
    qDebug() << query.lastError().text();
  }
}

void TaskLocalRepository::remove(const int &id) {
  QSqlQuery query(DatabaseManager::instance().database());

  query.prepare("DELETE FROM task WHERE id = :id");
  query.bindValue(":id", id);

  if (!query.exec()) {
    qDebug() << query.lastError().text();
  }
}

void TaskLocalRepository::edit(TaskModel *task) {
  QSqlQuery query(DatabaseManager::instance().database());

  query.prepare(
      "UPDATE task SET name = :name, status = :status WHERE id = :id");
  query.bindValue(":name", task->name());
  query.bindValue(":status", static_cast<int>(task->status()));
  query.bindValue(":id", task->id());

  if (!query.exec()) {
    qDebug() << query.lastError().text();
  }
}
