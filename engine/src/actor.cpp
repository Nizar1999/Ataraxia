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
#include <application.h>

namespace ata {
std::unordered_map<std::string, std::function<std::unique_ptr<Actor>()>>
    g_actorRegistry;

auto Actor::Move(const Vec3 position) -> void {
  const Vec3 newPos = m_position + position;
  auto& actors = g_app->m_currentScene->GetActors();
  bool collided = false;

  for (auto& actor : actors) {
    if (actor->GetPosition() == newPos) {
      collided = true;
      OnCollide(*actor);
    }
  }
  if (!collided) SetPosition(newPos);
}

auto Actor::OnCollide(Actor& actor) -> void {}
}  // namespace ata
