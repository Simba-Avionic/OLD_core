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
#ifndef CORE_LOGGER_ILOGGER_H_
#define CORE_LOGGER_ILOGGER_H_
#include "common/error_code.h"
namespace simba {
namespace core {
namespace logger {
class ILogger {
 public:
  virtual core::ErrorCode Debug(const std::string& log) = 0;
  virtual core::ErrorCode Info(const std::string& log) = 0;
  virtual core::ErrorCode Warning(const std::string& log) = 0;
  virtual core::ErrorCode Error(const std::string& log) = 0;
  virtual ~ILogger() = default;
};
}  // namespace logger
}  // namespace core
}  // namespace simba
#endif  // CORE_LOGGER_ILOGGER_H_
