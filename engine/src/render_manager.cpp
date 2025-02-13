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

#include <render_manager.h>

namespace ata
{
    RenderManager::RenderManager(Rect viewport)
        : m_buffer(new FrameBuffer)
        , m_viewport(viewport)
    {
    }

    RenderManager::~RenderManager()
    {
        delete m_buffer;
    }

    auto RenderManager::Startup() -> void
    {
        m_displayThread = std::thread(&RenderManager::DisplayBuffer, this);
    }

    auto RenderManager::Clear() -> void
    {
        m_buffer->Clear();
    }

    auto RenderManager::Draw(Scene& scene) -> void
    {
        Camera& activeCam = scene.GetActiveCam();
        for(auto& actor : scene.GetActors())
        {
            IVec2 worldPos = actor->GetPosition();
            IVec2 viewPos  = activeCam.GetViewMatrix() * worldPos;
            m_buffer->Write(m_viewport, viewPos, actor->GetRenderData().symbol);
        }
    }

    auto RenderManager::Display() -> void
    {
        std::lock_guard<std::mutex> lock(m_bufferMtx);
        m_buffer->Swap();
    }

    auto RenderManager::DisplayBuffer() -> void
    {
        while(true)
        {
            {
                std::lock_guard<std::mutex> lock(m_bufferMtx);
                m_buffer->Draw();
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(33)); //~30Hz
        }
    }

} // namespace ata
