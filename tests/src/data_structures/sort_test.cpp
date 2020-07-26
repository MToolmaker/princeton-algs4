//
// Created by Ivan Yarkov on 16/07/2020.
//

#include <data_structures/vector.h>
#include <algorithms/sort.h>

namespace tests {
	void runInsertionSortTest();

	void runInsertionSortWithComparatorTest();

	void runSelectionSortTest();

	void runSelectionSortWithComparatorTest();

	void runShellSortTest();

	void runShellSortWithComparatorTest();

	void runMergeSortTest();

	void runMergeSortWithComparatorTest();

	void runSortTests() {
		runInsertionSortTest();
		runInsertionSortWithComparatorTest();
		runSelectionSortTest();
		runSelectionSortWithComparatorTest();
		runShellSortTest();
		runShellSortWithComparatorTest();
		runMergeSortTest();
		runMergeSortWithComparatorTest();
	}

	void fillWithNaturalNumbersInDescendingOrderFrom(int number, data_structures::Vector<int>& vector);

	void checkContainsNaturalNumberInAscendingOrder(data_structures::Vector<int>& vector);

	template<class Less = std::less<int>>
	void checkSortingAlgorithm(void (*sort)(data_structures::Vector<int>&, Less&));

	struct LessInt {
		bool operator()(const int& a, const int& b) const {
			return a < b;
		}
	};

	void runInsertionSortTest() {
		checkSortingAlgorithm(algorithms::insertion_sort);
	}

	void runInsertionSortWithComparatorTest() {
		checkSortingAlgorithm<LessInt>(algorithms::insertion_sort);
	}

	void runSelectionSortTest() {
		checkSortingAlgorithm(algorithms::selection_sort);
	}

	void runSelectionSortWithComparatorTest() {
		checkSortingAlgorithm<LessInt>(algorithms::selection_sort);
	}

	void runShellSortTest() {
		checkSortingAlgorithm(algorithms::shell_sort);
	}

	void runShellSortWithComparatorTest() {
		checkSortingAlgorithm<LessInt>(algorithms::shell_sort);
	}

	void runMergeSortTest() {
		checkSortingAlgorithm(algorithms::bottom_up_merge_sort);
	}

	void runMergeSortWithComparatorTest() {
		checkSortingAlgorithm<LessInt>(algorithms::bottom_up_merge_sort);
	}

	template<class Less>
	void checkSortingAlgorithm(void (*sort)(data_structures::Vector<int>&, Less&)) {
		data_structures::Vector<int> vector(1);
		fillWithNaturalNumbersInDescendingOrderFrom(9, vector);
		Less less{};
		sort(vector, less);
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