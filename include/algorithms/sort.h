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

	template<class T, class Less>
	void merge(data_structures::Vector<T>& data,
			   data_structures::Vector<T>& auxiliary,
			   int lo,
			   int mid,
			   int hi,
			   Less less) {
		for (int k = lo; k <= hi; k++) {
			auxiliary[k] = data[k];
		}
		int i = lo;
		int j = mid + 1;
		for (int k = lo; k <= hi; k++) {
			if (i > mid) data[k] = auxiliary[j++];
			else if (j > hi) data[k] = auxiliary[i++];
			else if (less(auxiliary[j], auxiliary[i])) data[k] = auxiliary[j++];
			else data[k] = auxiliary[i++];
		}
	}

	template<class T, class Less>
	void top_down_merge_sort(data_structures::Vector<T>& vector,
							 data_structures::Vector<T>& auxiliary,
							 Less& less,
							 int lo,
							 int hi) {
		if (hi <= lo) return;
		int mid = lo + (hi - lo) / 2;
		top_down_merge_sort(vector, auxiliary, less, lo, mid);
		top_down_merge_sort(vector, auxiliary, less, mid + 1, hi);
		if (!less(vector[mid + 1], vector[mid])) return;
		merge(vector, auxiliary, lo, mid, hi, less);
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

	template<class T, class Less>
	void bottom_up_merge_sort(data_structures::Vector<T>& vector, Less& less) {
		int size = vector.size();
		int upperBound = size - 1;
		data_structures::Vector<T> auxiliary(size, size, false);
		for (int sz = 1; sz < size; sz = 2 * sz)
			for (int lo = 0; lo < size - sz; lo += 2 * sz)
				merge(vector, auxiliary, lo, lo + sz - 1, std::min(lo + 2 * sz - 1, upperBound), less);
	}

	template<class T, class Less>
	void top_down_merge_sort(data_structures::Vector<T>& vector, Less& less) {
		int size = vector.size();
		data_structures::Vector<T> auxiliary(size, size, false);
		::top_down_merge_sort(vector, auxiliary, less, 0, size - 1);
	}

	template<class T>
	void swap(data_structures::Vector<T>& vector, int i, int j) {
		T tmp = vector[j];
		vector[j] = vector[i];
		vector[i] = tmp;
	}
}
#endif //PRINCETON_ALGS4_INCLUDE_ALGORITHMS_SORT_H_
