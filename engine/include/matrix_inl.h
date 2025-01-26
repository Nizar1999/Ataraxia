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

#include <matrix.h>

namespace ata {

MAT_T_DEC
Tmat<T, m, n>::Tmat(T val) {
  for (std::size_t i = 0; i < m; ++i) m_mat[i][i] = val;
}

// Unary Operators
MAT_T_DEC
auto Tmat<T, m, n>::operator[](std::size_t i) const -> const ColType<T, m, n>& {
  return m_mat[i];
}

MAT_T_DEC
auto Tmat<T, m, n>::operator[](std::size_t i) -> ColType<T, m, n>& {
  return m_mat[i];
}

// Binary Operators
MAT_T_BINARY_DEC
auto operator*(Tmat<T, m, n> mat, U s)
    -> std::remove_reference_t<decltype(mat)> {
  for (auto& row : mat.m_mat) {
    for (auto& ele : row) {
      ele = static_cast<T>(ele * s);
    }
  }
  return mat;
}

MAT_T_BINARY_DEC
auto operator*(Tmat<T, m, n> mat, const Tvec2<U>& v)
    -> std::remove_reference_t<decltype(v)> {
  Tvec2<U> res;
  res.x = static_cast<U>(mat[0][0] * v.x) + static_cast<U>(mat[0][1] * v.y) +
          mat[0][2];
  res.y = static_cast<U>(mat[1][0] * v.x) + static_cast<U>(mat[1][1] * v.y) +
          mat[1][2];
  return res;
}
}  // namespace ata
