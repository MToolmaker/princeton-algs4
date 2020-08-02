//
// Created by Ivan Yarkov on 17/07/2020.
//

#ifndef PRINCETON_ALGS4_INCLUDE_ALGORITHMS_SHUFFLE_H_
#define PRINCETON_ALGS4_INCLUDE_ALGORITHMS_SHUFFLE_H_

#include <data_structures/vector.h>
#include <random>

namespace algorithms {
	template<class T>
	void swap(data_structures::Vector<T>& vector, int i, int j);

	template<class T>
	void shuffle(data_structures::Vector<T>& vector) {
		int size = vector.size();
		std::random_device dev;
		std::mt19937 rng(dev());
		for (int i = 1; i < size; ++i) {
			std::uniform_int_distribution<std::mt19937::result_type> distribution(0, i);
			int random = distribution(rng);
			swap(vector, i, random);
		}
	}
}
#endif //PRINCETON_ALGS4_INCLUDE_ALGORITHMS_SHUFFLE_H_
