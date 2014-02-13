cmake_minimum_required(VERSION 2.6)
project(opengl-boilerplate)

add_executable(main main.c callbacks.c)

find_package(PkgConfig REQUIRED)
pkg_search_module(OPENGL REQUIRED gl)
pkg_search_module(GLU REQUIRED glu)
pkg_search_module(GLEW REQUIRED glew)
pkg_search_module(GLFW REQUIRED glfw3)

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${OPENGL_INCLUDE_DIRS}")
include_directories("${GLU_INCLUDE_DIRS}")
include_directories("${GLEW_INCLUDE_DIRS}")
include_directories("${GLFW_INCLUDE_DIRS}")

target_link_libraries(main
    ${OPENGL_LIBRARIES}
    ${GLU_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${GLFW_LIBRARIES}
)
