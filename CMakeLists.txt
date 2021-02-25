#Project configuration
cmake_minimum_required(VERSION 3.11)
project(learn-opengl VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Packages
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS} ${glfw3_INCLUDE_DIRS})

#Sources and includes
file(GLOB_RECURSE sources "src/*.*" "lib/glad/src/glad.c")
include_directories("lib/glad/include", "include")


add_executable(learn-opengl ${sources})
target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_DL_LIBS} ${OPENGL_LIBRARIES} glfw)