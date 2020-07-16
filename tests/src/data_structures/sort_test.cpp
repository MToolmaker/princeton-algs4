//
// Created by Ivan Yarkov on 16/07/2020.
//

#include <data_structures/vector.h>
#include <algorithms/sort.h>

namespace tests {
	void runInsertionSortTest();

	void runSortTests() {
		runInsertionSortTest();
	}

	void runInsertionSortTest() {
		data_structures::Vector<int> vector(1);
		for (int i = 9; i >= 0; --i) {
			vector.pushBack(i);
		}
		algorithms::insertion_sort(vector);
		for (int i = 0; i < 10; ++i) {
			assert(vector[i] == i);
		}
	}
}