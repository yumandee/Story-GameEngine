#pragma once

#include "pch.h"
#include "ShaderImplementation.h"

namespace Story
{
    class OpenGLShader : public ShaderImplementation
    {
    public:
        virtual void Load(const std::string& vertexFile, const std::string& fragmentFile) override;
        virtual void Use() override;
    private:
        unsigned int mShaderProgram{ 0 };
    };

}