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
    int white_spaces_beginning = 0;

    while (raw[white_spaces_beginning] == ' ') {
      white_spaces_beginning++;
    }

    if (raw.find("=") != std::string::npos) {
      if (raw[raw.find("=") - 1] == ' ') {
        name = raw.substr(white_spaces_beginning, raw.find("=") - 1 - white_spaces_beginning);
        value = raw.substr(raw.find("=") + 2);
      } else {
        name = raw.substr(white_spaces_beginning, raw.find("=") - white_spaces_beginning);
        value = raw.substr(raw.find("=") + 1);
      }
    } else {
      name = raw.substr(white_spaces_beginning);
    }
  }
  const std::string GetValue() { return value; }
  const std::string GetName() { return name; }
  ~Parm() = default;
};
}  // namespace core
}  // namespace simba
#endif  // CORE_APPLICATION_PARM_H_
