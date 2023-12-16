/**
 * @file Logger.cpp
 * @author Mateusz Krajewski (matikrajek42@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "logger/Logger.h"
#include "logger/ILogger.h"

namespace simba {
namespace core {
namespace logger {
Logger::Logger(ConsoleLogger_& instance,const std::string& appName,loggingLevel lvl):instance(instance),appName(appName),level(lvl) {
}
void Logger::Debug(const std::string& log, const std::source_location& location) {
    if (level == DEBUG){
    this->instance.Debug("["+this->appName+"]"+log,location);
    }
}
void Logger::Info(const std::string& log, const std::source_location& location) {
    if (level == DEBUG || level == INFO) {
    this->instance.Info("["+this->appName+"]"+log,location);
    }
}
void Logger::Warning(const std::string& log, const std::source_location& location) {
    if (level == DEBUG || level == INFO || level == WARNING) {
    this->instance.Warning("["+this->appName+"]"+log,location);
    }
}
void Logger::Error(const std::string& log, const std::source_location& location) {
    if (level == DEBUG || level == INFO || level == WARNING || level == ERROR) {
    this->instance.Error("["+this->appName+"]"+log,location);
    }
}

} // logger
} // core
} // simba