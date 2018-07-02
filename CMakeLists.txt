cmake_minimum_required(VERSION 2.8)

set (CMAKE_CXX_STANDARD 11)

project(kdtree)
add_executable(${PROJECT_NAME} main.cpp KDTree.cpp)
