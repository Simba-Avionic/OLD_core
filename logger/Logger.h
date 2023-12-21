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
#include <memory>
#include <vector>

namespace simba {
namespace core {
namespace logger {

class Logger{
 public:
  static void Debug(const std::string& log, const std::source_location& location = std::source_location::current());
  static void Info(const std::string& log, const std::source_location& location = std::source_location::current());
  static void Warning(const std::string& log, const std::source_location& location = std::source_location::current());
  static void Error(const std::string& log, const std::source_location& location = std::source_location::current());
  static void SetParms(const std::string& appName,loggingLevel lvl = WARNING);
  static void AddLogger(std::shared_ptr<ILogger> logger);
 private:
    static std::string appName;
    static loggingLevel level;
    static std::vector<std::shared_ptr<ILogger>> loggers;
};

} // logger
} // core
} // simba

using AppLogger = simba::core::logger::Logger;

#endif // LOGGER_HPP_