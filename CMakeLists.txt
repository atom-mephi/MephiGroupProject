cmake_minimum_required(VERSION 3.0)

project(Atom)

set (CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}\\stack ${PROJECT_SOURCE_DIR}\\vector ${PROJECT_SOURCE_DIR}\\allocator)

add_subdirectory(stack)
add_subdirectory(vector)
add_subdirectory(allocator)

add_executable(main main.cpp)