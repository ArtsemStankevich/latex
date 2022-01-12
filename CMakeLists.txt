cmake_minimum_required(VERSION 3.10)
project(roots)

set(CMAKE_C_STANDARD 11)

add_executable(roots
        source/roots/roots.c)

target_link_libraries(roots PRIVATE m)