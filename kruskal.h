#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <iostream>

#include "weighedClique.h"

class KruskalTree
{
public:
    KruskalTree();

    size_t add(); // return the index where the element was added ( = table.size() - 1 )

    size_t add(const size_t root); // same as above

    void connect(const size_t first, const size_t second); // connects two sets, after the operation the first points to the root of second

    bool inSameSet(const size_t first, const size_t second); // checks if two elements belong to same set

    size_t findRoot(const size_t source); // finds the real root of an element

    size_t size(const size_t source);

    size_t getLargestComponentSize() const;

    void printTree(std::ostream & file) const;

private:

    std::vector<size_t> table; // stores the pointer to root
    std::vector<size_t> commSizes; // sizes of the sets are kept here

    size_t largestComponentSize;

};

#endif
