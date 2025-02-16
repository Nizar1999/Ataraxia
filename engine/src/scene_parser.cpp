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
#include <logger.h>
#include <scene_parser.h>
#include <vector.h>

#include <array>
#include <sstream>
#include <string>

namespace
{
    auto Split(const std::string &s, char delim) -> std::array<std::string, 2>
    {
        std::array<std::string, 2> result;
        std::stringstream          ss(s);
        std::string                item;

        int i = 0;
        while (getline(ss, item, delim)) { result[i++] = item; }

        return result;
    }
}   // namespace

namespace ata::scene_parser
{
    auto ParseProperty(const std::string &property) -> std::pair<std::string, std::string>
    {
        std::array<std::string, 2> v = Split(property, ':');
        return { v[0], v[1] };
    }

    auto ParseVec(std::string_view s) -> Vec2
    {
        const std::string removeParanthesis = std::string(s.substr(1, s.size() - 2));

        auto v = Split(removeParanthesis, ',');
        return { std::stof(v[0]), std::stof(v[1]) };
    }

    auto ParseActor(const std::string &actorInfo) -> std::optional<ActorDefinition>
    {
        std::stringstream ss(actorInfo);
        std::string       property;
        ActorDefinition   actor;

        while (std::getline(ss, property, '|'))
        {
            auto [key, value] = ParseProperty(property);
            if (key == "Type")
            {
                if (! g_actorRegistry.contains(value)) return std::nullopt;
                actor.m_type = value;
            }
            if (key == "Pos")
            {
                if (actor.m_type.empty()) return std::nullopt;
                actor.m_position = ParseVec(value);
            }
        }

        return actor;
    }
}   // namespace ata::scene_parser
