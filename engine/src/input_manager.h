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
#include <input.h>
#include <input_action.h>
#include <singleton.h>

#include <functional>
#include <unordered_map>
#include <vector>

namespace ata
{
    template <typename T>
    using InputActionCallbackT = std::function<void(T*)>;
    using InputActionCallback  = std::function<void()>;
    using CallbackMapping      = std::unordered_map<InputAction, std::vector<InputActionCallback>, InputAction::Hash>;

    class InputManager : public Singleton<InputManager>
    {
    public:
        auto ATA PollActions() -> void;

        template <typename T>
        auto BindInputAction(InputAction action, T* object, InputActionCallbackT<T> callback) -> void;
        auto BindInputAction(InputAction action, InputActionCallback callback) -> void;

    private:
        CallbackMapping m_callbacks;

        static auto IsPressed(KeyCode code) -> bool;
    };

    template <typename T>
    auto InputManager::BindInputAction(InputAction action, T* object, InputActionCallbackT<T> callback) -> void
    {
        m_callbacks[action].push_back(std::bind(callback, object));
    }

} // namespace ata
