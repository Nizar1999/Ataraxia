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

namespace ata
{
#define MAT_T_DEC template <typename T, std::size_t m, std::size_t n>

    MAT_T_DEC
    using RowType = std::conditional_t<m == 2, Vec2, Vec3>;
    MAT_T_DEC
    using ColType = std::conditional_t<n == 2, Vec2, Vec3>;

    MAT_T_DEC
    struct Tmat
    {
        Tmat() = default;
        Tmat(T val);

        // Unary Operators
        auto operator[](std::size_t i) const -> const ColType<T, m, n>&;
        auto operator[](std::size_t i) -> ColType<T, m, n>&;

    private:
        std::array<ColType<T, m, n>, m> m_mat;
    };

// Binary Operators
#define MAT_T_BINARY_DEC template <typename T, std::size_t m, std::size_t n, typename U>

    MAT_T_BINARY_DEC
    auto operator*(Tmat<T, m, n> mat, U scalar) -> std::remove_reference_t<decltype(mat)>;

    MAT_T_BINARY_DEC
    auto operator*(Tmat<T, m, n> mat, const ColType<U, m, n>& vec) -> std::remove_reference_t<decltype(vec)>;

    // Aliasing
    using Mat3 = Tmat<float, 3, 3>;
} // namespace ata

#include <matrix_inl.h>
