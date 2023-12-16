/**
 * @file ILogger.h
 * @author Bartosz Snieg (snieg45@gmail.com)
 * @brief This file define interface for logger
 * @version 0.1
 * @date 2023-10-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef LOGGER_ILOGGER_H_
#define LOGGER_ILOGGER_H_
#include <string>
#include <source_location>

#include "core/common/error_code.h"
namespace simba {
namespace core {
namespace logger {

enum loggingLevel{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    OFF
};

class ILogger {

 public:
  virtual void Debug(const std::string& log, const std::source_location& location = std::source_location::current()) = 0;
  virtual void Info(const std::string& log, const std::source_location& location = std::source_location::current()) = 0;
  virtual void Warning(const std::string& log, const std::source_location& location = std::source_location::current()) = 0;
  virtual void Error(const std::string& log, const std::source_location& location = std::source_location::current()) = 0;
};
}  // namespace logger
}  // namespace core
}  // namespace simba
#endif  // LOGGER_ILOGGER_H_
