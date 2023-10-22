/**
 * @file console_logger.cc
 * @author Bartosz Snieg (snieg45@gmail.com)
 * @brief This file define console logger
 * @version 1.0
 * @date 2023-10-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "logger/console_logger.h"

#include "spdlog/spdlog.h"
namespace simba {
namespace core {
namespace logger {
core::ErrorCode ConsoleLogger::Debug(const std::string& log) {
  spdlog::debug(log);
  return core::ErrorCode::kOk;
}
core::ErrorCode ConsoleLogger::Info(const std::string& log) {
  spdlog::info(log);
  return core::ErrorCode::kOk;
}
core::ErrorCode ConsoleLogger::Warning(const std::string& log) {
  spdlog::warn(log);
  return core::ErrorCode::kOk;
}
core::ErrorCode ConsoleLogger::Error(const std::string& log) {
  spdlog::error(log);
  return core::ErrorCode::kOk;
}
}  // namespace logger
}  // namespace core
}  // namespace simba
