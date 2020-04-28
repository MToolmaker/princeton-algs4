//
// Created by Ivan Yarkov on 26/04/2020.
//

#ifndef PRINCETON_ALGS4_NEW_UNION_FIND_H
#define PRINCETON_ALGS4_NEW_UNION_FIND_H
namespace data_structures{
struct UnionFind {
    explicit UnionFind(int numberOfElements);

    UnionFind(UnionFind &another) = delete;

    bool areConnected(int firstElement, int secondElement);

    void doUnion(int firstElement, int secondElement);

    ~UnionFind();

    bool operator==(const UnionFind &rhs) = delete;

    bool operator!=(const UnionFind &rhs) = delete;

private:
    int *myElements;
    int *mySizes;
    int myNumberOfElements;

    int root(int element);
};

};
#endif //PRINCETON_ALGS4_NEW_UNION_FIND_H
