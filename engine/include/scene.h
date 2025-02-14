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

#include <actor.h>
#include <camera.h>

#include <filesystem>
#include <memory>
#include <string>
#include <vector>

namespace ata
{
    class Scene
    {
      public:
        using Actors = std::vector<std::unique_ptr<Actor>>;

        explicit Scene(std::filesystem::path path);
        auto Load() -> void;

        // TODO: handle no cam set
        auto GetActiveCam() -> Camera & { return m_activeCam; }
        auto GetActors() const -> const Actors & { return m_actors; }

      private:
        std::string           m_name;
        std::filesystem::path m_path;

        // TODO: reconcile actors and cameras?
        Actors m_actors;
        Camera m_activeCam;
    };
}   // namespace ata
