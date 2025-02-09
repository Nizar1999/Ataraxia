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

#include <cstdio>
#include <format>
#include <iostream>

namespace ata::console
{
    struct CMD
    {
        static constexpr const char* ESC = "\x1b";
        static constexpr const char* CSI = "\x1b[";
        static constexpr const char* DEC = "\x1b(";
    };

    namespace
    {
        template <typename... Args>
        auto print(Args&&... args) -> void
        {
            size_t      repeatCount = sizeof...(args);
            std::string fmt;
            for(int i = 0; i < repeatCount; ++i)
                fmt += "{}";
            std::cout << std::vformat(fmt, std::make_format_args(args...));
            std::cout << std::flush;
        }
    } // namespace

    auto SetColor(Color color) -> void
    {
        print(CMD::CSI, static_cast<int>(color), "m");
    }

    auto ResetColor() -> void
    {
        SetColor(Color::RESET);
    }

    auto MoveCursor(int n, CursorDirection direction) -> void
    {
        print(CMD::CSI, n, static_cast<char>(direction));
    }

    auto SetCursorPosition(std::size_t x, std::size_t y) -> void
    {
        print(CMD::CSI, y + 1, ';', x + 1, 'H');
    }

    auto SetCursorVisibility(CursorVisibility visibility) -> void
    {
        print(CMD::CSI, "?25", static_cast<char>(visibility));
    }

    auto Clear() -> void
    {
        print(CMD::CSI, "2J", CMD::CSI, "3J");
    }

    auto ResetCursor() -> void
    {
        print(CMD::CSI, 'H');
    }

    auto UseAlternateBuffer() -> void
    {
        print(CMD::CSI, "?1049h");
    }

    auto RestorePrimaryBuffer() -> void
    {
        print(CMD::CSI, "?1049l");
    }

    auto EnableLineDrawingMode() -> void
    {
        print(CMD::DEC, 0);
    }

    auto DisableLineDrawingMode() -> void
    {
        print(CMD::DEC, 'B');
    }

    namespace
    {
        auto DrawBorder(std::size_t x, std::size_t y, Border border) -> void
        {
            SetCursorPosition(x, y);
            print(static_cast<char>(border));
        }
    } // namespace

    auto DrawVerticalLines(Rect bounds) -> void
    {
        for(std::size_t row = bounds.x; row < bounds.x + bounds.h; ++row)
        {
            if(bounds.y > 0)
            {
                DrawBorder(row, bounds.y - 1, Border::Vertical);
            }
            DrawBorder(row, bounds.y + bounds.w, Border::Vertical);
        }
    }

    auto DrawHorizontalLines(Rect bounds) -> void
    {
        for(std::size_t col = bounds.y; col < bounds.y + bounds.w; ++col)
        {
            if(bounds.x > 0)
            {
                DrawBorder(bounds.x - 1, col, Border::Horizontal);
            }
            DrawBorder(bounds.x + bounds.h, col, Border::Horizontal);
        }
    }

    auto DrawBoxBorders(Rect bounds) -> void
    {
        EnableLineDrawingMode();

        // Corners
        if(bounds.x > 0 && bounds.y > 0)
        {
            DrawBorder(bounds.x - 1, bounds.y - 1, Border::TopLeft);
        }

        // Condition for y right side?
        if(bounds.x > 0)
        {
            DrawBorder(bounds.x - 1, bounds.y + bounds.w, Border::TopRight);
        }

        // Condition for x bottom?
        if(bounds.y > 0)
        {
            DrawBorder(bounds.x + bounds.h, bounds.y - 1, Border::BottomLeft);
        }

        DrawBorder(bounds.x + bounds.h, bounds.y + bounds.w, Border::BottomRight);

        DrawHorizontalLines(bounds);
        DrawVerticalLines(bounds);
        DisableLineDrawingMode();
    }

    auto Write(std::string_view msg)
    {
        std::cout << msg;
    }
} // namespace ata::console
