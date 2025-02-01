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

#include <console.h>

#include <cstdio>
#include <format>
#include <iostream>

namespace ata::console {
struct CMD {
  static constexpr const char* ESC = "\x1b";
  static constexpr const char* CSI = "\x1b[";
};

namespace {
template <typename... Args>
auto print(Args&&... args) -> void {
  size_t repeatCount = sizeof...(args);
  std::string fmt;
  for (int i = 0; i < repeatCount; ++i) fmt += "{}";
  std::cout << std::vformat(fmt, std::make_format_args(args...));
}
}  // namespace

auto SetColor(Color color) -> void {
  print(CMD::CSI, static_cast<int>(color), "m");
}

auto ResetColor() -> void { SetColor(Color::RESET); }

auto MoveCursor(int n, CursorDirection direction) -> void {
  print(CMD::CSI, n, static_cast<char>(direction));
}

auto SetCursorPosition(int x, int y) -> void {
  print(CMD::CSI, x, ';', y, 'H');
}

auto SetCursorVisibility(CursorVisibility visibility) -> void {
  print(CMD::CSI, "?25", static_cast<char>(visibility));
}

auto Clear() -> void { print(CMD::CSI, "2J", CMD::CSI, "3J"); }

auto ResetCursor() -> void { print(CMD::CSI, 'H'); }

auto UseAlternateBuffer() -> void { print(CMD::CSI, "?1049h"); }

auto RestorePrimaryBuffer() -> void { print(CMD::CSI, "?1049l"); }
}  // namespace ata::console
