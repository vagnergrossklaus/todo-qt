#include "taskremoterepository.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include <QUrl>

#include "manager/configuration/configurationmanager.h"
#include "manager/network/networkmanager.h"

TaskRemoteRepository::TaskRemoteRepository() {}

QVector<TaskModel *> TaskRemoteRepository::findAll() {

  QUrl url(QString("http://%1:%2/todo/task/%3")
               .arg(ConfigurationManager::instance().configuration().host())
               .arg(ConfigurationManager::instance().configuration().port())
               .arg(ConfigurationManager::instance().configuration().user()));

  QNetworkRequest request;
  request.setUrl(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  QByteArray response = NetworkManager::instance().get(request);

  QJsonDocument json = QJsonDocument::fromJson(response);

  TaskModel *task = nullptr;
  QVector<TaskModel *> tasks = {};
  for (auto value : json.array()) {
    task = new TaskModel(value.toObject().value("name").toString());
    task->setId(value.toObject().value("id").toInt());
    task->setStatus(value.toObject().value("state").toInt());
    tasks.append(task);
  }

  return tasks;
}

void TaskRemoteRepository::add(TaskModel *task) {

  QJsonObject t;
  t["name"] = task->name();
  t["state"] = static_cast<int>(task->status());

  QJsonObject json;
  json["name"] = "vagner";
  json["task"] = t;

  QJsonDocument document;
  document.setObject(json);

  QUrl url("http://127.0.0.1:5000/todo/task");

  qDebug() << document.toJson();

  QNetworkRequest request;
  request.setUrl(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  QByteArray response =
      NetworkManager::instance().post(request, document.toJson());

  document = QJsonDocument::fromJson(response);
  t = document.object();
  task->setId(t.value("id").toInt());
}

void TaskRemoteRepository::remove(const int &id) {

  QJsonObject jsonTask;
  jsonTask.insert("id", id);

  QJsonDocument document;
  document.setObject(jsonTask);

  QUrl url(QString("http://127.0.0.1:5000/todo/task/vagner/%1").arg(id));

  QNetworkRequest request;
  request.setUrl(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  NetworkManager::instance().put(request, document.toJson());
}

void TaskRemoteRepository::edit(TaskModel *task) {

  QJsonObject jsonTask;
  jsonTask.insert("name", task->name());
  jsonTask.insert("state", static_cast<int>(task->status()));

  QJsonObject json;
  json["name"] = "vagner";
  json["task"] = jsonTask;

  QJsonDocument document;
  document.setObject(json);

  QUrl url(QString("http://127.0.0.1:5000/todo/task/%1").arg(task->id()));

  qDebug() << document.toJson();

  QNetworkRequest request;
  request.setUrl(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  NetworkManager::instance().put(request, document.toJson());
}
