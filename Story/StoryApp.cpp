#include "pch.h"

#include "StoryApp.h"
#include "Sprite.h"
#include "Shader.h"

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

        glEnable(GL_BLEND);

        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        float vertices[] = {
            -0.5f, -0.5f, 0.0f, 0.0f,
            -0.5f,  0.5f, 0.0f, 1.0f,
             0.5f, -0.5f, 1.0f, 0.0f,
             0.5f,  0.5f, 1.0f, 1.0f};

        unsigned indeces[] = {
            0, 1, 2,
            1, 2, 3};

        unsigned int VBO, VAO, EBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)(2 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeces), indeces, GL_STATIC_DRAW);

        Story::Shader myShader;
        myShader.Load("C:/Users/mandee/OneDrive/College/senior/Fall/Game Engines/Adventure/Story/Assets/Shader/vertexShader1.glsl", "C:/Users/mandee/OneDrive/College/senior/Fall/Game Engines/Adventure/Story/Assets/Shader/fragmentShader1.glsl");

        Story::Sprite fish;
        fish.LoadImage("C:/Users/mandee/OneDrive/College/senior/Fall/Game Engines/Adventure/Story/Assets/Textures/Test.png");

        while (true) {
            OnUpdate();
            glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            fish.Bind();
            myShader.Use();
            glBindVertexArray(VAO);
            // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            mGameWindow.SwapBuffers();
            mGameWindow.PollEvents();
        }
    }

    void StoryApp::OnUpdate() {

    }

    StoryApp::StoryApp() {
    }
}

