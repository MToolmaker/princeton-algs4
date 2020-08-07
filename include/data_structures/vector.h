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
		explicit Vector(int capacity) : Vector(0, capacity, true) {}

		explicit Vector(int size, int capacity) : Vector(size, capacity, true) {}

		explicit Vector(int size, int capacity, bool shouldSetWithNulls) {
			assert(capacity > 0);
			myCapacity = capacity;
			myCurrentSize = size;
			myArray = new T[myCapacity];
			if (!shouldSetWithNulls) return;
			for (int i = 0; i < myCurrentSize; i++) {
				myArray[i] = T{};
			}
		}

		Vector(const Vector& vector) {
			myCapacity = vector.myCapacity;
			myCurrentSize = vector.myCurrentSize;
			myArray = new T[myCapacity];
			for (int i = 0; i < myCurrentSize; i++) {
				myArray[i] = vector.myArray[i];
			}
		}

		Vector& operator=(Vector vector) {
			std::swap(myCapacity, vector.myCapacity);
			std::swap(myCurrentSize, vector.myCurrentSize);
			std::swap(*myArray, *vector.myArray);
			return *this;
		}

		T& operator[](int index) {
			assert(0 <= index && index < myCurrentSize);
			return myArray[index];
		}

		T operator[](int index) const {
			assert(0 <= index && index < myCurrentSize);
			return myArray[index];
		}

		friend std::ostream& operator<<(std::ostream& outputStream, const Vector& vector) {
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

		int size() const {
			return myCurrentSize;
		}

		~Vector() {
			delete[] myArray;
		}

	private:
		int myCapacity{};
		T *myArray;
		int myCurrentSize{};

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
