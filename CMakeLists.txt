cmake_minimum_required(VERSION 3.16)
project(princeton-algs4)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        main.cpp
        src/data_structures/union_find.cpp
        src/exercises/percolation/percolation.cpp
        src/data_structures/vertex2f.cpp)

set(TEST_SOURCES
        tests/src/data_structures/stack_test.cpp
        tests/src/test.cpp
        tests/src/data_structures/union_find_test.cpp
        tests/src/exercises/percolation_test.cpp
        tests/src/data_structures/queue_test.cpp
        tests/src/data_structures/sort_test.cpp
        tests/src/data_structures/convex_hull_tests.cpp
        tests/src/data_structures/max_pq_test.cpp
        tests/src/util.cpp)

set(HEADERS
        include/data_structures/stack.h
        include/data_structures/union_find.h
        include/exercises/percolation.h
        include/data_structures/queue.h
        include/data_structures/vector.h
        include/algorithms/sort.h
        include/algorithms/shuffle.h
        include/algorithms/convex_hull.h
        include/data_structures/vertex2f.h
        include/data_structures/max_pq.h)

set(TEST_HEADERS
        tests/include/data_structures/stack_test.h
        tests/include/test.h
        tests/include/data_structures/union_find_test.h
        tests/include/exercises/percolation_test.h
        tests/include/data_structures/queue_test.h
        tests/include/data_structures/vector_test.h
        tests/src/data_structures/vector_test.cpp
        tests/include/data_structures/sort_test.h
        tests/include/data_structures/convex_hull_test.h
        tests/include/data_structures/max_pq_test.h
        tests/include/util.h)

include_directories("${PROJECT_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/tests/include")

add_executable(princeton-algs4 ${SOURCES} ${HEADERS} ${TEST_SOURCES} ${TEST_HEADERS})