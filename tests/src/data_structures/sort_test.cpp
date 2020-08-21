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

	void runBottomUpMergeSortTest();

	void runBottomUpMergeSortWithComparatorTest();

	void runTopDownMergeSortTest();

	void runTopDownMergeSortWithComparatorTest();

	void runQuickSortWithComparatorTest();

	void runSortTests() {
		runInsertionSortTest();
		runInsertionSortWithComparatorTest();
		runSelectionSortTest();
		runSelectionSortWithComparatorTest();
		runShellSortTest();
		runShellSortWithComparatorTest();
		runBottomUpMergeSortTest();
		runBottomUpMergeSortWithComparatorTest();
		runTopDownMergeSortTest();
		runTopDownMergeSortWithComparatorTest();
		runQuickSortWithComparatorTest();
		std::cout << "All sort tests passed" << std::endl;
	}

	void fillWithNaturalNumbers(int number, data_structures::Vector<int>& vector);

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

	void runBottomUpMergeSortTest() {
		checkSortingAlgorithm(algorithms::bottom_up_merge_sort);
	}

	void runBottomUpMergeSortWithComparatorTest() {
		checkSortingAlgorithm<LessInt>(algorithms::bottom_up_merge_sort);
	}

	void runTopDownMergeSortTest() {
		checkSortingAlgorithm(algorithms::top_down_merge_sort);
	}

	void runTopDownMergeSortWithComparatorTest() {
		checkSortingAlgorithm<LessInt>(algorithms::top_down_merge_sort);
	}

	void runQuickSortWithComparatorTest() {
		data_structures::Vector<int> vector(1);
		fillWithNaturalNumbers(9, vector);
		struct IntComparator {
			__unused static int compare(const int a, const int b) {
				return a < b ? -1 : a > b ? 1 : 0;
			}
		};
		IntComparator intComparator{};
		algorithms::quick_sort(vector, intComparator);
		checkContainsNaturalNumberInAscendingOrder(vector);
	}

	template<class Less>
	void checkSortingAlgorithm(void (*sort)(data_structures::Vector<int>&, Less&)) {
		data_structures::Vector<int> vector(1);
		fillWithNaturalNumbers(9, vector);
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

	void fillWithNaturalNumbers(int number, data_structures::Vector<int>& vector) {
		assert(number >= 1);
		for (int i = number; i >= 0; --i) {
			vector.pushBack(i);
		}
		algorithms::shuffle(vector);
	}
}