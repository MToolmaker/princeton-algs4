//
// Created by Ivan Yarkov on 16/07/2020.
//

#include <data_structures/vector.h>
#include <algorithms/sort.h>

namespace tests {
	void runInsertionSortTest();

	void runSelectionSortTest();

	void runShellSortTest();

	void runSortTests() {
		runInsertionSortTest();
		runSelectionSortTest();
		runShellSortTest();
		std::cout << "All sort tests passed" << std::endl;
	}

	void fillWithNaturalNumbersInDescendingOrderFrom(int number, data_structures::Vector<int>& vector);

	void checkContainsNaturalNumberInAscendingOrder(data_structures::Vector<int>& vector);

	void runInsertionSortTest() {
		data_structures::Vector<int> vector(1);
		fillWithNaturalNumbersInDescendingOrderFrom(58000, vector);
		algorithms::insertion_sort(vector);
		checkContainsNaturalNumberInAscendingOrder(vector);
	}

	void runSelectionSortTest() {
		data_structures::Vector<int> vector(1);
		fillWithNaturalNumbersInDescendingOrderFrom(900, vector);
		algorithms::selection_sort(vector);
		checkContainsNaturalNumberInAscendingOrder(vector);
	}

	void runShellSortTest() {
		data_structures::Vector<int> vector(1);
		fillWithNaturalNumbersInDescendingOrderFrom(58000, vector);
		algorithms::shell_sort(vector);
		checkContainsNaturalNumberInAscendingOrder(vector);
	}

	void checkContainsNaturalNumberInAscendingOrder(data_structures::Vector<int>& vector) {
		int size = vector.size();
		for (int i = 0; i < size; ++i) {
			assert(vector[i] == i);
		}
	}

	void fillWithNaturalNumbersInDescendingOrderFrom(int number, data_structures::Vector<int>& vector) {
		assert(number >= 1);
		for (int i = number; i >= 0; --i) {
			vector.pushBack(i);
		}
	}
}