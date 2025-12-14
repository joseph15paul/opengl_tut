add_executable(ex58)

target_sources(ex58 PRIVATE ex58.cpp "${CMAKE_SOURCE_DIR}/glad.c")

find_package(OpenGL)
target_link_libraries(ex58 PRIVATE GL)

find_package(glfw3 REQUIRED)
target_link_libraries(ex58 PRIVATE glfw)
