#ifndef CONFIGURATIONMANAGER_H
#define CONFIGURATIONMANAGER_H

#include "model/configmodel.h"

class ConfigurationManager {
public:
  ConfigurationManager();

  static ConfigurationManager &instance();

  ConfigModel configuration() const;

private:
  ConfigModel _configuration;

  void load();
};

#endif // CONFIGURATIONMANAGER_H
