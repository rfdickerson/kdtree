cmake_minimum_required(VERSION 3.2)

set (CMAKE_CXX_STANDARD 14)

project(kdtree)
add_executable(${PROJECT_NAME} main.cpp KDTree.cpp)
