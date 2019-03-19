#include "networkmanager.h"

#include <QEventLoop>
#include <QNetworkReply>

NetworkManager::NetworkManager() : QObject(Q_NULLPTR) {
  _restclient = new QNetworkAccessManager();
}

void NetworkManager::onFinished(QNetworkReply *reply) {
  qDebug() << reply->errorString();
  qDebug() << reply->readAll();
}

NetworkManager &NetworkManager::instance() {
  static NetworkManager manager;
  return manager;
}

QByteArray NetworkManager::get(QNetworkRequest request) {

  QEventLoop loop;
  connect(_restclient, &QNetworkAccessManager::finished, &loop,
          &QEventLoop::quit);

  QNetworkReply *reply = _restclient->get(request);

  loop.exec();

  return reply->readAll();
}

QByteArray NetworkManager::post(QNetworkRequest request,
                                const QByteArray &data) {
  QEventLoop loop;
  connect(_restclient, &QNetworkAccessManager::finished, &loop,
          &QEventLoop::quit);

  QNetworkReply *reply = _restclient->post(request, data);

  loop.exec();

  return reply->readAll();
}

void NetworkManager::put(QNetworkRequest request, const QByteArray &data) {
  QEventLoop loop;
  connect(_restclient, &QNetworkAccessManager::finished, &loop,
          &QEventLoop::quit);

  QNetworkReply *reply = _restclient->put(request, data);

  qDebug() << reply->errorString();
  qDebug() << reply->readAll();

  loop.exec();
}
