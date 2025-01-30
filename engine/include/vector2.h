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
#include <type_traits>

namespace ata {
template <typename T>
struct Tvec3;

template <typename T>
struct Tvec2 {
  T x{};
  T y{};

  // Constructors
  Tvec2() = default;
  Tvec2(T x, T y);

  template <typename U>
  Tvec2(const Tvec3<U>& v);

  // Assignment
  template <typename U>
  auto operator=(const Tvec2<U>& v) -> const Tvec2<T>&;

  // Unary Operators
  auto operator[](std::size_t i) -> T&;
  auto operator[](std::size_t i) const -> const T&;
};

// Unary Operators
template <typename T>
auto operator-(const Tvec2<T>& v) -> std::remove_reference_t<decltype(v)>;

// Binary Operators
template <typename T, typename U>
auto operator+=(Tvec2<T>& v, const Tvec2<U>& u)
    -> std::remove_reference_t<decltype(v)>;

template <typename T, typename U>
auto operator+(const Tvec2<T>& v, const Tvec2<U>& u)
    -> std::remove_reference_t<decltype(v)>;

template <typename T, typename U>
auto operator*(const Tvec2<T>& v, U s) -> std::remove_reference_t<decltype(v)>;

template <typename T, typename U>
auto operator*(U s, const Tvec2<T>& v) -> std::remove_reference_t<decltype(v)>;

}  // namespace ata

#include <vector2_inl.h>
