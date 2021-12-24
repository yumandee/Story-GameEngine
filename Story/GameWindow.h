#pragma once
#include "pch.h"
#include "StoryUtils.h"
#include "WindowImplementation.h"
#include "Events.h"
namespace Story {

    class STORY_API GameWindow
    {
    public:
        GameWindow();

        void CreateWindow(int width, int height, const std::string& name);
        void SwapBuffers();
        void PollEvents();
        int GetWindowWidth() const;
        int GetWindowHeight() const;
        void SetKeyPressedCallback(std::function<void(KeyPressedEvent &)> func);

    private:
        std::unique_ptr<WindowImplementation> mWindow;
    };

}


