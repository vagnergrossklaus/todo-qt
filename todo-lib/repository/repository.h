#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "todo-lib_global.h"

#include <QVector>

template <class T> class Repository {
public:
  Repository() {}

  virtual QVector<T *> findAll() = 0;
  virtual void add(T *t) = 0;
  virtual void remove(const int &id) = 0;
  virtual void update(T *t) = 0;
};

#endif // REPOSITORY_H
