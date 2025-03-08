#include "include/mutils-logger.h"
#include "include/mutils-fhandler.h"
#include <iostream>
#include <optional>

mu::Logger::Logger(LogLevel _level, const std::optional<std::string>& _destination) : level(_level)
{
  if (_destination) {
    this->destination = _destination;
  }
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

  std::string log_entry = "[" + log_level_to_string(_level) + "]: " + _message + "\n";

  if (this->destination && !this->destination->empty()) {
    mu::FileHandler output_file(*this->destination);
    output_file.write(log_entry);
  } else {
    std::cout << log_entry;
  }

  return true;
}