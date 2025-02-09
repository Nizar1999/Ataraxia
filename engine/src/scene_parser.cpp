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

#include <memory>
#include <sstream>
#include <string>
#include <vector>

namespace
{
    auto Split(const std::string& s, char delim) -> std::vector<std::string>
    {
        std::vector<std::string> result;
        std::stringstream        ss(s);
        std::string              item;

        while(getline(ss, item, delim))
        {
            result.push_back(item);
        }

        return result;
    }
} // namespace

namespace ata::scene_parser
{
    auto ParseProperty(std::string property) -> std::pair<std::string, std::string>
    {
        auto v = Split(property, ':');
        return {v[0], v[1]};
    }

    auto ParseVec(std::string_view s) -> ata::Vec2
    {
        const std::string removeP = std::string(s.substr(1, s.size() - 2));
        auto              v       = Split(removeP, ',');
        ata::Vec2         res(std::stof(v[0]), std::stof(v[1]));
        return res;
    }

    auto ParseActor(const std::string& actorInfo) -> std::unique_ptr<ata::Actor>
    {
        std::stringstream           ss(actorInfo);
        std::string                 property;
        std::unique_ptr<ata::Actor> actor;

        while(std::getline(ss, property, '|'))
        {
            auto [key, value] = ParseProperty(property);
            if(key == "Type")
            {
                if(!ata::g_actorRegistry.contains(value))
                    return nullptr;
                actor = ata::g_actorRegistry[value]();
            }
            if(key == "Pos")
            {
                if(!actor)
                    ata::logger::Log(ata::logger::LogLevel::ERROR, "Failed to parse Pos, no actor set");
                ata::Vec2 position = ParseVec(value);
                actor->SetPosition(position);
            }
            // TODO: Parse additional properties
            ata::logger::Log(ata::logger::LogLevel::INFO, key + " " + value);
        }

        return actor;
    }
} // namespace ata::scene_parser
