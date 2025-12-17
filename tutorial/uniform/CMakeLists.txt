add_executable(shaderUni)

target_sources(shaderUni PRIVATE shaderUni.cpp "${CMAKE_SOURCE_DIR}/glad.c")

find_package(OpenGL)
target_link_libraries(shaderUni PRIVATE GL)

find_package(glfw3 REQUIRED)
target_link_libraries(shaderUni PRIVATE glfw)

