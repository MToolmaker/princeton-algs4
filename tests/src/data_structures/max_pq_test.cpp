//
// Created by Ivan Yarkov on 21/08/2020.
//

#include <data_structures/max_pq.h>
#include <data_structures/max_pq_test.h>
#include <util.h>
namespace tests {
	struct IntMore {
		bool operator()(const int a, const int b) const {
			return a > b;
		}
	};

	static const int TEST_NUMBER_OF_ELEMENTS = 99;
	static const IntMore intMore{};

	void runMaxPriorityQueueWithDefaultConstructorTest();

	void runMaxPriorityQueueWithVectorConstructorTest();

	void checkDeleteMaxOperation(data_structures::MaxPQ<int, IntMore>& maxPq);

	void runMaxPriorityQueueTests() {
		runMaxPriorityQueueWithDefaultConstructorTest();
		runMaxPriorityQueueWithVectorConstructorTest();
		std::cout << "All max priority queue tests passed" << std::endl;
	}

	void runMaxPriorityQueueWithDefaultConstructorTest() {
		data_structures::Vector<int> vector(1);
		fillWithRandomNaturalNumbers(TEST_NUMBER_OF_ELEMENTS, vector);
		data_structures::MaxPQ<int, IntMore> maxPq(5, intMore);
		for (int i = 0; i < vector.size(); ++i) {
			maxPq.insert(vector[i]);
		}
		checkDeleteMaxOperation(maxPq);
	}

	void runMaxPriorityQueueWithVectorConstructorTest() {
		data_structures::Vector<int> vector(1);
		fillWithRandomNaturalNumbers(TEST_NUMBER_OF_ELEMENTS, vector);
		data_structures::MaxPQ<int, IntMore> maxPq(vector, vector.size(), intMore);
		checkDeleteMaxOperation(maxPq);
	}

	void checkDeleteMaxOperation(data_structures::MaxPQ<int, IntMore>& maxPq) {
		for (int i = TEST_NUMBER_OF_ELEMENTS; i >= 0; --i) {
			assert((maxPq.deleteMax() == i) && (maxPq.size() == i));
		}
		assert(maxPq.isEmpty());
	}
}