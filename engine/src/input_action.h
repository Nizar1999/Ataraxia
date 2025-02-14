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

namespace ata
{
    enum class KeyCode : unsigned int;
    struct ATA InputAction
    {
        auto operator==(const InputAction &other) const -> bool;

        struct ATA Hash
        {
            auto operator()(const InputAction &action) const -> unsigned int;
        };

        KeyCode m_key;
    };

    enum class KeyCode : unsigned int
    {
        // Printable keys
        Backspace = 0x08,
        Tab       = 0x09,
        Enter     = 0x0D,
        Shift     = 0x10,
        Ctrl      = 0x11,
        Alt       = 0x12,
        Pause     = 0x13,
        CapsLock  = 0x14,
        Esc       = 0x1B,
        Space     = 0x20,

        // Navigation keys
        PageUp     = 0x21,
        PageDown   = 0x22,
        End        = 0x23,
        Home       = 0x24,
        LeftArrow  = 0x25,
        UpArrow    = 0x26,
        RightArrow = 0x27,
        DownArrow  = 0x28,

        // Alphabet keys
        A = 0x61,
        B = 0x62,
        C = 0x63,
        D = 0x64,
        E = 0x65,
        F = 0x66,
        G = 0x67,
        H = 0x68,
        I = 0x69,
        J = 0x6A,
        K = 0x6B,
        L = 0x6C,
        M = 0x6D,
        N = 0x6E,
        O = 0x6F,
        P = 0x70,
        Q = 0x71,
        R = 0x72,
        S = 0x73,
        T = 0x74,
        U = 0x75,
        V = 0x76,
        W = 0x77,
        X = 0x78,
        Y = 0x79,
        Z = 0x7A,

        // Digit keys
        D0 = 0x30,
        D1 = 0x31,
        D2 = 0x32,
        D3 = 0x33,
        D4 = 0x34,
        D5 = 0x35,
        D6 = 0x36,
        D7 = 0x37,
        D8 = 0x38,
        D9 = 0x39
    };
}   // namespace ata
