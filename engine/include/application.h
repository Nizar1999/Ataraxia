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
#include <input.h>
#include <renderer.h>
#include <scene.h>

namespace ata {
extern ATA Input* g_input;
extern ATA Renderer* g_renderer;
extern ATA Scene* g_currentScene;

class ATA Application {
 public:
  virtual auto Init() -> void = 0;
  virtual auto OnTick() -> void = 0;
  virtual ~Application() = default;

  auto PreInit() -> int;
  auto Update() -> void;
  auto LoadScene(std::string_view scenePath) -> void;

 protected:
  const char* m_initialScenePath;
};
}  // namespace ata

extern ata::Application* g_app;
