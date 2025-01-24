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

namespace ata {
template <typename T>
struct Tvec2;

template <typename T>
struct Tvec3 {
  T x{};
  T y{};
  T z{};

  // Constructor
  Tvec3() = default;
  Tvec3(T x, T y, T z);

  template <typename U>
  Tvec3(const Tvec2<U>& v);

  // Assignment
  template <typename U>
  auto operator=(const Tvec2<U>& v) -> void;
};

template <typename T>
struct Tvec2 {
  T x{};
  T y{};

  // Constructor
  Tvec2() = default;
  Tvec2(T x, T y);

  template <typename U>
  Tvec2(const Tvec3<U>& v);

  // Assignment
  template <typename U>
  auto operator=(const Tvec3<U>& v) -> void;
};

using Vec2 = Tvec2<float>;
using Vec3 = Tvec3<float>;
using IVec2 = Tvec2<int>;
using IVec3 = Tvec3<int>;
}  // namespace ata

#include <vector_inl.h>
