cmake_minimum_required(VERSION 3.21)
project(latex C)

set(CMAKE_C_STANDARD 11)

add_executable(latex
        source/roots/roots.c)
