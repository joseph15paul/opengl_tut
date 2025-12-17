add_executable(shaderAttr)

target_sources(shaderAttr PRIVATE shaderAttr.cpp "${CMAKE_SOURCE_DIR}/glad.c")

find_package(OpenGL)
target_link_libraries(shaderAttr PRIVATE GL)

find_package(glfw3 REQUIRED)
target_link_libraries(shaderAttr PRIVATE glfw)

