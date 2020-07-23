//
// Created by Ivan Yarkov on 18/07/2020.
//

#ifndef PRINCETON_ALGS4_INCLUDE_ALGORITHMS_CONVEX_HULL_H_
#define PRINCETON_ALGS4_INCLUDE_ALGORITHMS_CONVEX_HULL_H_

#include <memory>
#include <data_structures/vector.h>
#include <algorithms/sort.h>
#include <data_structures/stack.h>
#include <data_structures/vertex2f.h>

namespace {

}

namespace algorithms {
	using data_structures::Vertex2f;
	using data_structures::Vector;
	using data_structures::Stack;

	static int ccw(const Vertex2f& a, const Vertex2f& b, const Vertex2f& c);

	void sortByY(Vector<Vertex2f>& points_sorted_by_y_in_ascending_order);

	void sortByPolarAngle(Vector<Vertex2f>& points);

	Vector<Vertex2f> orderPointsByPolarAngle(const Vector<Vertex2f>& points);

	Stack<Vertex2f> find_convex_hull(const Vector<Vertex2f>& points) {
		assert(points.size() >= 3);
		Vector<Vertex2f> ordered_by_polar_angle = orderPointsByPolarAngle(points);
		Stack<Vertex2f> hull = Stack<Vertex2f>(8);
		hull.push(ordered_by_polar_angle[0]);
		hull.push(ordered_by_polar_angle[1]);
		int size = points.size();
		for (int i = 2; i < size; i++) {
			Vertex2f top = hull.pop();
			while (ccw(hull.peek(), top, ordered_by_polar_angle[i]) <= 0) {
				top = hull.pop();
			}
			hull.push(top);
			hull.push(ordered_by_polar_angle[i]);
		}
		return hull;
	}

	Vector<Vertex2f> orderPointsByPolarAngle(const Vector<Vertex2f>& points) {
		Vector<Vertex2f> sorted_points = points;
		sortByY(sorted_points);
		sortByPolarAngle(sorted_points);
		return sorted_points;
	}

	void sortByY(Vector<Vertex2f>& points_sorted_by_y_in_ascending_order) {
		struct LessByY {
			bool operator()(const Vertex2f& a, const Vertex2f& b) const {
				return a.y < b.y;
			}
		};
		LessByY lessByY{};
		shell_sort<Vertex2f, LessByY>(points_sorted_by_y_in_ascending_order, lessByY);
	}

	void sortByPolarAngle(Vector<Vertex2f>& points) {
		struct LessPolarAngle {
			explicit LessPolarAngle(const Vertex2f& vertex) : my_vertex(vertex) {}

			bool operator()(const Vertex2f& a, const Vertex2f& b) const {
				int cross_product = cross(
						a.x - my_vertex.x,
						a.y - my_vertex.y,
						b.x - my_vertex.x,
						b.y - my_vertex.y);
				return cross_product > 0;
			}

		private:
			const Vertex2f my_vertex;

			static int cross(const int x1, const int y1, const int x2, const int y2) {
				return x1 * y2 - x2 * y1;
			};
		};
		LessPolarAngle lessByAngle(points[0]);
		shell_sort<Vertex2f, LessPolarAngle>(points,lessByAngle);
	}

	static int ccw(const Vertex2f& a, const Vertex2f& b, const Vertex2f& c) {
		int area2 = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
		if (area2 < 0) return -1;
		if (area2 > 0) return 1;
		return 0;
	}
}
#endif //PRINCETON_ALGS4_INCLUDE_ALGORITHMS_CONVEX_HULL_H_
