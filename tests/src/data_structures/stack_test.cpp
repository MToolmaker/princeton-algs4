//
// Created by Ivan Yarkov on 25/04/2020.
//

#include <iostream>
#include <data_structures/stack.h>

namespace tests {
    void testStackWithOneElement();

    void testStackResizing();

    void testPeek();

    void runAllStackTests() {
        testStackWithOneElement();
        testStackResizing();
        testPeek();
        std::cout << "All stack tests passed" << std::endl;
    }

    void testStackWithOneElement() {
        data_structures::Stack<char> stack(1);
        char testLetter = 'a';
        stack.push(testLetter);
        assert(stack.getSize() == 1);
        assert(stack.pop() == testLetter);
        assert(stack.isEmpty());
        assert(stack.getSize() == 0);
    }

    void testStackResizing() {
        data_structures::Stack<int> stack(1);
        for (int i = 1; i <= 100; i++) {
            stack.push(i);
            assert(stack.getSize() == i);
        }
        for (int i = 100; i >= 1; i--) {
            assert(stack.getSize() == i);
            assert(stack.pop() == i);
        }
    }

    void testPeek() {
        data_structures::Stack<char> stack(1);
        char testCharacter = 'a';
        stack.push(testCharacter);
        assert(stack.getSize() == 1);
        assert(stack.peek() == testCharacter);
        assert(stack.getSize() == 1);
    }
}
