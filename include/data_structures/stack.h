//
// Created by Ivan Yarkov on 25/04/2020.
//

#ifndef PRINCETON_ALGS4_SRC_DATA_STRUCTURES_STACK_H_
#define PRINCETON_ALGS4_SRC_DATA_STRUCTURES_STACK_H_

#include <memory>

namespace data_structures {
	template<class T>
	struct Stack {
	public:
		explicit Stack(int capacity) {
			assert(capacity >= 1);
			myCapacity = capacity;
			myCurrentSize = 0;
			myArray = new T[myCapacity];
		}

		void push(T element) {
			if (myCurrentSize >= myCapacity) {
				resize(2 * myCapacity);
			}
			myArray[myCurrentSize] = element;
			myCurrentSize++;
		}

		T pop() {
			assert(myCurrentSize > 0);
			if (myCurrentSize == myCapacity / 4) {
				resize(myCapacity / 2);
			}
			return myArray[--myCurrentSize];
		}

		T peek() {
			return myArray[myCurrentSize - 1];
		}

		int getSize() {
			return myCurrentSize;
		}

		int isEmpty() {
			return myCurrentSize <= 0;
		}

	private:
		int myCapacity;
		T *myArray;
		int myCurrentSize;

		void resize(int newSize) {
			T *newArray = new T[newSize];
			for (int i = 0; i < myCurrentSize; i++) {
				newArray[i] = myArray[i];
			}
			delete[] myArray;
			myArray = newArray;
			myCapacity = newSize;
		}
	};
}
#endif //PRINCETON_ALGS4_SRC_DATA_STRUCTURES_STACK_H_