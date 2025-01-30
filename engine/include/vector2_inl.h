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

#include <assert.h>
#include <vector2.h>

namespace ata {
// Constructor
template <typename T>
Tvec2<T>::Tvec2(T i, T j) : x(i), y(j) {}

template <typename T>
template <typename U>
Tvec2<T>::Tvec2(const Tvec3<U>& v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)) {}

// Assignment
template <typename T>
template <typename U>
auto Tvec2<T>::operator=(const Tvec2<U>& v) -> const Tvec2<T>& {
  x = static_cast<T>(v.x);
  y = static_cast<T>(v.y);
  return *this;
}

// Unary Operators
template <typename T>
auto Tvec2<T>::operator[](std::size_t i) -> T& {
  assert(i >= 0 && i < 2);
  switch (i) {
    default:
    case 0:
      return x;
    case 1:
      return y;
  }
}

template <typename T>
auto Tvec2<T>::operator[](std::size_t i) const -> const T& {
  assert(i >= 0 && i < 2);
  switch (i) {
    default:
    case 0:
      return x;
    case 1:
      return y;
  }
}

template <typename T>
auto operator-(const Tvec2<T>& v) -> std::remove_reference_t<decltype(v)> {
  return -1 * v;
}

// Binary Operators
template <typename T, typename U>
auto operator+=(Tvec2<T>& v, const Tvec2<U>& u)
    -> std::remove_reference_t<decltype(v)> {
  v = v + u;
  return v;
}

template <typename T, typename U>
auto operator+(const Tvec2<T>& v, const Tvec2<U>& u)
    -> std::remove_reference_t<decltype(v)> {
  return {static_cast<T>(u.x + v.x), static_cast<T>(u.y + v.y)};
}

template <typename T, typename U>
auto operator*(const Tvec2<T>& v, U s)
    -> std::remove_reference<decltype(v)>::type {
  return s * v;
}

template <typename T, typename U>
auto operator*(U s, const Tvec2<T>& v)
    -> std::remove_reference<decltype(v)>::type {
  return {static_cast<T>(s * v.x), static_cast<T>(s * v.y)};
}

}  // namespace ata
