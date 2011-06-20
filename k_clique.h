#ifndef H_K_CLIQUE
#define H_K_CLIQUE

#include <vector>
#include <map>
#include <cassert>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <set>
#include <ctime>
#include <list>

#include "weighedClique.h"
//#include "numSet2.h"
#include "cliqueHash.h"
//#include "multiIter.h"
#include "kruskal.h"
#include "nodeCommunities.h"
#include "communityTracker.h"
#include "dendrogram.h"

// typedef float EdgeData;
// typedef  SymmNet<size_t> NetType; // needs laboratory's library
//typedef std::list<size_t> nodeList; // standard library
// typedef std::vector<numSet> vectorMap;
//typedef std::vector<clique> cliqueVector; // standard library
// typedef std::map< clique, size_t, compareIndexes > nodeCliqueMap;
// typedef std::map< clique, size_t > nodeCliqueMap;
typedef Set<size_t> nodeSet; // needs laboratory's library
//typedef std::vector<numSet2> vectorSet; // standard library
//typedef std::map< clique, size_t > nodeCliqueMap;

size_t determineHashSize(const size_t numElements, const size_t k);

void getNetSizeAndLinkNumbers(char * fileName, size_t & netSize, size_t & numLinks);

bool readLine(std::ifstream & myfile, size_t & source, size_t & dest, float & weight);

void kCliquesFind(std::vector<weighedClique> & cliqueVector, NetType & net, size_t source, size_t dest, const float weight, const size_t k, const size_t weightFunction);

void kCommunitiesFind(std::vector<weighedClique> & cliqueVector, KruskalTree & communities, cliqueHash & k1cliquesHash, NetType & net, const size_t k);

void outputCommunityStructure(KruskalTree & communities, cliqueHash & k1cliquesHash, std::ofstream & file);

void unweightedSCP(NetType & net, std::ifstream & file, const size_t numberOfLinks, const size_t k);

bool weighedCliqueCmp(weighedClique lhs, weighedClique rhs);

void kCommunitiesFindWeighted(std::vector<weighedClique> & cliqueVector, KruskalTree & communities, cliqueHash & k1cliquesHash, NetType & net, const size_t k, const float threshold);

void weightedSCP(NetType & net, std::ifstream & file, const size_t numberOfLinks, const size_t k, const float threshold, const size_t weightFunction);

void percolation(char * fileName, const size_t k, const size_t weighted, const float threshold, const size_t weightFunction);

#endif
