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
    this->logger_ = std::make_shared<logger::ConsoleLogger>();
    const auto config = parms.find("config_path");
    if (config != parms.cend()) {
      std::ifstream f(config->second.GetValue());
      if (f.is_open()) {
        data = nlohmann::json::parse(f);
      } else {
        logger_->Error("File on path: " + config->second.GetValue() +
                       " not exist!!");
      }
    }

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
