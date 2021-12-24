#include "pch.h"

#include "StoryApp.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "stb_image.h"


namespace Story {

    void StoryApp::Run() {
        STORY_LOG("Story app running...");
        
        mTimeOfNextFrame = std::chrono::steady_clock::now() + mFrameDuration;

        while (true) {
            mGameWindow.SetKeyPressedCallback([this](KeyPressedEvent &event)
                                              { OnKeyPressed(event); });

            Renderer::ClearFrame();

            OnUpdate();


            std::this_thread::sleep_until(mTimeOfNextFrame);

            mGameWindow.SwapBuffers();

            mGameWindow.PollEvents();

            mTimeOfNextFrame += mFrameDuration;
        }

        Renderer::ShutDown();
    }

    void StoryApp::OnUpdate() {

    }

    void StoryApp::OnKeyPressed(KeyPressedEvent& event) {
        STORY_LOG(event.GetKeyCode());
    }

    StoryApp::StoryApp() {
        mGameWindow.CreateWindow(800, 600, "Game");

        mGameWindow.SetKeyPressedCallback([this](KeyPressedEvent &event)
                                          { OnKeyPressed(event); });

        Renderer::Init();
    }

    int StoryApp::GetGameWindowWidth() const
    {
        return mGameWindow.GetWindowWidth();
    }

    int StoryApp::GetGameWindowHeight() const
    {
        return mGameWindow.GetWindowHeight();
    }
}

