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

  ata::g_input->BindInputAction<Player>({ata::KeyCode::W}, this, &Player::OnW);
  ata::g_input->BindInputAction<Player>({ata::KeyCode::A}, this, &Player::OnA);
  ata::g_input->BindInputAction<Player>({ata::KeyCode::S}, this, &Player::OnS);
  ata::g_input->BindInputAction<Player>({ata::KeyCode::D}, this, &Player::OnD);
}

auto Player::OnCollide(Actor& actor) -> void {
  if (actor.GetRenderData().symbol == 'E') {
    // g_app->LoadScene("test.scene");
    return;
  }
}

auto Player::OnW() -> void { Move({0, -1, 0}); }
auto Player::OnA() -> void { Move({-1, 0, 0}); }
auto Player::OnS() -> void { Move({0, 1, 0}); }
auto Player::OnD() -> void { Move({1, 0, 0}); }
}  // namespace demo
