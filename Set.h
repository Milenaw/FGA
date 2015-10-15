//
// Created by benjamin on 15.10.15.
//

#ifndef FGA_SET_H
#define FGA_SET_H

//This class should represent a set of Elements. The operations of add an element, check whether an element is in the set , merging, and intersection, should be implemented

#include <bitset>
#include "ElementWrapper.h"

template <int ORDER>
class Set {
public:
    Set(std::vector<EW>* all);
    Set(std::vector<EW*> set, std::vector<EW>* all);
    Set(const Set& orign);
    virtual ~Set();

    Set merge(const Set& other) const;
    Set intersection(const Set& other) const;
    std::vector<EW*> get(const std::vector<EW>& all) const;
    int order() const; //Number of element in the set

private:
    std::bitset<ORDER> bitset; //Which element is in the set, 0 for is not in the set, 1 for it is
    std::vector<EW>* all; //Pointer to the original Elements
};


#endif //FGA_SET_H
