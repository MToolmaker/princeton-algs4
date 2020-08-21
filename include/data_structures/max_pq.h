//
// Created by Ivan Yarkov on 02/08/2020.
//

#ifndef PRINCETON_ALGS4_INCLUDE_DATA_STRUCTURES_MAX_PQ_H_
#define PRINCETON_ALGS4_INCLUDE_DATA_STRUCTURES_MAX_PQ_H_

#include <data_structures/vector.h>

namespace data_structures {
	template<class T, class More>
	struct MaxPQ final {
		explicit MaxPQ(const int capacity, const More& less) : myCurrentSize(1),
															   myCapacity(capacity + 1),
															   myArray(new T[capacity + 1]),
															   myMore(less) {}

		explicit MaxPQ(const Vector<T>& keys, const int capacity, const More& less) : MaxPQ(capacity, less) {
			int size = keys.size();
			for (int i = 0; i < size; ++i) {
				insert(keys[i]);
			}
			myCurrentSize = size + 1;
		}

		void insert(const T& key) {
			if (myCurrentSize == myCapacity) {
				resize(2 * myCapacity - 1);
			}
			assert(myCurrentSize < myCapacity);
			myArray[myCurrentSize] = key;
			swim(myCurrentSize);
			++myCurrentSize;
		}

		T deleteMax() {
			assert(myCurrentSize > 1);
			T& topElement = myArray[1];
			T max = topElement;
			myCurrentSize--;
			swap(topElement, myArray[myCurrentSize]);
			sink(1);
			return max;
		}

		__unused T max() {
			return myArray[1];
		}

		int size() {
			return myCurrentSize - 1;
		}

		bool isEmpty() {
			return size() == 0;
		}

	private:
		int myCapacity{};
		T *myArray;
		int myCurrentSize{};
		More myMore;

		void sink(int currentIndex) {
			int childrenOffset;
			while ((childrenOffset = currentIndex * 2) <= myCurrentSize - 1) {
				bool hasSecondChild = childrenOffset < (myCurrentSize - 1);
				bool isSecondChildLargerThanFirst =
						hasSecondChild && myMore(myArray[childrenOffset + 1], myArray[childrenOffset]);
				if (isSecondChildLargerThanFirst) ++childrenOffset;
				if (!swapChildAndParentIfNeeded(childrenOffset, currentIndex)) return;
				currentIndex = childrenOffset;
			}
		}

		void swim(int currentIndex) {
			int parentIndex;
			while ((parentIndex = currentIndex / 2) >= 1) {
				if (!swapChildAndParentIfNeeded(currentIndex, parentIndex)) return;
				currentIndex = parentIndex;
			}
		}

		bool swapChildAndParentIfNeeded(int childIndex, int parentIndex) {
			T& current = myArray[childIndex];
			T& parent = myArray[parentIndex];
			if (!myMore(current, parent)) return false;
			swap(current, parent);
			return true;
		}

		void swap(T& a, T& b) {
			T tmp = a;
			a = b;
			b = tmp;
		}

		void resize(int newSize) {
			T *newArray = new T[newSize];
			for (int i = 1; i < myCurrentSize; i++) {
				newArray[i] = myArray[i];
			}
			delete[] myArray;
			myArray = newArray;
			myCapacity = newSize;
		}
	};
}
#endif //PRINCETON_ALGS4_INCLUDE_DATA_STRUCTURES_MAX_PQ_H_
