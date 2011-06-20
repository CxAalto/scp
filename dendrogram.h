#ifndef DENDRO_TREE_H
#define DENDRO_TREE_H

#include <cstddef>
#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <algorithm>

class Dendrogram
{
public:
    Dendrogram() {}

    void addNewBottom(const float weight, const size_t size, const size_t comIndex);

    void changeSize(const float weight, const size_t size, const size_t comIndex);

    void addConnection(const float weight, const size_t size, const std::set<size_t> & comsToMerge, const size_t newComIndex);

    void printFromNode(const size_t comIndex, std::ostream & file);

    void printTree(std::ostream & file);

    ~Dendrogram();

private:

    class DendrogramNode
    {
        friend class Dendrogram;

        public:
            DendrogramNode(float weight, size_t size, size_t comIndex) : weight(weight), size(size), comIndex(comIndex), parent(NULL) {}

            void addChild(DendrogramNode * child) { children.insert(child); } // TESTI

        private:
            float weight;
            size_t size;
            size_t comIndex;
            DendrogramNode * parent;

            std::set<DendrogramNode*> children; // TESTI
    };

    static bool compareNodes(DendrogramNode * first, DendrogramNode * second) { return first->weight > second->weight; }

    // the nodes which no other node points to
    std::vector<DendrogramNode*> bottom;

    // all nodes in the dendrogram, used for freeing the memory
    std::vector<DendrogramNode*> nodes;

    // map that holds the mapping from community indexes
    std::map<size_t, DendrogramNode*> comIndexMap;
};

#endif
