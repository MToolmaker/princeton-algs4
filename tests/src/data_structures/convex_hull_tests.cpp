//
// Created by Ivan Yarkov on 23/07/2020.
//

#include <data_structures/convex_hull_test.h>
#include <data_structures/vector.h>
#include <data_structures/vertex2f.h>
#include <algorithms/convex_hull.h>

namespace tests {
	using data_structures::Vertex2f;
	using data_structures::Vector;
	using data_structures::Stack;

	void runComplexConvexHullTest();

	void runConvexHullTests() {
		runComplexConvexHullTest();
		std::cout << "All convex hull tests passed" << std::endl;
	}

	void fillInternalVertices(Vector<Vertex2f>& vertices);

	void fillConvexHullVertices(Vector<Vertex2f>& vertices, Stack<Vertex2f>& expected_convex_hull_vertices);

	void testConvexHull(const Vector<Vertex2f>& vertices, Stack<Vertex2f>& expected_convex_hull);

	void runComplexConvexHullTest() {
		Vector<Vertex2f> vertices(11);
		fillInternalVertices(vertices);
		Stack<Vertex2f> expected_convex_hull(5);
		fillConvexHullVertices(vertices, expected_convex_hull);
		testConvexHull(vertices, expected_convex_hull);
	}

	void testConvexHull(const Vector<Vertex2f>& vertices, Stack<Vertex2f>& expected_convex_hull) {
		auto actual_convex_hall = algorithms::find_convex_hull(vertices);
		int actual_convex_hull_size = actual_convex_hall.getSize();
		assert(expected_convex_hull.getSize() == actual_convex_hull_size);
		for (int i = 0; i < actual_convex_hull_size; i++) {
			assert(actual_convex_hall.pop() == expected_convex_hull.pop());
		}
	}

	void fillInternalVertices(Vector<Vertex2f>& vertices) {
		vertices.pushBack(Vertex2f(2, 3));
		vertices.pushBack(Vertex2f(2, 2));
		vertices.pushBack(Vertex2f(3, 2));
		vertices.pushBack(Vertex2f(3, 1));
		vertices.pushBack(Vertex2f(4, 3));
		vertices.pushBack(Vertex2f(6, 2));
	}

	void fillConvexHullVertices(Vector<Vertex2f>& vertices, Stack<Vertex2f>& expected_convex_hull_vertices) {
		const Vertex2f firstConvexHullVertex(7, 0);
		vertices.pushBack(firstConvexHullVertex);
		expected_convex_hull_vertices.push(firstConvexHullVertex);
		const Vertex2f secondConvexHullVertex(5, 5);
		vertices.pushBack(secondConvexHullVertex);
		expected_convex_hull_vertices.push(secondConvexHullVertex);
		const Vertex2f thirdConvexHullVertex(3, 5);
		vertices.pushBack(thirdConvexHullVertex);
		expected_convex_hull_vertices.push(thirdConvexHullVertex);
		const Vertex2f forthConvexHullVertex(1, 3);
		vertices.pushBack(forthConvexHullVertex);
		expected_convex_hull_vertices.push(forthConvexHullVertex);
		const Vertex2f fifthConvexHullVertex(1, 1);
		vertices.pushBack(fifthConvexHullVertex);
		expected_convex_hull_vertices.push(fifthConvexHullVertex);
	}
}