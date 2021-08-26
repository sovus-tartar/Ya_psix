cmake_minimum_required(VERSION 3.20)
project(kvadratka C)

set(CMAKE_C_STANDARD 11)

add_executable(kvadratka kvadr_main.c sources/kvadr_func.c sources/kvadr_head.h tests/kvadr_test.c)
