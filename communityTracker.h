#ifndef COMMUNITYTRACKER_H
#define COMMUNITYTRACKER_H

#include <iostream>
#include <vector>
#include <utility>

#include "../lcelib/Nets.H"
#include "cliqueHash.h"
#include "nodeCommunities.h"
#include "kruskal.h"
#include "dendrogram.h"

class CommunityTracker
{
public:

    CommunityTracker(cliqueHash & hash, KruskalTree & tree, nodeCommunities & nodeComs, Dendrogram & dendrogram, NetType & net);

    void addClique(weighedClique & kclique);

    void print(std::ostream & file) const;

private:

    cliqueHash & hash;
    KruskalTree & tree;
    nodeCommunities & nodeComs;
    Dendrogram & dendrogram;
    NetType & net;

    std::vector<size_t> tempVector; // used when creating (k-1)-cliques, this way we avoid creating a new vector object for every k-clique
    weighedClique k1clique;

    //std::vector<std::pair<size_t, size_t> > mergingCommunities; // tells which communities merge as a result from adding a clique
    std::set<size_t> comsToMerge;

};

#endif
