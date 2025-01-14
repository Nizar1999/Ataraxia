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

#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace ata {
namespace {
std::vector<std::string> Split(const std::string& s, char delim) {
  std::vector<std::string> result;
  std::stringstream ss(s);
  std::string item;

  while (getline(ss, item, delim)) {
    result.push_back(item);
  }

  return result;
}

std::pair<std::string, std::string> ParseProperty(std::string property) {
  std::vector<std::string> v = Split(property, ':');
  return {v[0], v[1]};
}
}  // namespace

Scene::Scene(std::filesystem::path path) : m_path(path) {}
auto Scene::Load() -> void {
  std::ifstream sceneFile(m_path);
  if (!sceneFile.is_open()) {
    ata::logger::Log(ata::logger::LogLevel::ERROR, "Could not read scene file");
    return;
  }

  std::string sceneObject;
  while (std::getline(sceneFile, sceneObject)) {
    std::stringstream ss(sceneObject);
    std::string property;
    while (std::getline(ss, property, '-')) {
      auto [key, value] = ParseProperty(property);
      ata::logger::Log(ata::logger::LogLevel::INFO,
                       "Key: " + key + " Value: " + value);
    }
  }

  sceneFile.close();
}
}  // namespace ata
