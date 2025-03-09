#include "include/mutils-logger.h"
#include "include/mutils-fhandler.h"
#include <iostream>
#include <optional>

mu::Logger::Logger(mu::LogLevel _level, const std::optional<std::string>& _destination) :
    level(_level),
    destination(_destination)
{
}

bool mu::Logger::should_log(mu::LogLevel _level)
{
  return static_cast<int>(_level) >= static_cast<int>(this->level);
}

bool mu::Logger::log(const std::string& _message, LogLevel _level)
{
  if (!should_log(_level)) {
    return false;
  }

  std::string log_entry;

  if (this->destination && !this->destination->empty()) {
    log_entry = "[" + log_level_to_string(_level) + "]: " + _message + "\n";
    mu::FileHandler output_file(*this->destination);
    output_file.write(log_entry);
  } else {
    switch (_level) {
    case mu::LogLevel::DEBUG:
      log_entry = "\033[1;34m[" + log_level_to_string(_level) + "]\033[0;37m: " + _message + "\n";
      break;
    case mu::LogLevel::INFO:
      log_entry = "\033[1;32m[" + log_level_to_string(_level) + "]\033[0;37m: " + _message + "\n";
      break;
    case LogLevel::WARN:
      log_entry = "\033[1;33m[" + log_level_to_string(_level) + "]\033[0;37m: " + _message + "\n";
      break;
    case LogLevel::ERROR:
      log_entry = "\033[1;31m[" + log_level_to_string(_level) + "]\033[0;37m: " + _message + "\n";
      break;
    }
    std::cout << log_entry;
  }

  return true;
}