add_executable(adventure main.cpp)

target_link_libraries(adventure story_lib)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/.. PROPERTY VS_STARTUP_PROJECT adventure)

include_directories(../Story)

file(COPY Assets DESTINATION ../Adventure)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)
