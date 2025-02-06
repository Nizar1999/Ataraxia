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

namespace ata::console {

enum class Color {
  BLACK = 30,
  RED = 31,
  GREEN = 32,
  YELLOW = 33,
  BLUE = 34,
  MAGENTA = 35,
  CYAN = 36,
  WHITE = 37,
  RESET = 0,
};

enum class CursorDirection {
  UP = 'A',
  DOWN = 'B',
  FORWARD = 'C',
  BACKWARD = 'D',
  NEXT_LINE = 'E',
  PREVIOUS_LINE = 'F',
  HORIZONTAL_POS = 'G',
  VERTICAL_POS = 'd',
};

enum class CursorVisibility { SHOW = 'h', HIDE = 'l' };

enum class Border {
  TopRight = 'k',
  TopLeft = 'l',
  BottomRight = 'j',
  BottomLeft = 'm',
  Center = 'n',
  CenterRight = 'u',
  CenterLeft = 't',
  CenterTop = 'w',
  CenterBottom = 'v',
  Horizontal = 'q',
  Vertical = 'x',
};

// TODO(nizar): Make threading safe
auto SetColor(Color color) -> void;
auto ResetColor() -> void;
auto MoveCursor(int n, CursorDirection direction) -> void;
auto SetCursorPosition(std::size_t x, std::size_t y) -> void;
auto SetCursorVisibility(CursorVisibility visibility) -> void;
auto Clear() -> void;
auto ResetCursor() -> void;
auto UseAlternateBuffer() -> void;
auto RestorePrimaryBuffer() -> void;
auto EnableLineDrawingMode() -> void;
auto DisableLineDrawingMode() -> void;
auto DrawBoxBorders(Rect bounds) -> void;
auto DrawVerticalLines(Rect bounds) -> void;
auto DrawHorizontalLines(Rect bounds) -> void;
}  // namespace ata::console
