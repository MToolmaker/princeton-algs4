//
// Created by Ivan Yarkov on 16/07/2020.
//

#ifndef PRINCETON_ALGS4_INCLUDE_ALGORITHMS_SORT_H_
#define PRINCETON_ALGS4_INCLUDE_ALGORITHMS_SORT_H_

namespace algorithms {
	template<class T>
	void swap(data_structures::Vector<T>& vector, int i, int j);
}

namespace {
	template<class T>
	void n_sort(int n, data_structures::Vector<T>& vector, int size) {
		for (int i = n; i < size; i += n) {
			for (int j = i; j >= n && vector[j - n] > vector[j]; j -= n) {
				algorithms::swap(vector, j, j - n);
			}
		}
	}
}

namespace algorithms {
	template<class T>
	void insertion_sort(data_structures::Vector<T>& vector) {
		int size = vector.size();
		for (int i = 1; i < size; ++i) {
			n_sort(1, vector, size);
		}
	}

	template<class T>
	void selection_sort(data_structures::Vector<T>& vector) {
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

	template<class T>
	void shell_sort(data_structures::Vector<T>& vector) {
		int size = vector.size();
		int n = 1;
		int thirdOfSize = size / 3;
		while (n < thirdOfSize) {
			n = 3 * n + 1;
		}
		while (n >= 1) {
			n_sort(n, vector, size);
			n = n / 3;
		}
	}

	template<class T>
	void swap(data_structures::Vector<T>& vector, int i, int j) {
		int tmp = vector[j];
		vector[j] = vector[i];
		vector[i] = tmp;
	}
}
#endif //PRINCETON_ALGS4_INCLUDE_ALGORITHMS_SORT_H_
