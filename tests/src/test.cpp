//
// Created by Ivan Yarkov on 25/04/2020.
//

#include <data_structures/stack_test.h>
#include <data_structures/union_find_test.h>
#include <data_structures/queue_test.h>
#include <exercises/percolation_test.h>
namespace tests {
    void runTests() {
		runStackTests();
		runUnionFindTests();
		runPercolationTests();
		runQueueTests();
    }
}