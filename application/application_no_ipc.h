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
#include <string>

#include "application/Iapplication.h"
#include "logger/ILogger.h"
#include "logger/console_logger.h"
namespace simba {
namespace core {
class ApplicationNoIPC : public IApplication {
 protected:
  std::shared_ptr<logger::ILogger> logger_;
  virtual void Run(const std::unordered_map<std::string, Parm>& parms) override {
    logger_->Error("Application function: Run is not implemented: ");
  }

  void onRun(const std::unordered_map<std::string, Parm>& parms) override {
    this->logger_ = std::make_shared<logger::ConsoleLogger>();
    logger_->Info("Application started");
    this->Run(parms);
    logger_->Info("Application stopped");
  }

 public:
  virtual ~ApplicationNoIPC() = default;
};
}  // namespace core
}  // namespace simba
#endif  // CORE_APPLICATION_APLICATION_NO_IPC_H_
