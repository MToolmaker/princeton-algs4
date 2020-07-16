//
// Created by Ivan Yarkov on 16/07/2020.
//

#ifndef PRINCETON_ALGS4_INCLUDE_ALGORITHMS_SORT_H_
#define PRINCETON_ALGS4_INCLUDE_ALGORITHMS_SORT_H_

#include <data_structures/vector.h>

namespace algorithms {
	template<class T>
	void insertion_sort(data_structures::Vector<T> &vector) {
		int size = vector.size();
		for (int i = 1; i < size; ++i) {
			for (int j = i; j >= 1 && vector[j - 1] > vector[j]; --j) {
				int tmp = vector[j];
				vector[j] = vector[j - 1];
				vector[j - 1] = tmp;
			}
		}
	}
}
#endif //PRINCETON_ALGS4_INCLUDE_ALGORITHMS_SORT_H_
