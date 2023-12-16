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
#include <string>

#include "logger/console_logger.h"

#include "spdlog/spdlog.h"


namespace simba {
namespace core {
namespace logger {
  ConsoleLogger::ConsoleLogger() {
    spdlog::set_level(spdlog::level::debug);
  }
void ConsoleLogger::Debug(const std::string& log) {
  spdlog::debug(log);
  return void::kOk;
}
void ConsoleLogger::Info(const std::string& log) {
  spdlog::info(log);
  return void::kOk;
}
void ConsoleLogger::Warning(const std::string& log) {
  spdlog::warn(log);
  return void::kOk;
}
void ConsoleLogger::Error(const std::string& log) {
  spdlog::error(log);
  return void::kOk;
}
}  // namespace logger
}  // namespace core
}  // namespace simba
