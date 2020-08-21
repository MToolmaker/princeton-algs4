//
// Created by Ivan Yarkov on 25/04/2020.
//

#include <data_structures/stack_test.h>
#include <data_structures/union_find_test.h>
#include <data_structures/queue_test.h>
#include <data_structures/vector_test.h>
#include <data_structures/sort_test.h>
#include <data_structures/convex_hull_test.h>
#include <data_structures/max_pq_test.h>
#include <exercises/percolation_test.h>


namespace tests {
	void runTests() {
		runStackTests();
		runUnionFindTests();
		runPercolationTests();
		runQueueTests();
		runVectorTests();
		runSortTests();
		runConvexHullTests();
		runMaxPriorityQueueTests();
	}
}