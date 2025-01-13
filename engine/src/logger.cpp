/*
        MIT License

        Copyright (c) 2025 Nizar Daouk

        Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"), to
   deal in the Software without restriction, including without limitation the
   rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
   sell copies of the Software, and to permit persons to whom the Software is
        furnished to do so, subject to the following conditions:

        The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

        THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
        FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
        LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
   IN THE SOFTWARE.
*/

#include <logger.h>

#include <chrono>
#include <iostream>
#include <sstream>

namespace ata::logger {

struct ANSIColors {
  static constexpr const char* black = "\033[30m";
  static constexpr const char* red = "\033[31m";
  static constexpr const char* green = "\033[32m";
  static constexpr const char* yellow = "\033[33m";
  static constexpr const char* blue = "\033[34m";
  static constexpr const char* magenta = "\033[35m";
  static constexpr const char* cyan = "\033[36m";
  static constexpr const char* white = "\033[37m";
  static constexpr const char* reset = "\033[0m";
};

constexpr auto GetLevelStr(LogLevel level) -> const char* {
  switch (level) {
    case LogLevel::TRACE:
      return "TRACE";
    case LogLevel::DEBUG:
      return "DEBUG";
    case LogLevel::INFO:
      return "INFO";
    case LogLevel::WARN:
      return "WARN";
    case LogLevel::ERROR:
      return "ERROR";
    case LogLevel::FATAL:
      return "FATAL";
    default:
      return "UNKNOWN";
  }
}

constexpr auto GetColor(LogLevel level) -> const char* {
  switch (level) {
    case LogLevel::TRACE:
      return ANSIColors::white;
    case LogLevel::DEBUG:
      return ANSIColors::blue;
    case LogLevel::INFO:
      return ANSIColors::green;
    case LogLevel::WARN:
      return ANSIColors::yellow;
    case LogLevel::ERROR:
      return ANSIColors::red;
    case LogLevel::FATAL:
      return ANSIColors::magenta;
    default:
      return ANSIColors::reset;
  }
}

auto Log(LogLevel level, std::string_view msg,
         const std::source_location location) -> void {
  std::stringstream output;

  output << GetColor(level);

  auto now = std::chrono::system_clock::now();
  auto in_time_t = std::chrono::system_clock::to_time_t(now);
  output << std::put_time(std::localtime(&in_time_t), "[%Y-%m-%d %X]");

  if (level == LogLevel::ERROR || level == LogLevel::FATAL) {
    output << location.file_name() << '(' << location.line() << ':'
           << location.column() << ") `" << location.function_name() << "`: ";
  }

  output << GetColor(level) << "[" << GetLevelStr(level) << "]: " << msg
         << ANSIColors::reset << '\n';

  std::clog << output.str();
}

}  // namespace ata::logger
