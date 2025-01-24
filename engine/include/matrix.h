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

#include <vector.h>

#include <array>

namespace ata {

template <typename T, std::size_t m>
struct Tmat {
  Tmat(T val) {
    for (std::size_t i = 0; i < m; ++i) m_mat[i][i] = val;
  }

  std::array<T, m>& operator[](std::size_t i) { return m_mat[i]; }

  auto operator*(const Tvec2<T> v) -> decltype(v) {
    Tvec2<T> res;
    res.x = m_mat[0][0] * v.x + m_mat[0][1] * v.y + m_mat[0][2];
    res.y = m_mat[1][0] * v.x + m_mat[1][1] * v.y + m_mat[1][2];
    return res;
  }

 private:
  std::array<std::array<T, m>, m> m_mat{};
};

using M3 = Tmat<int, 3>;

template <typename T>
auto Translate(const Tvec2<T>& v) -> M3 {
  M3 m(1.0);
  m[0][2] = v.x;
  m[1][2] = v.y;
  return m;
}

}  // namespace ata
