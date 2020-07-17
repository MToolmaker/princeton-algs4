//
// Created by Ivan Yarkov on 26/04/2020.
//

#include <cassert>
#include <data_structures/union_find.h>

namespace data_structures {
	UnionFind::UnionFind(int numberOfElements) {
		assert(numberOfElements >= 0);
		myElements = new int[numberOfElements];
		mySizes = new int[numberOfElements];
		myNumberOfElements = numberOfElements;
		for (int i = 0; i < myNumberOfElements; i++) {
			myElements[i] = i;
			mySizes[i] = 1;
		}
	}

	UnionFind::~UnionFind() {
		delete[] myElements;
		delete[] mySizes;
	}

	bool UnionFind::areConnected(int firstElement, int secondElement) {
		return root(firstElement) == root(secondElement);
	}

	void UnionFind::doUnion(int firstElement, int secondElement) {
		assert(firstElement >= 0 && firstElement < myNumberOfElements);
		assert(secondElement >= 0 && secondElement < myNumberOfElements);
		int firstElementRoot = root(firstElement);
		int secondElementRoot = root(secondElement);
		if (firstElementRoot == secondElementRoot) return;
		int smallestTreeRoot;
		int biggestTreeRoot;
		if (mySizes[firstElementRoot] > mySizes[secondElementRoot]) {
			biggestTreeRoot = firstElementRoot;
			smallestTreeRoot = secondElementRoot;
		} else {
			biggestTreeRoot = secondElementRoot;
			smallestTreeRoot = firstElementRoot;
		}
		mySizes[biggestTreeRoot] = mySizes[biggestTreeRoot] + mySizes[smallestTreeRoot];
		myElements[smallestTreeRoot] = biggestTreeRoot;
	}

	int UnionFind::root(int element) {
		assert(element >= 0 && element < myNumberOfElements);
		int rootElement = element;
		while (rootElement != myElements[rootElement]) {
			rootElement = myElements[rootElement];
		}
		int currentElement;
		while (element != myElements[element]) {
			currentElement = element;
			element = myElements[element];
			myElements[currentElement] = rootElement;
		}
		return element;
	}
}