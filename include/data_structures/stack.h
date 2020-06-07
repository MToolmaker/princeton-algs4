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
            array = new T[myCapacity];
        }

        void push(T element) {
            if (myCurrentSize >= myCapacity) {
                resize(2 * myCapacity);
            }
            array[myCurrentSize] = element;
            myCurrentSize++;
        }

        T pop() {
            assert(myCurrentSize > 0);
            return array[--myCurrentSize];
        }

        T peek() {
            return array[myCurrentSize - 1];
        }

        int getSize() {
            return myCurrentSize;
        }

        int isEmpty() {
            return myCurrentSize <= 0;
        }

    private:
        int myCapacity;
        T *array;
        int myCurrentSize;

		void resize(int newSize) {
			T *newUnderlyingArray = new T[newSize];
			for (int i = 0; i < myCurrentSize; i++) {
				newUnderlyingArray[i] = array[i];
			}
			delete[] array;
			array = newUnderlyingArray;
			myCapacity = newSize;
		}
    };
}
#endif //PRINCETON_ALGS4_SRC_DATA_STRUCTURES_STACK_H_