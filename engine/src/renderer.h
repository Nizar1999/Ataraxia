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

#include <config.h>
#include <frame_buffer.h>
#include <scene.h>

#include <mutex>
#include <thread>

namespace ata {
class ATA Renderer {
 public:
  Renderer();
  ~Renderer();

  Renderer(const Renderer& other) = delete;
  auto operator=(const Renderer& other) -> Renderer& = delete;

  auto Clear() -> void;
  auto Draw(Scene& scene) -> void;
  auto Display() -> void;
  auto SetViewport(Rect bounds) -> void { m_viewport = bounds; }

 private:
  Rect m_viewport;
  FrameBuffer m_buffer;
  std::thread m_displayThread;
  std::mutex m_bufferMtx;

  auto DisplayBuffer() -> void;
};
}  // namespace ata
