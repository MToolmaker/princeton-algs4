//
// Created by Ivan Yarkov on 11/07/2020.
//

#include <data_structures/vector.h>

namespace tests {
	void testVectorResize();

	void runVectorTests() {
		testVectorResize();
		std::cout << "All vector tests passed" << std::endl;
	}

	void testVectorResize() {
		data_structures::Vector<int> v(10);
		for (int i = 0; i < 100; i++) {
			assert(v.size() == i);
			v.pushBack(i);
			assert(v[i] == i);
		}
	}
}