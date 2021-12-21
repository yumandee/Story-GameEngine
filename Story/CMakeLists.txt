set(SOURCE_FILES 
   StoryApp.cpp 
   GameWindow.cpp 
   GLFWimpl/GlfwImplementation.cpp
   Sprite.cpp
   Shader.cpp
   Renderer.cpp
   OpenGLimpl/OpenGLSprite.cpp
   OpenGLimpl/OpenGLShader.cpp
   OpenGLimpl/OpenGLRenderer.cpp
)

set(HEADER_FILES 
   Story.h 
   StoryApp.h 
   StoryUtils.h 
   WindowImplementation.h 
   GameWindow.h 
   GLFWimpl/GlfwImplementation.h 
   Sprite.h
   Shader.h
   Renderer.h
   SpriteImplementation.h
   ShaderImplementation.h
   RendererImplementation.h
   OpenGLimpl/OpenGLSprite.h
   OpenGLimpl/OpenGLShader.h
   OpenGLimpl/OpenGLRenderer.h
)

add_library(story_lib SHARED ${SOURCE_FILES} ${HEADER_FILES} )

target_precompile_headers(story_lib PRIVATE pch.h)

add_definitions(-DSTORY_LIB)

target_link_libraries(story_lib glfw glad stbi) 

include_directories(../glfw/include)
include_directories(../Story)
include_directories(../glad/include)
include_directories(../stbi)

