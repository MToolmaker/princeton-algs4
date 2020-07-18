//
// Created by Ivan Yarkov on 16/07/2020.
//

#include <data_structures/vector.h>
#include <algorithms/sort.h>
#include <functional>

namespace tests {
	void runInsertionSortTest();

	void runInsertionSortWithComparatorTest();

	void runSelectionSortTest();

	void runSelectionSortWithComparatorTest();

	void runShellSortTest();

	void runShellSortWithComparatorTest();

	void runSortTests() {
		runInsertionSortTest();
		runInsertionSortWithComparatorTest();
		runSelectionSortTest();
		runSelectionSortWithComparatorTest();
		runShellSortTest();
		runShellSortWithComparatorTest();
		std::cout << "All sort tests passed" << std::endl;
	}

	void fillWithNaturalNumbersInDescendingOrderFrom(int number, data_structures::Vector<int>& vector);

	void checkContainsNaturalNumberInAscendingOrder(data_structures::Vector<int>& vector);

	struct LessInt {
		bool operator()(const int& a, const int& b) const {
			return a < b;
		}
	};

	void runInsertionSortTest() {
		data_structures::Vector<int> vector(1);
		fillWithNaturalNumbersInDescendingOrderFrom(9, vector);
		algorithms::insertion_sort(vector);
		checkContainsNaturalNumberInAscendingOrder(vector);
	}

	void runInsertionSortWithComparatorTest() {
		data_structures::Vector<int> vector(1);
		fillWithNaturalNumbersInDescendingOrderFrom(9, vector);
		algorithms::insertion_sort<int, LessInt>(vector);
		checkContainsNaturalNumberInAscendingOrder(vector);
	}

	void runSelectionSortTest() {
		data_structures::Vector<int> vector(1);
		fillWithNaturalNumbersInDescendingOrderFrom(9, vector);
		algorithms::selection_sort(vector);
		checkContainsNaturalNumberInAscendingOrder(vector);
	}

	void runSelectionSortWithComparatorTest() {
		data_structures::Vector<int> vector(1);
		fillWithNaturalNumbersInDescendingOrderFrom(9, vector);
		algorithms::selection_sort<int, LessInt>(vector);
		checkContainsNaturalNumberInAscendingOrder(vector);
	}

	void runShellSortTest() {
		data_structures::Vector<int> vector(1);
		fillWithNaturalNumbersInDescendingOrderFrom(9, vector);
		algorithms::shell_sort(vector);
		checkContainsNaturalNumberInAscendingOrder(vector);
	}

	void runShellSortWithComparatorTest() {
		data_structures::Vector<int> vector(1);
		fillWithNaturalNumbersInDescendingOrderFrom(9, vector);
		algorithms::shell_sort<int, LessInt>(vector);
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