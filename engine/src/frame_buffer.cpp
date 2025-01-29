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
#include <frame_buffer.h>

#include <functional>
#include <iostream>

namespace ata {
FrameBuffer::FrameBuffer() {
  console::SetCursorVisibility(console::CursorVisibility::HIDE);
  Clear();
  m_framePresenter = std::thread(std::mem_fn(&FrameBuffer::PresentFrame), this);
}

FrameBuffer::~FrameBuffer() {
  if (m_framePresenter.joinable()) m_framePresenter.join();
}

auto FrameBuffer::Clear() -> void {
  for (auto& row : m_backBuffer) {
    row.fill('O');
  }
}

auto FrameBuffer::PresentFrame() -> void {
  while (true) {
    console::ResetCursor();
    {
      std::lock_guard<std::mutex> lock(m_frontBufferMtx);
      for (auto& row : m_frontBuffer) {
        for (auto ele : row) {
          std::cout << ele;
        }
        std::cout << '\n';
      }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(33));  //~30Hz
  }
}

auto FrameBuffer::Draw(IVec2 pos, char symbol) -> void {
  auto [x, y] = pos;
  if (x >= 0 && x < s_rows && y >= 0 && y < s_cols) m_backBuffer[x][y] = symbol;
}

auto FrameBuffer::SwapBuffers() -> void {
  std::lock_guard<std::mutex> lock(m_frontBufferMtx);
  m_frontBuffer = m_backBuffer;
}
}  // namespace ata
