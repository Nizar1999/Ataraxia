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

#include <vector3.h>

namespace ata {
// Constructor
template <typename T>
Tvec3<T>::Tvec3(T i, T j, T k) : x(i), y(j), z(k) {}

template <typename T>
template <typename U>
Tvec3<T>::Tvec3(const Tvec2<U>& v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)) {}

// Assignment
template <typename T>
template <typename U>
auto Tvec3<T>::operator=(const Tvec2<U>& v) -> void {
  x = static_cast<T>(v.x);
  y = static_cast<T>(v.y);
}

// Unary Operators
template <typename T>
auto Tvec3<T>::operator-() const -> const Tvec3 {
  return -1 * *this;
}

// Binary Scalar Arithmetic
template <typename T>
template <typename U>
auto Tvec3<T>::operator*(U s) const -> const Tvec3 {
  return {static_cast<T>(s * x), static_cast<T>(s * y), static_cast<T>(s * z)};
}

template <typename T, typename U>
auto operator*(U s, const Tvec3<T>& v)
    -> std::remove_reference<decltype(v)>::type {
  return {static_cast<T>(s * v.x), static_cast<T>(s * v.y),
          static_cast<T>(s * v.z)};
}
}  // namespace ata
