//
// Created by Ivan Yarkov on 26/04/2020.
//

#include <iostream>
#include "../../src/data_structures/union_find.h"

namespace tests {
    void testElementsConnection();

    void testUnion();

    void runAllUnionFindTests() {
        testElementsConnection();
        testUnion();
        std::cout << "All union-find tests passed" << std::endl;
    }

    void testElementsConnection() {
        data_structures::UnionFind unionFind(3);
        assert(!unionFind.areConnected(0, 1) && !unionFind.areConnected(1, 0));
        assert(!unionFind.areConnected(1, 2) && !unionFind.areConnected(2, 1));
        assert(!unionFind.areConnected(0, 2) && !unionFind.areConnected(2, 0));
    }

    void testUnion() {
        data_structures::UnionFind unionFind(3);
        unionFind.doUnion(0, 1);
        assert(unionFind.areConnected(0, 1) && unionFind.areConnected(1, 0));
        assert(!unionFind.areConnected(1, 2) && !unionFind.areConnected(2, 1));
        assert(!unionFind.areConnected(0, 2) && !unionFind.areConnected(2, 0));
        unionFind.doUnion(0, 2);
        assert(unionFind.areConnected(0, 1) && unionFind.areConnected(1, 0));
        assert(unionFind.areConnected(1, 2) && unionFind.areConnected(2, 1));
        assert(unionFind.areConnected(0, 2) && unionFind.areConnected(2, 0));
    }
}