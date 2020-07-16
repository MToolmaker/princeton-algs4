cmake_minimum_required(VERSION 3.16)
project(princeton-algs4)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        main.cpp
        src/data_structures/union_find.cpp
        src/exercises/percolation/percolation.cpp
        )

set(TEST_SOURCES
        tests/src/data_structures/stack_test.cpp
        tests/src/test.cpp
        tests/src/data_structures/union_find_test.cpp
        tests/src/exercises/percolation_test.cpp
        tests/src/data_structures/queue_test.cpp
        tests/src/data_structures/sort_test.cpp)

set(HEADERS
        include/data_structures/stack.h
        include/data_structures/union_find.h
        include/exercises/percolation.h
        include/data_structures/queue.h
        include/data_structures/vector.h
        include/algorithms/sort.h)

set(TEST_HEADERS
        tests/include/data_structures/stack_test.h
        tests/include/test.h
        tests/include/data_structures/union_find_test.h
        tests/include/exercises/percolation_test.h
        tests/include/data_structures/queue_test.h
        tests/include/data_structures/vector_test.h
        tests/src/data_structures/vector_test.cpp
        tests/include/data_structures/sort_test.h)

include_directories("${PROJECT_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/tests/include")

add_executable(princeton-algs4 ${SOURCES} ${HEADERS} ${TEST_SOURCES} ${TEST_HEADERS})