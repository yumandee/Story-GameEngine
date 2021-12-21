#include "pch.h"
#include "Shader.h"
#include "OpenGLimpl/OpenGLShader.h"
namespace Story
{
	Shader::Shader()
	{
		#ifdef STORY_OPENGL
			mShader = std::unique_ptr<ShaderImplementation>{new OpenGLShader};
		#else
			#only_OpenGL_is_supported_so_far
		#endif
	}

	void Shader::Load(const std::string& vertexFile, const std::string& fragmentFile)
	{
		mShader->Load(vertexFile, fragmentFile);
	}

	void Shader::Use()
	{
		mShader->Use();
	}
}
