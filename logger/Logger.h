/**
 * @file Logger.h
 * @author Mateusz Krajewski (matikrajek42@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include "common/error_code.h"
#include "logger/ILogger.h"
#include "logger/_console_logger.hpp"

namespace simba {
namespace core {
namespace logger {

class Logger:public ILogger{
 public:
  Logger(ConsoleLogger_& instance,const std::string& appName,loggingLevel lvl = WARNING);
  void Debug(const std::string& log, const std::source_location& location = std::source_location::current()) override;
  void Info(const std::string& log, const std::source_location& location = std::source_location::current()) override;
  void Warning(const std::string& log, const std::source_location& location = std::source_location::current()) override;
  void Error(const std::string& log, const std::source_location& location = std::source_location::current()) override;
 private:
 ConsoleLogger_& instance;
 std::string appName;
 loggingLevel level;

};

} // logger
} // core
} // simba

#endif // LOGGER_HPP_