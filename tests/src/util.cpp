//
// Created by Ivan Yarkov on 21/08/2020.
//

#include <cassert>
#include <algorithms/shuffle.h>

namespace tests {
	void fillWithRandomNaturalNumbers(int number, data_structures::Vector<int>& vector) {
		assert(number >= 1);
		for (int i = number; i >= 0; --i) {
			vector.pushBack(i);
		}
		algorithms::shuffle(vector);
	}
}