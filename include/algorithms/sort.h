//
// Created by Ivan Yarkov on 16/07/2020.
//

#ifndef PRINCETON_ALGS4_INCLUDE_ALGORITHMS_SORT_H_
#define PRINCETON_ALGS4_INCLUDE_ALGORITHMS_SORT_H_

#include <data_structures/vector.h>

namespace algorithms {
	template<class T>
	void swap(data_structures::Vector<T>& vector, int i, int j);
}

namespace {
	template<class T, class Less>
	void n_sort(int n, data_structures::Vector<T>& vector, int size, Less& less) {
		for (int i = n; i < size; i += n) {
			for (int j = i; j >= n && less(vector[j], vector[j - n]); j -= n) {
				algorithms::swap(vector, j, j - n);
			}
		}
	}
}

namespace algorithms {
	template<class T, class Less>
	void insertion_sort(data_structures::Vector<T>& vector, Less& less) {
		n_sort(1, vector, vector.size(), less);
	}

	template<class T, class Less>
	void selection_sort(data_structures::Vector<T>& vector, Less& less) {
		int size = vector.size();
		for (int i = 0; i < size; ++i) {
			T smallest = vector[i];
			int smallestIndex = i;
			for (int j = i + 1; j < size; ++j) {
				if (less(vector[j], smallest)) {
					smallestIndex = j;
				}
			}
			swap(vector, smallestIndex, i);
		}
	}

	template<class T, class Less>
	void shell_sort(data_structures::Vector<T>& vector, Less& less) {
		int size = vector.size();
		int n = 1;
		int thirdOfSize = size / 3;
		while (n < thirdOfSize) {
			n = 3 * n + 1;
		}
		while (n >= 1) {
			n_sort(n, vector, size, less);
			n = n / 3;
		}
	}

	template<class T>
	void swap(data_structures::Vector<T>& vector, int i, int j) {
		T tmp = vector[j];
		vector[j] = vector[i];
		vector[i] = tmp;
	}
}
#endif //PRINCETON_ALGS4_INCLUDE_ALGORITHMS_SORT_H_
