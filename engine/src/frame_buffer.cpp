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

#include <console.h>
#include <frame_buffer.h>

#include <iostream>

namespace ata
{
    FrameBuffer::FrameBuffer()
        : FrameBuffer(60, 30)
    {
    }

    FrameBuffer::FrameBuffer(std::size_t width, std::size_t height)
        : m_width(width)
        , m_height(height)
        , m_frontBuffer(std::vector(m_height, BufferType(m_width)))
        , m_backBuffer(std::vector(m_height, BufferType(m_width)))
    {
        console::SetCursorVisibility(console::CursorVisibility::HIDE);
        Clear();
    }

    auto FrameBuffer::Clear() -> void
    {
        for(auto& row : m_backBuffer)
        {
            std::fill(row.begin(), row.end(), ' ');
        }
    }

    auto FrameBuffer::Draw() -> void
    {
        for(std::size_t y = 0; y < m_height; ++y)
        {
            console::SetCursorPosition(0, y);
            for(auto symbol : m_frontBuffer[y])
            {
                std::cout << symbol;
            }
        }
        std::cout << std::flush;
        console::ResetCursor();
    }

    auto FrameBuffer::Write(Rect viewport, IVec2 pos, char symbol) -> void
    {
        auto [x, y] = pos;
        x += static_cast<int>(viewport.x);
        y += static_cast<int>(viewport.y);

        if(x >= viewport.x && x < (viewport.x + viewport.w) && y >= viewport.y && y < (viewport.y + viewport.h))
            m_backBuffer[y][x] = symbol;
    }

    auto FrameBuffer::Swap() -> void
    {
        m_frontBuffer = m_backBuffer;
    }
} // namespace ata
