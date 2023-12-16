/**
 * @file console_logger.h
 * @author Bartosz Snieg (snieg45@gmail.com)
 * @brief This file define console logger
 * @version 1.0
 * @date 2023-10-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef LOGGER_CONSOLE_LOGGER_H_
#define LOGGER_CONSOLE_LOGGER_H_
#include "core/common/error_code.h"
#include "core/logger/ILogger.h"
#include <string>
namespace simba {
namespace core {
namespace logger {

class ConsoleLogger : public ILogger {
 public:
  ConsoleLogger();
  void Debug(const std::string& log) override;
  void Info(const std::string& log) override;
  void Warning(const std::string& log) override;
  void Error(const std::string& log) override;
};
}  // namespace logger
}  // namespace core
}  // namespace simba
#endif  // LOGGER_CONSOLE_LOGGER_H_
