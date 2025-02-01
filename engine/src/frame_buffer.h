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

#pragma once

#include <rect.h>
#include <vector.h>

#include <mutex>
#include <thread>
#include <vector>

namespace ata {
class FrameBuffer {
 public:
  FrameBuffer(Rect bounds);
  ~FrameBuffer();

  auto Clear() -> void;
  auto Draw(IVec2 pos, char symbol) -> void;
  auto SwapBuffers() -> void;
  auto GetBounds() -> const Rect& { return m_bounds; }

 private:
  using InnerBuffer = std::vector<char>;
  using Buffer = std::vector<std::vector<char>>;

  Rect m_bounds;
  Buffer m_backBuffer;
  Buffer m_frontBuffer;

  std::thread m_framePresenter;
  mutable std::mutex m_frontBufferMtx;

  auto PresentFrame() -> void;
};
}  // namespace ata
