cmake_minimum_required(VERSION 3.16)
project(princeton-algs4-new)

set(CMAKE_CXX_STANDARD 14)

add_executable(princeton-algs4-new src/data_structures/stack.h main.cpp tests/data_structures/stack.h tests/test.h tests/data_structures/stack.cpp tests/test.cpp)