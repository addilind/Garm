cmake_minimum_required(VERSION 3.3)
project(garm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
option(GLFW_BUILD_DOCS OFF)
option(GLFW_INSTALL OFF)

#add_subdirectory(glfw)
#add_subdirectory(glm) #completely header based only
#add_subdirectory(glbinding)

set(SOURCE_FILES main.cpp)
set(SRC_CORE core/core.cpp core/core.h)
add_executable(garm ${SOURCE_FILES} ${SRC_CORE})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")