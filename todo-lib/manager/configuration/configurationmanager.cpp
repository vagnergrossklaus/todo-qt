#include "configurationmanager.h"

#include <QSettings>

ConfigurationManager::ConfigurationManager() { load(); }

ConfigurationManager &ConfigurationManager::instance() {
  static ConfigurationManager manager;
  return manager;
}

ConfigModel ConfigurationManager::configuration() const {
  return _configuration;
}

void ConfigurationManager::load() {
  QSettings settings("todo.ini", QSettings::Format::IniFormat);
  _configuration.setRepository(settings.value("REPOSITORY", 0).toInt());
  _configuration.setUser(settings.value("USER", "").toString());
  _configuration.setHost(settings.value("REMOTE/HOST", "").toString());
  _configuration.setPort(settings.value("REMOTE/PORT", 0).toInt());
}
