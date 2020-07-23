//
// Created by Ivan Yarkov on 23/07/2020.
//

#ifndef PRINCETON_ALGS4_INCLUDE_DATA_STRUCTURES_VERTEX2F_H_
#define PRINCETON_ALGS4_INCLUDE_DATA_STRUCTURES_VERTEX2F_H_

#include <ostream>

namespace data_structures {
	struct Vertex2f {
		int x;
		int y;

		Vertex2f();

		explicit Vertex2f(int x, int y);

		Vertex2f(const Vertex2f& vertex);

		friend std::ostream& operator<<(std::ostream& outputStream, const Vertex2f& vertex);

		bool operator==(const Vertex2f& vertex) const;
	};
}
#endif //PRINCETON_ALGS4_INCLUDE_DATA_STRUCTURES_VERTEX2F_H_
