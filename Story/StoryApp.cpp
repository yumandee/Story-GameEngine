#include "pch.h"

#include "StoryApp.h"
#include "Sprite.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "stb_image.h"


namespace Story {
    void StoryApp::Run() {
        std::cout << "Story running..." << std::endl;
        mGameWindow.CreateWindow(800, 600,"Test");

        Story::Sprite fish;
        fish.LoadImage("C:/Users/mandee/OneDrive/College/senior/Fall/Game Engines/Adventure/Story/Assets/Textures/Test.png");
        while (true) {
            OnUpdate();
            fish.Bind();
            mGameWindow.SwapBuffers();
            mGameWindow.PollEvents();
        }
    }

    void StoryApp::OnUpdate() {

    }

    StoryApp::StoryApp() {
    }
}

