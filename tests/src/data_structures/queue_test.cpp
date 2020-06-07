//
// Created by Ivan Yarkov on 07/06/2020.
//

#include <data_structures/queue.h>
#include <iostream>

namespace tests {
	void testComplexOperations();
	void testIsFull();

	void runQueueTests() {
		testComplexOperations();
		testIsFull();
		std::cout << "All queue tests passed" << std::endl;
	}

	void testComplexOperations() {
		data_structures::Queue<int> queue(10);
		for (int i = 1; i <= 100; i++) {
			queue.enqueue(i);
		}
		assert(queue.size() == 100);
		for (int i = 1; i <= 100; i++) {
			assert(queue.dequeue() == i);
		}
		assert(queue.isEmpty());
		assert(queue.size() == 0);
		for (int i = 1; i <= 200; i++) {
			queue.enqueue(i);
		}
		assert(queue.size() == 200);
		for (int i = 1; i <= 200; i++) {
			assert(queue.dequeue() == i);
		}
		assert(queue.isEmpty());
		assert(queue.size() == 0);
	}

	void testIsFull() {
		data_structures::Queue<int> queue(10);
		for (int i = 1; i <= 10; i++) {
			queue.enqueue(i);
		}
		assert(queue.isFull());
	}
}
