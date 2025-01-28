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

#include <fcntl.h>
#include <input_handler.h>
#include <termios.h>
#include <unistd.h>

namespace ata {
namespace {
auto PressedKey() -> bool {
  struct termios oldt, newt;
  int ch;
  bool ret = false;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  newt.c_cc[VMIN] = 1;
  newt.c_cc[VTIME] = 0;
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  ch = getchar();
  if (ch != EOF) {
    ret = true;
    ungetc(ch, stdin);
  }

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ret;
}
}  // namespace

auto InputHandler::PollKeyPresses() -> void {
  while (true) {
    if (PressedKey()) {
      unsigned int ch = getchar();
      std::lock_guard lk(m_keyStateMtx);
      m_keyStates[ch] = true;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}
}  // namespace ata
