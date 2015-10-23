//
// Created by benjamin on 15.10.15.
//

#ifndef FGA_SUBSET_H
#define FGA_SUBSET_H

//This class should represent a set of Elements. The operations of add an element, check whether an element is in the set , merging, and intersection, should be implemented

#include "boost/dynamic_bitset.hpp"
#include "ElementWrapper.h"

class Subset {
public:
    Subset(int order, std::vector<EW>* all);
    Subset(int order, std::vector<EW*> set, std::vector<EW>* all);
    Subset(const Subset& orign);
    virtual ~Subset();

    Subset merge(const Subset& other) const;
    Subset intersection(const Subset& other) const;
    std::vector<EW*> get() const;
    void add(EW* element);
    int getOrder() const; //Number of elements in the set

private:
    boost::dynamic_bitset<> bitset; //Which element is in the set, 0 for is not in the set, 1 for it is
    std::vector<EW>* all; //Pointer to the original Elements
    int order; //Order of the group
};


#endif //FGA_SUBSET_H
