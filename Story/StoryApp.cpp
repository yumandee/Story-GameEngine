#include "pch.h"
#include "StoryApp.h"
// GLFW - supports multiple platforms and creates a window 
#include "GLFW/glfw3.h"


namespace Story {
    void StoryApp::Run() {
        std::cout << "Story running..." << std::endl;

        // GLFWwindow* window; 

        // glfwInit();

        // GLFWmonitor* mon = glfwGetPrimaryMonitor();
        // window = glfwCreateWindow(1920, 1080, "Test", mon, NULL);
        mGameWindow.CreateWindow(800, 600,"Test");
        // window = glfwCreateWindow(800, 600, "Test", NULL, NULL);

        while (true) {
            OnUpdate();
            mGameWindow.SwapBuffers();
            // glfwSwapBuffers(window);
            mGameWindow.PollEvents();
            // glfwPollEvents();
        }
    }

    void StoryApp::OnUpdate() {

    }

    StoryApp::StoryApp() {
    }
}

