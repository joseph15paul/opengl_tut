cmake_minimum_required(VERSION 3.31)

project(circle)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories("${CMAKE_SOURCE_DIR}/Include")

add_executable(circle)
target_sources(circle PRIVATE circle.cpp glad.c)

target_include_directories(circle PRIVATE "${CMAKE_SOURCE_DIR}/Include")

add_subdirectory(tutorial)

find_package(OpenGL)
target_link_libraries(circle PRIVATE GL)

find_package(glfw3 REQUIRED)
target_link_libraries(circle PRIVATE glfw)

