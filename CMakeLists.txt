cmake_minimum_required(VERSION 3.25)
project(sk_32_unit_testing LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(MYSQL_DIR /usr/lib64/)
set(MYSQL_INCL /usr/include/)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)