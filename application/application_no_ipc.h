/**
 * @file Iapplication.h
 * @author Bartosz Snieg (snieg45@gmail.com)
 * @brief Interface for all Simba application
 * @version 1.0
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef CORE_APPLICATION_APLICATION_NO_IPC_H_
#define CORE_APPLICATION_APLICATION_NO_IPC_H_
#include <memory>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>
#include <fstream>

#include "core/application/Iapplication.h"
#include "core/logger/ILogger.h"
#include "core/logger/console_logger.h"

namespace simba {
namespace core {
class ApplicationNoIPC : public IApplication {
 protected:
  std::shared_ptr<logger::ILogger> logger_;
  nlohmann::json data{};
  virtual void Run(
      const std::unordered_map<std::string, Parm>& parms) override {
    logger_->Error("Application function: Run is not implemented: ");
  }

  void onRun(const std::unordered_map<std::string, Parm>& parms) override {
    AppLogger::SetParms("NONE", logger::loggingLevel::DEBUG);
    AppLogger::AddLogger(std::make_shared<logger::ConsoleLogger>());
    AppLogger::Info("Application started");
    this->Run(parms);
    AppLogger::Info("Application stopped");
  }

 public:
  virtual ~ApplicationNoIPC() = default;
};
}  // namespace core
}  // namespace simba
#endif  // CORE_APPLICATION_APLICATION_NO_IPC_H_
