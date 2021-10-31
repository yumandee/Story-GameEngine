cmake_minimum_required(VERSION 3.18)

project(adventure)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32) 
   add_definitions(-DSTORY_WINDOWS)
elseif(APPLE)
   add_definitions(-DSTORY_MAC)
elseif(UNIX)
   add_definitions(-DSTORY_LINUX)
endif()


add_subdirectory(Adventure)
add_subdirectory(Story)
add_subdirectory(glfw)