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
#include <input.h>
#include <player.h>

namespace demo {
Player::Player() {
  m_renderData = {'P'};
  auto input = g_app->m_input;
  assert(input != nullptr);

  input->BindInputAction<Player>({ata::KeyCode::W}, this, &Player::OnW);
  input->BindInputAction<Player>({ata::KeyCode::A}, this, &Player::OnA);
  input->BindInputAction<Player>({ata::KeyCode::S}, this, &Player::OnS);
  input->BindInputAction<Player>({ata::KeyCode::D}, this, &Player::OnD);
}

auto Player::OnW() -> void { m_position += ata::Vec3(-1, 0, 0); }
auto Player::OnA() -> void { m_position += ata::Vec3(0, -1, 0); }
auto Player::OnS() -> void { m_position += ata::Vec3(1, 0, 0); }
auto Player::OnD() -> void { m_position += ata::Vec3(0, 1, 0); }
}  // namespace demo
