cmake_minimum_required(VERSION 3.20)
project(str_functions)

set(CMAKE_CXX_STANDARD 14)

add_executable(str_functions sources/main.c tests/tests.c sources/functions.c headers/functions.h)
