set(SOURCE_FILES StoryApp.cpp GameWindow.cpp GLFWimpl/GlfwImplementation.cpp)

set(HEADER_FILES Story.h StoryApp.h StoryUtils.h WindowImplementation.h GameWindow.h GLFWimpl/GlfwImplementation.h )

add_library(story_lib SHARED ${SOURCE_FILES} ${HEADER_FILES} )

target_precompile_headers(story_lib PRIVATE pch.h)

add_definitions(-DSTORY_LIB)

target_link_libraries(story_lib glfw) 

include_directories(../glfw/include)
include_directories(../Story)