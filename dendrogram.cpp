#include "dendrogram.h"

void Dendrogram::addNewBottom(const float weight, const size_t size, const size_t comIndex)
{
    DendrogramNode *newNode = new DendrogramNode(weight, size, comIndex);
    comIndexMap[comIndex] = newNode;
    bottom.push_back(newNode);
    nodes.push_back(newNode);
}

void Dendrogram::changeSize(const float weight, const size_t size, const size_t comIndex)
{
    DendrogramNode *newNode = new DendrogramNode(weight, size, comIndex);
    nodes.push_back(newNode);
    newNode->addChild(comIndexMap[comIndex]); // TESTI
    comIndexMap[comIndex]->parent = newNode;
    comIndexMap[comIndex] = newNode;
}

void Dendrogram::addConnection(const float weight, const size_t size, const std::set<size_t> & comsToMerge, const size_t newComIndex)
{
    DendrogramNode *newNode = new DendrogramNode(weight, size, newComIndex);
    nodes.push_back(newNode);
    for (std::set<size_t>::iterator i = comsToMerge.begin(); i != comsToMerge.end(); i++)
    {
        comIndexMap[*i]->parent = newNode;
        newNode->addChild(comIndexMap[*i]); // TESTI
    }
}

void Dendrogram::printFromNode(const size_t comIndex, std::ostream & file)
{
    DendrogramNode *node = comIndexMap[comIndex];
    while (node)
    {
        file << node->weight << " " << node->size << " " << node->comIndex << std::endl;
        node = node->parent;
    }
}

void Dendrogram::printTree(std::ostream & file)
{
    std::sort(nodes.begin(), nodes.end(), compareNodes);
    for (std::vector<DendrogramNode*>::iterator i = nodes.begin(); i != nodes.end(); i++)
    {
        file << (*i)->weight << "\t" << (*i)->comIndex << "\t" << (*i)->size;
        for (std::set<DendrogramNode*>::iterator j = (*i)->children.begin(); j != (*i)->children.end(); j++) // TESTI
            file << "\t|\t" << (*j)->comIndex << "\t" << (*j)->size; // TESTI
        file << std::endl;
    }
}

Dendrogram::~Dendrogram()
{
    for (std::vector<DendrogramNode*>::iterator i = nodes.begin(); i != nodes.end(); i++)
        delete *i;
}
