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
        std::cout << "Story running..." << std::endl;
        mGameWindow.CreateWindow(800, 600,"Test");

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Glad failed to initialize" << std::endl;
        }

        Renderer::Init();

        Story::Shader myShader;
        myShader.Load(
            "Assets/Shader/myVertexShader.glsl", 
            "Assets/Shader/myFragmentShader.glsl");
        myShader.SetVec2IntUniform(
            "screenSize", 
            mGameWindow.GetWindowWidth(), 
            mGameWindow.GetWindowHeight());
        Story::Sprite fish;
        fish.LoadImage("Assets/Textures/Test.png");

        while (true) {
            
            Renderer::ClearFrame();

            OnUpdate();

            Renderer::Draw(fish, 100, 50, fish.GetWidth(), fish.GetHeight(), myShader);

            mGameWindow.SwapBuffers();
            mGameWindow.PollEvents();
        }

        Renderer::ShutDown();
    }

    void StoryApp::OnUpdate() {

    }

    StoryApp::StoryApp() {
    }
}

