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
std::string  Logger::appName = "NONE";
loggingLevel Logger::level = loggingLevel::WARNING;
std::vector<std::shared_ptr<ILogger>> Logger::loggers = {};


void Logger::SetParms(const std::string& appName,loggingLevel lvl) {
  Logger::appName = appName;
  Logger::level = lvl;
}
void Logger::Debug(const std::string& log, const std::source_location& location) {
    if (Logger::level == DEBUG){
    for( auto logger : Logger::loggers)
    {
        logger->Debug(log, location);
    }
    }
}
void Logger::Info(const std::string& log, const std::source_location& location) {
    if (level == DEBUG || level == INFO) {
    for( auto logger : Logger::loggers)
    {
        logger->Info(log, location);
    }
    }
}
void Logger::Warning(const std::string& log, const std::source_location& location) {
    if (level == DEBUG || level == INFO || level == WARNING) {
        for( auto logger : this->loggers)
    {
        logger->Warning(log, location);
    }
    }
}
void Logger::Error(const std::string& log, const std::source_location& location) {
    if (level == DEBUG || level == INFO || level == WARNING || level == ERROR) {
    for( auto logger : this->loggers)
    {
        logger->Error(log, location);
    }
    }
}

void Logger::AddLogger(std::shared_ptr<ILogger> logger){
    this->loggers.push_back(logger);
}

} // logger
} // core
} // simba