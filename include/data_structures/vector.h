//
// Created by Ivan Yarkov on 11/07/2020.
//

#ifndef PRINCETON_ALGS4_INCLUDE_DATA_STRUCTURES_VECTOR_H_
#define PRINCETON_ALGS4_INCLUDE_DATA_STRUCTURES_VECTOR_H_

#include <memory>
#include <cassert>
#include <iostream>

namespace data_structures {
	template<class T>
	struct Vector {
		explicit Vector(int capacity) {
			assert(capacity > 0);
			myCapacity = capacity;
			myCurrentSize = 0;
			myArray = new T[myCapacity];
		}

		Vector(const Vector &vector) {
			myCapacity = vector.myCapacity;
			myCurrentSize = vector.myCurrentSize;
			myArray = new T[myCapacity];
			for (int i = 0; i < myCurrentSize; i++) {
				myArray[i] = vector.myArray[i];
			}
		}

		Vector &operator=(const Vector &vector) {
			if (this == &vector) return *this;
			std::swap(*this, vector);
			return *this;
		};

		int& operator[](int index) {
			assert(0 <= index && index < myCurrentSize);
			return myArray[index];
		};

		friend std::ostream &operator<<(std::ostream &outputStream, const Vector &vector) {
			outputStream << "[ ";
			for (int i = 0; i < vector.myCurrentSize; i++) {
				outputStream << vector.myArray[i] << " ";
			}
			outputStream << "]";
			return outputStream;
		}

		void pushBack(T element) {
			if (myCurrentSize == myCapacity) {
				resize(2 * myCapacity);
			}
			myArray[myCurrentSize++] = element;
		}

		int size() {
			return myCurrentSize;
		}

		~Vector() {
			delete [] myArray;
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
#endif //PRINCETON_ALGS4_INCLUDE_DATA_STRUCTURES_VECTOR_H_
