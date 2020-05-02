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
            currentSize = 0;
            array = new T[myCapacity];
        }

        void push(T element) {
            if (currentSize >= myCapacity) {
                int newSize = 2 * myCapacity;
                T *newUnderlyingArray = new T[newSize];
                for (int i = 0; i < myCapacity; i++) {
                    newUnderlyingArray[i] = array[i];
                }
                delete[] array;
                array = newUnderlyingArray;
                myCapacity = newSize;
            }
            array[currentSize] = element;
            currentSize++;
        }

        T pop() {
            assert(currentSize > 0);
            return array[--currentSize];
        }

        T peek() {
            return array[currentSize - 1];
        }

        int getSize() {
            return currentSize;
        }

        int isEmpty() {
            return currentSize <= 0;
        }

    private:
        int myCapacity;
        T *array;
        int currentSize;
    };
}
#endif //PRINCETON_ALGS4_SRC_DATA_STRUCTURES_STACK_H_