/**
 * @file _console_logger.h
 * @author Mateusz Krajewski (matikrajek42@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _LOGGER_CONSOLE_LOGGER_H_
#define _LOGGER_CONSOLE_LOGGER_H_
#include "common/error_code.h"
#include "logger/ILogger.h"
#include <string>
#include <source_location>
namespace simba {
namespace core {
namespace logger {


class ConsoleLogger_ : public ILogger {
 public:
  static ConsoleLogger_& getInstance(){
    static ConsoleLogger_ instance;
    return instance;
  }
  ConsoleLogger_(){};
  void Debug(const std::string& log, const std::source_location& location) override;
  void Info(const std::string& log, const std::source_location& location) override;
  void Warning(const std::string& log, const std::source_location& location) override;
  void Error(const std::string& log, const std::source_location& location) override;
 private:

    void printLog(const std::string& prefix, const std::string& log, const std::source_location& location);
};
}  // namespace logger
}  // namespace core
}  // namespace simba
#endif  // _LOGGER_CONSOLE_LOGGER_H_

