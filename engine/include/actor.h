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
#include <vector.h>

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

namespace ata
{
    struct RenderData
    {
        char symbol;
    };

    struct ActorDefinition
    {
        std::string m_type;
        Vec3        m_position;
        RenderData  m_renderData;
    };

    class ATA Actor
    {
      public:
        virtual ~Actor() = default;
        virtual auto v_Startup() -> void;

        auto SetPosition(Vec3 position) -> void { m_position = position; };
        auto GetPosition() const -> const Vec3 { return m_position; };
        auto GetRenderData() const -> const RenderData { return m_renderData; };

      protected:
        Vec3       m_position;
        RenderData m_renderData;

        virtual auto OnCollide(Actor &actor) -> void;
    };

    using registrationFn = std::function<std::unique_ptr<Actor>()>;
    using ActorRegistry  = std::unordered_map<std::string, registrationFn>;

    ATA extern ActorRegistry g_actorRegistry;

    inline auto RegisterClass(const std::string &className, registrationFn fn) -> void
    {
        g_actorRegistry[className] = fn;
    }

#define REGISTER_ACTOR(className)                                                                                      \
    struct className##Registrar                                                                                        \
    {                                                                                                                  \
        className##Registrar()                                                                                         \
        {                                                                                                              \
            ata::RegisterClass(#className,                                                                             \
                               []() -> std::unique_ptr<ata::Actor> { return std::make_unique<className>(); });         \
        }                                                                                                              \
    };                                                                                                                 \
    static className##Registrar g_##className##StaticClass;
}   // namespace ata
