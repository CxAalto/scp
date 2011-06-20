#ifndef CLIQUE2_H
#define CLIQUE2_H

#include <list>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cfloat>

class clique
{

protected:
    std::vector<size_t> nodes;

public:
    friend std::ostream& operator <<(std::ostream &os,const clique &obj);
    clique();
    const size_t size() const;
    const size_t at(const size_t i) const;
    //virtual void addNodes(const std::vector<size_t> & unsorted_nodes);
    virtual void copyClique(const clique & old_clique);

    /*
    clique( clique & old_clique) {
      copyClique(old_clique);
    }

    clique( const clique & old_clique) {
      copyClique(old_clique);
    }
    */

    void replaceNodes( const std::vector<size_t> & unsorted_nodes );
    void printClique() const;
    clique(const std::vector<size_t> & unsorted_nodes);
    bool operator== ( const clique & clique2 ) const;
    bool operator!= ( const clique & clique2 ) const;
    bool operator< ( const clique & clique2) const;

    ~clique()
    {
        //     nodes.clear();
    }



};
#endif




#ifndef W_CLIQUE_H
#define W_CLIQUE_H

// #include <math.h>
#include "../lcelib/Nets.H"
//#include "clique2.H"

//#ifndef NET_TYPE
//#define NET_TYPE
typedef  SymmNet<float> NetType;
//#endif


class weighedClique: public clique
{
private:
    float weight;
    void getLinks(const  NetType & net);

public:
    weighedClique();
    float (weighedClique::*weightFunc)(const NetType &) const; // define function pointer
    weighedClique( const std::vector<size_t> & unsorted_nodes, const NetType & net, size_t funcType = 0 );
    void addNodes(const std::vector<size_t> & unsorted_nodes, const  NetType & net);
    void copyClique(const weighedClique & old_clique);
    void replaceNodes(  const std::vector<size_t> & unsorted_nodes, const NetType & net );
    float getWeight() const
    {
        return weight;
    }

    //wanha
    float minWeight(const NetType & net) const;

    //wanha
    float maxWeight(const NetType & net) const;


    //wanha
    float intensity(const NetType & net) const;

    void printWeightedClique(std::ostream & file) const;

};

#endif
