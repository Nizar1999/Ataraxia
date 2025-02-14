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

#include <application.h>
#include <input_manager.h>
#include <render_manager.h>
#include <scene_manager.h>

#include <memory>

extern auto CreateApplication() -> ata::Application *;

int main()
{
    std::unique_ptr<ata::Application> app;
    app.reset(CreateApplication());
    app->v_Startup();

    auto renderManager = std::make_unique<ata::RenderManager>(ata::Rect { .x = 0, .y = 0, .w = 60, .h = 30 });
    auto inputManager  = std::make_unique<ata::InputManager>();
    auto sceneManager  = std::make_unique<ata::SceneManager>();

    renderManager->Startup();
    sceneManager->Startup("mainmenu.scene");

    while (true)
    {
        renderManager->Clear();
        inputManager->PollActions();

        app->v_PreFrameRender();
        renderManager->Draw(sceneManager->GetCurrentScene());
        app->v_PostFrameRender();

        renderManager->Display();
    }

    app->v_Shutdown();
}
