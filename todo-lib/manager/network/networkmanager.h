#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include "todo-lib_global.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QObject>

class TODOLIBSHARED_EXPORT NetworkManager : public QObject {
  Q_OBJECT
public:
  static NetworkManager &instance();

  QByteArray get(QNetworkRequest request);
  QByteArray post(QNetworkRequest request, const QByteArray &data);
  void put(QNetworkRequest request, const QByteArray &data);

private:
  NetworkManager();

  void onFinished(QNetworkReply *reply);

  QNetworkAccessManager *_restclient;
};

#endif // NETWORKMANAGER_H
