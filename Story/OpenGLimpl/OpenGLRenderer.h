#pragma once

#include "RendererImplementation.h"
#include "Sprite.h"
#include "Shader.h"

namespace Story 
{
    class OpenGLRenderer : public RendererImplementation
    {
    public:
        OpenGLRenderer();
        virtual void Draw(Sprite& sprite,
            int xPos, int yPos,
            int width, int height,
            Shader& shader) override;
        virtual void ClearFrame() override;

    };
}