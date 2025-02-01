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

#include <algorithm>

namespace ata {
auto ConsoleRenderer::ClearBuffer() -> void {
  std::ranges::for_each(m_targets, [](auto& target) { target->Clear(); });
}

namespace {
auto DrawSceneToTarget(Scene& scene, FrameBuffer& target) -> void {
  Camera& activeCam = scene.GetActiveCam();
  for (auto& actor : scene.GetActors()) {
    IVec2 worldPos = actor->GetPosition();
    target.Draw(activeCam.GetViewMatrix() * worldPos,
                actor->GetRenderData().symbol);
  }
}
}  // namespace

auto ConsoleRenderer::DrawScene(Scene& scene) -> void {
  std::ranges::for_each(
      m_targets, [&scene](auto& target) { DrawSceneToTarget(scene, *target); });
}

auto ConsoleRenderer::SwapBuffers() -> void {
  std::ranges::for_each(m_targets, [](auto& target) { target->SwapBuffers(); });
}

auto ConsoleRenderer::AddTarget(Rect bounds) -> void {
  m_targets.emplace_back(std::make_unique<FrameBuffer>(bounds));
}

}  // namespace ata
