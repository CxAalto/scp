#ifndef CLIQUE_HASH
#define CLIQUE_HASH

#include <list>
#include "weighedClique.h"


class cliqueHash
{

    // typedef std::list<std::pair<clique,size_t> > cliqueIndexSet;
    typedef std::list<std::pair<clique,size_t> > cliqueIndexSet;

private:

    size_t size;
    std::vector<cliqueIndexSet> hashTable;
    size_t hash_bits;
    size_t a, b, c, offSet;

    size_t hash_function(const clique key);

    cliqueIndexSet::iterator iter;
    std::pair<clique,size_t> currPair;
    size_t curr_hash_key;
    size_t keyCount;

public:

    cliqueHash(const size_t hashSize, const size_t t, const size_t keySize);


    cliqueHash();


    bool contains(const clique & key);


    int getValue(const clique & key);


    void put(const clique & key, const size_t value);


    std::pair<clique,size_t> begin();


    std::pair<clique,size_t> next();


    bool finished();


    size_t getKeyCount()
    {
        return keyCount;
    }

};

#endif
