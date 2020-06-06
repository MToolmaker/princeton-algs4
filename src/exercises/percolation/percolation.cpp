//
// Created by Ivan Yarkov on 27/04/2020.
//

#include <cassert>
#include <random>
#include <iostream>
#include <exercises/percolation.h>
#include <data_structures/union_find.h>

namespace exercises {
	enum class CellColor {
		WHITE,
		BLACK,
	};

	long current_time_nanoseconds();

	void connectLeftIfOpen(data_structures::UnionFind &unionFind,
						   const CellColor *cellColors,
						   int randomElement);

	void connectTopIfOpen(int n, data_structures::UnionFind &unionFind,
						  const CellColor *cellColors,
						  int randomElement);

	void connectRightIfOpen(data_structures::UnionFind &unionFind,
							const CellColor *cellColors,
							int randomElement);

	void connectBottomIfOpen(int n, data_structures::UnionFind &unionFind,
							 const CellColor *cellColors,
							 int randomElement);

	void openAdjacentSites(int n, data_structures::UnionFind &unionFind,
						   const CellColor *cellColors,
						   int randomElement);

	double findPercolationNumber(int n) {
		assert(n >= 2);
		data_structures::UnionFind unionFind(n * n + 2);
		auto *cellColors = new CellColor[n * n];
		for (int i = 0; i < n * n; i++) {
			cellColors[i] = CellColor::BLACK;
		}
		// Connect top to fake node
		for (int i = 1; i <= n; i++) {
			unionFind.doUnion(0, i);
		}
		// Connect bottom to fake node
		for (int i = n * n; i >= n * (n - 1) + 1; i--) {
			unionFind.doUnion(i, n * n + 1);
		}
		std::mt19937 generator(current_time_nanoseconds());
		std::uniform_int_distribution<> distribution(1, n * n);
		int numberOfOpenSites = 0;
		int randomElement;
		do {
			do {
				randomElement = distribution(generator);
			} while (cellColors[randomElement - 1] == CellColor::WHITE);
			cellColors[randomElement - 1] = CellColor::WHITE;
			numberOfOpenSites++;
			openAdjacentSites(n, unionFind, cellColors, randomElement);
		} while (!unionFind.areConnected(0, n * n + 1));
		delete[] cellColors;
		return static_cast<double>(numberOfOpenSites) / static_cast<double>(n * n);;
	}

	void openAdjacentSites(int n, data_structures::UnionFind &unionFind,
						   const CellColor *cellColors,
						   int randomElement) {
		if (randomElement == 1) {
			connectRightIfOpen(unionFind, cellColors, randomElement);
			connectBottomIfOpen(n, unionFind, cellColors, randomElement);
		} else if (randomElement == n) {
			connectLeftIfOpen(unionFind, cellColors, randomElement);
			connectBottomIfOpen(n, unionFind, cellColors, randomElement);
		} else if (randomElement == n * (n - 1) + 1) {
			connectTopIfOpen(n, unionFind, cellColors, randomElement);
			connectRightIfOpen(unionFind, cellColors, randomElement);
		} else if (randomElement == n * n) {
			connectTopIfOpen(n, unionFind, cellColors, randomElement);
			connectLeftIfOpen(unionFind, cellColors, randomElement);
		} else if (2 <= randomElement && randomElement <= n - 1) {
			connectLeftIfOpen(unionFind, cellColors, randomElement);
			connectRightIfOpen(unionFind, cellColors, randomElement);
			connectBottomIfOpen(n, unionFind, cellColors, randomElement);
		} else if (n * (n - 1) + 2 <= randomElement && randomElement <= n * n - 1) {
			connectLeftIfOpen(unionFind, cellColors, randomElement);
			connectRightIfOpen(unionFind, cellColors, randomElement);
			connectTopIfOpen(n, unionFind, cellColors, randomElement);
		} else if (((randomElement - 1) % n) == 0) {
			connectRightIfOpen(unionFind, cellColors, randomElement);
			connectTopIfOpen(n, unionFind, cellColors, randomElement);
			connectBottomIfOpen(n, unionFind, cellColors, randomElement);
		} else if ((randomElement % n) == 0) {
			connectLeftIfOpen(unionFind, cellColors, randomElement);
			connectTopIfOpen(n, unionFind, cellColors, randomElement);
			connectBottomIfOpen(n, unionFind, cellColors, randomElement);
		} else {
			connectLeftIfOpen(unionFind, cellColors, randomElement);
			connectRightIfOpen(unionFind, cellColors, randomElement);
			connectTopIfOpen(n, unionFind, cellColors, randomElement);
			connectBottomIfOpen(n, unionFind, cellColors, randomElement);
		}
	}

	void
	connectBottomIfOpen(int n, data_structures::UnionFind &unionFind,
						const CellColor *cellColors,
						int randomElement) {
		if (cellColors[randomElement + n - 1] == CellColor::WHITE) {
			unionFind.doUnion(randomElement, randomElement + n);
		}
	}

	void connectRightIfOpen(data_structures::UnionFind &unionFind,
							const CellColor *cellColors,
							int randomElement) {
		if (cellColors[randomElement] == CellColor::WHITE) {
			unionFind.doUnion(randomElement, randomElement + 1);
		}
	}

	void connectTopIfOpen(int n, data_structures::UnionFind &unionFind,
						  const CellColor *cellColors,
						  int randomElement) {
		if (cellColors[randomElement - n - 1] == CellColor::WHITE) {
			unionFind.doUnion(randomElement, randomElement - n);
		}
	}

	void connectLeftIfOpen(data_structures::UnionFind &unionFind, const CellColor *cellColors, int randomElement) {
		if (cellColors[randomElement - 2] == CellColor::WHITE) {
			unionFind.doUnion(randomElement, randomElement - 1);
		}
	}

	long current_time_nanoseconds() {
		struct timespec tm{};
		clock_gettime(CLOCK_REALTIME, &tm);
		return tm.tv_nsec;
	}
}
