/**
 * @file parm.h
 * @author Bartosz Snieg (snieg45@gmail.com)
 * @brief Application paramiters
 * @version 1.0
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef CORE_APPLICATION_PARM_H_
#define CORE_APPLICATION_PARM_H_
#include <algorithm>
#include <string>
#include <algorithm>
namespace simba {
namespace core {
class Parm {
 protected:
  std::string name{""};
  std::string value{""};

 public:
  Parm(const std::string raw) {
    std::string rawCopy = raw;
    rawCopy.erase(std::remove_if(rawCopy.begin(), rawCopy.end(), ::isspace), rawCopy.end());
    if (rawCopy.find("=") != std::string::npos) {
      if (rawCopy.substr(rawCopy.find("=")+1)[0] == '=') { 
        name = rawCopy.substr(0, rawCopy.find("="));
        value = rawCopy.substr(rawCopy.find("=")+2);
      } else {
        name = rawCopy.substr(0, rawCopy.find("="));
        value = rawCopy.substr(rawCopy.find("=")+1);
      }
    } else {
      name = rawCopy;
    }
  }
  const std::string GetValue() { return value; }
  const std::string GetName() { return name; }
  ~Parm() = default;
};
}  // namespace core
}  // namespace simba
#endif  // CORE_APPLICATION_PARM_H_
