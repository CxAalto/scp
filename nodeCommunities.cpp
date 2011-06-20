#include "nodeCommunities.h"

nodeCommunities::nodeCommunities() : largest(0) {}

void nodeCommunities::addClique(const size_t index, const clique & newClique)
{
    // add the nodes to the set
    for (size_t i = 0; i < newClique.size(); i++)
        communities[index].put(newClique.at(i));
    // check if this community becomes the largest
    if (communities[index].size() > largest)
    {
        largest = communities[index].size();
        largestCom = index;
    }
}

void nodeCommunities::erase(const size_t index)
{
    communities.erase(index);
    if (index == largestCom)
    {
        largest = 0;
        for (std::map<size_t, nodeSet>::iterator i = communities.begin(); i != communities.end(); i++)
            if (i->second.size() > largest)
            {
                largest = i->second.size();
                largestCom = i->first;
            }
    }
}

size_t nodeCommunities::connect(size_t first, size_t second)
{
    for (nodeSet::iterator i = communities[first].begin(); !i.finished(); ++i)
        communities[second].put(*i);

    erase(first);
    if (communities[second].size() > largest)
    {
        largest = communities[second].size();
        largestCom = second;
    }

    return second;
}

void nodeCommunities::printCommunities(std::ostream & file) const
{
    file << "largest: " << largest << std::endl;
    for (std::map<size_t, nodeSet>::const_iterator i = communities.begin(); i != communities.end(); i++)
    {
        file << i->first << ": ";
        for (nodeSet::const_iterator j = i->second.begin(); !j.finished(); ++j)
            file << *j << " ";
        file << std::endl;
    }
    file << std::endl;
}
