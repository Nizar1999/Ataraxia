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

#include <actor.h>
#include <game.h>

ata::Application* g_app = new demo::Game();

namespace demo {
Game::Game() { m_initialScenePath = "mainmenu.scene"; }

auto Game::Init() -> void {
  m_input->BindInputAction<Game>({ata::KeyCode::A}, this, &Game::OnA);
  m_input->BindInputAction<Game>({ata::KeyCode::D}, this, &Game::OnD);
  m_input->BindInputAction<Game>({ata::KeyCode::W}, this, &Game::OnW);
  m_input->BindInputAction<Game>({ata::KeyCode::S}, this, &Game::OnS);
}

auto Game::OnTick() -> void {
  auto& player = m_currentScene->GetActors()[0];
  auto [x, y, _] = player->GetPosition();
}

auto Game::OnW() -> void {
  auto& cam = m_currentScene->GetActiveCam();
  auto pos = cam.GetPosition();
  ata::Vec2 newP = {pos.x - 1.0f, pos.y};
  const_cast<ata::Camera&>(cam).SetPosition(newP);
}

auto Game::OnS() -> void {
  auto& cam = m_currentScene->GetActiveCam();
  auto pos = cam.GetPosition();
  ata::Vec2 newP = {pos.x + 1.0f, pos.y};
  const_cast<ata::Camera&>(cam).SetPosition(newP);
}

auto Game::OnD() -> void {
  auto& cam = m_currentScene->GetActiveCam();
  auto pos = cam.GetPosition();
  ata::Vec2 newP = {pos.x, pos.y + 1.0f};
  const_cast<ata::Camera&>(cam).SetPosition(newP);
}

auto Game::OnA() -> void {
  auto& cam = m_currentScene->GetActiveCam();
  auto pos = cam.GetPosition();
  ata::Vec2 newP = {pos.x, pos.y - 1.0f};
  const_cast<ata::Camera&>(cam).SetPosition(newP);
}
}  // namespace demo
