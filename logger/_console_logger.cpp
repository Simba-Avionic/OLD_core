/**
 * @file _console_logger.cpp
 * @author Mateusz Krajewski (matikrajek42@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "logger/_console_logger.hpp"
#include "common/error_code.h"
#include <iostream>

namespace simba{
namespace core{
namespace logger{


void ConsoleLogger_::printLog(const std::string& prefix, const std::string& log, const std::source_location& location) {
    std::cout << prefix << "[" << location.file_name() << ":"
    << location.line() << ":" << location.function_name() << "]"
    << log << std::endl;
}


void ConsoleLogger_::Debug(const std::string& log, const std::source_location& location) {
    this->printLog("[DEBUG]", log, location);
}
void ConsoleLogger_::Info(const std::string& log, const std::source_location& location) {
        this->printLog("[INFO]", log, location);
}
void ConsoleLogger_::Warning(const std::string& log, const std::source_location& location) {
    this->printLog("[WARNING]", log, location);

}
void ConsoleLogger_::Error(const std::string& log, const std::source_location& location) {
    this->printLog("ERROR", log, location);
}

} // logger
} // core
} // simba