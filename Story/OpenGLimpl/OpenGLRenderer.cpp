#include "pch.h"
#include "OpenGLRenderer.h"
#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

namespace Story
{
	OpenGLRenderer::OpenGLRenderer()
	{
      if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
      {
         std::cout << "Glad failed to initialize" << std::endl;
      }

      glEnable(GL_BLEND);

      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   }
	void OpenGLRenderer::Draw(Sprite& sprite, int xPos, int yPos, int width, int height, Shader& shader)
	{
      float vertices[] = {
            xPos,         yPos,          0.0f, 0.0f,
            xPos,         yPos + height, 0.0f, 1.0f,
            xPos + width, yPos,          1.0f, 0.0f,
            xPos + width, yPos + height, 1.0f, 1.0f
      };

      unsigned indeces[] = {
         0, 1, 2,
         1, 2, 3
      };

      unsigned int VBO, VAO, EBO;
      glGenVertexArrays(1, &VAO);
      glGenBuffers(1, &VBO);
      glGenBuffers(1, &EBO);
      glBindVertexArray(VAO);

      glBindBuffer(GL_ARRAY_BUFFER, VBO);
      glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

      glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);
      glEnableVertexAttribArray(0);

      glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)(2 * sizeof(float)));
      glEnableVertexAttribArray(1);

      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeces), indeces, GL_STATIC_DRAW);
   
      sprite.Bind();
      shader.Use();

      glBindVertexArray(VAO);
      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
   }

	void OpenGLRenderer::ClearFrame()
	{
      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
   }
}