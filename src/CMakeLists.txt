cmake_minimum_required(VERSION 3.25)
project(hello_world)
include_directories(${PROJECT_SOURCE_DIR})
add_executable(app main.cpp foo.cpp)