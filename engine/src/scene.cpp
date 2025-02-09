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

#include <logger.h>
#include <scene.h>
#include <scene_parser.h>

#include <fstream>
#include <string>

namespace ata
{
    Scene::Scene(std::filesystem::path path)
        : m_path(path)
    {
    }

    auto Scene::Load() -> void
    {
        std::ifstream sceneFile(m_path);
        if(!sceneFile.is_open())
        {
            ata::logger::Log(ata::logger::LogLevel::ERROR, "Could not read scene file");
            return;
        }

        // Read each actor
        std::string actorInfo;
        while(std::getline(sceneFile, actorInfo))
        {
            if(auto actor = scene_parser::ParseActor(actorInfo))
            {
                m_actors.push_back(std::move(actor));
            }
        }

        ata::logger::Log(ata::logger::LogLevel::INFO, "Loaded Actors: " + std::to_string(m_actors.size()));
        sceneFile.close();
    }

} // namespace ata
