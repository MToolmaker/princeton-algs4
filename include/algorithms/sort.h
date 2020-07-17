//
// Created by Ivan Yarkov on 16/07/2020.
//

#ifndef PRINCETON_ALGS4_INCLUDE_ALGORITHMS_SORT_H_
#define PRINCETON_ALGS4_INCLUDE_ALGORITHMS_SORT_H_

#include <data_structures/vector.h>
namespace {
	template<class T>
	void swap(data_structures::Vector<T> &vector, int i, int j) {
		int tmp = vector[j];
		vector[j] = vector[i];
		vector[i] = tmp;
	}
}

namespace algorithms {
	template<class T>
	void insertion_sort(data_structures::Vector<T> &vector) {
		int size = vector.size();
		for (int i = 1; i < size; ++i) {
			for (int j = i; j >= 1 && vector[j - 1] > vector[j]; --j) {
				swap(vector, j, j - 1);
			}
		}
	}

	template<class T>
	void selection_sort(data_structures::Vector<T> &vector) {
		int size = vector.size();
		for (int i = 0; i < size; ++i) {
			int smallest = vector[i];
			int smallestIndex = i;
			for (int j = i + 1; j < size; ++j) {
				if (vector[j] < smallest) {
					smallestIndex = j;
				}
			}
			swap(vector, smallestIndex, i);
		}
	}
}
#endif //PRINCETON_ALGS4_INCLUDE_ALGORITHMS_SORT_H_
