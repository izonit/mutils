//===------------------------------------------------===//
//
// Logging utility with different log levels.
//
// Consists of a class with logging methods
//
// Originally created: 07.03.2025 (DD.MM.YYYY)
// Author: mizorint (a.k.a. izonit)
//
//===------------------------------------------------===//

#pragma once

#include <optional>
#include <string>

namespace mu {
  // Enum of all possible log levels you can choose from
  enum class LogLevel {
    DEBUG,
    INFO,
    WARN,
    ERROR //
  };

  class Logger {
  private:
    // Current log level (you provide it in the constructor)
    mu::LogLevel level;

    // Where to log the output(stdout by default)
    std::optional<std::string> destination;

    // Convert the LogLevel enum's content into a string
    inline std::string log_level_to_string(mu::LogLevel _level)
    {
      switch (_level) {
      case mu::LogLevel::DEBUG:
        return "DEBUG";
      case mu::LogLevel::INFO:
        return "INFO";
      case mu::LogLevel::WARN:
        return "WARN";
      case mu::LogLevel::ERROR:
        return "ERROR";
      default:
        return "UNKNOWN";
      }
    }

    /* Check whether or not logger should log the output
     * (compare current log level with the message's log level) */
    bool should_log(mu::LogLevel _level);

  public:
    // Constructor of the logger (select the log level and the destination)
    Logger(mu::LogLevel _level, const std::optional<std::string>& _destination);

    // Default destructor
    ~Logger() = default;

    /* Log the message to the destination you selected (respects your current selected log level)
     * Returns true if the operation is succesful, false if faulty */
    bool log(const std::string& _message, LogLevel _level);
  };
} // namespace mu