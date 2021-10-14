cmake_minimum_required(VERSION 3.20)
project(kvadratka C)

set(CMAKE_C_STANDARD 11)

add_executable(kvadratka sources/main.c sources/equation.c include/equation.h tests/test.c)
