cmake_minimum_required(VERSION 2.88888888)
project(BScGraf_RMUGLK_OGL_Kisfeladat1)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

link_directories(../Linux/Bin)
include_directories( ${OPENGL_INCLUDE_DIRS}, ${GLEW_INCLUDE_DIRS}, ${SDL2_INCLUDE_DIRS} )

set(EXECUTABLE_NAME "BScGraf_RMUGLK_OGL_Kisfeladat1_Octahedron")

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")
add_definitions(-DDEBUG)
add_definitions(-D_DEBUG)
add_definitions(-DAPP_NAME="${EXECUTABLE_NAME}")
add_subdirectory(BScGraf_RMUGLK_OGL_Kisfeladat1)

