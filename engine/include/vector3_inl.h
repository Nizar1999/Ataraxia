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
#include <vector3.h>

#include <compare>

namespace ata
{
    // Constructor
    template <typename T>
    Tvec3<T>::Tvec3(T i, T j, T k)
        : x(i)
        , y(j)
        , z(k)
    {
    }

    template <typename T>
    template <typename U>
    Tvec3<T>::Tvec3(const Tvec2<U>& v)
        : x(static_cast<T>(v.x))
        , y(static_cast<T>(v.y))
    {
    }

    // Assignment
    template <typename T>
    template <typename U>
    auto Tvec3<T>::operator=(const Tvec3<U>& v) -> const Tvec3<T>&
    {
        x = static_cast<T>(v.x);
        y = static_cast<T>(v.y);
        z = static_cast<T>(v.z);
        return *this;
    }

    // Unary Operators
    template <typename T>
    auto Tvec3<T>::operator[](std::size_t i) -> T&
    {
        assert(i >= 0 && i < 3);
        switch(i)
        {
        default:
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        }
    }

    template <typename T>
    auto Tvec3<T>::operator[](std::size_t i) const -> const T&
    {
        assert(i >= 0 && i < 3);
        switch(i)
        {
        default:
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        }
    }

    template <typename T>
    auto Tvec3<T>::operator-() -> Tvec3<T>
    {
        return *this * -1;
    }

    // Binary Operators
    template <typename T>
    template <typename U>
    auto Tvec3<T>::operator<=>(const Tvec3<U>& v) const
    {
        if(auto cmp = x <=> static_cast<T>(v.x); cmp != 0)
            return cmp;
        if(auto cmp = y <=> static_cast<T>(v.y); cmp != 0)
            return cmp;
        return z <=> static_cast<T>(v.z);
    }

    template <typename T>
    template <typename U>
    auto Tvec3<T>::operator==(const Tvec3<U>& v) const -> bool
    {
        return std::is_eq(x <=> static_cast<T>(v.x)) && std::is_eq(y <=> static_cast<T>(v.y)) && std::is_eq(z <=> static_cast<T>(v.z));
    }

    template <typename T>
    template <typename U>
    auto Tvec3<T>::operator+=(const Tvec3<U>& u) -> Tvec3<T>&
    {
        *this = *this + u;
        return *this;
    }

    template <typename T, typename U>
    auto operator+(const Tvec3<T>& v, const Tvec3<U>& u) -> std::remove_reference_t<decltype(v)>
    {
        return {static_cast<T>(v.x + u.x), static_cast<T>(v.y + u.y), static_cast<T>(v.z + u.z)};
    }

    template <typename T, typename U>
    auto operator*(const Tvec3<T>& v, U s) -> std::remove_reference<decltype(v)>::type
    {
        return s * v;
    }

    template <typename T, typename U>
    auto operator*(U s, const Tvec3<T>& v) -> std::remove_reference<decltype(v)>::type
    {
        return {static_cast<T>(s * v.x), static_cast<T>(s * v.y), static_cast<T>(s * v.z)};
    }
} // namespace ata
