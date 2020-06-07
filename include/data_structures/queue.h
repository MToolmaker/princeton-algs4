//
// Created by Ivan Yarkov on 07/06/2020.
//

#ifndef PRINCETON_ALGS4_INCLUDE_DATA_STRUCTURES_QUEUE_H_
#define PRINCETON_ALGS4_INCLUDE_DATA_STRUCTURES_QUEUE_H_

#include <cassert>

namespace data_structures {
	template<class T>
	class Queue {
	public:
		explicit Queue(int capacity) {
			assert(capacity >= 1);
			myCapacity = capacity;
			myHeadNumber = 0;
			myTailNumber = 0;
			myArray = new T[myCapacity];
			mySize = 0;
		}

		void enqueue(T element) {
			if (mySize != 0 && myTailNumber == myHeadNumber) {
				resize(2 * myCapacity);
			}
			myArray[myTailNumber] = element;
			myTailNumber = getNextNumber(myTailNumber);
			mySize++;
		}

		T dequeue() {
			assert(myHeadNumber != myTailNumber);
			if (mySize == myCapacity / 4) {
				resize(myCapacity / 2);
			}
			T element = myArray[myHeadNumber];
			myHeadNumber = getNextNumber(myHeadNumber);
			mySize--;
			return element;
		}

		bool isEmpty() {
			return mySize == 0;
		}

		bool isFull() {
			return mySize == myCapacity;
		}

		int size() {
			return mySize;
		}

		virtual ~Queue() {
			delete[] myArray;
		}

	private:
		int myCapacity;
		T *myArray;
		int myHeadNumber;
		int myTailNumber;
		int mySize;

		void resize(int newSize) {
			T *newArray = new T[newSize];
			int j = myHeadNumber;
			for (int i = 0; i < mySize; ++i) {
				newArray[i] = myArray[j];
				j = getNextNumber(j);
			}
			delete[] myArray;
			myArray = newArray;
			myCapacity = newSize;
			myHeadNumber = 0;
			myTailNumber = mySize;
		}

		int getNextNumber(int number) const {
			return (number + 1) % myCapacity;
		}
	};
}
#endif //PRINCETON_ALGS4_INCLUDE_DATA_STRUCTURES_QUEUE_H_
