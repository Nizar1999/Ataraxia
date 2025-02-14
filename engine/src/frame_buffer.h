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

#include <rect.h>
#include <vector.h>

#include <vector>

namespace ata
{
    class FrameBuffer
    {
        using BufferType = std::vector<char>;

      public:
        FrameBuffer();
        FrameBuffer(std::size_t width, std::size_t height);

        auto Clear() -> void;
        auto Write(Rect viewport, IVec2 pos, char symbol) -> void;
        auto Draw() -> void;
        auto Swap() -> void;

      private:
        std::size_t m_width;
        std::size_t m_height;

        std::vector<BufferType> m_backBuffer;
        std::vector<BufferType> m_frontBuffer;
    };
}   // namespace ata
