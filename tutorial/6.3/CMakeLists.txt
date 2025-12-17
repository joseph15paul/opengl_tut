add_executable(shaderInOut)

target_sources(shaderInOut PRIVATE shaderInOut.cpp "${CMAKE_SOURCE_DIR}/glad.c")

find_package(OpenGL)
target_link_libraries(shaderInOut PRIVATE GL)

find_package(glfw3 REQUIRED)
target_link_libraries(shaderInOut PRIVATE glfw)
