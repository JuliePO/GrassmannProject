cmake_minimum_required(VERSION 2.8)

project(ImacGrassmann)

include_directories(eigen)
include_directories(lib/include)
add_subdirectory(lib)

set(ALL_LIBRARIES gca)

add_subdirectory(Grassmann)

set(CMAKE_CXX_FLAGS "-Wall -g")

