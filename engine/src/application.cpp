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

#include <application.h>
#include <console.h>
#include <logger.h>

namespace ata {
ATA Input* g_input = nullptr;
ATA Renderer* g_renderer = nullptr;
ATA Scene* g_currentScene = nullptr;

auto Application::PreInit() -> int {
  if (!m_initialScenePath) {
    logger::Log(logger::LogLevel::FATAL, "Initial scene is not set!");
    return 0;
  }

  LoadScene(m_initialScenePath);
  return 1;
}

auto Application::Update() -> void {
  g_renderer->Clear();
  g_input->PollActions();

  OnTick();

  g_renderer->Display();
}

auto Application::LoadScene(std::string_view scenePath) -> void {
  g_currentScene = new Scene(scenePath);
  g_currentScene->Load();
}
}  // namespace ata
