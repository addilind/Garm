cmake_minimum_required(VERSION 3.3)
project(garm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

########################################################## Lib GLFW: build subdir
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL OFF)
option(GLFW_USE_HYBRID_HPG ON)

add_subdirectory(external/glfw glfw)

########################################################## Lib GLM: header only
#add_subdirectory(external/glm) #cmake only for tests

########################################################## Lib glbinding: Frankenstein build
# The project cmake does not play nice, so it was Frankensteined here
include(external/glbinding/cmake/Custom.cmake)
set(OPTION_PORTABLE_INSTALL ON)
set(IDE_FOLDER "")
set(OPTION_GL_BY_STRINGS OFF)
set(OPTION_STRINGS_BY_GL ON)
set(INSTALL_BIN       ".")
set(INSTALL_SHARED    ".")
set(INSTALL_LIB       ".")
set(INSTALL_INCLUDE   ".")
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)
add_subdirectory(external/glbinding/source/glbinding glbinding)

########################################################## Garm
include_directories(external/glfw/include external/glm external/glbinding/source/glbinding/include)

set(SOURCE_FILES main.cpp)
set(SRC_CORE Core/Core.cpp Core/Core.h)
set(SRC_GUI GUI/GUI.cpp GUI/GUI.h GUI/GUI.shallowinclude.h)
add_executable(garm ${SOURCE_FILES} ${SRC_CORE} ${SRC_GUI})

target_link_libraries(garm glbinding ${GLBINDING_LIBRARIES} glfw ${GLFW_LIBRARIES})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")