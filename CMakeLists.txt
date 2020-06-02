cmake_minimum_required(VERSION 3.16)
project(princeton-algs4)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        main.cpp
        src/data_structures/union_find.cpp
        exercises/percolation/percolation.cpp
        )

set(TEST_SOURCES
        tests/data_structures/stack.cpp
        tests/test.cpp
        tests/data_structures/union_find.cpp
        )

set(HEADERS
        src/data_structures/stack.h
        src/data_structures/union_find.h
        exercises/percolation/percolation.h
        )

set(TEST_HEADERS
        tests/data_structures/stack.h
        tests/test.h
        tests/data_structures/union_find.h
        )

add_executable(princeton-algs4 ${SOURCES} ${HEADERS} ${TEST_SOURCES} ${TEST_HEADERS})