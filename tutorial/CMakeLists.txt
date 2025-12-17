add_executable(ex58)
add_executable(shaderTut)

add_subdirectory(6.3)
add_subdirectory(uniform)
add_subdirectory(attrib)

target_sources(ex58 PRIVATE ex58.cpp "${CMAKE_SOURCE_DIR}/glad.c")
target_sources(shaderTut PRIVATE shaderTut.cpp "${CMAKE_SOURCE_DIR}/glad.c")

find_package(OpenGL)
target_link_libraries(ex58 PRIVATE GL)
target_link_libraries(shaderTut PRIVATE GL)

find_package(glfw3 REQUIRED)
target_link_libraries(ex58 PRIVATE glfw)
target_link_libraries(shaderTut PRIVATE glfw)
