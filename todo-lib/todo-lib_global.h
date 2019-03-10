#ifndef TODOLIB_GLOBAL_H
#define TODOLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TODOLIB_LIBRARY)
#  define TODOLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define TODOLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // TODOLIB_GLOBAL_H
