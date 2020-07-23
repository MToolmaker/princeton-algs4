//
// Created by Ivan Yarkov on 23/07/2020.
//
#include <data_structures/vertex2f.h>
namespace data_structures {
	Vertex2f::Vertex2f() {
		this->x = 0;
		this->y = 0;
	}

	Vertex2f::Vertex2f(const Vertex2f& vertex) {
		this->x = vertex.x;
		this->y = vertex.y;
	}

	Vertex2f::Vertex2f(const int x, const int y) {
		this->x = x;
		this->y = y;
	}

	std::ostream& operator<<(std::ostream& outputStream, const Vertex2f& vertex) {
		outputStream << "(" << vertex.x << ", " << vertex.y << ") ";
		return outputStream;
	}

	bool Vertex2f::operator==(const Vertex2f& vertex) const {
		return x == vertex.x && y == vertex.y;
	}
}