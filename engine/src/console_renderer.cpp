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

#include <console_renderer.h>

#include <iostream>
#include <thread>

namespace ata {
int i = 0;
int j = 0;
auto ConsoleRenderer::ClearBuffer() -> void {
  for (auto& row : m_buffer) row.fill(' ');
}

auto ConsoleRenderer::Display(const Scene& scene) -> void {
  system("clear");
  for (auto& actor : scene.GetActors()) {
    m_buffer[i][j] = actor->GetRenderData().symbol;
  }
  i = ++i % s_bufferH;
  j = ++j % s_bufferW;
  for (auto& row : m_buffer) {
    for (auto ele : row) {
      std::cout << ele;
    }
    std::cout << '\n';
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(33));  //~30fps
}
}  // namespace ata
